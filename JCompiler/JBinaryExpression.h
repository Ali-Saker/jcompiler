#pragma once
#include "JExpression.h"
class Context;
/* Parent of all binary expressions */
class JBinaryExpression : public JExpression
{
public:
	JExpression* lhs;
	JExpression* rhs;
	char* op;

	JBinaryExpression(int, int, JExpression *, JExpression *, char *);
	/* Until writing this comment, i think all binary expressions have same pre/analyzing */
	virtual void preAnalyze(Context *);
	virtual void analyze();

};

