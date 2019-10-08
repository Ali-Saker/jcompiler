#include"Context.h"
#include"PrimitiveType.h"
#include"JLiteralDouble.h"
#include"Utils.h" 
JLiteralDouble::JLiteralDouble(int line, int col, char * value) :JLiteral(line, col, "JLiteralDouble",
	PrimitiveType::JDOUBLE, value)
{

}

void JLiteralDouble::preAnalyze(Context *){
}
/* check if value member of char group */
void JLiteralDouble::analyze(){

}

void JLiteralDouble::codegen(){
	Utils::out << "li.s $f1," <<  this->value << endl;
	Utils::out << "swc1 $f1,0($sp)" << endl;
	Utils::out << "addi $sp,$sp,-4" << endl;
}