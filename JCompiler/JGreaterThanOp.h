#pragma once
#include "JComparison.h"
class JExpression;
class Context;

class JGreaterThanOp :
	public JComparison
{
public:

	JGreaterThanOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

