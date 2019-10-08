#pragma once
#include"JStatement.h"
class JExpression;
class Context;
class JExpressionStatement : public JStatement{
public:
	JExpression* expression;

	JExpressionStatement(JExpression *);


	virtual void preAnalyze(Context *);

	/* do analyse to check if expression has a side effect */
	virtual void analyze();
	virtual void codegen();
};
