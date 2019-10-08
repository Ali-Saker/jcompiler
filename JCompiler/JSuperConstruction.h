#pragma once
#include"JExpression.h"
#include"ExpressionStatementInterface.h"
class Context;
class JSuperConstruction : public JExpression, public ExpressionStatementInterface
{
public:
	vector<JExpression*> *args;

	JSuperConstruction(int, int, vector<JExpression*> *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
};

