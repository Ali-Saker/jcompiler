#include"JAST.h"
#include"typeName.h"
#include"Type.h"
#include"JClassDeclaration.h"
#include"CompilationContext.h"
#include"JCompilationUnit.h"

/*Includes requested for implementation.*/
#include"packageContext.h"
#include"JPackage.h"
#include"ErrorRecovery.h"
#include"Utils.h"
#include"ReferenceType.h"
#include"ClassNameDefn.h"
#include"InterfaceNameDefn.h"

JCompilationUnit::JCompilationUnit(char *fileName, char *path, TypeName *packageName, int mainMethodFrequency,
	vector<Type*>* imports, vector<JAST*> *typeDeclarations, CompilationContext *compilationContext){

	this->fileName = fileName;
	this->path = path;
	this->packageName = packageName;
	this->mainMethodFrequency = mainMethodFrequency;
	this->imports = imports;
	this->typeDeclarations = typeDeclarations;
	this->compilationContext = compilationContext;
	this->preAnalyzed = false;
	this->analyzed = false;
}
    
JClassDeclaration *JCompilationUnit::hasClass(char *name){
 	ClassNameDefn *classDefn = (ClassNameDefn *)this->compilationContext->lookUp(Utils::hashCodeCat(name, 0));

	if (classDefn != 0){
		return classDefn->definingClass;
	}
	else{
		return 0;
	}
}

void JCompilationUnit::preAnalyze(Context* surrounding) {
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;

	this->compilationContext = new CompilationContext(surrounding, this);

	string errMsg;
	int errLine, errCol;

	/* Check package name if it's correct according to physical file's path. */
	if (this->packageName == 0 || strcmp(this->packageName->name, 
		this->compilationContext->packageContext->definigPackage->name) != 0){
	
		errMsg = "The declared package " + Utils::toString(this->packageName == 0 ? "\"\"" : this->packageName->name) +
			" does not match the expected package " + Utils::toString(this->compilationContext->packageContext->definigPackage->name) + ".";
		errLine = this->packageName == 0? 1 : this->packageName->getLine();
		errCol = this->packageName == 0 ? 1 : this->packageName->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}

	/* Pre-analyze the locally declared type(s). */
	for (int i = 0; typeDeclarations != 0 && i < typeDeclarations->size(); i++){
		JAST * typeDecl = typeDeclarations->at(i);
		typeDecl->preAnalyze(compilationContext);

	}
	//	errMsg = "class " + Utils::toString(typeDecl->getThisType()->name) + " should be declared in it's own file."
}


void JCompilationUnit::analyze() {
	if (this->analyzed) return;
	this->analyzed = true;

	string errMsg;
	int errLine, errCol;
	
	/* Check imported types if it's actually exist */
	for (int i = 0; this->imports != 0 && i < this->imports->size(); i++){

		if (!((ReferenceType *)this->imports->at(i))->resolve(this->compilationContext->surroundingContext) &&
			!((ReferenceType *)this->imports->at(i))->resolveAsInterface(this->compilationContext->surroundingContext)){
			errMsg = "The import '" + Utils::toString(this->imports->at(i)->typeName->name) + "' cann't be resolved.";
			errLine = this->imports->at(i)->typeName->getLine();
			errCol = this->imports->at(i)->typeName->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
		else{
			/* if import is resolved, add class/interface to this context. */
			char *hashedImportName;

			if (dynamic_cast<JClassDeclaration *>(((ReferenceType *)this->imports->at(i))->referenceTypeDecl)){

				hashedImportName = Utils::hashCodeCat(this->imports->at(i)->typeName->nameAfterLastPeriod(), 0);
				this->compilationContext->add(Utils::hashKey(hashedImportName, strlen(hashedImportName)),
					new ClassNameDefn((JClassDeclaration *)(((ReferenceType *)this->imports->at(i))->referenceTypeDecl)));
			}
			else{
				hashedImportName = Utils::hashCodeCat(this->imports->at(i)->typeName->nameAfterLastPeriod(), 3);
				this->compilationContext->add(Utils::hashKey(hashedImportName, strlen(hashedImportName)),
					new InterfaceNameDefn((JInterfaceDeclaration *)(((ReferenceType *)this->imports->at(i))->referenceTypeDecl)));
			}
		}
	}

	/* call analyze for each typeDeclaration*/
	for (int i = 0; this->typeDeclarations != 0 && i < this->typeDeclarations->size(); i++) {
		this->typeDeclarations->at(i)->analyze();
	}
}

void JCompilationUnit::precodegen(){
	for (int i = 0; this->typeDeclarations != 0 && i < this->typeDeclarations->size(); i++){
		this->typeDeclarations->at(i)->precodegen();
	}
}

void JCompilationUnit::codegen(){
	for (int i = 0; this->typeDeclarations != 0 && i < this->typeDeclarations->size(); i++){
		this->typeDeclarations->at(i)->codegen();
	}
}

void JCompilationUnit::getparent(){
	for (int i = 0; this->typeDeclarations != 0 && i < this->typeDeclarations->size(); i++){
		this->typeDeclarations->at(i)->getparent();
	}
}