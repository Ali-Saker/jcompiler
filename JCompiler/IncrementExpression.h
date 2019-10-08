#pragma once
#include "JUnaryExpression.h"
class JExpression;
class Context;
class IncrementExpression : public JUnaryExpression
{
public:

	IncrementExpression(int, int, char *, JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
};


