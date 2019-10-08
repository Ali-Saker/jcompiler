#pragma once
#include"JStatement.h"
class JExpression;
class Context;

class JJumpStatement : public JStatement{
public:

	/*
	* jump name
	* 1. break
	* 2. continue
	* 3. return
	* 4. throw
	*/
	char *jumpName;

	/* the returned expression */
	JExpression* returnExpression;

	JJumpStatement(int, int, char *, JExpression *);

	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void codegen();
};