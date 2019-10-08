#include"JCompilationUnit.h"
#include"CompilationContext.h"


CompilationContext::CompilationContext(Context *surrounding, JCompilationUnit *definingCompilationUnit) :
Context("CompilationContext", surrounding->projectContext, surrounding->packageContext, 0, surrounding){
	this->compilationContext = this;
	this->definingCompilationUnit = definingCompilationUnit;
}
