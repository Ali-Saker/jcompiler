#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralChar.h"
#include "Utils.h"
JLiteralChar::JLiteralChar(int line, int col, char * value) :JLiteral(line, col, "JLiteralChar",
	PrimitiveType::JCHAR, value)
{

}

void JLiteralChar::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralChar::analyze(){

}
void JLiteralChar::codegen(){
		Utils::out << "li $t1," << (int) this->value[0] << endl;
		Utils::out << "sw $t1,0($sp)" << endl;
		Utils::out << "addi $sp,$sp,-4" << endl;
	}