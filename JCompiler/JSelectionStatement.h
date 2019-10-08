#pragma once
#include"JStatement.h"
class JExpression;

class JSelectionStatement : public JStatement{

public:
	/** Test expression. */
	JExpression *condition;

	JSelectionStatement(int line, int col, char* statementType, JExpression *condition);
};