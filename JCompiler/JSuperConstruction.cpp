#include"Context.h"
#include"JSuperConstruction.h"

JSuperConstruction::JSuperConstruction(int line, int col, vector<JExpression*> *args)
: JExpression(line, col, "JSuperConstruction", 0)
{
	this->args = args;
}
void JSuperConstruction::preAnalyze(Context *surrounding){

}
void JSuperConstruction::analyze(){

}