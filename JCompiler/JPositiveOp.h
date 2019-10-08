#pragma once
#include "JUnaryExpression.h"
class JExpression;
class Context;
class JPositiveOp : public JUnaryExpression
{
public:

	JPositiveOp(int, int, JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();

};



