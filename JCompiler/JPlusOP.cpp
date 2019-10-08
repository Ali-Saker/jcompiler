#include"JExpression.h"
#include"Context.h"
#include"JPlusOP.h"
#include"Utils.h"
JPlusOP::JPlusOP(int line, int col, JExpression* lhs, JExpression* rhs)
: JArithmaticBinaryExpression(line, col, lhs, rhs, "+")
{
}

/*virtual JExpression* analyze(Context* surrounding){
	lhs = (JExpression*)lhs->analyze(surrounding);
	rhs = (JExpression*)rhs->analyze(surrounding);

	string errMsg;

	if (lhs->expressionType->equals(TypeName::STRINGTYPE)
		|| rhs->expressionType->equals(TypeName::STRINGTYPE)) {
		return (new JStringConcatOp(this->getLine(), this->getCol(), lhs, rhs))->analyze(surrounding);
	}
	else if ((lhs->expressionType->equals("double") && lhs->expressionType->matchesExpected(rhs->expressionType, "+"))
		|| (rhs->expressionType->equals("double") && rhs->expressionType->matchesExpected(lhs->expressionType, "+"))) {
		expressionType = TypeName::DOUBLETYPE;
	}
	else if ((lhs->expressionType->equals("float") && lhs->expressionType->matchesExpected(rhs->expressionType, "+"))
		|| (rhs->expressionType->equals("float") && rhs->expressionType->matchesExpected(lhs->expressionType, "+"))) {
		expressionType = TypeName::FLOATYPE;
	}
	else if ((lhs->expressionType->equals("long") && lhs->expressionType->matchesExpected(rhs->expressionType, "+"))
		|| (rhs->expressionType->equals("long") && rhs->expressionType->matchesExpected(lhs->expressionType, "+"))) {
		expressionType = TypeName::LONGTYPE;
	}
	else if ((lhs->expressionType->equals("int") && lhs->expressionType->matchesExpected(rhs->expressionType, "+"))
		|| (rhs->expressionType->equals("int") && rhs->expressionType->matchesExpected(lhs->expressionType, "+"))) {
		expressionType = TypeName::INTYPE;
	}
	else {
		expressionType = TypeName::ANYTYPE;
		errMsg = "The operator + is undefined for the argument type(s) " +
			Utils::toString(lhs->expressionType->name) + ", " +
			Utils::toString(rhs->expressionType->name) + ".";

		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
	}
	return this;
}*/


void JPlusOP::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();
	Utils::adeptTypes(this);
	if (this->isFP()){
		Utils::out << "lwc1  $f1,4($sp)" << endl;
		Utils::out << "lwc1  $f2,8($sp)" << endl;
		Utils::out << "add.s $f1,$f1,$f2" << endl;
		Utils::out << "swc1 $f1,8($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;
	}
	else if (this->isIntegral()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "add $t1,$t1,$t2" << endl;
		Utils::out << "sw $t1,8($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;
	}
	else if (this->isString()){
		Utils::out << "li $s3,4" << endl;
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "lw $t4,0($t1)" << endl;
		Utils::out << "lw $t5,0($t2)" << endl;
		Utils::out << "add $t6,$t4,$t5" << endl;
		
		///result ref in $t3
		  Utils::out << "move $a0,$t6" << endl;
		  Utils::out << "addi $a0,$a0,1" << endl;
		  Utils::out << "sll $a0,$a0,2" << endl;
		  Utils::out << "li $v0,9" << endl;
		  Utils::out << "syscall" << endl;
		  Utils::out << "move $t3,$v0" << endl;
		  Utils::out << "move $t7,$v0" << endl;

		///
		Utils::out << "sw $t6,0($t3)" << endl;
		Utils::out << "li $s1,0" << endl;
		Utils::out << "li $s2,1" << endl;
		Utils::out << "loop"<< Utils::LoopCount<<" :" << endl;
		
		Utils::out << "addiu $t1,$t1,4" << endl; //*4
		Utils::out << "addiu $t3,$t3,4" << endl; //*4
		Utils::out << "addiu $s1,$s1,1" << endl; //*4
		Utils::out << "lw $t6,0($t1)" << endl; 
		Utils::out << "sw $t6,0($t3)" << endl; 
		Utils::out << "beq $s1,$t4,end" << Utils::LoopCount << endl;
		Utils::out << "j loop" << Utils::LoopCount << endl;
		Utils::out << "end" << Utils::LoopCount++<< " :" << endl;

		Utils::out << "li $s1,0" << endl;
		Utils::out << "loop" << Utils::LoopCount << " :" << endl;
		
		Utils::out << "addiu $t2,$t2,4" << endl; //*4
		Utils::out << "addiu $t3,$t3,4" << endl; //*4
		Utils::out << "addiu $s1,$s1,1" << endl; //*4
		Utils::out << "lw $t6,0($t2)" << endl;
		Utils::out << "sw $t6,0($t3)" << endl;
		Utils::out << "beq $s1,$t5,end" << Utils::LoopCount << endl;
		Utils::out << "j loop" << Utils::LoopCount << endl;
		Utils::out << "end" << Utils::LoopCount++ << " :" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;
		Utils::out << "sw $t7,4($sp)" << endl;
		
	}
}