#include"AccessProperty.h"
#include"Type.h"
#include"ClassContext.h"
#include"JClassDeclaration.h"
/*Includes requested by implementation.*/
#include"Utils.h"
#include"ClassNameDefn.h"
#include"ClassContext.h"
#include"JConstructorDeclaration.h"
#include"packageContext.h"
#include"JPackage.h"
#include"PrimitiveType.h"
#include"ErrorRecovery.h"
#include"ReferenceType.h"
#include"typeName.h"
#include"JVariableDeclarator.h"
#include"JBlock.h"
#include"VariableNameDefn.h"
#include"JInterfaceDeclaration.h"
#include"MethodNameDefn.h"
#include"JMethodDeclaration.h"
#include"ConversionTable.h"
#include"JFieldDeclaration.h"
JClassDeclaration::JClassDeclaration(int line, int col, char *name, AccessProperty *accessProperty, Type *superType,
	vector<Type*> *implementedInterfaces, ClassContext *classContext, vector<JAST*> *classBlock) :JAST(line, col){


	this->name = name;
	this->accessProperty = accessProperty;
	this->superType = superType;
	this->implementedInterfaces = implementedInterfaces;
	this->classContext = classContext;
	this->classBlock = classBlock;
	this->constructorNum = 0;
	this->isDone = false;
}

