#pragma once
#include "JBoolBinaryExpression.h"
class JExpression;
class Context;
class JEqualOp : public JBoolBinaryExpression
{
public:

	JEqualOp(int, int, JExpression *, JExpression *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};

