#pragma once
#include<vector>
using namespace std;
#include "JExpression.h"
#include"LHSExpressionInterface.h"
class TypeName;
class Context;
class JArrayExpression :
	public JExpression, public LHSExpressionInterface
{
public:
	JExpression* target;
	JExpression* index;
	JArrayExpression(int, int, JExpression *, JExpression *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};
