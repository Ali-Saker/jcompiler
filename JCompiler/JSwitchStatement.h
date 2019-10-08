#pragma once
#include"JSelectionStatement.h"
class JBlock;
class JExpression;
class Context;
class JSwitchStatement : public JSelectionStatement{
public:
	JBlock* block;

	JSwitchStatement(int, int, JExpression *, JBlock *);
	int id;
	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void codegen();
};
