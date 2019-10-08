#include"Context.h"
#include"JStatement.h"

JStatement::JStatement(int line, int col, char *statementType) : JAST(line, col){
	this->statementType = statementType;
	this->hasReturn = false;
}
