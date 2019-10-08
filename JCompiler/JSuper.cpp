#include"Context.h"
#include"JSuper.h"
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
JSuper::JSuper(int line, int col)
: JExpression(line, col, "JSuper", 0)
{
}
void JSuper::preAnalyze(Context* surrounding)
{
	this->setContext(surrounding);
}

void JSuper::analyze()
{
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	ClassContext *classContext = surrounding->getClassContext();
	if (classContext != 0){
		if (classContext->definingClass->superType != 0){
			JClassDeclaration *classDeclaration = (JClassDeclaration *)((ReferenceType *)classContext->definingClass->superType)->referenceTypeDecl;
			this->expressionType = new ReferenceType(new TypeName(0, 0, classDeclaration->fullName));
			((ReferenceType *)this->expressionType)->referenceTypeDecl = classDeclaration;

			MethodContext *methodContext = surrounding->getMethodContext();
			if (methodContext != 0 && methodContext->definingMethod->accessProperty->isStatic()){
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "cannot use super in a static context";
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}
		else{
			/* his super type is Object class*/
		}
	}
	
}
void JSuper::codegen(){
	Utils::out << "addi $sp,$sp,-4" << endl;
	Utils::out << "sw $s7,4($sp)" << endl;
	Utils::out << "move $v0,$s7" << endl;
}