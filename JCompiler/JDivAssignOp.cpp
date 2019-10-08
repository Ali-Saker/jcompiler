#include"JExpression.h"
#include"Context.h"
#include"JDivAssignOp.h"
#include"Utils.h"
JDivAssignOp::JDivAssignOp(int line, int col, JExpression* lhs, JExpression* rhs)
: JAssignment(line, col, lhs, rhs, "/=")
{
}

void JDivAssignOp::codegen()
{
	this->rhs->codegen(); // $sp + 4 //only in assignment
	this->lhs->codegen();

	Utils::adeptTypes(this);
	if (this->isFP()){
		Utils::out << "lwc1  $f1,8($sp)" << endl;
		Utils::out << "lwc1  $f2,4($sp)" << endl;
		Utils::out << "div.s $f1,$f1,$f2" << endl;
		Utils::out << "swc1 $f1,8($sp)" << endl;
		Utils::out << "swc1 $f1,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	else if (this->isIntegral()){
		Utils::out << "lw $t1,8($sp)" << endl;
		Utils::out << "lw $t2,4($sp)" << endl;
		Utils::out << "div $t1,$t2" << endl;
		Utils::out << "mflo $t1" << endl;
		Utils::out << "sw $t1,8($sp)" << endl;
		Utils::out << "sw $t1,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}

}