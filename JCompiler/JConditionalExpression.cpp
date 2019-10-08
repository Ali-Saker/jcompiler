#include"Context.h"
#include"JConditionalExpression.h"

JConditionalExpression::JConditionalExpression(int line, int col, JExpression *condition,
JExpression *thenPart, JExpression *elsePart) : JExpression(line, col, "JConditionalExpression", 0)
{
	this->condition = condition;
	this->thenPart = thenPart;
	this->elsePart = elsePart;
}
void JConditionalExpression::preAnalyze(Context* surrounding)
{
}

void JConditionalExpression::analyze()
{

}
//JExpression* analyze(Context* surrounding){
//	condition = (JExpression*)condition->analyze(surrounding);
//	thenPart = (JExpression*)thenPart->analyze(surrounding);
//	elsePart = (JExpression*)elsePart->analyze(surrounding);
//
//	string errMsg;
//
//	// check if condition return bool type
//	if (!condition->expressionType->equals(TypeName::BOOLTYPE)){
//		errMsg = "Type mismatch : cannot convert from " +
//			Utils::toString(condition->expressionType->name) + "to boolean.";
//
//		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//	}
//
//	// cant decide return type
//
//	return this;
//}