#include"JExpression.h"
#include"Context.h"
#include"JNegateOp.h"

/**/
#include"LHSExpressionInterface.h"
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"PrimitiveType.h"
#include"typeName.h"
#include"Utils.h"
JNegateOp::JNegateOp(int line, int col, JExpression* arg)
: JUnaryExpression(line, col, "-", arg)
{
}
void JNegateOp::preAnalyze(Context* surrounding)
{
	if (this->arg != 0){
		this->arg->preAnalyze(surrounding);
	}
}

void JNegateOp::analyze()
{
	string errMsg;
	int errLine, errCol;

	if (this->arg != 0 && this->arg->expressionType != nullptr){
		if (!dynamic_cast<PrimitiveType *>(this->arg->expressionType)){
			errLine = this->arg->getLine();
			errCol = this->arg->getCol();
			errMsg = "The operator - is undefined for the argument type(s) "
				+ Utils::toString(this->expressionType->typeName->name);
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			this->expressionType = nullptr;
		}
		else{
			this->expressionType = this->arg->expressionType;
		}
	}
	else{
		this->expressionType = nullptr;
	}
}
//virtual JExpression* analyze(Context* surrounding){
//	arg = arg->analyze(surrounding);
//
//	string errMsg;
//
//	if (!arg->expressionType->isNumber()){
//		errMsg = "The operator - is undefined for the argument type " +
//			Utils::toString(arg->expressionType->name) + ".";
//
//		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//	}
//
//	expressionType = TypeName::INTYPE;
//	return this;
//}

void JNegateOp::codegen(){
	this->arg->codegen();
	Utils::out << "lw $t1,4($sp)" << endl;
	Utils::out << "li $t2,-1" << endl;
	Utils::out << "mul $t1,$t1,t2" << endl;
	Utils::out << "sw $t1,4($sp)" << endl;
}