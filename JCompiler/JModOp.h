#pragma once
#include "JArithmaticBinaryExpression.h"
class JExpression;
class Context;

class JModOp : public JArithmaticBinaryExpression
{
public:

	JModOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};



