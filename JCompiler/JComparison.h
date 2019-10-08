#pragma once
#include "JBoolBinaryExpression.h"
class JExpression;
class Context;
class JComparison : public JBoolBinaryExpression
{
public:

	JComparison(int, int, JExpression *, JExpression *, char *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
};

