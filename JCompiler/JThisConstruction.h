#pragma once
#include"JExpression.h"
#include"ExpressionStatementInterface.h"
class Context;
class JThisConstruction : public JExpression, public ExpressionStatementInterface
{
public:
	vector<JExpression*> *args;

	JThisConstruction(int, int, vector<JExpression*> *);

	virtual void preAnalyze(Context *);
	//get pointer to class by defining Reference type and be sure it has constructor with same arguments
	virtual void analyze();
};

