#pragma once
#include "JComparison.h"
class JExpression;
class Context;

class JGreaterOrEqualOp : public JComparison
{
public:

	JGreaterOrEqualOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};
