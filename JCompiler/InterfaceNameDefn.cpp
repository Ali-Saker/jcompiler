#include"JInterfaceDeclaration.h"
#include"InterfaceNameDefn.h"

InterfaceNameDefn::InterfaceNameDefn(JInterfaceDeclaration* definingInterface) : Defn("InterfaceNameDefn")
{
	this->definingInterface = definingInterface;
}