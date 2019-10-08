#include"Type.h"
#include"JBlock.h"
#include"Context.h"
#include"JNewOp.h"
/**/
#include"ReferenceType.h"
#include"ClassContext.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"typeName.h"
#include"JConstructorDeclaration.h"
#include"JClassDeclaration.h"
#include<vector>
#include"ConversionTable.h"
#include"JBlock.h"
#include "JFormalParameter.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"JVariable.h"
#include"PrimitiveType.h"
#include"AccessProperty.h"
#include"ArrayType.h"
#include"JClass.h"
using namespace std;
JNewOp::JNewOp(int line, int col, Type *type, vector<JExpression*> *args, JBlock *block)
: JExpression(line, col, "JNewOp", 0)
{
	this->type = type;
	this->args = args;
	this->block = block;
	this->target = 0;
	this->routedName = 0;
}

void JNewOp::preAnalyze(Context* surrounding)
{
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;

	if (this->args != 0){
		for (int i = 0; i < args->size(); i++){
			this->args->at(i)->preAnalyze(surrounding);
		}
	}
	this->setContext(surrounding);
}

void JNewOp::analyze()
{
	if (this->analyzed) return;
	this->analyzed = true;


	string errMsg;
	int errLine, errCol;
	JClassDeclaration *classDeclaration = 0;
	Context *surrounding = this->getContext();

	/*if target and routed name are null*/
	if (target == 0 && routedName == 0){
		if (dynamic_cast<PrimitiveType *>(this->type)){
			errLine = this->getLine();
			errCol = this->getCol();
			errMsg = "can't instantiate object of primitive type " + Utils::toString(this->type->typeName->name) + ".";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			this->expressionType = 0;
		}
		else{
			ReferenceType *referenceType = (ReferenceType *)this->type;
			ReferenceType *referenceTypeWithotLastName = 0;
			bool resolved = referenceType->resolve(surrounding->getClassContext());
			bool resolvedWithoutLastName = false;
			if (referenceType->typeName->numberOfParts() > 0){
				referenceTypeWithotLastName = new ReferenceType(referenceType->typeName->nameBeforeLastPeriod());
				resolvedWithoutLastName = referenceTypeWithotLastName->resolve(surrounding->surroundingContext);
			}
			if (resolved){
				classDeclaration = (JClassDeclaration *)referenceType->referenceTypeDecl;
				if (resolvedWithoutLastName){
					JClassDeclaration *outer = (JClassDeclaration *)referenceTypeWithotLastName->referenceTypeDecl;
					if (classDeclaration->accessProperty == 0 || !classDeclaration->accessProperty->isStatic()){
						errLine = this->getLine();
						errCol = this->getCol();
						errMsg = "No enclosing instance of type " + Utils::toString(outer->name) + " is accessible." +
							+" Must qualify the allocation with an enclosing instance of type " + Utils::toString(outer->name) +
							" (e.g. x.new A() where x is an instance of " + Utils::toString(outer->name) + " ).";
						ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					}
				}

				if (classDeclaration->accessProperty != 0 && classDeclaration->accessProperty->isAbstract()){
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = "can't instatiate abstract type " + Utils::toString(classDeclaration->fullName) + ".";
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
				//error if abstract class
				this->expressionType = referenceType;
				this->isVarName = 1;

				/*check parameters*/
				bool ErrorDetected = true;
				int n = classDeclaration->classBlock == 0 ? 0 : classDeclaration->classBlock->size();
				for (int i = 0; i < n; i++){
					if (dynamic_cast<JConstructorDeclaration *>(classDeclaration->classBlock->at(i))){
						JConstructorDeclaration *constructor = (JConstructorDeclaration *)classDeclaration->classBlock->at(i);
						if (this->args == 0){
							if (constructor->params == 0){
								this->_constructor = constructor;
								ErrorDetected = false;
								break;
							}
						}
						else{
							if (constructor->params != 0){
								if (Utils::compareParameters(*(this->args), *(constructor->params))){
									this->_constructor = constructor;
									ErrorDetected = false;
									break;
								}
							}
						}
					}
				}

				if (ErrorDetected){
					errLine = this->getLine();
					errCol = this->getCol();
					string params = "";
					for (int i = 0; this->args != 0 && i < this->args->size(); i++){
						params += Utils::toString(this->args->at(i)->expressionType == 0 ?
							"undefined" : this->args->at(i)->expressionType->getName().first);
						if (i < (int)this->args->size() - 1){
							params += ", ";
						}
					}
					errMsg = "there is not constructor " + Utils::toString(this->type->typeName->name) +
						" applicable for these arguments(" + params + ")";
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
			}
			else{
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "can't instantiate object of unresolved type " + Utils::toString(this->type->typeName->name) + ".";
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				this->expressionType = 0;
			}
			
		}
		
		return;
	}
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
				errMsg = "primitive type " + Utils::toString(target->expressionType->typeName->name) + " does not have a class " +
					Utils::toString(this->type->typeName->name);
			}
			else if (dynamic_cast<ArrayType*>(target->expressionType)){
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "array type " + Utils::toString(target->expressionType->getName().first) + " does not have a class " +
					Utils::toString(target->expressionType->typeName->name);

			}
			else{
				bool fieldNameFound = false;
				/*target is  some variable name*/
				if (target->isVarName){
					JAST *reference = ((ReferenceType *)target->expressionType)->referenceTypeDecl;
					if (dynamic_cast<JClassDeclaration *>(reference)){
						JClassDeclaration *classDecl = ((JClassDeclaration *)reference);
						/*check if accessed field is method name*/
						map<string, bool> toBeUsed;
						if (classDeclaration = classDecl->hasType(this->type->typeName->name, toBeUsed)){

							classDeclaration->analyze();

							if (classDeclaration->accessProperty != 0){
								if (classDeclaration->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "class " + Utils::toString(classDeclaration->fullName) + " is a private class";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
								else if (classDeclaration->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "class " + Utils::toString(classDeclaration->fullName) + " is a protected class";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
								else if (classDeclaration->accessProperty->isAbstract()){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "can't instatiate abstract type " + Utils::toString(classDeclaration->fullName) + ".";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = new ReferenceType(new TypeName(0, 0, classDeclaration->name));
							((ReferenceType*)this->expressionType)->referenceTypeDecl = classDeclaration;
							this->isVarName = 1;
							fieldNameFound = 1;
						}
					}
				}
				else{
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = Utils::toString(target->expressionType->typeName->name) + " is not a variable name.";
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					this->expressionType = 0;
					return;
				}
	

				if (!fieldNameFound){
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = "type " + Utils::toString(target->expressionType->typeName->name) + " does not have a type " +
						Utils::toString(this->type->typeName->name) + ".";
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					this->expressionType = 0;
				}
				else{
					bool ErrorDetected = true;
					int n = classDeclaration->classBlock == 0 ? 0 : classDeclaration->classBlock->size();
					for (int i = 0; i < n; i++){
						if (dynamic_cast<JConstructorDeclaration *>(classDeclaration->classBlock->at(i))){
							JConstructorDeclaration *constructor = (JConstructorDeclaration *)classDeclaration->classBlock->at(i);
							if (this->args == 0){
								if (constructor->params == 0){
									this->_constructor = constructor;
									ErrorDetected = false;
									break;
								}
							}
							else{
								if (constructor->params != 0){
									if (Utils::compareParameters(*(this->args), *(constructor->params))){
										ErrorDetected = false;
										this->_constructor = constructor;
										break;
									}
								}
							}
						}
					}

					if (ErrorDetected){
						errLine = this->getLine();
						errCol = this->getCol();
						string params = "";
						for (int i = 0; this->args != 0 && i < this->args->size(); i++){
							params += Utils::toString(this->args->at(i)->expressionType == 0 ?
								"undefined" : this->args->at(i)->expressionType->getName().first);
							if (i < (int)this->args->size() - 1){
								params += ", ";
							}
						}
						errMsg = "there is not constructor " + Utils::toString(this->type->typeName->name) +
							" applicable for these arguments(" + params + ")";
						ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					}
				}
			}
		}
	}
}
void JNewOp::codegen(){


	if (this->target != 0){
		this->target->codegen();
		Utils::out << "lw $t1, 4($sp)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	else{
		Utils::out << "move $t1, $s7" << endl;
	}
	JClassDeclaration * jcl = ((JClassDeclaration *)((ReferenceType *) this->expressionType)->referenceTypeDecl);
	int size = jcl->fieldId - 1;
	int jcl_gp = jcl->gpOffset * -4;

	Utils::out << "li $a0," << (size + 5) * 4 << endl;
	Utils::out << "li $v0, 9" << endl;
	Utils::out << "syscall" << endl;
	Utils::out << "move $t2,$v0" << endl;
	//outer
	Utils::out << "sw $t1,0($t2)" << endl;
	//tag
	Utils::out << "sw $zero,4($t2)" << endl;
	//size
	Utils::out << "li $t1," << size << endl;
	Utils::out << "sw $t1,8($t2)" << endl;
	//dispatcher
	Utils::out << "move $t1,$gp" << endl;
	Utils::out << "addi $t1,$t1," << jcl_gp << endl;
	Utils::out << "sw $t1,12($t2)" << endl;
	

	Utils::out << "addi $sp,$sp,-16" << endl;
	Utils::out << "sw $fp,4($sp)" << endl;
	Utils::out << "sw $ra,8($sp)" << endl;
	Utils::out << "sw $s7,12($sp)" << endl;
	Utils::out << "sw $t2,16($sp)" << endl;

	Utils::out << "move $s7,$t2" << endl;
	((ReferenceType*)this->expressionType)->referenceTypeDecl->codegen();
	for (int i = 0; this->args != 0 && i < this->args->size(); i++){
		this->args->at(i)->codegen();
	}
	//add argumants
	Utils::out << "jal " << this->_constructor->label << endl;

	Utils::out << "lw $fp,4($sp)" << endl;
	Utils::out << "lw $ra,8($sp)" << endl;
	Utils::out << "lw $s7,12($sp)" << endl;
	Utils::out << "addi $sp,$sp,12" << endl;



}