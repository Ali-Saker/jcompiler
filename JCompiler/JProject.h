#pragma once
#include<vector>
using namespace std;
class JPackage;
class ProjectContext;
class Package;

class JProject{
public:
	char *name;
	char *path;
	vector<JPackage *> *packages;
	ProjectContext *projectContext;
	

	JProject(char *, char*, vector<JPackage *> *, ProjectContext *);

	JPackage *hasPackage(char *);
	
	void preAnalyze();

	void analyze();

	void precodegen();
	void codegen();
	void getparent();
};