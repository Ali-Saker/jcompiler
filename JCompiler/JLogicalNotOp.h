#pragma once
#include "JUnaryExpression.h"
class JExpression;
class Context;
class JLogicalNotOp : public JUnaryExpression
{
public:

	JLogicalNotOp(int, int, JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};


