#pragma once
#include "JComparison.h"
class JExpression;
class Context;

class JLessOrEqualOp :
	public JComparison
{
public:

	JLessOrEqualOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

