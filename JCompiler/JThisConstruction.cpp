#include"Context.h"
#include"JThisConstruction.h"

JThisConstruction::JThisConstruction(int line, int col, vector<JExpression*> *args)
: JExpression(line, col, "JThisConstruction", 0)
{
	this->args = args;
}
void JThisConstruction::preAnalyze(Context *surrounding){

}
void JThisConstruction::analyze(){

}