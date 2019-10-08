#include"Type.h"
#include"AccessProperty.h"
#include"JVariableDeclarator.h"
#include"Context.h"
#include"JFieldDeclaration.h"

/**/
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"ArrayType.h"
#include"typeName.h"
#include"Utils.h"
#include"VariableNameDefn.h"
JFieldDeclaration::JFieldDeclaration(int line, int col, Type *type, AccessProperty *accessProperty,
	vector<JVariableDeclarator*> *decls) : JAST(line, col)
{
	this->type = type;
	this->accessProperty = accessProperty;
	this->decls = decls;
}

void JFieldDeclaration::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	string errMsg;
	int errLine, errCol;
	for (int i = 0; this->decls != 0 && i < this->decls->size(); i++){
		/*give variable declarator it's access property*/
		this->decls->at(i)->accessProperty = this->accessProperty;
		this->decls->at(i)->isField = 1;
		/*give variable declarator it's type*/
		if (this->decls->at(i)->type == 0){
			this->decls->at(i)->type = this->type;
		}
		else{
			if (dynamic_cast<ArrayType *>(this->type)){
				((ArrayType *)this->decls->at(i)->type)->type = ((ArrayType *)this->type)->type;
				((ArrayType *)this->decls->at(i)->type)->dimensions += ((ArrayType *)this->type)->dimensions;
			}
			else{
				((ArrayType *)this->decls->at(i)->type)->type = this->type;
			}
			
		}

		/*check access property if it's valid*/

		/*check access property for this field which is located in a class*/
		if (surrounding->getInterfaceContext() == 0){
			if (this->accessProperty != 0){

				this->accessProperty->validAsFieldAccessProperty(this->decls->at(i)->getLine(),
					this->decls->at(i)->getCol(), this->decls->at(i)->name);

				if (this->accessProperty->isFinal() && this->decls->at(i)->initializer == 0){
					errMsg = "the blank final field '" + Utils::toString(this->decls->at(i)->name) +
						"' may not have been initialized";
					errLine = this->getLine();
					errCol = this->getCol();
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
			}
		}
		else{/*check access property for this field which is located in an interface*/
			if (this->accessProperty != 0){
				this->accessProperty->validAsInterfaceFieldAccessProperty(this->decls->at(i)->getLine(),
					this->decls->at(i)->getCol(), this->decls->at(i)->name);
			}
			if (this->decls->at(i)->initializer == 0){
				errMsg = "the blank final field '" + Utils::toString(this->decls->at(i)->name) +
					"' may not have been initialized";
				errLine = this->getLine();
				errCol = this->getCol();
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}

		/* add field to sorrounding class context */
		char *hashedVariableName = Utils::hashCodeCat(this->decls->at(i)->name, 1);
		if (surrounding->add(Utils::hashKey(hashedVariableName, strlen(hashedVariableName)), new VariableNameDefn(this->decls->at(i))) == 0){
			errMsg = "field '" + Utils::toString(this->decls->at(i)->name) + "' is already defined.";
			errLine = this->decls->at(i)->getLine();
			errCol = this->decls->at(i)->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}

		/*preAnalyze variable declarator*/
		this->decls->at(i)->preAnalyze(surrounding);
	}
	this->setContext(surrounding);
}

void JFieldDeclaration::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	/*check if the returned type can be resolved in this context.*/
	if (!dynamic_cast<PrimitiveType *>(this->type)){
		if (dynamic_cast<ReferenceType *>(this->type)){
			if (!((ReferenceType *)this->type)->resolve(surrounding) &&
				!((ReferenceType *)this->type)->resolveAsInterface(surrounding)){

				errMsg = "type '" + Utils::toString(this->type->typeName->name) + "' cann't be resolved.";
				errLine = this->type->typeName->getLine();
				errCol = this->type->typeName->getCol();
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}
		else{
			if (!dynamic_cast<PrimitiveType *>(((ArrayType *)this->type)->type)){
				ReferenceType *actualReferenceType = (ReferenceType *)((ArrayType *)this->type)->type;
				if (!actualReferenceType->resolve(surrounding) &&
					!actualReferenceType->resolveAsInterface(surrounding)){

					errMsg = "type '" + Utils::toString(actualReferenceType->typeName->name) + "' cann't be resolved.";
					errLine = actualReferenceType->typeName->getLine();
					errCol = actualReferenceType->typeName->getCol();
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
			}
		}
	}
	for (int i = 0; this->decls != 0 && i < this->decls->size(); i++){
		this->decls->at(i)->analyze();
		if (this->accessProperty != 0 && this->accessProperty->isStatic()){
			this->decls->at(i)->id = Utils::staticCount++;
		}
		else{
			this->decls->at(i)->id = this->id++;
		}
	}
}

void JFieldDeclaration::codegen(){
	for (int i = 0; i < this->decls->size(); i++){
		this->decls->at(i)->codegen();
	}
}