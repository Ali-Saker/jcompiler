#pragma once
#include "JBinaryExpression.h"
class JExpression;
class Context;
/* Abstract parent of all boolean binary expressions. */
class JBoolBinaryExpression : public JBinaryExpression
{
public:

	JBoolBinaryExpression(int, int, JExpression *, JExpression *, char *);
};

