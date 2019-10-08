#include"JExpression.h"
#include"Context.h"
#include"Printer.h"
#include"Utils.h"
Printer::Printer(JExpression *expr):JStatement(0,0,"Printer"){
	this->expr = expr;
}

void Printer::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	this->expr->preAnalyze(surrounding);
	this->setContext(surrounding);
}

void Printer::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	this->expr->analyze();
}

void Printer::codegen(){
	this->expr->codegen();
	
	if (this->expr->isFP()){
		Utils::out << "lwc1  $f12 ,4($sp)" << endl;
		Utils::out << "addi $sp, $sp, 4" << endl;
		Utils::out << "li $v0, 2" << endl;
		Utils::out << "syscall" << endl;
	}
	else if(this->expr->isChar()){
		Utils::out << "lw $a0 ,4($sp)" << endl;
		Utils::out << "addi $sp, $sp, 4" << endl;
		Utils::out << "li $v0, 11" << endl;
		Utils::out << "syscall" << endl;
	}
	else if (this->expr->isRef() || this->expr->isIntegral()){
		Utils::out << "lw $a0 ,4($sp)" << endl;
		Utils::out << "addi $sp, $sp, 4" << endl;
		Utils::out << "li $v0, 1" << endl;
		Utils::out << "syscall" << endl;
	}
	else if (this->expr->isString()){
		Utils::out << "lw $t0 ,4($sp)" << endl;
		Utils::out << "addiu $sp, $sp, 4" << endl;
		Utils::out << "lw $t1,0($t0)" << endl;
		Utils::out << "addiu $t0,$t0,4" << endl;
		Utils::out << "loop" << Utils::LoopCount << ":" << endl;
		Utils::out << "beq $t1,$zero,end" << Utils::LoopCount << endl;

		Utils::out << "lw $a0 ,0($t0)" << endl;
		Utils::out << "li $v0, 11" << endl;
		Utils::out << "syscall" << endl;

		Utils::out << "addiu $t1,$t1,-1" << endl;
		Utils::out << "addiu $t0,$t0,4" << endl;

		Utils::out << "j loop" << Utils::LoopCount  << endl;
		Utils::out << "end" << Utils::LoopCount++ << ":" << endl;

		
	}

}