#include"Type.h"
#include"JLiteral.h"
#include"Utils.h"
JLiteral::JLiteral(int line, int col, char *expressionName, Type *expressionType, char *value)
:JExpression(line, col, expressionName, expressionType)
{
	this->value = value;
}
