#pragma once

#include<vector>
#include"JAST.h"
using namespace std;


class MethodContext;
class AccessProperty;
class Type;
class JFormalParameter;
class JBlock;

class JMethodDeclaration :public JAST{

public:
	/** Method name. */
	char* name;

	/* method context where statements, local variables defined.*/
	MethodContext *methodContext;

    /** Method access property. */
	AccessProperty *accessProperty;

	bool hasReturnStatement;

	Type *returnType;

	int id;

	int childId;
    /** The formal parameters. */
    vector<JFormalParameter*> *params;

	vector<Type *> *throws;

    /** Method body. */
    JBlock* body;

	string label;

	int variableCount;

	JMethodDeclaration(int, int, char *, MethodContext *, AccessProperty *, Type *,
		vector<JFormalParameter*> *, vector<Type *> *, JBlock*);

	JMethodDeclaration *overridenMethod;

	JMethodDeclaration* getOverridenMethod();

	bool overridChecked;

	virtual void preAnalyze(Context*);

	virtual void analyze();

	virtual void precodegen();
};