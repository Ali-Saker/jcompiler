#include"JMethodDeclaration.h"
#include"MethodContext.h"

MethodContext::MethodContext(Context *surrounding, JMethodDeclaration *definingMethod) :
Context("MethodContext", surrounding->projectContext, surrounding->packageContext, surrounding->compilationContext,
surrounding)
{
	this->definingMethod = definingMethod;
}