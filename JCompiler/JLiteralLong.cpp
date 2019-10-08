#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralLong.h"
#include"Utils.h"
JLiteralLong::JLiteralLong(int line, int col, char * value) :JLiteral(line, col, "JLiteralLong",
PrimitiveType::JLONG, value)
{

}

void JLiteralLong::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralLong::analyze(){

}

void JLiteralLong::codegen(){
	Utils::out << "li $t1," << this->value << endl;
	Utils::out << "sw $t1,0($sp)" << endl;
	Utils::out << "addi $sp,$sp,-4" << endl;
}