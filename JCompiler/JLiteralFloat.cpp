#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralFloat.h"
#include "Utils.h";
JLiteralFloat::JLiteralFloat(int line, int col, char * value) :JLiteral(line, col, "JLiteralFloat",
PrimitiveType::JFLOAT, value)
{

}

void JLiteralFloat::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralFloat::analyze(){

}

void JLiteralFloat::codegen(){
	string val = Utils::toString(this->value);
	Utils::out << "li.s $f1," << val.substr(0,val.length()-1) << endl;
	Utils::out << "swc1 $f1,0($sp)" << endl;
	Utils::out << "addi $sp,$sp,-4" << endl;
}