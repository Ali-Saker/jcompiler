#pragma once
#include "JBoolBinaryExpression.h"
class JExpression;
class Context;
class JNotEqualOp : public JBoolBinaryExpression
{
public:

	JNotEqualOp(int, int, JExpression *, JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};

