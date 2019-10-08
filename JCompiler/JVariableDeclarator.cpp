#include"Type.h"
#include"AccessProperty.h"
#include "JExpression.h"
#include"Context.h"
#include"JVariableDeclarator.h"

/**/
#include"Utils.h"
#include"JFieldDeclaration.h"
#include"ConversionTable.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"ArrayType.h"
#include"JClassDeclaration.h"
#include"JInterfaceDeclaration.h"
#include"ErrorRecovery.h"
#include"MethodContext.h"
#include"JMethodDeclaration.h"
JVariableDeclarator::JVariableDeclarator(int line, int col, char* name, Type *type,
            JExpression* initializer):JAST(line, col){

        this->name = name;
		this->type = type;
        this->initializer = initializer;
		this->accessProperty = 0;
		this->isField = 0;
    }



void JVariableDeclarator::preAnalyze(Context* surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	if (this->initializer != 0){
		this->initializer->preAnalyze(surrounding);
	}
	this->setContext(surrounding);
}

void JVariableDeclarator::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	if (this->initializer != 0){
		this->initializer->analyze();
		pair<char *, int> lhs, rhs;
		lhs = this->type->getName();
		rhs = this->initializer->expressionType == 0 ? make_pair(nullptr, 0) : this->initializer->expressionType->getName();

		if (lhs.first != nullptr && rhs.first != nullptr){
			
			errLine = this->initializer->getLine();
			errCol = this->initializer->getCol();
			int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhs.first),
				Utils::toString(rhs.first), "=");
			if (status == 0){
				errMsg = "The operator = is undefined for the argument type(s) " + Utils::toString(lhs.first)
					+ ", " + Utils::toString(rhs.first);
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
			if (status == 2){
				errMsg = "Type mismatch: cannot convert from " + Utils::toString(rhs.first)
					+ " to " + Utils::toString(lhs.first);
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
			if (status == 1){
				if (lhs.second != rhs.second){
					char *_lhs = new char[300];
					strcpy(_lhs , lhs.first);
					char *_rhs = new char[300];
					strcpy(_rhs, rhs.first);
					
					int d1 = lhs.second, d2 = rhs.second;
					while (d1-- != 0)strcat(_lhs, "[]");
					while (d2-- != 0)strcat(_rhs, "[]");
					errMsg = "Type mismatch: cannot convert from " + Utils::toString(_rhs)
						+ " to " + Utils::toString(_lhs);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
			}
		}
	}

	if (!this->isField){
		JMethodDeclaration *methodDecl = this->getContext()->getMethodContext()->definingMethod;
		int y = methodDecl->childId;
		this->id = methodDecl->childId;
		methodDecl->childId++;
	}
}


void JVariableDeclarator::codegen(){
	if (this->initializer != 0){
		this->initializer->codegen();
		if (this->initializer->isFP()){
			Utils::out << "lwc1 $f1,4($sp)" << endl;
		}
		else{
			Utils::out << "lw $t1,4($sp)" << endl;
		}
		
		Utils::out << "addiu $sp,$sp,4" << endl;
		if (this->accessProperty != 0 && this->accessProperty->isStatic()){
			if (this->initializer->isFP()){
				Utils::out << "swc1 $f1," << this->id * 4 << "($gp)" << endl;
			}
			else{
				Utils::out << "sw $t1," << this->id * 4 << "($gp)" << endl;
			}
			
		}
		else if (this->isField){
			if (this->initializer->isFP()){
				Utils::out << "swc1 $f1," << (this->id + 4) * 4 << "($s7)" << endl;
			}
			else{
				Utils::out << "sw $t1," << (this->id + 4) * 4 << "($s7)" << endl;
			}
			
		}
		else{
			if (this->initializer->isFP()){
				Utils::out << "swc1 $f1," << (this->id) * -4 << "($fp)" << endl;
			}
			else{
				Utils::out << "sw $t1," << (this->id ) * -4 << "($fp)" << endl;
			}
			
		}


	}

}