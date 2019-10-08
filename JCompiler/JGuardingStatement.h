#pragma once

#include<vector>
#include"JStatement.h"
using namespace std;
class JBlock;
class JCatch;
class Context;

class JGuardingStatement : public JStatement{
public:
	JBlock* tryBlock;
	vector<JCatch*>* catches;
	JBlock* finallyBlock;

	JGuardingStatement(int, int, JBlock *,
		vector<JCatch*> *, JBlock *);

	virtual void preAnalyze(Context *);

	virtual void analyze();
};

