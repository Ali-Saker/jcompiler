#include"JExpression.h"
#include"Context.h"
#include"JPlusAssignOp.h"
#include"Utils.h"
JPlusAssignOp::JPlusAssignOp(int line, int col, JExpression* lhs, JExpression* rhs)
: JAssignment(line, col, lhs, rhs, "+=")
{
}
void JPlusAssignOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();
	Utils::adeptTypes(this);
	if (this->isFP()){
		Utils::out << "lwc1 $f1,4($sp)" << endl;
		Utils::out << "lwc1  $f2,8($sp)" << endl;
		Utils::out << "add.s $f1,$f1,$f2" << endl;
		Utils::out << "swc1 $f1,8($sp)" << endl;
		Utils::out << "swc1 $f1,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	else if (this->isIntegral()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "add $t1,$t1,$t2" << endl;
		Utils::out << "sw $t1,8($sp)" << endl;
		Utils::out << "sw $t1,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
	else if (this->isString()){
		Utils::out << "li $s3,4" << endl;
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "lw $t4,0($t1)" << endl;
		Utils::out << "lw $t5,0($t2)" << endl;
		Utils::out << "add $t6,$t4,$t5" << endl;
		Utils::out << "addi $t6,$t6,1" << endl;
		///result ref in $t3
		Utils::out << "move $a0,$t6" << endl;
		Utils::out << "li $t9,4" << endl;
		Utils::out << "mul $a0,$t9,$t6" << endl;
		Utils::out << "li $v0,9" << endl;
		Utils::out << "syscall" << endl;
		Utils::out << "move $t3,$v0" << endl;
		///
		Utils::out << "sw $t6,0($t3)" << endl;
		Utils::out << "li $s1,1" << endl;
		Utils::out << "li $s2,1" << endl;
		Utils::out << "loop" << Utils::LoopCount << " :" << endl;
		Utils::out << "beq $s1,$t4,end" << endl;
		Utils::out << "addi $t1,$t1,4" << endl; //*4
		Utils::out << "addi $t3,$t3,4" << endl; //*4
		Utils::out << "addi $s1,$s1,1" << endl; //*4
		Utils::out << "addi $s2,$s2,1" << endl; //*4
		Utils::out << "lw $t6,0($t1)" << endl;
		Utils::out << "sw $t6,0($t3)" << endl;
		Utils::out << "jal loop" << Utils::LoopCount << endl;
		Utils::out << "end" << Utils::LoopCount++ << " :" << endl;

		Utils::out << "li $s1,1" << endl;
		Utils::out << "loop" << Utils::LoopCount << " :" << endl;
		Utils::out << "beq $s1,$t5,end" << endl;
		Utils::out << "add $t2,$t2,4" << endl; //*4
		Utils::out << "add $t3,$t3,4" << endl; //*4
		Utils::out << "addi $s1,$s1,1" << endl; //*4
		Utils::out << "addi $s2,$s2,1" << endl; //*4
		Utils::out << "lw $t6,0($t2)" << endl;
		Utils::out << "sw $t6,0($t3)" << endl;
		Utils::out << "jal loop" << Utils::LoopCount << endl;
		Utils::out << "end" << Utils::LoopCount++ << " :" << endl;

		Utils::out << "sw $t3,8($sp)" << endl;
		Utils::out << "sw $t3,0($v0)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}

}