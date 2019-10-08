#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralString.h"
#include "Utils.h"
JLiteralString::JLiteralString(int line, int col, char * value) :JLiteral(line, col, "JLiteralString",
	PrimitiveType::JSTRING, value)
{
}

void JLiteralString::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralString::analyze(){

}
void JLiteralString::codegen(){
	int length = strlen(this->value) - 2;
	int amount = (length + 1) * 4;

	Utils::out << "li $a0," << amount << endl;
	Utils::out << "li $v0,9" << endl;
	Utils::out << "syscall" << endl;
	Utils::out << "move $t1,$v0" << endl;
	Utils::out << "addiu $sp,$sp,-4" << endl;
	Utils::out << "sw $t1,4($sp)" << endl;
	//reference in t1
	Utils::out << "li $t2," << length << endl;
	Utils::out << "sw $t2,0($t1)" << endl;
	for (int i = 1; i < strlen(this->value) - 1; i++){
		Utils::out << "li $t2," << (int) this->value[i] << endl;
		Utils::out << "sw $t2," << (i) * 4 << "($t1)" << endl;
	}

}