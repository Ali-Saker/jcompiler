#pragma once
#include "Defn.h"
class JVariableDeclarator;

class VariableNameDefn : public Defn
{
public:
	JVariableDeclarator *definingVariable;
	VariableNameDefn(JVariableDeclarator *);
};

