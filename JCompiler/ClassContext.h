#pragma once
#include"Context.h"
class JClassDeclaration;
class Defn;

class ClassContext : public Context
{
public:
	JClassDeclaration *definingClass;

	ClassContext(Context *, JClassDeclaration *);

	Defn *addInnerType(long long, Defn*);
};