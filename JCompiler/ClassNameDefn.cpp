#include"JClassDeclaration.h"
#include"ClassNameDefn.h"

ClassNameDefn::ClassNameDefn(JClassDeclaration* definingClass) : Defn("ClassNameDefn")
{
	this->definingClass = definingClass;
}