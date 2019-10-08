#include"JExpression.h"
#include"Context.h"
#include"JPositiveOp.h"

JPositiveOp::JPositiveOp(int line, int col, JExpression* arg)
: JUnaryExpression(line, col, "+", arg){
}
void JPositiveOp::preAnalyze(Context* surrounding)
{
}

void JPositiveOp::analyze()
{

}


//virtual JExpression* analyze(Context* surrounding){
//	arg = arg->analyze(surrounding);
//
//	string errMsg;
//
//	if (!arg->expressionType->isNumber()){
//		errMsg = "The operator + is undefined for the argument type " +
//			Utils::toString(arg->expressionType->name) + ".";
//
//		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//	}
//
//	expressionType = TypeName::INTYPE;
//	return this;
//}
