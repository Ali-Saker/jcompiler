#pragma once

#include"Defn.h"
class JMethodDeclaration;

class MethodNameDefn : public Defn
{
public:

	JMethodDeclaration *definingMethod;

	MethodNameDefn(JMethodDeclaration *);
};

