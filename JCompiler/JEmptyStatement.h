#pragma once
#include"JStatement.h"
class Context;
class JEmptyStatement : public JStatement{

public:
	JEmptyStatement(int line, int col);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};