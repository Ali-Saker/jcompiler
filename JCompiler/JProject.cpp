#include"JPackage.h"
#include"ProjectContext.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"JProject.h"

/**/
#include"PackageNameDefn.h"

JProject::JProject(char *name, char* path, vector<JPackage *> *packages, ProjectContext *projectContext){
	this->name = name;
	this->path = path;
	this->packages = packages;
	this->projectContext = projectContext;
}

JPackage *JProject::hasPackage(char *name){
	PackageNameDefn *packageDefn = (PackageNameDefn *)this->projectContext->lookUp(name);
	if (packageDefn != 0){
		return packageDefn->definingPackage;
	}
	else{
		return 0;
	}
}

void JProject::preAnalyze(){
	/*Project context initialized by main thread*/

	for (int i = 0; this->packages != 0 && i < this->packages->size(); i++){
		this->packages->at(i)->preAnalyze(this->projectContext);
	}
}

void JProject::analyze(){
	for (int i = 0; this->packages != 0 && i < this->packages->size(); i++){
		this->packages->at(i)->analyze();
	}

	int mainMethodFrequency = 0;
	for (int i = 0; this->packages != 0 && i < this->packages->size(); i++){
		JPackage *package = this->packages->at(i);
		mainMethodFrequency += package->mainMethodFrequency;
	}
	string errMsg;
	if (mainMethodFrequency > 1){
		errMsg = "can't define more than one 'main' thread.";
		ErrorRecovery::reportSemanticError(0, 0, Utils::toCharArray(errMsg));

	}
	else if (mainMethodFrequency == 0){
		errMsg = "no 'main' thread found to run this project.";
		ErrorRecovery::reportSemanticError(0, 0, Utils::toCharArray(errMsg));
	}

}
void JProject::precodegen(){
	for (int i = 0; this->packages != 0 && i < this->packages->size(); i++){
		this->packages->at(i)->precodegen();
	}
}
void JProject::codegen(){
	for (int i = 0; this->packages != 0 && i < this->packages->size(); i++){
		this->packages->at(i)->codegen();
	}
}

void JProject::getparent(){
	for (int i = 0; this->packages != 0 && i < this->packages->size(); i++){
		this->packages->at(i)->getparent();
	}
}