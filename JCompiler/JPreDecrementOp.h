#pragma once
#include "IncrementExpression.h"
#include"ExpressionStatementInterface.h"
class JExpression;
class Context;

class JPreDecrementOp : public IncrementExpression, public ExpressionStatementInterface
{
public:

	JPreDecrementOp(int, int, JExpression *);
	virtual void codegen();
};

