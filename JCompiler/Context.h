#pragma once

#include<map>
using namespace std;
class Defn;
class ProjectContext;
class PackageContext;
class CompilationContext;
class InterfaceContext;
class ClassContext;
class MethodContext;
typedef map<long long, Defn* > SymbolTable;

class Context
{
public:
	
	char* contextName;

	ProjectContext *projectContext;

	PackageContext *packageContext;

	CompilationContext* compilationContext;

	Context* surroundingContext;

	SymbolTable symbolTable;

	Context(char *, ProjectContext *, PackageContext *, CompilationContext *, Context *);

	ClassContext *getClassContext();

	InterfaceContext *getInterfaceContext();

	MethodContext *getMethodContext();

	virtual Defn *add(long long, Defn*);

	Defn *addType(char *, Defn *);

	Defn *addInterface(char *, Defn *);

	Defn *lookUp(char *);
};


