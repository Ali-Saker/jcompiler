#pragma once
#include"JExpression.h"
class Context;
class TypeName;
class JClassDeclaration;
class JClass : public JExpression{
public:

	TypeName *typeName;
	JClassDeclaration *classDeclaration;
	JClass(TypeName *, JClassDeclaration *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
};