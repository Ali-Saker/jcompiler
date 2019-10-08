#include"JExpression.h"
#include"Context.h"
#include"JBoolBinaryExpression.h"

JBoolBinaryExpression::JBoolBinaryExpression(int line, int col, JExpression *lhs, JExpression *rhs, char *op)
: JBinaryExpression(line, col, lhs, rhs, op)
{
}