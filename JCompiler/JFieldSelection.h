#pragma once
#include "JExpression.h"
#include"LHSExpressionInterface.h"

class TypeName;
class Context;
class JVariableDeclarator;
class JFieldSelection :
	public JExpression, public LHSExpressionInterface
{
public:
	JExpression* target;
	char* fieldName;
	TypeName *routedName;
	char * fieldtype;
	JVariableDeclarator *variableDeclaration;
	JFieldSelection(int, int, JExpression *, char *, TypeName *);
	virtual void preAnalyze(Context *);
	virtual void  analyze();
	virtual void  codegen();
};
