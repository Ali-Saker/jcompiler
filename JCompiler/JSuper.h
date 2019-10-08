#pragma once
#include "JExpression.h"
class Context;
class JSuper : public JExpression
{
public:

	JSuper(int, int);

	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void codegen();
};
