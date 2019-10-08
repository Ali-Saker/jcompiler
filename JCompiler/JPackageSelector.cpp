#include "typeName.h"
#include "Context.h"
#include"Type.h"
#include "JPackage.h"
#include "JPackageSelector.h"
#include "ProjectContext.h"
#include "PackageNameDefn.h"
#include "Utils.h"

JPackageSelector::JPackageSelector(TypeName * typeName, JPackage * package) 
:JExpression(typeName->getLine(), typeName->getCol(),"JPackageSelector",0)
{
	this->typeName = typeName;
	this->package = package;
	this->isPackageName = 1;
}


JPackageSelector::~JPackageSelector()
{
}

void JPackageSelector::preAnalyze(Context * surrounding){

	if (this->package != 0){
		this->package->preAnalyze(surrounding->projectContext);
	}
	this->setContext(surrounding);
}
void JPackageSelector::analyze(){
	Context * surrounding = this->getContext();

	PackageNameDefn *packageDefn = 0;
	vector<string> names = Utils::tokenize(this->typeName->name);
	string packageName = names[0];
	for (int i = 0; i < names.size(); i++){
		if (i > 0){
			packageName += "." + names[i];
		}
		packageDefn = (PackageNameDefn*)surrounding->projectContext->lookUp(Utils::toCharArray(packageName));
		if (packageDefn != 0){
			this->package = packageDefn->definingPackage;
			break;
		}
	}


	if (this->package != 0){
		this->package->analyze();
		this->expressionType = new Type(0);
	}
}