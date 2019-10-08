#include"JExpression.h"
#include"Context.h"
#include"JLogicalNotOp.h"
#include"Utils.h"

JLogicalNotOp::JLogicalNotOp(int line, int col, JExpression* arg)
: JUnaryExpression(line, col, "!", arg)
{
}

void JLogicalNotOp::preAnalyze(Context* surrounding)
{
}

void JLogicalNotOp::analyze()
{

}
//virtual JExpression* analyze(Context* surrounding){
//	arg = arg->analyze(surrounding);
//
//	string errMsg;
//
//	if (!arg->expressionType->equals(TypeName::BOOLTYPE)){
//		errMsg = "The operator ! is undefined for the argument type " +
//			Utils::toString(arg->expressionType->name) + ".";
//
//		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//	}
//
//	expressionType = TypeName::BOOLTYPE;
//	return this;
//}

void JLogicalNotOp::codegen(){
	this->arg->codegen();
	Utils::out << "lw $t1,4($sp)" << endl;
	Utils::out << "xori $t1,$t1,1" << endl;
	Utils::out << "sw $t1,4($sp)" << endl;
}