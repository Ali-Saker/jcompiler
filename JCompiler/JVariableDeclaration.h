#pragma once 
#include<vector>
#include"JStatement.h"
using namespace std;

class Type;
class AccessProperty;
class JVariableDeclarator;
class Context;
/* Class to represent local variables */

class JVariableDeclaration :public JStatement {

public:

	/* local variable's type */
	Type *type;

	AccessProperty* accessProperty;

    /** Variable declarators. */
    vector<JVariableDeclarator*>* decls;

	JVariableDeclaration(int, int, Type *, AccessProperty *, vector<JVariableDeclarator*> *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};
