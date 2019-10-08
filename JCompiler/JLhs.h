#pragma once
#include"JExpression.h"

class JLhs
{
public:
	JLhs(){}

	virtual JExpression* analyzeLhs(Context* context){ return 0; }

	~JLhs(){}
};

