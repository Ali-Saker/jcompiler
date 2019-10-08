#pragma once
#include"JExpression.h"
#include"ConstantExpressionInterface.h"
class Type;
/*Abstract class to represent all types of JLiteral*/
class JLiteral : public JExpression, public ConstantExpressionInterface
{
public:
	/*value of this literal as a string, in code generation phase we resolve it.*/
	char *value;
	JLiteral(int, int, char *, Type *, char *);
	virtual void codegen(){};
};

