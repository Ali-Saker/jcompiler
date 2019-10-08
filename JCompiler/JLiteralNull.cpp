#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralNull.h"
#include "Utils.h"
JLiteralNull::JLiteralNull(int line, int col, char * value) :JLiteral(line, col, "JLiteralNull",
	PrimitiveType::JNUL, value)
{

}

void JLiteralNull::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralNull::analyze(){

}

void JLiteralNull::codegen(){
	Utils::out << "sw $zero,0($sp)" << endl;
	Utils::out << "addi $sp,$sp,-4" << endl;
}