#pragma once

#include<vector>
#include<map>
#include<string>
#include"JAST.h"
using namespace std;

class AccessProperty;
class Type;
class ClassContext;
class JVariableDeclarator;
class JMethodDeclaration;
class JClassDeclaration :public JAST {

public:
    /** Class name. */
    char* name;

	char *fullName;
	/** Class access property. */
	AccessProperty *accessProperty;

	int methodId;
	int fieldId;
	int gpOffset;
	Type* superType;
	bool isDone;;
	int constructorNum;
	vector<Type*> *implementedInterfaces;

	/* Context of this class where inner classes, members defined.*/
	ClassContext *classContext;

	/** Class block. */
	vector<JAST*> *classBlock;

	JClassDeclaration(int, int, char *, AccessProperty *, Type *,
		vector<Type*> *, ClassContext *, vector<JAST*> *);

	JClassDeclaration *hasType(char *, map<string, bool> &);

	JVariableDeclarator *hasVariable(char *);

	JMethodDeclaration *hasMethod(char *);

	virtual void preAnalyze(Context *);

	bool hasSuper(char* );

	virtual void analyze();
	virtual void precodegen();
	virtual void codegen();
	void fillDipatch(int);
	virtual void getparent();
	void init();
};