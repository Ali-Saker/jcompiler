#pragma once
#include<vector>
#include"JMethodDeclaration.h"
using namespace std;

class MethodContext;
class AccessProperty;
class Type;
class JFormalParameter;
class JBlock;

class JConstructorDeclaration : public JMethodDeclaration{

public:
    /**
     * Construct an AST node for a constructor declaration given the line
     * number, modifiers, constructor name, formal parameters, and the
     * constructor body.
     */

	JConstructorDeclaration(int, int, char *, MethodContext *, AccessProperty *, Type *,
		vector<JFormalParameter*>*, vector<Type *> *, JBlock*);
    
	virtual void preAnalyze(Context *);

	virtual void analyze();
	virtual void precodegen();
	
};
