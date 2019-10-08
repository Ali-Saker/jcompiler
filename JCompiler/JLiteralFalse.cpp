#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralFalse.h"
#include "Utils.h"
JLiteralFalse::JLiteralFalse(int line, int col, char * value) :JLiteral(line, col, "JLiteralFalse",
PrimitiveType::JBOOLEAN, value)
{

}

void JLiteralFalse::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralFalse::analyze(){

}

void JLiteralFalse::codegen(){
		Utils::out << "sw $zero,0($sp)" << endl;
		Utils::out << "addi $sp,$sp,-4" << endl;
	}
