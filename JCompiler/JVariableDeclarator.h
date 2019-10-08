#pragma once
#include"JAST.h"
class Type;
class AccessProperty;
class JExpression;
class Context;

class JVariableDeclarator :public JAST {

public:
    /** Variable name. */
    char* name;

	bool isField;

	int id;

	Type* type;

	AccessProperty *accessProperty;

    /** Variable initializer. */
	JExpression* initializer;

	JVariableDeclarator(int, int, char *, Type *, JExpression *);

	virtual void preAnalyze(Context*);

	virtual void analyze();
	virtual void codegen();
};

