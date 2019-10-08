#pragma once
#include "JBoolBinaryExpression.h"
class JExpression;
class Context;
class JLogicalOrOp : public JBoolBinaryExpression
{
public:

	JLogicalOrOp(int, int, JExpression *, JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};