JClassDeclaration *JClassDeclaration::hasType(char *name, map<string, bool> &route){
	if (route[Utils::toString(this->name)] != 0){
		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(),
			Utils::toCharArray("class " + Utils::toString(this->name) + " extends it's self."));
		return 0;
	}
	else{
		route[Utils::toString(this->name)] = 1;
	}
	ClassNameDefn *classDefn = (ClassNameDefn *)this->classContext->lookUp(Utils::hashCodeCat(name, 0));
	if (classDefn != 0){
		return classDefn->definingClass;
	}
	else{
		if (this->superType == 0){
			return 0;
		}
		if (((ReferenceType *)this->superType)->referenceTypeDecl == 0){

			((ReferenceType *)this->superType)->resolve(this->classContext->surroundingContext);
		}

		if (((ReferenceType *)this->superType)->referenceTypeDecl != 0){
			return ((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->hasType(name, route);
		}
		else{
			return 0;
		}
	}
}

JVariableDeclarator *JClassDeclaration::hasVariable(char *name){
	VariableNameDefn *varDefn = (VariableNameDefn *)this->classContext->lookUp(Utils::hashCodeCat(name, 1));
	JVariableDeclarator *variableDecl = 0;
	if (varDefn != 0){
		return varDefn->definingVariable;
	}
	else{
		if (this->superType != 0){
			((ReferenceType *)this->superType)->resolve(this->classContext->surroundingContext);
			if (((ReferenceType *)this->superType)->referenceTypeDecl != 0){
				variableDecl = ((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->hasVariable(name);
				if (variableDecl != 0) return variableDecl;
			}
		}

		if (this->implementedInterfaces != 0){
			for (int i = 0; i < this->implementedInterfaces->size(); i++){
				((ReferenceType *)this->implementedInterfaces->at(i))->resolveAsInterface(this->classContext->surroundingContext);
				if (((ReferenceType *)this->implementedInterfaces->at(i))->referenceTypeDecl != 0){
					variableDecl = ((JInterfaceDeclaration *)((ReferenceType *)
						this->implementedInterfaces->at(i))->referenceTypeDecl)->hasVariable(name);
					if (variableDecl != 0) return variableDecl;
				}
			}
		}
	}

	return 0;
}


JMethodDeclaration *JClassDeclaration::hasMethod(char *name){
	MethodNameDefn *methodDefn = (MethodNameDefn *)this->classContext->lookUp(Utils::hashCodeCat(name, 2));
	JMethodDeclaration *methodDecl = 0;
	if (methodDefn != 0){
		return methodDefn->definingMethod;
	}
	else{
		if (this->superType != 0){
			((ReferenceType *)this->superType)->resolve(this->classContext->surroundingContext);
			if (((ReferenceType *)this->superType)->referenceTypeDecl != 0){
				methodDecl = ((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->hasMethod(name);
				if (methodDecl != 0) return methodDecl;
			}
		}

		if (this->implementedInterfaces != 0){
			for (int i = 0; i < this->implementedInterfaces->size(); i++){
				((ReferenceType *)this->implementedInterfaces->at(i))->resolveAsInterface(this->classContext->surroundingContext);
				if (((ReferenceType *)this->implementedInterfaces->at(i))->referenceTypeDecl != 0){
					methodDecl = ((JInterfaceDeclaration *)((ReferenceType *)
						this->implementedInterfaces->at(i))->referenceTypeDecl)->hasMethod(name);
					if (methodDecl != 0) return methodDecl;
				}
			}
		}
	}

	return 0;
}

void JClassDeclaration::preAnalyze(Context *surrounding){
	string errMsg;
	int errLine, errCol;
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	this->classContext = new ClassContext(surrounding, this);
	if (surrounding->addType(this->name, new ClassNameDefn(this)) == 0){
		errMsg = "type " + Utils::toString(this->name) + " is already defined.";
		errLine = this->getLine();
		errCol = this->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}
	if (dynamic_cast<ClassContext *>(surrounding)){
		this->fullName = new char[300];
		strcpy(fullName, ((ClassContext *)surrounding)->definingClass->fullName);
		strcat(this->fullName, ".");
		strcat(this->fullName, this->name);
	}
	else{
		this->fullName = new char[300];
		strcpy(fullName, surrounding->packageContext->definigPackage->name);
		strcat(this->fullName, ".");
		strcat(this->fullName, this->name);
	}

	if (this->accessProperty != 0 && !dynamic_cast<ClassContext *>(this->classContext->surroundingContext)){
		this->accessProperty->validAsClassAccessProperty(this->getLine(), this->getCol(), this->name);
	}
	else if (this->accessProperty != 0){
		this->accessProperty->validAsInnerClassAccessProperty(this->getLine(), this->getCol(), this->name);
	}
	bool hasExplicitConstructor = false;


	for (int i = 0; this->classBlock != 0 && i < this->classBlock->size(); i++) {
		JAST *member = this->classBlock->at(i);
		member->preAnalyze(this->classContext);

		if (dynamic_cast<JConstructorDeclaration *>(member)) {
			hasExplicitConstructor = true;
		}
	}

	/* if this class has no constructor create default. */
	if (!hasExplicitConstructor){
		JConstructorDeclaration* defaultConstructor = new JConstructorDeclaration(0, 0, this->name, 0,
			new AccessProperty(), PrimitiveType::JVOID, 0, 0, new JBlock(0, 0, 0, 0) );
		defaultConstructor->accessProperty->setAccessProperty(3);

		if (this->classBlock == 0)
			this->classBlock = new vector<JAST *>;
		this->classBlock->push_back(defaultConstructor);
		defaultConstructor->preAnalyze(this->classContext);
	}
	ConversionTable::getCurrentInstance()->addType(Utils::toString(this->fullName), Utils::toString(this->fullName));
}

void JClassDeclaration::getparent(){
	string errMsg;
	int errLine, errCol;
	if (this->parentChecked) return;
	this->parentChecked = true;
	/*look for super type in context and return it*/
	if (this->superType != 0 && ((ReferenceType *)this->superType)->resolve(this->classContext->surroundingContext) == 0){
		errMsg = "'" + Utils::toString(this->superType->typeName->name) + "' cann't be resolved to a class.";
		errLine = this->superType->typeName->getLine();
		errCol = this->superType->typeName->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		this->superType = 0;
	}
	if (this->superType != 0){
		ConversionTable::getCurrentInstance()->addType(Utils::toString(this->fullName), Utils::toString(this->superType->getName().first));
	}
}

void JClassDeclaration::analyze(){
	string errMsg;
	int errLine, errCol;
	if (this->analyzed) return;
	this->analyzed = true;
	/* look for implemented interfaces in context and return it */
	for (int i = 0; this->implementedInterfaces != 0 && i < this->implementedInterfaces->size(); i++){
		ReferenceType *implementedInterface = (ReferenceType *)this->implementedInterfaces->at(i);
		if (!implementedInterface->resolveAsInterface(this->classContext->surroundingContext)){
			errMsg = "'" + Utils::toString(this->implementedInterfaces->at(i)->typeName->name) + "' cann't be resolved to an interface.";
			errLine = this->implementedInterfaces->at(i)->typeName->getLine();
			errCol = this->implementedInterfaces->at(i)->typeName->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			/*remove not resolved interface. */
			this->implementedInterfaces->erase(this->implementedInterfaces->begin() + i);
		}
	}

	for (int i = 0; this->implementedInterfaces != 0 && i < this->implementedInterfaces->size(); i++){
		ConversionTable::getCurrentInstance()->addType(Utils::toString(this->fullName),
			Utils::toString(this->implementedInterfaces->at(i)->getName().first));
	}
	/* check if super type is final */
	if (this->superType != 0 && ((ReferenceType *)this->superType)->referenceTypeDecl != 0 &&
		((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->accessProperty != 0 &&
		(((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->accessProperty->isFinal())){
		errMsg = "class '" + Utils::toString(this->name) +
			"' cann't inherit the final class '" + Utils::toString(this->superType->typeName->name) + "'.";
		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
	}


	if (this->superType != 0){
		this->methodId = ((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->methodId;
		this->fieldId = ((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->fieldId;
	}
	else{
		this->methodId = this->fieldId = 0;
	}
	
	for (int i = 0; this->classBlock != 0 && i < this->classBlock->size(); i++){
		JAST *member = this->classBlock->at(i);
		if (dynamic_cast<JFieldDeclaration *> (member)){
			((JFieldDeclaration *)member)->id = this->fieldId;
		}
		
		if (dynamic_cast<JMethodDeclaration *> (member) && !dynamic_cast<JConstructorDeclaration*> (member)){
			if (((JMethodDeclaration *)member)->accessProperty != 0 && ((JMethodDeclaration *)member)->accessProperty->isStatic()){
				((JMethodDeclaration *)member)->id = Utils::staticCount++;
			}
			else{

				JMethodDeclaration *methodDecl = ((JMethodDeclaration *)member)->getOverridenMethod();
				if (methodDecl != 0){
					((JMethodDeclaration *)member)->id = methodDecl->id;
				}
				else{
					((JMethodDeclaration *)member)->id = this->methodId++;
				}
			}
		}

		member->analyze();

		if (dynamic_cast<JFieldDeclaration *> (member)){
			this->fieldId = ((JFieldDeclaration *)member)->id;
		}
	}

	this->gpOffset = Utils::GlobalOffset;
	Utils::GlobalOffset += this->methodId;
	return;
}

bool JClassDeclaration::hasSuper(char* name){
	if (strcmp(name, this->fullName) == 0){
		return true;
	}
	else{
		if (this->superType != 0){
			return ((JClassDeclaration *)(((ReferenceType *)(this->superType))->referenceTypeDecl))->hasSuper(name);
		}
		else{
			return false;
		}
	}
}

void JClassDeclaration::precodegen(){
	if (this->isDone){
		return;
	}
	this->isDone = true;

	if (this->superType != 0){
		((ReferenceType *)this->superType)->referenceTypeDecl->precodegen();
	}
	for (int i = 0; this->classBlock != 0 && i < this->classBlock->size(); i++){
		if (dynamic_cast<JMethodDeclaration *> (this->classBlock->at(i)) || dynamic_cast<JClassDeclaration *> (this->classBlock->at(i))){
			this->classBlock->at(i)->precodegen();
		}
	}
	

}

void JClassDeclaration::codegen(){
	//this->gpOffset = Utils::GlobalOffset;
	if (this->superType != 0){
		((JClassDeclaration *)((ReferenceType *)this->superType)->referenceTypeDecl)->fillDipatch(this->gpOffset);
	}
	this->fillDipatch(this->gpOffset);
	for (int i = 0; this->classBlock != 0 && i < this->classBlock->size(); i++){
		if (dynamic_cast<JFieldDeclaration *> (this->classBlock->at(i))
			&& ((JFieldDeclaration *)this->classBlock->at(i))->accessProperty != 0 
			&& ((JFieldDeclaration *)this->classBlock->at(i))->accessProperty->isStatic()){
			this->classBlock->at(i)->codegen();
		}
	}

}

void JClassDeclaration::fillDipatch(int offset){
	for (int i = 0; this->classBlock != 0 && i < this->classBlock->size(); i++){
		if (dynamic_cast<JMethodDeclaration *> (this->classBlock->at(i))
			&& !dynamic_cast<JConstructorDeclaration *> (this->classBlock->at(i))){
			JMethodDeclaration * jmd = (JMethodDeclaration *) this->classBlock->at(i);
			if (jmd->accessProperty == 0 || !jmd->accessProperty->isStatic()){
				Utils::out << "la $t1," << jmd->label << endl;
				Utils::out << "sw $t1," << (offset + (jmd->id)) *-4 << "($gp)" << endl;
		//		Utils::GlobalOffset++;
			}
		}
	}
}


void JClassDeclaration::init(){

	if (this->superType != 0){
		JClassDeclaration *parent = (JClassDeclaration *)((ReferenceType *)(this->superType))->referenceTypeDecl;
		parent->init();
	}
	vector<JAST*>* blockVec = this->classBlock;
	for (int i = 0; blockVec != 0 && i < blockVec->size(); i++){
		if (dynamic_cast<JFieldDeclaration*>(blockVec->at(i)) &&
			(((JFieldDeclaration*)blockVec->at(i))->accessProperty == 0 ||
			(!((JFieldDeclaration*)blockVec->at(i))->accessProperty->isStatic()))){
			blockVec->at(i)->codegen();
		}
	}
}