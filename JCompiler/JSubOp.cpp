#include"JExpression.h"
#include"Context.h"
#include"JSubOp.h"
#include "Utils.h"
JSubOp::JSubOp(int line, int col, JExpression* lhs, JExpression* rhs) 
: JArithmaticBinaryExpression(line, col, lhs, rhs, "-")
{
}

void JSubOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();
	Utils::adeptTypes(this);
	if (this->isFP()){
		Utils::out << "lwc1  $f1,4($sp)" << endl;
		Utils::out << "lwc1  $f2,8($sp)" << endl;
		Utils::out << "sub.s $f1,$f1,$f2" << endl;
		Utils::out << "swc1 $f1,8($sp)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	else if (this->isIntegral()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "sub $t1,$t1,$t2" << endl;
		Utils::out << "sw $t1,8($sp)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
}