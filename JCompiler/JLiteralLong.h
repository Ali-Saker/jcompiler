#pragma once
#include"JLiteral.h"
class Context;

class JLiteralLong : public JLiteral{
public:

	JLiteralLong(int, int, char *);

	virtual void preAnalyze(Context *);
	/* check if value member of char group */
	virtual void analyze();

	virtual void codegen();
};