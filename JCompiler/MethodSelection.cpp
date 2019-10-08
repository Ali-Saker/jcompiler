#include"JMethodSelection.h"
#include"Context.h"
#include"typeName.h"
/**/
#include"Type.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include"ArrayType.h"
#include"JClassDeclaration.h"
#include"JInterfaceDeclaration.h"
#include"JVariableDeclarator.h"
#include"JMethodDeclaration.h"
#include"typeName.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"JFormalParameter.h"
#include"ConversionTable.h"
#include"ClassContext.h"
#include"AccessProperty.h"
#include"JPackage.h"
#include"JPackageSelector.h"
#include"Frame.h"
#include"JBlock.h"
#include"CompilationContext.h"
#include"InterfaceContext.h"
#include"MethodNameDefn.h"
#include"JSuper.h"
JMethodSelection::JMethodSelection(int line, int col, vector<JExpression*>* args,
	JExpression* target, char* methodName, TypeName *routedName)
: JExpression(line, col, "JMethodSelection", 0)
{
	this->args = args;
	this->target = target;
	this->methodName = methodName;
	this->routedName = routedName;
	this->outerNum = -1;
}
void JMethodSelection::resolve(Context *surrounding){

	if (dynamic_cast<CompilationContext *>(surrounding)){
		return;
	}
	if (dynamic_cast<ClassContext *>(surrounding)){
		JClassDeclaration *classDecl = ((ClassContext *)surrounding)->definingClass;
		this->methodDeclaration = classDecl->hasMethod(this->methodName);
		this->outerNum++;
		if (this->methodDeclaration != 0) return;
	}
	else if (dynamic_cast<JInterfaceDeclaration *>(surrounding)){
		JInterfaceDeclaration *interfaceDecl = ((InterfaceContext *)surrounding)->definingInterface;
		this->methodDeclaration = interfaceDecl->hasMethod(this->methodName);
		if (this->methodDeclaration != 0) return;
	}
	else{
		MethodNameDefn *methodDefn = (MethodNameDefn *)surrounding->lookUp(Utils::hashCodeCat(this->methodName, 1));
		if (methodDefn != 0){
			this->methodDeclaration = methodDefn->definingMethod;
			return;
		}
	}

	this->resolve(surrounding->surroundingContext);
}

