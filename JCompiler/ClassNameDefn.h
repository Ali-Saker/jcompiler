#pragma once
#include"Defn.h"
class JClassDeclaration;

class ClassNameDefn : public Defn
{
public:
	JClassDeclaration *definingClass;

	ClassNameDefn(JClassDeclaration *);

};

