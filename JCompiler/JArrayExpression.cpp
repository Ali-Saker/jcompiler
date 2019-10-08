#include"Context.h"
#include"typeName.h"
#include"JArrayExpression.h"
#include"Type.h"
#include"ReferenceType.h"
#include"ArrayType.h"
#include"PrimitiveType.h"
#include"ErrorRecovery.h"
#include"Utils.h"
#include"JClassDeclaration.h"

JArrayExpression::JArrayExpression(int line, int col, JExpression *target, JExpression *index)
: JExpression(line, col, "JArrayExpression", 0){
	this->target = target;
	this->index = index;
}


void JArrayExpression::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	if (this->target != 0) this->target->preAnalyze(surrounding);
	if (this->index != 0) this->index->preAnalyze(surrounding);
	this->setContext(surrounding);
}
void JArrayExpression::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	this->index->analyze();
	if (this->index->expressionType == 0 || (!dynamic_cast<PrimitiveType *>(this->index->expressionType)
		|| (dynamic_cast<PrimitiveType *>(this->index->expressionType) && this->index->expressionType != PrimitiveType::JINTEGER))){
		errMsg = "array index must be of integer type.";
		errLine = this->getLine();
		errCol = this->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}
	/***************************************************Begining of (target not Null)************************************************/
	if (target != 0){
		target->preAnalyze(surrounding);
		target->analyze();
		/*type exist*/
		if (target->expressionType == 0){
			errLine = this->getLine();
			errCol = this->getCol();
			errMsg = "bad expression prefix.";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
		else{
			/*check target type*/
			if (dynamic_cast<ArrayType*>(target->expressionType)){
				ArrayType *type = (ArrayType *)target->expressionType;
				int dims = type->dimensions;
				
				if (dims == 1){
					this->expressionType = type->type;
					this->isVarName = 1;
				}
				else{
					this->expressionType = new ArrayType(type->type, dims - 1);
				}

			}else{
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "bad expression prefix.";
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}
	}
}
void JArrayExpression::codegen(){
	this->index->codegen(); //
	this->target->codegen();

	Utils::out << "lw $t1,8($sp)" << endl; //$t1 is index
	Utils::out << "lw $t2,4($sp)" << endl; //$t2 is ref
	Utils::out << "addi $t1,$t1,1" << endl;
	Utils::out << "sll $t1,$t1,2" << endl;
	Utils::out << "addu $v0,$t1,$t2" << endl;
	Utils::out << "lw $t1,0($v0)" << endl;
	Utils::out << "sw $t1,8($sp)" << endl;
	Utils::out << "addi $sp,$sp,4" << endl;

}