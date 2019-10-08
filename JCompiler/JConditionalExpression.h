#pragma once
#include "JExpression.h"
#include"ExpressionStatementInterface.h"
class Context;
class JConditionalExpression : public JExpression, ExpressionStatementInterface
{
public:

	JExpression *condition;
	JExpression *thenPart;
	JExpression *elsePart;
	JConditionalExpression(int, int, JExpression *, JExpression *, JExpression *);

	virtual void preAnalyze(Context *);

	virtual void analyze();
};

