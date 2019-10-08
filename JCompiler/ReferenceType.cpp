#include"JAST.h"
#include"typeName.h"
#include"Context.h"
#include"ReferenceType.h"

/**/
#include"Utils.h"
#include"ClassNameDefn.h"
#include"JClassDeclaration.h"
#include"packageContext.h"
#include"JPackage.h"
#include"CompilationContext.h"
#include"JCompilationUnit.h"
#include"ClassContext.h"
#include<map>
#include<string>
#include<vector>
#include"PackageNameDefn.h"
#include"ProjectContext.h"
#include"InterfaceNameDefn.h"
#include"JInterfaceDeclaration.h"
ReferenceType::ReferenceType(TypeName *typeName) : Type(typeName){
	this->referenceTypeDecl = 0;
};

pair<char *, int> ReferenceType::getName(){
	if (this->referenceTypeDecl == 0) return make_pair(nullptr, 0);

	if (dynamic_cast<JClassDeclaration *>(this->referenceTypeDecl)){
		return make_pair(((JClassDeclaration*)this->referenceTypeDecl)->fullName, 0);
	}
	else{
		return make_pair(((JInterfaceDeclaration*)this->referenceTypeDecl)->fullName, 0);
	}
}

bool ReferenceType::routedResolve(Context *surrounding){
	/*tokenize names like x.y.z to {x, y, z}. */
	vector<string> routedName = Utils::tokenize(this->typeName->name);
	int n = routedName.size(), i = 0;
	JClassDeclaration *expectedClass = 0;
	JPackage *expectedPackage = 0;
	string compositeName = "";
	while (i < n){
		if (expectedPackage != 0){
			expectedClass = expectedPackage->hasClass(Utils::toCharArray(routedName[i]));
			if (expectedClass != 0){
				break;
			}
		}
		else{
			TypeName *tempTypeName = new TypeName(0, 0, Utils::toCharArray(routedName[0]));
			ReferenceType *tempReferenceType = new ReferenceType(tempTypeName);
			if (tempReferenceType->resolve(surrounding)){
				expectedClass = (JClassDeclaration *)tempReferenceType->referenceTypeDecl;
				break;
			}
		}

		PackageNameDefn *packageDefn = 0;
		while (i < n){
			if (compositeName == ""){
				compositeName = routedName[i];
			}
			else{
				compositeName += "." + routedName[i];
			}
			packageDefn = (PackageNameDefn *)surrounding->projectContext->lookUp(Utils::toCharArray(compositeName));
			if (packageDefn != 0){
				break;
			}
			else{
				i++;
			}
		}
		if (packageDefn == 0){
			return false;
		}
		else{
			expectedPackage = packageDefn->definingPackage;
		}
		i++;
	}
	i++;

	if (expectedClass != 0){
		while (i < n){
			map<string, bool> route;
			expectedClass = expectedClass->hasType(Utils::toCharArray(routedName[i]), route);
			if (expectedClass == 0) return false;
			i++;
		}
	}
	else{
		return false;
	}

	this->referenceTypeDecl = expectedClass;
	return true;
}
bool ReferenceType::resolve(Context *surrounding){
	if (this->referenceTypeDecl != 0) return true;

	/* resolve routed names as: x.y.z in different way by method routedResolve. */
	if (Utils::toString(this->typeName->name).find('.') < Utils::toString(this->typeName->name).length()){
		return routedResolve(surrounding);
	}
	
	JClassDeclaration *expectedClass = 0;

	if (strcmp(surrounding->contextName, "PackageContext") == 0){
		expectedClass = ((PackageContext *)surrounding)->definigPackage->hasClass(this->typeName->name);
		if (expectedClass != 0){
			this->referenceTypeDecl = expectedClass;
			return true;
		}
		else{
			return false;
		}
	}

	if (strcmp(surrounding->contextName, "CompilationContext") == 0){
		expectedClass = ((CompilationContext *)surrounding)->definingCompilationUnit->hasClass(this->typeName->name);
		if (expectedClass != 0){
			this->referenceTypeDecl = expectedClass;
			return true;
		}
		else{
			return this->resolve(surrounding->surroundingContext);
		}
	}

	if (strcmp(surrounding->contextName, "ClassContext") == 0){
		map<string, bool> route;
		expectedClass = ((ClassContext *)surrounding)->definingClass->hasType(this->typeName->name, route);
		if (expectedClass != 0){
			this->referenceTypeDecl = expectedClass;
			return true;
		}
		else{
			return this->resolve(surrounding->surroundingContext);
		}
	}
}


bool ReferenceType::resolveAsRoutedInterface(Context *surrounding){
	vector<string> routedName = Utils::tokenize(this->typeName->name);
	int n = routedName.size(), i = 0;
	PackageNameDefn *packageDefn = 0;
	string compositeName = "";
	while (i < n){
		if (compositeName == ""){
			compositeName = routedName[i];
		}
		else{
			compositeName += "." + routedName[i];
		}
		packageDefn = (PackageNameDefn *)surrounding->projectContext->lookUp(Utils::toCharArray(compositeName));
		if (packageDefn != 0){
			break;
		}
		else{
			i++;
		}
	}

	if (i == n-1 || packageDefn == 0) return false;
	i++;
	JInterfaceDeclaration *expectedInterface = packageDefn->definingPackage->hasInterface(Utils::toCharArray(routedName[i]));
	if (i < n-1 || expectedInterface == 0) return false;
	this->referenceTypeDecl = expectedInterface;
	return true;
}

bool ReferenceType::resolveAsInterface(Context *surrounding){
	if (this->referenceTypeDecl != 0) return true;
	/* resolve routed names as: x.y.z in different way by method resolveAsRoutedInterface. */
	if (Utils::toString(this->typeName->name).find('.') < Utils::toString(this->typeName->name).length()){
		return resolveAsRoutedInterface(surrounding);
	}

	InterfaceNameDefn *interfaceDefn = (InterfaceNameDefn *)surrounding->lookUp(Utils::hashCodeCat(this->typeName->name, 3));
	interfaceDefn = interfaceDefn == 0 ? (InterfaceNameDefn *)surrounding->surroundingContext->
		lookUp(Utils::hashCodeCat(this->typeName->name, 3)) :
		interfaceDefn;

	if (interfaceDefn != 0){
		this->referenceTypeDecl = interfaceDefn->definingInterface;
		return true;
	}
	else{
		return false;
	}
}
