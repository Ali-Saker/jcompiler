#pragma once
#include "JExpression.h"
class JWildExpression :
	public JExpression
{
public:

	JWildExpression(int line, int col) : JExpression(line, col)
	{
	}

	virtual JExpression* analyze(Context* surrounding){ return this; }

	~JWildExpression()
	{
	}
};

