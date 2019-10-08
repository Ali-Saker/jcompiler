#pragma once
#include "IncrementExpression.h"
#include"ExpressionStatementInterface.h"
class JExpression;
class Context;

class JPostDecrementOp : public IncrementExpression, public ExpressionStatementInterface
{
public:

	JPostDecrementOp(int, int, JExpression *);
	virtual void codegen();
};
