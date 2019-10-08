#pragma once
#include "JExpression.h"
#include<vector>
#include"typeName.h"
class JNewInnerOp :
	public JExpression
{
public:
	char* qualifiedName;
	JExpression* newExpr;

	JNewInnerOp(int line, int col, char* qualifiedName, JExpression* newExpr) : JExpression(line, col)
	{
		this->qualifiedName = qualifiedName;
		this->newExpr = newExpr;
	}

	~JNewInnerOp()
	{
	}
};


