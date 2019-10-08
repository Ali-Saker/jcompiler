#pragma once

#include<vector>
#include"JAST.h"
using namespace std;

class Type;
class AccessProperty;
class JVariableDeclarator;
class Context;

class JFieldDeclaration :public JAST{

public:
	
	Type *type;
	AccessProperty *accessProperty;
	vector<JVariableDeclarator*> *decls;
	int id;
	JFieldDeclaration(int, int, Type *, AccessProperty *, vector<JVariableDeclarator*> *);

	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void codegen();
};
