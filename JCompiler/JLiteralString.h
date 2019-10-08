#pragma once
#include"JLiteral.h"
class Context;

class JLiteralString : public JLiteral{
public:

	JLiteralString(int, int, char *);

	virtual void preAnalyze(Context *);
	/* check if value member of char group */
	virtual void analyze();
	virtual void codegen();
	
};