#pragma once
#include "JArithmaticBinaryExpression.h"
class JExpression;
class Context;
class JMulOp : public JArithmaticBinaryExpression
{
public:

	JMulOp(int, int, JExpression *, JExpression *);

	virtual void codegen();
};


