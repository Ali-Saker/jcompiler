#pragma once
#include"JExpression.h"
#include"LHSExpressionInterface.h"
class Context;
class TypeName;
class JVariableDeclarator;
class JVariable : public JExpression, public LHSExpressionInterface{
public:

	TypeName *typeName;
	JVariableDeclarator *variableDeclarator;
	JVariable(TypeName *, JVariableDeclarator *);
	void resolve(Context *);
	int outerNum;
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};