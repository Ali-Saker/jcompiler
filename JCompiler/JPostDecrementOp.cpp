#include"JExpression.h"
#include"Context.h"
#include"JPostDecrementOp.h"
/**/
#include"LHSExpressionInterface.h"
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
JPostDecrementOp::JPostDecrementOp(int line, int col, JExpression* arg) 
: IncrementExpression(line, col, "e--", arg)
{
}
void JPostDecrementOp::codegen(){
	this->arg->codegen();
	Utils::out << "lw $t1,4($sp)" << endl;
	Utils::out << "add $t1,$t1,-1" << endl;
	Utils::out << "sw $t1,0($v0)" << endl;

}