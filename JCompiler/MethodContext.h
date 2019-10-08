#pragma once
#include"Context.h"
class JMethodDeclaration;

class MethodContext :
	public Context
{
public:
	JMethodDeclaration *definingMethod;
	MethodContext(Context *, JMethodDeclaration *);
};
