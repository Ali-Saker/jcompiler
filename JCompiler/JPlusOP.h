#pragma once
#include "JArithmaticBinaryExpression.h"
class JExpression;
class Context;

class JPlusOP : public JArithmaticBinaryExpression
{

public:
	JPlusOP(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

