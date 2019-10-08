#pragma once
#include "IncrementExpression.h"
#include"ExpressionStatementInterface.h"
class JExpression;
class Context;
class JPreIncrementOp : public IncrementExpression, public ExpressionStatementInterface
{
public:

	JPreIncrementOp(int, int, JExpression *);
	virtual void codegen();
};


