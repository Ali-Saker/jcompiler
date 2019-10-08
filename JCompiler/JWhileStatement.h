#pragma once
#include"JIterationStatement.h"
class JExpression;
class JStatement;
class Context;

class JWhileStatement: public JIterationStatement{
public:

	JExpression* condition;

	JWhileStatement(int, int, JStatement *, JExpression *);
	virtual void preAnalyze(Context *);

	virtual void analyze();

	virtual void codegen();
};
