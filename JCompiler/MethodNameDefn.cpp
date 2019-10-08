#include"JMethodDeclaration.h"
#include"MethodNameDefn.h"


MethodNameDefn::MethodNameDefn(JMethodDeclaration *definingMethod) : Defn("MethodNameDefn")
{
	this->definingMethod = definingMethod;
}