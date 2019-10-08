#pragma once
#include "JExpression.h"
class Context;
class JThis : public JExpression
{
public:

	JThis(int, int);

	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void codegen();
};

