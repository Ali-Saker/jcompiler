#pragma once
#include "JAssignment.h"
class JExpression;
class Context;
class JAssignOp : public JAssignment
{
public:

	JAssignOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

