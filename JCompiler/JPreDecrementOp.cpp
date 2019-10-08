#include"JExpression.h"
#include"Context.h"
#include"JPreDecrementOp.h"
#include"Utils.h"
JPreDecrementOp::JPreDecrementOp(int line, int col, JExpression *arg ) 
: IncrementExpression(line, col, "--e", arg) {
}

void JPreDecrementOp::codegen(){
	this->arg->codegen();
	Utils::out << "lw $t1,4($sp)" << endl;
	Utils::out << "add $t1,$t1,-1" << endl;
	Utils::out << "sw $t1,0($v0)" << endl;
	Utils::out << "sw $t1,4($sp)" << endl;

}