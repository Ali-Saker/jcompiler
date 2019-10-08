#include"Type.h"
#include"Context.h"
#include"CastExpression.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"ConversionTable.h"
#include"Utils.h"
#include"ArrayType.h"
#include"typeName.h"
#include<iostream>
using namespace std;
CastExpression::CastExpression(int line, int col, Type *castType, JExpression *arg)
:JExpression(line, col, "CastExpression", 0){
	this->castType = castType;
	this->arg = arg;
}

void CastExpression::preAnalyze(Context *surrounding){
	this->setContext(surrounding); 
	if (this->arg != 0){
		this->arg->preAnalyze(surrounding);
	}
}
void CastExpression::analyze(){
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();

	if (this->arg != 0){
		this->arg->analyze();
	}

	if (dynamic_cast<ReferenceType *>(this->castType)){
		((ReferenceType *)this->castType)->resolve((Context *)surrounding->getClassContext());
	}
	if (dynamic_cast<ArrayType *>(this->castType)){
		Type * type = ((ArrayType *)(this->castType))->type;
		if (dynamic_cast<ReferenceType *>(type)){
			((ReferenceType *)type)->resolve((Context *)surrounding->getClassContext());
			if (((ReferenceType *)type)->referenceTypeDecl == 0){
				errCol = this->getCol();
				errLine = this->getLine();
				errMsg = Utils::toString(this->castType->typeName->name) + " cannot resolved to a type";
				ErrorRecovery::reportSemanticError(errLine,errCol,Utils::toCharArray(errMsg));
			}
		}
		

	}

	if (this->arg != 0 && this->arg->expressionType != 0 && this->castType != 0 && this->castType->getName().first != 0){
		pair<char *, int> lhs = this->castType->getName();
		pair<char *, int> rhs = this->arg->expressionType->getName();

		int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhs.first),
			Utils::toString(rhs.first), "cast");

		if (status != 1 || lhs.second != rhs.second){
			string type1 = Utils::toString(lhs.first);
			string type2 = Utils::toString(rhs.first);
			while (lhs.second--)type1 += "[]";
			while (rhs.second--)type2 += "[]";
			errLine = this->getLine();
			errCol = this->getCol();
			errMsg = "Type mismatch: cannot cast " + type2
				+ " to " + type1;

			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
		else{
			this->expressionType = this->castType;
		}
		
	}
}

void CastExpression::codegen(){
	bool is_fp = dynamic_cast<PrimitiveType *> (this->castType) && 
		(  this->castType == PrimitiveType::JFLOAT 
		|| this->castType == PrimitiveType::JDOUBLE
		);
	bool is_int = dynamic_cast<PrimitiveType *> (this->castType) &&
		(this->castType == PrimitiveType::JCHAR
		|| this->castType == PrimitiveType::JINTEGER
		|| this->castType == PrimitiveType::JLONG

		);
	 this->arg->codegen();
	  
	 if (is_fp){
		if (this->arg->isIntegral()){
			//convert to fp
			Utils::out << "lwc1 $f1, 4($sp)" << endl;
			Utils::out << "cvt.s.w $f1, $f1" << endl;
			Utils::out << "swc1 $f1, 4($sp)" << endl;

		}
		
	}
	else if (is_int){
		if (this->arg->isFP()){
			//convert to fp
			Utils::out << "lwc1 $f1, 4($sp)" << endl;
			Utils::out << "cvt.w.s $f1, $f1" << endl;
			Utils::out << "mfc1 $t1, $f1" << endl;
			Utils::out << "sw $t1, 4($sp)" << endl;

		}
		
	}
}