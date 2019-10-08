#pragma once
#include "JArithmaticBinaryExpression.h"
class JExpression;
class Context;

class JSubOp :
	public JArithmaticBinaryExpression
{
public:

	JSubOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

