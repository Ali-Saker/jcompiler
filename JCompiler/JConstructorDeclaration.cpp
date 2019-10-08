#include"MethodContext.h"
#include"AccessProperty.h"
#include"Type.h"
#include"JFormalParameter.h"
#include"JBlock.h"
#include"JConstructorDeclaration.h"

/**/
#include"Utils.h"
#include"MethodNameDefn.h"
#include"JVariableDeclarator.h"
#include"ClassContext.h"
#include"JClassDeclaration.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"ArrayType.h"
#include"typeName.h"
#include"JFieldDeclaration.h"
JConstructorDeclaration::JConstructorDeclaration(int line, int col, char *name, MethodContext *methodContext,
AccessProperty *accessProperty, Type *returnType, vector<JFormalParameter*> *params, vector<Type *> *throws, JBlock *body) :
	JMethodDeclaration(line, col, name, methodContext, accessProperty, PrimitiveType::JVOID, params, throws, body)
{
	 
}

void JConstructorDeclaration::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	this->methodContext = new MethodContext(surrounding, this);
	string errMsg;
	int errLine, errCol;
	char *hashedMethodName = Utils::hashCodeCat(this->name, 2);
	if (surrounding->add(Utils::hashKey(hashedMethodName, strlen(hashedMethodName)), new MethodNameDefn(this)) == 0){
		errMsg = "method '" + Utils::toString(this->name) + "' is already defined.";
		errLine = this->getLine();
		errCol = this->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}

	/*check access property for this method which is located in a class*/
	if (this->methodContext->getInterfaceContext() == 0){
		if (this->accessProperty != 0){
			this->accessProperty->validAsMethodAccessProperty(this->getLine(), this->getCol(), this->name);
		}

		/* Check proper local use of abstract*/
		if (this->body == 0 && (this->accessProperty == 0 && !this->accessProperty->isAbstract())) {
			errMsg = "Method with no body must be abstarct.";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}

		if (this->body != 0 && this->accessProperty != 0 && this->accessProperty->isAbstract()){
			errMsg = "abstract method cannot have a body.";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}

		JClassDeclaration *surroundingClass = surrounding->getClassContext()->definingClass;
		if (this->body == 0 && this->accessProperty != 0 && this->accessProperty->isAbstract() &&
			(surroundingClass->accessProperty == 0 || !surroundingClass->accessProperty->isAbstract())){
			errMsg = "The type '" + Utils::toString(surroundingClass->name) + "' must be an abstract class to define abstract methods";
			errLine = surroundingClass->getLine();
			errCol = surroundingClass->getCol();
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));

			errMsg = "The abstract method '" + Utils::toString(this->name) + "' in type '"
				+ Utils::toString(surroundingClass->name) + "'can only be defined by an abstract class";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}
	}
	/*check default parameters, they must be located at end of parameters list. */
	bool prevParamWasIntializedInMiddle = false;
	bool errorReported = false;
	for (int i = 0; this->params != 0 && i < this->params->size(); i++){
		this->params->at(i)->preAnalyze(this->methodContext);
		if (!errorReported){
			if (!this->params->at(i)->variableDeclarator->initializer != 0 && prevParamWasIntializedInMiddle){
				errMsg = "Default parameters must be initialized at end.";
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				errorReported = true;
			}
			else if (this->params->at(i)->variableDeclarator->initializer != 0){
				prevParamWasIntializedInMiddle = 1;
				errLine = this->params->at(i)->variableDeclarator->getLine();
				errCol = this->params->at(i)->variableDeclarator->getCol();
			}
		}
	}

	for (int i = 0; this->body != 0 && this->body->statements != 0 && i < this->body->statements->size(); i++){
		this->body->statements->at(i)->preAnalyze(this->methodContext);
	}
	JClassDeclaration *classDecl = surrounding->getClassContext()->definingClass;
	this->label = Utils::toString(this->methodContext->getClassContext()->definingClass->fullName) + "." + Utils::toString(this->name);
	this->label = this->label + Utils::toString(classDecl->constructorNum);
	classDecl->constructorNum++;
	this->setContext(surrounding);
}
void JConstructorDeclaration::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	for (int i = 0; params != 0 && i < params->size(); i++){
		params->at(i)->analyze();
	}

	for (int i = 0; this->body != 0 && this->body->statements != 0 && i < this->body->statements->size(); i++){
		this->body->statements->at(i)->analyze();
	}
}




void JConstructorDeclaration::precodegen(){


	Utils::out << this->label << ":" << endl;
	Utils::out << "addi $sp,$sp," << this->childId * -4 << endl;
	JClassDeclaration *classDecl = this->getContext()->getClassContext()->definingClass;
	
	classDecl->init();
	

	
	for (int i = 0; this->body->statements != 0 && i < this->body->statements->size(); i++){
		this->body->statements->at(i)->codegen();
	}

	Utils::out << "end" << this->label << ":" << endl;
	if (dynamic_cast<PrimitiveType *> (this->returnType) && this->returnType == PrimitiveType::JVOID){
		Utils::out << "addi $sp,$sp," << this->childId * 4 << endl;
	}
	
	Utils::out << "jr $ra" << endl;
}