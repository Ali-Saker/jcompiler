#include"MethodContext.h"
#include"AccessProperty.h"
#include"Type.h"
#include"JFormalParameter.h"
#include"JBlock.h"
#include"JMethodDeclaration.h"

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
#include"JVariableDeclaration.h"
#include"CompilationContext.h"
#include"JCompilationUnit.h"
#include"ProjectContext.h"
#include"JProject.h"
JMethodDeclaration::JMethodDeclaration(int line, int col, char *name, MethodContext *methodContext, AccessProperty *accessProperty,
	Type *returnType, vector<JFormalParameter*> *params, vector<Type *> *throws, JBlock* body) : JAST(line, col)
{
	this->name = name;
	this->methodContext = methodContext;
	this->accessProperty = accessProperty;
	this->returnType = returnType;
	this->params = params;
	this->throws = throws;
	this->body = body;
	this->hasReturnStatement = 0;
	this->variableCount = 0;
	this->childId = 0;
	this->overridenMethod = 0;
	this->overridChecked = 0;
}

void JMethodDeclaration::preAnalyze(Context* surrounding){
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
	else{/*check access property for this method which is located in an interface*/
		if (this->accessProperty != 0){
			this->accessProperty->validAsInterfaceMethodAccessProperty(this->getLine(), this->getCol(),
				this->name);
		}
		if (this->accessProperty != 0 && this->accessProperty->isStatic() && this->body == 0){
			errMsg = Utils::toString(this->name) + " static method requires a body.";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}
		if ((this->accessProperty == 0 || !this->accessProperty->isStatic()) && this->body != 0){
			errMsg = "abstract method '" + Utils::toString(this->name) + "' can't has a body.";
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

	if (Utils::itsMain(this)){
		((CompilationContext *)this->methodContext->compilationContext)->definingCompilationUnit->mainMethodFrequency++;
	}
	this->label = Utils::toString(this->methodContext->getClassContext()->definingClass->fullName) + "." + Utils::toString(this->name);
}

void JMethodDeclaration::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	/*check if the returned type can be resolved in this context.*/
	if (!dynamic_cast<PrimitiveType *>(this->returnType)){
		if (dynamic_cast<ReferenceType *>(this->returnType)){
			if (!((ReferenceType *)this->returnType)->resolve(this->methodContext->surroundingContext) &&
				!((ReferenceType *)this->returnType)->resolveAsInterface(this->methodContext->surroundingContext)){

				errMsg = "type '" + Utils::toString(this->returnType->typeName->name) + "' cann't be resolved.";
				errLine = this->returnType->typeName->getLine();
				errCol = this->returnType->typeName->getCol();
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}
		else{
			if (!dynamic_cast<PrimitiveType *>(((ArrayType *)this->returnType)->type)){
				ReferenceType *actualReferenceType = (ReferenceType *)((ArrayType *)this->returnType)->type;
				if (!actualReferenceType->resolve(this->methodContext->surroundingContext) &&
					!actualReferenceType->resolveAsInterface(this->methodContext->surroundingContext)){

					errMsg = "type '" + Utils::toString(actualReferenceType->typeName->name) + "' cann't be resolved.";
					errLine = actualReferenceType->typeName->getLine();
					errCol = actualReferenceType->typeName->getCol();
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
			}
		}
	}

	for (int i = 0; params != 0 && i < params->size(); i++){
		params->at(i)->analyze();
	}

	for (int i = 0; this->body != 0 && this->body->statements != 0 && i < this->body->statements->size(); i++){
		if (dynamic_cast<JVariableDeclaration *> (this->body->statements->at(i))){
			this->variableCount += 1;
		}
		this->body->statements->at(i)->analyze();
	}

	if (!dynamic_cast<PrimitiveType *>(this->returnType) || ((PrimitiveType *)this->returnType) != PrimitiveType::JVOID){
		if (!this->hasReturnStatement){
			errMsg = "This method must return a result of type '" + Utils::toString(this->returnType->typeName->name) + "'.";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}
	}
	return;
}

JMethodDeclaration *JMethodDeclaration::getOverridenMethod(){
	if (this->overridChecked) return this->overridenMethod;
	this->overridChecked = true;
	JClassDeclaration *classDecl = this->methodContext->getClassContext()->definingClass;
	if (classDecl->superType == 0) return 0;
	((ReferenceType *)classDecl->superType)->resolve(this->methodContext->getClassContext());
	classDecl = (JClassDeclaration *)((ReferenceType *)classDecl->superType)->referenceTypeDecl;
	if (classDecl == 0) return 0;

	while (true){
		JMethodDeclaration *method = classDecl->hasMethod(this->name);
		if (method != 0){
			vector<JFormalParameter *> v1;
			vector<JFormalParameter *> v2;
			for (int i = 0; this->params != 0 && i < this->params->size(); i++){
				v1.push_back(this->params->at(i));
			}
			for (int i = 0; method->params != 0 && i < method->params->size(); i++){
				v2.push_back(method->params->at(i));
			}
			if (Utils::compareParams(v1, v2)){
				this->overridenMethod = method;
				return this->overridenMethod;
			}
		}

		if (classDecl->superType == 0) return 0;
		((ReferenceType *)classDecl->superType)->resolve(this->methodContext->getClassContext());
		classDecl = (JClassDeclaration *)((ReferenceType *)classDecl->superType)->referenceTypeDecl;
		if (classDecl == 0) return 0;
	}

	return 0;
}

void JMethodDeclaration::precodegen(){
	if (Utils::itsMain(this)){
		Utils::out << "main :" << endl;
		Utils::out << "move $fp,$sp" << endl;
		Utils::out << "addiu $sp, $sp ," << (this->childId) *-4<< endl;
		this->methodContext->projectContext->definingProject->codegen();
		for (int i = 0; this->body->statements != 0 && i < this->body->statements->size(); i++){
			this->body->statements->at(i)->codegen();
		}
		Utils::out << "li $v0,10" << endl;
		Utils::out << "syscall" << endl;
	}
	else{
		Utils::out << this->label << ":" << endl;
		if (this->childId){
			int params_num = this->params == 0 ? 0 : this->params->size();
			Utils::out << "addiu $sp,$sp," << (this->childId - 1)* -4 << endl;
		}
		for (int i = 0; this->body->statements != 0 && i < this->body->statements->size(); i++){
			this->body->statements->at(i)->codegen();
		}

		Utils::out << "end" << this->label << ":" << endl;
		if (dynamic_cast<PrimitiveType *> (this->returnType) && this->returnType == PrimitiveType::JVOID){
			//	Utils::out << "addiu $sp,$sp," << (this->childId -1) * 4 << endl;
				Utils::out << "move $sp,$fp" << endl;
	
		}
		else{
			Utils::out << "lw $t1,4($sp) " << endl;
			Utils::out << "addi $sp,$sp,4 " << endl;
			if (this->childId){
			///	Utils::out << "addiu $sp,$sp," << (this->childId - 1) * 4 << endl;
				Utils::out << "move $sp,$fp" << endl;
			}
			Utils::out << "addi $sp,$sp,-4 " << endl;
			Utils::out << "sw $t1,4($sp) " << endl;
			
		}
		Utils::out << "jr $ra" << endl;
	}
}