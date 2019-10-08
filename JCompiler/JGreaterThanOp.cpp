#include"JExpression.h"
#include"Context.h"
#include"JGreaterThanOp.h"
#include"Utils.h"
JGreaterThanOp::JGreaterThanOp(int line, int col, JExpression *lhs, JExpression *rhs)
: JComparison(line, col, lhs, rhs, ">")
{
}

void JGreaterThanOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();

	//$sp +4 // $sp+8
	if (this->isFP()){
		Utils::out << "lwc1 $f1,4($sp)" << endl;
		Utils::out << "lwc1  $f2,8($sp)" << endl;
		Utils::out << "c.lt.s $f2, $f1" << endl;
		Utils::out << "cfc1   $t3, $25" << endl;
		Utils::out << "sw $t3,8($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;

	}
	else if (this->isIntegral() || this->isString() || this->isRef()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "sgt $t3,$t1,$t2" << endl;
		Utils::out << "sw $t3,8($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;
	}
}