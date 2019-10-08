#pragma once
#include"JLiteral.h"
class Context;

class JLiteralFalse : public JLiteral{
public:

	JLiteralFalse(int, int, char *);

	virtual void preAnalyze(Context *);
	/* check if value member of char group */
	virtual void analyze();

	virtual void codegen();

};