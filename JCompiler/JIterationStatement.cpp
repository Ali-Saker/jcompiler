#include"JIterationStatement.h"

JIterationStatement::JIterationStatement(int line, int col, char* statementType, JStatement* statement)
	: JStatement(line, col, statementType){
	this->statement = statement;
}