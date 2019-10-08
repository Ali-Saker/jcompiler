#pragma once
#include"JExpression.h"
class Type;
class Context;
class CastExpression : public JExpression{
public:
	Type *castType;
	JExpression *arg;

	CastExpression(int, int, Type *, JExpression *);

	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();

};