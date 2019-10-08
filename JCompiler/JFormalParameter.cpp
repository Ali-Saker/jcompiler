#include"AccessProperty.h"
#include"JVariableDeclarator.h"
#include"Type.h"
#include"Context.h"
#include"JFormalParameter.h"

/**/
#include"Utils.h"
#include"LocalVariableNameDefn.h"
#include"JVariableDeclaration.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"ArrayType.h"
#include"VariableNameDefn.h"
#include"typeName.h"
#include"JMethodDeclaration.h"
#include "MethodContext.h"
#include"JExpression.h"
JFormalParameter::JFormalParameter(int line, int col, AccessProperty *accessProperty,
	JVariableDeclarator *variableDeclarator, Type *type) : JAST(line, col)
{
	this->accessProperty = accessProperty;
	this->variableDeclarator = variableDeclarator;
	this->type = type;
}


void JFormalParameter::preAnalyze(Context * surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	string errMsg;
	int errLine, errCol;

	/*give variable declarator it's access property*/
	this->variableDeclarator->accessProperty = this->accessProperty;

	/*give variable declarator it's type*/
	if (this->variableDeclarator->type == 0){
		this->variableDeclarator->type = this->type;
	}
	else{
		if (dynamic_cast<ArrayType *>(this->type)){
			((ArrayType *)this->variableDeclarator->type)->type = ((ArrayType *)this->type)->type;
			((ArrayType *)this->variableDeclarator->type)->dimensions += ((ArrayType *)this->type)->dimensions;
		}
		else{
			((ArrayType *)this->variableDeclarator->type)->type = this->type;
		}

	}

	/*check access property if it's valid*/
	if (this->accessProperty != 0){
		this->accessProperty->validAsLocalVariableAccessProperty(this->variableDeclarator->getLine(),
			this->variableDeclarator->getCol(), this->variableDeclarator->name);
	}
		
	/* add this->variableDeclarator to sorrounding method context */
	char *hashedVariableName = Utils::hashCodeCat(this->variableDeclarator->name, 1);
	if (surrounding->add(Utils::hashKey(hashedVariableName, strlen(hashedVariableName)), new VariableNameDefn(this->variableDeclarator)) == 0){
		errMsg = "parameter '" + Utils::toString(this->variableDeclarator->name) + "' is already defined.";
		errLine = this->variableDeclarator->getLine();
		errCol = this->variableDeclarator->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}

	/*preAnalyze variable declarator*/
	this->variableDeclarator->preAnalyze(surrounding);
	
	this->setContext(surrounding);
}

void JFormalParameter::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;

	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	/*check if the returned type can be resolved in this context.*/
	if (!dynamic_cast<PrimitiveType *>(this->type)){
		if (dynamic_cast<ReferenceType *>(this->type)){
			if (!((ReferenceType *)this->type)->resolve((Context *)surrounding->getClassContext()) &&
				!((ReferenceType *)this->type)->resolveAsInterface((Context *)surrounding->getClassContext())){

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
	this->variableDeclarator->analyze();
}

void JFormalParameter::codegen(){
	if (this->variableDeclarator->initializer != 0){
		this->variableDeclarator->initializer->codegen();
		Utils::out << "lw $t1, 4($sp)" << endl;
		int tempId = this->variableDeclarator->id * -4;
		Utils::out << "addi $t2, $fp, " << tempId << endl;
		Utils::out << "sw $t1 ,0($t2)" << endl;
		Utils::out << "addi $sp, $sp, 4" << endl;
	}
}