#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralTrue.h"
#include "Utils.h"
JLiteralTrue::JLiteralTrue(int line, int col, char * value) :JLiteral(line, col, "JLiteralTrue",
	PrimitiveType::JBOOLEAN, value)
{
}

void JLiteralTrue::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralTrue::analyze(){

}
void JLiteralTrue::codegen(){
	Utils::out << "li $t1,1" << endl;
	Utils::out << "sw $t1,0($sp)" << endl;
	Utils::out << "addi $sp,$sp,-4" << endl;
}