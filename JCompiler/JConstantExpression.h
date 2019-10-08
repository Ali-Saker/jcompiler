#pragma once
#include"JExpression.h"

class JConstantExpression :
	public JExpression
{
public:

	JConstantExpression(int line, int col, TypeName* expressionType, char* name)
		: JExpression(line, col, expressionType, name){
		isConstantExpression = true;
	}


	virtual JExpression* analyze(Context* context){
		

		return this;
	}


	~JConstantExpression()
	{
	}
};

