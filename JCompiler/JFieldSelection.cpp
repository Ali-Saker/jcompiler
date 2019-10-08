#include"Context.h"
#include"JFieldSelection.h"
#include<map>
/**/
#include"Type.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"JAST.h"
#include"ArrayType.h"
#include"JClassDeclaration.h"
#include"JInterfaceDeclaration.h"
#include"JVariableDeclarator.h"
#include"typeName.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"AccessProperty.h"
#include"ClassContext.h"
#include"JVariable.h"
#include"JPackageSelector.h"
#include"JClass.h"
#include"JPackage.h"
#include"JMethodSelection.h"
#include"JNewOp.h"
#include"Utils.h"
JFieldSelection::JFieldSelection(int line, int col, JExpression *target, char *fieldName, TypeName *routedName)
:JExpression(line, col, "JFieldSelection", 0){
	this->target = target;
	this->fieldName = fieldName;
	this->routedName = routedName;
	this->variableDeclaration = 0;
}

void JFieldSelection::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	this->setContext(surrounding);
	if (this->target != 0){
		this->target->preAnalyze(surrounding);
	}
}
void JFieldSelection::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	/*if target is null reclassify routed name*/
	if (target == 0){
		target = this->routedName->reclassifyNameBeforeLastPeriod(surrounding);
	}
	/***************************************************Begining of (target not Null)************************************************/
	if (target != 0){
		target->preAnalyze(surrounding);
		target->analyze();
		/*type exist*/
		if (target->expressionType == 0){
			errLine = this->getLine();
			errCol = this->getCol();
			errMsg = "bad expression prefix.";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
		else{
			/*check target type*/
			if (dynamic_cast<PrimitiveType*>(target->expressionType)){
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "primitive type " + Utils::toString(target->expressionType->typeName->name) + " does not have a field " +
					Utils::toString(this->fieldName);
			}
			else if (dynamic_cast<ArrayType*>(target->expressionType)){
				if (strcmp(this->fieldName, "length") != 0){
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = "array type " + Utils::toString(target->expressionType->getName().first) + " does not have a field " +
						Utils::toString(this->fieldName);
				}
			}
			else{
				bool fieldNameFound = false;

				/*target is name of some class*/
				if (target->isClassName){
					JAST *reference = ((ReferenceType *)(target->expressionType))->referenceTypeDecl;
					if (dynamic_cast<JClassDeclaration *>(reference)){
						JClassDeclaration *classDecl = ((JClassDeclaration *)reference);
						map<string, bool> toBeUsed;
						/*check if accessed field is variable name*/
						if (JVariableDeclarator *var = classDecl->hasVariable(this->fieldName)){
							if (!var->analyzed){
								var->analyze();
							}
							/*must be static*/
							if (var->accessProperty == 0 || !var->accessProperty->isStatic()){
								errLine = this->getLine();
								errCol = this->getCol();
								errMsg = "field " + Utils::toString(this->fieldName) + " not a static field";
								ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
							}
							/*can be private?*/
							if (var->accessProperty != 0){
								if (var->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "field " + Utils::toString(this->fieldName) + " is a private field";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}/*ok, can be protected*/
								else if (var->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "field " + Utils::toString(this->fieldName) + " is a protected field";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = var->type;
							this->isVarName = 1;
							this->variableDeclaration = var;
							fieldNameFound = 1;
						}
						/*check if accessed field is inner type*/
						else if (JClassDeclaration *classDeclaration = classDecl->hasType(this->fieldName, toBeUsed)){
							if (!classDeclaration->analyzed){
								classDeclaration->analyze();
							}
							/*must be static*/
							if (classDeclaration->accessProperty == 0 || !classDeclaration->accessProperty->isStatic()){
								errLine = this->getLine();
								errCol = this->getCol();
								errMsg = "class " + Utils::toString(this->fieldName) + " not a static class";
								ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
							}

							if (classDeclaration->accessProperty != 0){
								if (classDeclaration->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "class " + Utils::toString(this->fieldName) + " is a private class";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
								else if (classDeclaration->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "class " + Utils::toString(this->fieldName) + " is a protected class";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = new ReferenceType(new TypeName(0, 0, classDeclaration->name));
							((ReferenceType*)this->expressionType)->referenceTypeDecl = classDeclaration;
							this->isClassName = 1;
							fieldNameFound = 1;
						}
					}
				}
				/*target is  some variable name*/
				else if (target->isVarName){

					JAST *reference = ((ReferenceType *)target->expressionType)->referenceTypeDecl;
					if (dynamic_cast<JClassDeclaration *>(reference)){
						JClassDeclaration *classDecl = ((JClassDeclaration *)reference);
						map<string, bool> toBeUsed;
						/*check if accessed field is variable name*/
						if (JVariableDeclarator *var = classDecl->hasVariable(this->fieldName)){
							if (!var->analyzed){
								var->analyze();
							}
							if (var->accessProperty != 0){
								if (var->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "field " + Utils::toString(this->fieldName) + " is a private field";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
								else if (var->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "field " + Utils::toString(this->fieldName) + " is a protected field";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = var->type;
							this->isVarName = 1;
							this->variableDeclaration = var;
							fieldNameFound = 1;
						}
						/*check if accessed field is inner type name*/
						else if (JClassDeclaration *classDeclaration = classDecl->hasType(this->fieldName, toBeUsed)){
							if (!classDeclaration->analyzed){
								classDeclaration->analyze();
							}
							if (classDeclaration->accessProperty != 0){
								if (classDeclaration->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "class " + Utils::toString(this->fieldName) + " is a private class";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
								else if (classDeclaration->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "class " + Utils::toString(this->fieldName) + " is a protected class";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = new ReferenceType(new TypeName(0, 0, classDeclaration->name));
							((ReferenceType*)this->expressionType)->referenceTypeDecl = classDeclaration;
							this->isClassName = 1;
							fieldNameFound = 1;
						}
					}

				}
				/*target is some package name*/
				else if (target->isPackageName){
					JPackageSelector *packageSelector = (JPackageSelector *)target;
					JPackage *pacakge = packageSelector->package;
					JClassDeclaration *classDecl;
					/*check if that package has the accessed class*/
					if (classDecl = pacakge->hasClass(this->fieldName)){
						if (!classDecl->analyzed){
							classDecl->analyze();
						}
						this->expressionType = new ReferenceType(new TypeName(0, 0, classDecl->name));
						((ReferenceType*)this->expressionType)->referenceTypeDecl = classDecl;
						this->isClassName = 1;
						fieldNameFound = 1;
					}
				}
				if (!fieldNameFound){
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = "type " + Utils::toString(target->expressionType->typeName->name) + " does not have a field " +
						Utils::toString(this->fieldName);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					this->expressionType = 0;
				}
			}
		}
	}
}
 
void JFieldSelection::codegen(){
  //if this not static
	this->target->codegen();
	if (dynamic_cast<JVariable *>(this->target)){
		JVariable *var = (JVariable *)this->target;
		if (var->isClassName) return;
	}
	else if (dynamic_cast<JFieldSelection *>(this->target)){
		JFieldSelection *field = (JFieldSelection *)this->target;
		if (field->isClassName) return;
	}

	if (this->variableDeclaration->accessProperty == 0 || !this->variableDeclaration->accessProperty->isStatic()){
		Utils::out << "lw $t1,4($sp)" << endl;
		int offset = this->variableDeclaration->id * 4;
		Utils::out << "addi $v0,$t1," << offset + 16<< endl;
		Utils::out << "lw $t1,0($v0)"  << endl;
		Utils::out << "sw $t1,4($sp)" << endl;
	}
	else{
		int offset = this->variableDeclaration->id * 4; //static****
		Utils::out << "addi $v0,$gp," << offset << endl;
		Utils::out << "lw $t1,0($v0)"  << endl;
		Utils::out << "sw $t1,4($sp)" << endl;
	}
  //else get static offset
	//v0 refecence
	//$sp + 4 this reference
}