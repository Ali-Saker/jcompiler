#pragma once

#include<vector>
#include"JAST.h"
using namespace std;

class AccessProperty;
class Type;
class InterfaceContext;
class JVariableDeclarator;
class JMethodDeclaration;
class JInterfaceDeclaration :public JAST {

public:
	/** interface name. */
	char* name;

	char *fullName;
	/** interface access property. */
	AccessProperty *accessProperty;

	vector<Type*> *superTypes;

	/*interface context*/
	InterfaceContext *interfaceContext;

	/** Class block. */
	vector<JAST*> *interfaceBlock;

	JInterfaceDeclaration(int, int, char *, AccessProperty *, vector<Type*> *, InterfaceContext *, vector<JAST*> *);

	JVariableDeclarator *hasVariable(char *);
	JMethodDeclaration *hasMethod(char *);
	virtual void preAnalyze(Context *);

	virtual void analyze();
};