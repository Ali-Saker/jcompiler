#include"JVariableDeclaration.h"
#include"LocalVariableNameDefn.h"

LocalVariableNameDefn::LocalVariableNameDefn(JVariableDeclaration *definingLocalVariable)
: Defn("LocalVariableNameDefn")
{
	this->definingLocalVariable = definingLocalVariable;
}