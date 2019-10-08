#pragma once
#include"JAST.h"

class AccessProperty;
class JVariableDeclarator;
class Type;
class Context;
class JFormalParameter :public JAST{
	
public:

	AccessProperty *accessProperty;

	/** Parameter name and initializer */
	JVariableDeclarator *variableDeclarator;

	Type *type;
	JFormalParameter(int, int, AccessProperty *, JVariableDeclarator *, Type *);

	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void codegen();
};
