#pragma once
class JFormalParameter;
class JBlock;
class Context;
/*
 * Class that represent catch part 
 * catch(Type e)
 * {
 *	Statements
 * }
*/

class JCatch{
public:
	int line;
	int col;
	JFormalParameter *param;
	JBlock* catchBlock;

	JCatch(int line, int col, JFormalParameter *, JBlock *);

	virtual void preAnalyze(Context *);

	virtual void analyze();

};