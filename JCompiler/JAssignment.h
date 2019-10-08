#pragma once
#include "JBinaryExpression.h"
#include"ExpressionStatementInterface.h"
class JExpression;
class Context;
class JAssignment : public JBinaryExpression, public ExpressionStatementInterface
{
public:

	JAssignment(int, int, JExpression *, JExpression *, char *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	
};

