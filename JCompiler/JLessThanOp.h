#pragma once
#include "JComparison.h"
class JExpression;
class Context;

class JLessThanOp : public JComparison
{
public:

	JLessThanOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

