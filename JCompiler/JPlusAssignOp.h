#pragma once
#include "JAssignment.h"
class JExpression;
class Context;
class JPlusAssignOp : public JAssignment
{
public:

	JPlusAssignOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

