#include"JVariableDeclarator.h"
#include"VariableNameDefn.h"

VariableNameDefn::VariableNameDefn(JVariableDeclarator *definingVariable) : Defn("VariableNameDefn")
{
	this->definingVariable = definingVariable;
}