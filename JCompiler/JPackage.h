#pragma once

#include<vector>
using namespace std;

class JCompilationUnit;
class PackageContext;
class JClassDeclaration;
class JInterfaceDeclaration;
class Context;

class JPackage
{
public:

	char *name;
	char *path;
	int mainMethodFrequency;
	bool analyzed;
	bool preAnalyzed;
	vector<JCompilationUnit*> *compilationUnits;
	PackageContext *packageContext;

	JPackage(char *, char *, int, vector<JCompilationUnit*> *, PackageContext *);

	JClassDeclaration *hasClass(char *);
	JInterfaceDeclaration *hasInterface(char *);
	void preAnalyze(Context *);

	void analyze();
	void precodegen();
	void codegen();
	void getparent();
};

