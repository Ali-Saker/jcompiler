#include"JClassDeclaration.h"
#include"Defn.h"
#include"ClassContext.h"

ClassContext::ClassContext(Context *surrounding, JClassDeclaration *definingClass)
: Context("ClassContext", surrounding->projectContext, surrounding->packageContext,
surrounding->compilationContext, surrounding)
{
	this->definingClass = definingClass;
}