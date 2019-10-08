#pragma once
#include<vector>
class Context;
using namespace std;

/**
 * The abstract superclass of all nodes in the abstract syntax tree (AST).
 */

class JAST {

private:
	int line;
	int col;
	Context *surrounding;
public:
	JAST(int, int);
    int getLine();
	int getCol();
	bool analyzed;
	bool preAnalyzed;
	bool parentChecked;
	virtual void preAnalyze(Context *){};
	virtual void analyze(){};
	virtual void codegen(){};
	virtual void precodegen(){};
	virtual void getparent(){};
	void setContext(Context *);
	Context *getContext();


};