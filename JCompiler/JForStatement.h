#pragma once
#include<vector>
#include"JIterationStatement.h"
using namespace std;

class JExpressionStatement;
class JVariableDeclaration;
class JExpression;
class JStatement;
class Context;

class JForStatement : public JIterationStatement{
public:

	/**
	* For has 4 parts forInit, forExpr, forIncr, statement
	* forInit is expressionStatetments 1, or localVariableDeclaration 2
	*
	*/

	/* 1 */
	vector<JExpressionStatement*> *forInitExpressionStatements;

	/* 2 */
	JVariableDeclaration* forInitVariableDeclaration;

	JExpression* forExpr;

	vector<JExpressionStatement*> *forIncr;

	JForStatement(int, int, JStatement *, vector<JExpressionStatement*> *,
		JVariableDeclaration *, JExpression *, vector<JExpressionStatement*> *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();

};