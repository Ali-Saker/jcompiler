#include"Context.h"
#include"JThis.h"

/**/
#include"ClassContext.h"
#include"Type.h"
#include"ReferenceType.h"
#include"JClassDeclaration.h"
#include"typeName.h"
#include"JMethodDeclaration.h"
#include"MethodContext.h"
#include"AccessProperty.h"
#include"ErrorRecovery.h"
#include"Utils.h"
JThis::JThis(int line, int col)
:JExpression(line, col, "JThis", 0)
{
}

void JThis::preAnalyze(Context* surrounding)
{
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	this->setContext(surrounding);
}

void JThis::analyze()
{
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	ClassContext *classContext = surrounding->getClassContext();
	if (classContext != 0){
		this->expressionType = new ReferenceType(new TypeName(0, 0, classContext->definingClass->fullName));
		((ReferenceType *)this->expressionType)->referenceTypeDecl = classContext->definingClass;
		this->isVarName = 1;
		MethodContext *methodContext = surrounding->getMethodContext();
		if (methodContext != 0 && methodContext->definingMethod->accessProperty != 0
			&& methodContext->definingMethod->accessProperty->isStatic()){
			errLine = this->getLine();
			errCol = this->getCol();
			errMsg = "cannot use this in a static context";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
	}
	
}
void JThis::codegen(){
	Utils::out << "addi $sp,$sp,-4" << endl;
	Utils::out << "sw $s7,4($sp)" << endl;
	Utils::out << "move $v0,$s7" << endl;
}