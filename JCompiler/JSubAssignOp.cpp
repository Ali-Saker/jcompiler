#include"JExpression.h"
#include"Context.h"
#include"JSubAssignOp.h"
#include"Utils.h"
JSubAssignOp::JSubAssignOp(int line, int col, JExpression* lhs, JExpression* rhs)
: JAssignment(line, col, lhs, rhs, "-=")
{
}

void JSubAssignOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();
	Utils::adeptTypes(this);
	if (this->isFP()){
		Utils::out << "lwc1 $f1,4($sp)" << endl;
		Utils::out << "lwc1  $f2,8($sp)" << endl;
		Utils::out << "sub.s $f1,$f1,$f2" << endl;
		Utils::out << "swc1 $f1,8($sp)" << endl;
		Utils::out << "swc1 $f1,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	else if (this->isIntegral()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "sub $t1,$t1,$t2" << endl;
		Utils::out << "sw $t1,8($sp)" << endl;
		Utils::out << "sw $t1,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
}