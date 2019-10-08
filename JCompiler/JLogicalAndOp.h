#pragma once
#include "JBoolBinaryExpression.h"
class JExpression;
class Context;
class JLogicalAndOp : public JBoolBinaryExpression
{
public:

	JLogicalAndOp(int, int, JExpression *, JExpression *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};

