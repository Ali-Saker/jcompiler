#include"JUnaryExpression.h"

JUnaryExpression::JUnaryExpression(int line, int col, char *op, JExpression *arg) 
: JExpression(line, col, "JUnaryExpression", 0)
{
	this->op = op;
	this->arg = arg;
}