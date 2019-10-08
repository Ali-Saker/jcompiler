#pragma once
#include"JStatement.h"

class JIterationStatement: public JStatement{
public:

	JStatement* statement;
	int id;
	JIterationStatement(int, int, char *, JStatement *);
};
