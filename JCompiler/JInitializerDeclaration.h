#pragma once
#include"JAST.h"
class JBlock;
class Context;

class JInitializerDeclaration : public JAST{

public:
	bool is_static_Initializer;
	JBlock* block;

	JInitializerDeclaration(int, int, bool, JBlock *);

	virtual void preAnalyze(Context *);
	virtual void analyze();

};
