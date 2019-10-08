#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralInt.h"
#include "Utils.h"
JLiteralInt::JLiteralInt(int line, int col, char * value) :JLiteral(line, col, "JLiteralInt",
PrimitiveType::JINTEGER, value)
{

}

void JLiteralInt::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralInt::analyze(){

}

void JLiteralInt::codegen(){
	Utils::out << "li $t1," << this->value << endl;
	Utils::out << "sw $t1,0($sp)" << endl;
	Utils::out << "addi $sp,$sp,-4" << endl;
}