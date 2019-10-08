#pragma once
#include "JExpression.h"
#include"ExpressionStatementInterface.h"
#include<vector>

class Context;
class TypeName;
class JMethodDeclaration;
class JMethodSelection :
	public JExpression, public ExpressionStatementInterface
{
public:

	vector<JExpression*>* args;
	JExpression* target;
	char* methodName;
	TypeName *routedName;
	char *fieldtype;
	JMethodDeclaration *methodDeclaration;
	int outerNum;
	JMethodSelection(int, int, vector<JExpression*> *, JExpression *, char *, TypeName*);
	void resolve(Context *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};