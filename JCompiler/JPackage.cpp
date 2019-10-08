#include"JCompilationUnit.h"
#include"JClassDeclaration.h"
#include"JInterfaceDeclaration.h"
#include"packageContext.h"
#include"JPackage.h"

/**/
#include"ClassNameDefn.h"
#include"InterfaceNameDefn.h"
#include"Utils.h"
JPackage::JPackage(char *name, char *path, int mainMethodFrequency, vector<JCompilationUnit*> *compilationUnits,
	PackageContext *packageContext)
{
	this->name = name;
	this->path = path;
	this->mainMethodFrequency = mainMethodFrequency;
	this->compilationUnits = compilationUnits;
	this->packageContext = packageContext;
	this->analyzed = 0;
	this->preAnalyzed = 0;
}

JClassDeclaration *JPackage::hasClass(char *name){
	ClassNameDefn *classDefn = (ClassNameDefn *)this->packageContext->lookUp(Utils::hashCodeCat(name, 0));
	if (classDefn != 0){
		return classDefn->definingClass;
	}
	else{
		return 0;
	}
}

JInterfaceDeclaration *JPackage::hasInterface(char *name){
	InterfaceNameDefn *interfaceDefn = (InterfaceNameDefn *)this->packageContext->lookUp(Utils::hashCodeCat(name, 3));
	if (interfaceDefn != 0){
		return interfaceDefn->definingInterface;
	}
	else{
		return 0;
	}
}


void JPackage::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;

	this->preAnalyzed = true;
	packageContext = new PackageContext(surrounding, this);

	for (int i = 0; this->compilationUnits != 0 && i < this->compilationUnits->size(); i++){
		this->compilationUnits->at(i)->preAnalyze(this->packageContext);
	}

}

void JPackage::analyze(){
	if (this->analyzed) return;

	this->analyzed = true;
	for (int i = 0; this->compilationUnits != 0 && i < this->compilationUnits->size(); i++){
		this->compilationUnits->at(i)->analyze();
	}

	for (int i = 0; this->compilationUnits != 0 && i < this->compilationUnits->size(); i++){
		this->mainMethodFrequency += this->compilationUnits->at(i)->mainMethodFrequency;
	}
}

void JPackage::precodegen(){
	for (int i = 0; this->compilationUnits != 0 && i < this->compilationUnits->size(); i++){
		this->compilationUnits->at(i)->precodegen();
	}
}
void JPackage::codegen(){
	for (int i = 0; this->compilationUnits != 0 && i < this->compilationUnits->size(); i++){
		this->compilationUnits->at(i)->codegen();
	}
}

void JPackage::getparent(){
	for (int i = 0; this->compilationUnits != 0 && i < this->compilationUnits->size(); i++){
		this->compilationUnits->at(i)->getparent();
	}
}