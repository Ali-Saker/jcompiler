#pragma once
/**
 * The AST node for an expression. The syntax says all expressions are
 * statements, but a semantic check throws some (those without a side-effect)
 * out.
 * 
 * Every expression has a type and a flag saying whether or not it's a
 * statement-expression.
 */

#include"JStatement.h"
class Type;
class Context;
class JExpression :public JStatement {

public:
	char *expressionName;

	Type* expressionType;

	bool isVarName;

	bool isClassName;

	bool isPackageName;

	JExpression(int, int, char *, Type *);
	bool isString();
	bool isIntegral();
	bool isFP();
	bool isRef();
	bool isChar();
};