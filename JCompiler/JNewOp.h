#pragma once
#include "JExpression.h"
class Type;
class JBlock;
class Context;
class TypeName;
class JConstructorDeclaration;
class JNewOp : public JExpression
{
public:

	Type *type;
	vector<JExpression*> *args;

	JBlock* block; /*add new fields to the current instantiated object*/

	TypeName *routedName;
	JExpression *target;
	JConstructorDeclaration *_constructor;

	JNewOp(int, int, Type *, vector<JExpression*> *, JBlock *);

	virtual void preAnalyze(Context*);

	virtual void analyze();
	virtual void codegen();
};


