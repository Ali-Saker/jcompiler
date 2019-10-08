#include"JInterfaceDeclaration.h"
#include"InterfaceContext.h"

InterfaceContext::InterfaceContext(Context *surrounding, JInterfaceDeclaration *definingInterface) :
Context("InterfaceContext", surrounding->projectContext, surrounding->packageContext, surrounding->compilationContext,
	surrounding){
	this->definingInterface = definingInterface;
}