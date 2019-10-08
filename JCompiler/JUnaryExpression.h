#pragma once
#include "JExpression.h"

/*Abstract parent of all unary expressions*/
class JUnaryExpression : public JExpression
{
public:
	char* op;
	JExpression* arg;

	JUnaryExpression(int, int, char *, JExpression *);

};

