#include"AccessProperty.h"
#include"Type.h"
#include"InterfaceContext.h"
#include"JInterfaceDeclaration.h"

/*Includes requested by implementation.*/
#include"Utils.h"
#include"InterfaceNameDefn.h"
#include"InterfaceContext.h"
#include"packageContext.h"
#include"JPackage.h"
#include"JFieldDeclaration.h"
#include"JVariableDeclarator.h"
#include"JMethodDeclaration.h"
#include"JConstructorDeclaration.h"
#include"ReferenceType.h"
#include"typeName.h"
#include"JVariableDeclarator.h"
#include"VariableNameDefn.h"
#include"MethodNameDefn.h"
#include"JMethodDeclaration.h"
JInterfaceDeclaration::JInterfaceDeclaration(int line, int col, char *name, AccessProperty *accessProperty,
	vector<Type*> *superTypes, InterfaceContext *interfaceContext, vector<JAST*> *interfaceBlock) :JAST(line, col)
{
	this->name = name;
	this->accessProperty = accessProperty;
	this->superTypes = superTypes;
	this->interfaceContext = interfaceContext;
	this->interfaceBlock = interfaceBlock;
}


JVariableDeclarator *JInterfaceDeclaration::hasVariable(char *){
	VariableNameDefn *varDefn = (VariableNameDefn *)this->interfaceContext->lookUp(Utils::hashCodeCat(name, 1));
	JVariableDeclarator *variableDecl = 0;
	if (varDefn != 0){
		return varDefn->definingVariable;
	}
	else{
		if (this->superTypes != 0){
			for (int i = 0; i < this->superTypes->size(); i++){
				((ReferenceType *)this->superTypes->at(i))->resolveAsInterface(this->interfaceContext->surroundingContext);
				if (((ReferenceType *)this->superTypes->at(i))->referenceTypeDecl != 0){
					variableDecl = ((JInterfaceDeclaration *)((ReferenceType *)this->superTypes->at(i))->referenceTypeDecl)->hasVariable(name);
					if (variableDecl != 0) return variableDecl;
				}
			}
		}
	}

	return 0;

}

JMethodDeclaration *JInterfaceDeclaration::hasMethod(char *name){
	MethodNameDefn *methodDefn = (MethodNameDefn *)this->interfaceContext->lookUp(Utils::hashCodeCat(name, 2));
	JMethodDeclaration *methodDecl = 0;
	if (methodDefn != 0){
		return methodDefn->definingMethod;
	}
	else{
		if (this->superTypes != 0){
			for (int i = 0; i < this->superTypes->size(); i++){
				((ReferenceType *)this->superTypes->at(i))->resolveAsInterface(this->interfaceContext->surroundingContext);
				if (((ReferenceType *)this->superTypes->at(i))->referenceTypeDecl != 0){
					methodDecl = ((JInterfaceDeclaration *)((ReferenceType *)
						this->superTypes->at(i))->referenceTypeDecl)->hasMethod(name);
					if (methodDecl != 0) return methodDecl;
				}
			}
		}
	}

	return 0;
}

void JInterfaceDeclaration::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	string errMsg;
	int errLine, errCol;

	this->interfaceContext = new InterfaceContext(surrounding, this);

	/*add inteface to this compilation unit context. */
	if (surrounding->addInterface(this->name, new InterfaceNameDefn(this)) == 0){
		errMsg = "type '" + Utils::toString(this->name) + "' is already defined.";
		errLine = this->getLine();
		errCol = this->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}

	this->fullName = new char[300];
	strcpy(fullName , surrounding->packageContext->definigPackage->name);
	strcat(this->fullName, ".");
	strcat(this->fullName, this->name);

	if (this->accessProperty != 0){
		this->accessProperty->validAsInterfaceAccessProperty(this->getLine(), this->getCol(), this->name);
	}


	for (int i = 0; this->interfaceBlock !=0 && i < this->interfaceBlock->size(); i++) {
		JAST *member = this->interfaceBlock->at(i);

		member->preAnalyze(this->interfaceContext);

		if (dynamic_cast<JConstructorDeclaration*>(member)) {
			JConstructorDeclaration *constructor = (JConstructorDeclaration *)member;
			errMsg = "Interfaces cannot have constructors.";
			ErrorRecovery::reportSemanticError(constructor->getLine(), constructor->getCol(), Utils::toCharArray(errMsg));
		}
	}
}

void JInterfaceDeclaration::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	for (int i = 0; this->superTypes != 0 && i < this->superTypes->size(); i++){
		ReferenceType *superInterface = (ReferenceType *)this->superTypes->at(i);
		if (!superInterface->resolveAsInterface(this->interfaceContext->surroundingContext)){
			errMsg = "'" + Utils::toString(this->superTypes->at(i)->typeName->name) + "' cann't be resolved to an interface.";
			errLine = this->superTypes->at(i)->typeName->getLine();
			errCol = this->superTypes->at(i)->typeName->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			/* remove not resolved super type.*/
			this->superTypes->erase(this->superTypes->begin() + i);
		}
	}

	for (int i = 0; this->interfaceBlock != 0 && i < this->interfaceBlock->size(); i++) {
		JAST *member = this->interfaceBlock->at(i);
		member->analyze();
	}
}
