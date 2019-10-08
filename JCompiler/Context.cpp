#include"Defn.h"
#include"ProjectContext.h"
#include"packageContext.h"
#include"CompilationContext.h"
#include"ClassContext.h"
#include"InterfaceContext.h"
#include"Context.h"
#include"Utils.h"

/**/
#include"JClassDeclaration.h"
#include"JPackage.h"

Context::Context(char* contextName, ProjectContext *projectContext, PackageContext *packageContext, 
	CompilationContext* compilationContext, Context* surroundingContext){
	this->contextName = contextName;
	this->projectContext = projectContext;
	this->packageContext = packageContext;
	this->compilationContext = compilationContext;
	this->surroundingContext = surroundingContext;
}

ClassContext* Context::getClassContext(){

	return this == 0 ? 0 : strcmp(this->contextName, "ClassContext") == 0? (ClassContext*)this
		: surroundingContext->getClassContext();
}


InterfaceContext* Context::getInterfaceContext(){

	return this == 0 ? 0 : strcmp(this->contextName, "InterfaceContext") == 0 ? (InterfaceContext*)this
		: surroundingContext->getInterfaceContext();
}

MethodContext* Context::getMethodContext(){

	return this == 0 ? 0 : strcmp(this->contextName, "MethodContext") == 0 ? (MethodContext*)this
		: surroundingContext->getMethodContext();
}
/* add defn to this context. */
Defn* Context::add(long long key, Defn *value){
	if (symbolTable[key] != 0){
		return 0;
	}
	else{
		return symbolTable[key] = value;
	}
}
/* add type to this context and
 * if this context is compilation context
 * add type to surrounding context which is package context.
 */
Defn *Context::addType(char *key, Defn *value){

	char *hashedTypeName = Utils::hashCodeCat(key, 0);
	char *hashedInterfaceName = Utils::hashCodeCat(key, 3);
	long long typeKey = Utils::hashKey(hashedTypeName, strlen(hashedTypeName));
	long long interfaceKey = Utils::hashKey(hashedInterfaceName, strlen(hashedInterfaceName));
	

	if (this->symbolTable[typeKey] != 0 || this->symbolTable[interfaceKey] != 0){
		return 0;
	}
	else{
		if (dynamic_cast<CompilationContext *> (this)){
			if (this->surroundingContext->symbolTable[typeKey] != 0 || this->surroundingContext->symbolTable[interfaceKey] != 0){
				return 0;
			}
			else{
				return this->symbolTable[typeKey] = this->surroundingContext->symbolTable[typeKey] = value;
			}
		}
		else{
			return symbolTable[typeKey] = value;
		}
	}
}

Defn *Context::addInterface(char *key, Defn *value){

	char *hashedInterfaceName = Utils::hashCodeCat(key, 3);
	char *hashedTypeName = Utils::hashCodeCat(key, 0);
	long long interfaceKey = Utils::hashKey(hashedInterfaceName, strlen(hashedInterfaceName));
	long long typeKey = Utils::hashKey(hashedTypeName, strlen(hashedTypeName));

	if (this->symbolTable[interfaceKey] != 0 || this->symbolTable[typeKey] != 0){
		return 0;
	}
	else{
		if (this->surroundingContext->symbolTable[interfaceKey] != 0 || this->surroundingContext->symbolTable[typeKey] != 0){
			return 0;
		}
		else{
			return this->symbolTable[interfaceKey] = this->surroundingContext->symbolTable[interfaceKey] = value;
		}
	}
}

/* look up for name in this context. */

Defn *Context::lookUp(char *name){
	long long key = Utils::hashKey(name, strlen(name));
	return this->symbolTable[key];
}