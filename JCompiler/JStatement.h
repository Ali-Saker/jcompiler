#pragma once
#include"JAST.h"
class Context;
/* Parent of all statements (Expressions included) */
class JStatement :public JAST {
	
    /**
     * Construct an AST node for a statement given its line, col number and the statement's type.
     * .
     */
public:
	char* statementType;

	JStatement(int, int, char*);
	bool hasReturn;
};
