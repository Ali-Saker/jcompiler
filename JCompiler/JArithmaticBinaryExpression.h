#pragma once
#include "JBinaryExpression.h"
class JExpression;
class Context;
class JArithmaticBinaryExpression : public JBinaryExpression
{
public:

	JArithmaticBinaryExpression(int, int, JExpression *, JExpression *, char *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
};

