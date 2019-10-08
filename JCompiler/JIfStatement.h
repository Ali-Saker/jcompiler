#pragma once
#include"JSelectionStatement.h"
class JExpression;
class JStatement;
class Context;

class JIfStatement : public JSelectionStatement{

public:
	/** Then clause. */
	JStatement *thenPart;

	/** Else clause. */
	JStatement *elsePart;

	JIfStatement(int, int, JExpression *, JStatement *, JStatement *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};
