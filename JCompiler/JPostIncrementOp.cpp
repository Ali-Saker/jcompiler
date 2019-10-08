#include"JExpression.h"
#include"Context.h"
#include"JPostIncrementOp.h"
#include"Utils.h"
JPostIncrementOp::JPostIncrementOp(int line, int col, JExpression* arg) 
: IncrementExpression(line, col, "e++", arg) {
}


void JPostIncrementOp::codegen(){
	this->arg->codegen();
	Utils::out << "lw $t1,4($sp)" << endl;
	Utils::out << "add $t1,$t1,1" << endl;
	Utils::out << "sw $t1,0($v0)" << endl;

}