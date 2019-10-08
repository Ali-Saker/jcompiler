#include"JExpression.h"
#include"Context.h"
#include"JModOp.h"
#include"Utils.h"
JModOp::JModOp(int line, int col, JExpression* lhs, JExpression* rhs)
: JArithmaticBinaryExpression(line, col, lhs, rhs, "%")
{

}


//virtual JExpression* analyze(Context* surrounding){
//	lhs = (JExpression*)lhs->analyze(surrounding);
//	rhs = (JExpression*)rhs->analyze(surrounding);
//
//	string errMsg;
//
//	if ((lhs->expressionType->equals("double") && lhs->expressionType->matchesExpected(rhs->expressionType, "%"))
//		|| (rhs->expressionType->equals("double") && rhs->expressionType->matchesExpected(lhs->expressionType, "%"))) {
//		expressionType = TypeName::DOUBLETYPE;
//	}
//	else if ((lhs->expressionType->equals("float") && lhs->expressionType->matchesExpected(rhs->expressionType, "%"))
//		|| (rhs->expressionType->equals("float") && rhs->expressionType->matchesExpected(lhs->expressionType, "%"))) {
//		expressionType = TypeName::FLOATYPE;
//	}
//	else if ((lhs->expressionType->equals("long") && lhs->expressionType->matchesExpected(rhs->expressionType, "%"))
//		|| (rhs->expressionType->equals("long") && rhs->expressionType->matchesExpected(lhs->expressionType, "%"))) {
//		expressionType = TypeName::LONGTYPE;
//	}
//	else if ((lhs->expressionType->equals("int") && lhs->expressionType->matchesExpected(rhs->expressionType, "%"))
//		|| (rhs->expressionType->equals("int") && rhs->expressionType->matchesExpected(lhs->expressionType, "%"))) {
//		expressionType = TypeName::INTYPE;
//	}
//	else {
//		expressionType = TypeName::ANYTYPE;
//		errMsg = "The operator % is undefined for the argument type(s) " +
//			Utils::toString(lhs->expressionType->name) + ", " +
//			Utils::toString(rhs->expressionType->name) + ".";
//
//		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//	}
//	return this;
//}


void JModOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();
	Utils::adeptTypes(this);
	
 if (this->isIntegral()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "div $t1,$t2" << endl;
		Utils::out << "mfhi $t1" << endl;
		Utils::out << "sw $t1,8($sp)" << endl;
		Utils::out << "addi $sp,$sp,4" << endl;
	}
}