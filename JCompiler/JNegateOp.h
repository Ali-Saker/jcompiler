#pragma once
#include "JUnaryExpression.h"
class JExpression;
class Context;
class JNegateOp : public JUnaryExpression
{
public:

	JNegateOp(int, int, JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();

};



