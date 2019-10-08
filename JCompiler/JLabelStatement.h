#pragma once
#include"JStatement.h"
class JExpression;
class Context;
class JLabelStatement : public JStatement{

public:
	/* 
	 * lable name
	 * 1. case
	 * 2. default
	 */
	char *lableName;

	JExpression* constantExpression;

	JLabelStatement(int, int, char *,JExpression *);

	virtual void preAnalyze(Context *);

	/*analyse to check if expression is constatnt or not*/
	virtual void analyze();
	virtual void codegen();
};