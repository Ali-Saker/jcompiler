#pragma once
#include "IncrementExpression.h"
#include"ExpressionStatementInterface.h"
class JExpression;
class Context;
class JPostIncrementOp : public IncrementExpression, public ExpressionStatementInterface
{
public:

	JPostIncrementOp(int, int, JExpression *);
	virtual void codegen();
};


