#pragma once
#include "JAssignment.h"
class JExpression;
class Context;
class JMulAssignOp : public JAssignment
{
public:

	JMulAssignOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

