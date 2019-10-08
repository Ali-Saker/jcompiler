#pragma once
#include "JAssignment.h"
class JExpression;
class Context;
class JDivAssignOp : public JAssignment
{
public:

	JDivAssignOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

