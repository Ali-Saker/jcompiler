#pragma once
#include<vector>
#include"JStatement.h"
using namespace std;

class Context;

class JBlock :public JStatement {

public:
	 /** List of statements forming the block body. */
    vector<JStatement*> *statements;
	Context *blockContext;
	bool hasReturnStatement;
	int id;
	int kind;
	JBlock(int, int, vector<JStatement*> *, Context *);

	virtual void preAnalyze(Context *);

	virtual void analyze();

	virtual void codegen();
};
