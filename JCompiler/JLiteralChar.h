#pragma once
#include"JLiteral.h"
class Context;

class JLiteralChar : public JLiteral{
public:

	JLiteralChar(int, int, char *);

	virtual void preAnalyze(Context *);
	/* check if value member of char group */
	virtual void analyze();
	virtual void codegen();
	
};