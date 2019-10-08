#pragma once
#include"Defn.h"
class JVariableDeclaration;

class LocalVariableNameDefn :
	public Defn
{
public:

	JVariableDeclaration *definingLocalVariable;

	LocalVariableNameDefn(JVariableDeclaration *);
};

