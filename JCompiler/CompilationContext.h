#pragma once
#include"Context.h"
class JCompilationUnit;
class CompilationContext : public Context
{
public:
	JCompilationUnit *definingCompilationUnit;
	CompilationContext(Context *, JCompilationUnit *);
};