void JMethodSelection::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;

	this->setContext(surrounding);
	for (int i = 0; this->args != 0 && i < this->args->size(); i++){
		this->args->at(i)->preAnalyze(surrounding);
	}
}
void JMethodSelection::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;

	for (int i = 0; this->args != 0 && i < this->args->size(); i++){
		this->args->at(i)->analyze();
	}
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();


	if (target == 0 && routedName == 0){

		this->resolve(this->getContext()->getClassContext());
		if (this->methodDeclaration != 0){
			this->expressionType = this->methodDeclaration->returnType;
			this->isVarName = 1;
		}
		else{
			this->expressionType = 0;
			this->expressionType = 0;
			errMsg = "method " + Utils::toString(this->methodName) + " cann't be resolved.";
			errLine = this->getLine();
			errCol = this->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
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
				errMsg = "primitive type " + Utils::toString(target->expressionType->typeName->name) + " does not have a method " +
					Utils::toString(this->methodName);
			}
			else if (dynamic_cast<ArrayType*>(target->expressionType)){
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "array type " + Utils::toString(target->expressionType->getName().first) + " does not have a method " +
					Utils::toString(this->methodName);

			}
			else{
				bool fieldNameFound = false;
				/*target is name of some class*/
				if (target->isClassName){
					JAST *reference = ((ReferenceType *)(target->expressionType))->referenceTypeDecl;
					if (dynamic_cast<JClassDeclaration *>(reference)){
						JClassDeclaration *classDecl = ((JClassDeclaration *)reference);
						/*check if accessed field is method name*/
						if (methodDeclaration = classDecl->hasMethod(this->methodName)){
							methodDeclaration->analyze();
							/*must be static*/
							if (methodDeclaration->accessProperty == 0 || !methodDeclaration->accessProperty->isStatic()){
								errLine = this->getLine();
								errCol = this->getCol();
								errMsg = "method " + Utils::toString(this->methodName) + " not a static method";
								ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
							}
							/*can be private?*/
							if (methodDeclaration->accessProperty != 0){
								if (methodDeclaration->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "method " + Utils::toString(this->methodName) + " is a private method";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}/*ok, can be protected*/
								else if (methodDeclaration->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "method " + Utils::toString(this->methodName) + " is a protected method";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = methodDeclaration->returnType;
							this->isVarName = 1;
							fieldNameFound = 1;
						}
					}
				}
				/*target is  some variable name*/
				else if (target->isVarName){
					JAST *reference = ((ReferenceType *)target->expressionType)->referenceTypeDecl;
					if (dynamic_cast<JClassDeclaration *>(reference)){
						JClassDeclaration *classDecl = ((JClassDeclaration *)reference);
						/*check if accessed field is method name*/
						if (methodDeclaration = classDecl->hasMethod(this->methodName)){

							methodDeclaration->analyze();

							if (methodDeclaration->accessProperty != 0){
								if (methodDeclaration->accessProperty->isPrivate() && !Utils::canBePrivate(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "method " + Utils::toString(this->methodName) + " is a private method";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
								else if (methodDeclaration->accessProperty->isProtected() && !Utils::canBeProtected(surrounding, classDecl->fullName)){
									errLine = this->getLine();
									errCol = this->getCol();
									errMsg = "method " + Utils::toString(this->methodName) + " is a protected method";
									ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
								}
							}
							this->expressionType = methodDeclaration->returnType;
							this->isVarName = 1;
							fieldNameFound = 1;
						}
					}
				}
				/*target is some package name*/
				else if (target->isPackageName){
					JPackageSelector *packageSelector = (JPackageSelector *)target;
					JPackage *pacakge = packageSelector->package;
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = "can't access method " + Utils::toString(this->methodName) + " directly from package " +
						Utils::toString(pacakge->name);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					this->expressionType = 0;
					fieldNameFound = 1;
					return;
				}

				if (!fieldNameFound){
					errLine = this->getLine();
					errCol = this->getCol();
					errMsg = "type " + Utils::toString(target->expressionType->typeName->name) + " does not have a method " +
						Utils::toString(this->methodName);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					this->expressionType = 0;
				}
				else{
					/* method found, now check parameters*/
					bool ErrorDetected = true;
					if (this->args == 0){
						if (methodDeclaration->params == 0){
							ErrorDetected = false;
						}
					}
					else{
						if (methodDeclaration->params != 0){
							if (Utils::compareParameters(*(this->args), *(methodDeclaration->params))){
								ErrorDetected = false;
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
						errMsg = "method " + Utils::toString(this->methodName) +
							" is not applicable for these arguments(" + params + ")";
						ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					}
				}
			}
		}
	}
}

void JMethodSelection::codegen(){

	if (this->target != 0)
	{
		this->target->codegen();
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	

		//save old values
	Utils::out << "addi $sp,$sp,-12" << endl;
	Utils::out << "sw $fp,4($sp)" << endl;
	Utils::out << "sw $ra,8($sp)" << endl;
	Utils::out << "sw $s7,12($sp)" << endl;
	Utils::out << "move $s5,$sp" << endl;
	//change values
	int outer_num = this->outerNum;

	if (this->target != 0){
		Utils::out << "move $s7,$t1" << endl;
	}
	
	else if(this->outerNum > 0){
		Utils::out << "move $t1,$s7" << endl;
		while (outer_num--){
			Utils::out << "lw $t1,0($t1)" << endl;
		}
		Utils::out << "move $s7,$t1" << endl;
	}


	//int size = this->args == 0 ? 0 : this->args->size();
	//size += this->methodDeclaration->childId - 1;
	for (int i = 0; this->args != 0 && i < this->args->size(); i++){
		this->args->at(i)->codegen();
		
	 //	Utils::out << "addiu $sp,$sp,-4" << endl;
	}


	int start = this->args == 0 ? 0 : this->args->size();
	int params_size = this->methodDeclaration->params == 0 ? 0 : this->methodDeclaration->params->size();
	for (; start < params_size; start++){
		this->methodDeclaration->params->at(start)->codegen();
	}
	Utils::out << "move $fp,$s5" << endl;


	if (this->methodDeclaration->accessProperty == 0
		|| (!this->methodDeclaration->accessProperty->isStatic())){
		if (this->getContext()->getClassContext()->definingClass->superType != 0 &&
			dynamic_cast<JSuper *> (target)){
			Utils::out << "move $t1,$gp" << endl;
			int offset = ((JClassDeclaration *)this->getContext()->getClassContext()->definingClass->superType)->gpOffset;
			Utils::out << "addi $t1,$t1," << offset * -4 << endl;
		}
		else{
			///get label from dispatcher table
			Utils::out << "lw $t1,12($s7)" << endl;
			Utils::out << "lw $t1," << this->methodDeclaration->id * -4 << "($t1)" << endl;

		}
		///
	//	Utils::out << "lw $t1," << this->methodDeclaration->id * -4 << "($t1)" << endl;
	
		Utils::out << "jal $t1" << endl;

	}
	else{
		Utils::out << "jal " << this->methodDeclaration->label<< endl;
	}

	///
	if (dynamic_cast<PrimitiveType *>(this->methodDeclaration->returnType) &&
		                              this->methodDeclaration->returnType == PrimitiveType::JVOID){
		Utils::out << "lw $fp,4($sp)" << endl;
		Utils::out << "lw $ra,8($sp)" << endl;
		Utils::out << "lw $s7,12($sp)" << endl;
		Utils::out << "addi $sp,$sp,12" << endl;
	}
	else{
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $fp,8($sp)" << endl;
		Utils::out << "lw $ra,12($sp)" << endl;
		Utils::out << "lw $s7,16($sp)" << endl;
		Utils::out << "addi $sp,$sp,12" << endl;
		Utils::out << "sw $t1,4($sp)" << endl;
	}
}