#pragma once;
#include<string>
#include<vector>
using namespace std;

class JAST;
class TypeName;
class Type;
class CompilationContext;
class JClassDeclaration;
class Context;


/* Represent the file as tree it's root is JCompilationUnit */
class JCompilationUnit{

public:
	char *fileName;

	char *path;

	TypeName *packageName;

	int mainMethodFrequency;
	bool preAnalyzed;
	bool analyzed;
    /* List of imports. */
    vector<Type*>* imports;

	/** List of type declarations. */
	vector<JAST*> *typeDeclarations;

	/* context where imported types and outer classes defined.*/
	CompilationContext *compilationContext;

	JCompilationUnit(char *, char *, TypeName *, int, vector<Type*> *, vector<JAST*> *, CompilationContext *);
	
	JClassDeclaration *hasClass(char *);

	void preAnalyze(Context *);
	
	void analyze();

	void precodegen();

	void codegen();

	void getparent();
};