#include"JExpression.h"
#include"JSelectionStatement.h"

JSelectionStatement::JSelectionStatement(int line, int col, char* statementType, JExpression *condition)
	: JStatement(line, col, statementType) 
{
	this->condition = condition;
}