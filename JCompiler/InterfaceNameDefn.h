#pragma once
#include"Defn.h"
class JInterfaceDeclaration;

class InterfaceNameDefn : public Defn
{
public:
	JInterfaceDeclaration *definingInterface;

	InterfaceNameDefn(JInterfaceDeclaration *);

};

