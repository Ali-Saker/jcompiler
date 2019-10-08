#pragma once
using namespace std;
class Type;
class JExpression;
class Context;
class TypeName{
private:
    /* The line and column where type name occurs in the source file */
    int line;
	int col;
public:
	char *name;
	TypeName(int, int, char *);
	int getLine();
	int getCol();
	int numberOfParts();
	char *nameAfterLastPeriod();
	TypeName *nameBeforeLastPeriod();
	JExpression *reclassifyNameBeforeLastPeriod(Context *);
	//bool matchesExpected(TypeName*, char*);
};