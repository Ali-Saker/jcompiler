#pragma once
#include "JAssignment.h"
class JExpression;
class Context;
class JSubAssignOp : public JAssignment
{
public:

	JSubAssignOp(int, int, JExpression *, JExpression *);
	virtual void codegen();
};

