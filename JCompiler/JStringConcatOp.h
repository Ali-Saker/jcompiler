#pragma once
#include "JBinaryExpression.h"
class JStringConcatOp :
	public JBinaryExpression
{
public:

	JStringConcatOp(int line, int col, JExpression* lhs, JExpression* rhs) : JBinaryExpression(line, col, lhs, rhs, "+"){}

	virtual JExpression* analyze( Context* ){
		expressionType = TypeName::STRINGTYPE;
		return this;
	}

	~JStringConcatOp()
	{
	}
};


