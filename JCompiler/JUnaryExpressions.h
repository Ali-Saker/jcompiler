#pragma once
#include "JExpression.h"
class JUnaryExpressions :
	public JExpression
{
public:
	char* op;
	JExpression* arg;

	JUnaryExpressions(int line, int col, char* op, JExpression* arg) : JExpression(line, col, "UnaryExpression")
	{
		this->op = op;
		this->arg = arg;
	}

	virtual JExpression* analyze(Context* surrounding){ return this; }

	~JUnaryExpressions()
	{
	}
};

