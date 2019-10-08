#pragma once
#include<vector>
#include"JIterationStatement.h"
using namespace std;

class JVariableDeclaration;
class JExpression;
class JStatement;
class Context;

class JForeachStatement : public JIterationStatement{
public:

	JVariableDeclaration *foreachVariableDeclaration;

	JExpression *arrayExpr;


	JForeachStatement(int, int, JStatement *, JVariableDeclaration *, JExpression *);

	virtual void preAnalyze(Context *);

	virtual void analyze();

	virtual void codegen();
};