#include"Context.h";
#include"typeName.h"
#include"JVariable.h"
#include"JVariableDeclarator.h"
#include"ClassContext.h"
#include"InterfaceContext.h"
#include"JClassDeclaration.h"
#include"JInterfaceDeclaration.h"
#include"Utils.h"
#include"CompilationContext.h"
#include"MethodContext.h"
#include"VariableNameDefn.h"
#include"AccessProperty.h"
JVariable::JVariable(TypeName *typeName, JVariableDeclarator *variableDeclarator) 
: JExpression(typeName->getLine(), typeName->getCol(), "JVariable", 0){
	this->typeName = typeName;
	this->variableDeclarator = 0;
	this->isVarName = 1;
	this->outerNum = -1;
}
void JVariable::resolve(Context *surrounding){

	if (dynamic_cast<CompilationContext *>(surrounding)){
		return;
	}
	if (dynamic_cast<ClassContext *>(surrounding)){
		JClassDeclaration *classDecl = ((ClassContext *)surrounding)->definingClass;
		this->variableDeclarator = classDecl->hasVariable(this->typeName->name);
		this->outerNum++;
		if (this->variableDeclarator != 0) return;
	}
	else if (dynamic_cast<JInterfaceDeclaration *>(surrounding)){
		JInterfaceDeclaration *interfaceDecl = ((InterfaceContext *)surrounding)->definingInterface;
		this->variableDeclarator = interfaceDecl->hasVariable(this->typeName->name);
		if (this->variableDeclarator != 0) return ;
	}
	else{
		VariableNameDefn *varDefn = (VariableNameDefn *)surrounding->lookUp(Utils::hashCodeCat(this->typeName->name, 1));
		if (varDefn != 0){
			this->variableDeclarator = varDefn->definingVariable;
			return;
		}
	}

	this->resolve(surrounding->surroundingContext);
}
void JVariable::preAnalyze(Context *surrounding){
	this->setContext(surrounding);
}
void JVariable::analyze(){
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	this->resolve(surrounding);
	/* variable found*/
	if (this->variableDeclarator != 0){
		this->expressionType = this->variableDeclarator->type;
	}
	else{
		this->expressionType = 0;
		errMsg = "variable " + Utils::toString(this->typeName->name) + " cann't be resolved.";
		errLine = this->getLine();
		errCol = this->getCol();
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
	}

}

void JVariable::codegen(){
	if (!this->variableDeclarator->isField){
		int offset = this->variableDeclarator->id * -4; //offset from fp
		Utils::out << "addiu $v0,$fp," << offset << endl;

	}
	else {
		if (this->variableDeclarator->accessProperty != 0
			&& this->variableDeclarator->accessProperty->isStatic()){
			int offset = this->variableDeclarator->id * 4; //offset from fp
			Utils::out << "addiu $v0,$gp," << offset << endl;
		}
		else{
			//$s7 for this
			///proccess outer 
			int outer_num = this->outerNum;

			if (this->outerNum > 0){
				Utils::out << "move $t1,$s7" << endl;
				while (outer_num--){
					Utils::out << "lw $t1,0($t1)" << endl;
				}
				Utils::out << "move $s7,$t1" << endl;
			}
			int offset = this->variableDeclarator->id * 4; //offset from fp
			Utils::out << "addi $v0,$s7," << offset+16 << endl;
		}
	}
	if (this->isFP()){
		Utils::out << "lwc1 $f1,0($v0)" << endl;
		Utils::out << "swc1 $f1,0($sp)" << endl;
		Utils::out << "addiu $sp,$sp,-4" << endl;
	}
	else{
		Utils::out << "lw $t1,0($v0)" << endl;
		Utils::out << "sw $t1,0($sp)" << endl;
		Utils::out << "addiu $sp,$sp,-4" << endl;
	
	}
}