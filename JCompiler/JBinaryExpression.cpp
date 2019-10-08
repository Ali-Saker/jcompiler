#include"Context.h"
#include"JBinaryExpression.h"
JBinaryExpression::JBinaryExpression(int line, int col, JExpression *lhs, JExpression *rhs, char *op)
:JExpression(line, col, "JBinaryExpression", 0)
{
	this->lhs = lhs;
	this->rhs = rhs;
	this->op = op;
}
void JBinaryExpression::preAnalyze(Context *surrounding){

}
void JBinaryExpression::analyze(){

}
