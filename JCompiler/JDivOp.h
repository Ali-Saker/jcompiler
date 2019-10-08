#pragma once
#include "JArithmaticBinaryExpression.h"
class JExpression;
class Context;

class JDivOp : public JArithmaticBinaryExpression
{
public:

	JDivOp(int, int, JExpression*, JExpression*);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};



