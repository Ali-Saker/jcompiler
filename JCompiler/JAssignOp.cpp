#include"JExpression.h"
#include"Context.h"
#include"JAssignOp.h"
#include "Utils.h"
#include "JVariable.h"
#include "JVariableDeclarator.h"
#include "AccessProperty.h"
#include "JFieldSelection.h"
JAssignOp::JAssignOp(int line, int col, JExpression* lhs, JExpression* rhs)
: JAssignment(line, col, lhs, rhs, "=")
{
}

void JAssignOp::codegen(){
	//offset , type lhs
	this->rhs->codegen(); // $sp + 4 //only in assignment
	this->lhs->codegen();

	//$v0 = refence to lhs
	Utils::out << "addi $sp,$sp,4" << endl;
	Utils::out << "lw $t1,4($sp) " << endl;
	Utils::out << "sw $t1,0($v0)" << endl;
	

}