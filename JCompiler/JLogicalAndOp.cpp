#include"JExpression.h"
#include"Context.h"
#include"JLogicalAndOp.h"
/**/
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"Utils.h"
JLogicalAndOp::JLogicalAndOp(int line, int col, JExpression *lhs, JExpression *rhs)
: JBoolBinaryExpression(line, col, lhs, rhs, "&&")
{
}
void JLogicalAndOp::preAnalyze(Context *surrounding){
	if (this->lhs != 0){
		this->lhs->preAnalyze(surrounding);
	}
	if (this->rhs != 0){
		this->rhs->preAnalyze(surrounding);
	}
}
void JLogicalAndOp::analyze(){
	string errMsg;
	int errLine, errCol;
	if (this->lhs != 0){
		this->lhs->analyze();
	}

	if (this->rhs != 0){
		this->rhs->analyze();
	}

	if (this->lhs != 0 && this->rhs != 0){
		pair<char *, int> lhsName, rhsName;
		lhsName = this->lhs->expressionType->getName();
		rhsName = this->rhs->expressionType->getName();

		if (lhsName.first != nullptr && rhsName.first != nullptr){
			errLine = this->lhs->getLine();
			errCol = this->lhs->getCol();
			int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhsName.first),
				Utils::toString(rhsName.first), "&&");
			if (status == 0){
				errMsg = "The operator && is undefined for the argument type(s) " + Utils::toString(lhsName.first)
					+ ", " + Utils::toString(rhsName.first);
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
			if (status == 2){
				errMsg = "Incompatible operand types " + Utils::toString(lhsName.first)
					+ " and " + Utils::toString(rhsName.first);
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
			if (status == 1){
				if (lhsName.second != rhsName.second){
					char *_lhs = lhsName.first;
					char *_rhs = rhsName.first;
					int d1 = lhsName.second, d2 = rhsName.second;
					while (d1--)strcat(_lhs, "[]");
					while (d2--)strcat(_rhs, "[]");
					errMsg = "Incompatible operand types " + Utils::toString(_rhs)
						+ " and " + Utils::toString(_lhs);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
				else{
					this->expressionType = this->lhs->expressionType;
				}
			}
		}
	}
}


void JLogicalAndOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();

	Utils::out << "lw $t1,8($sp)" << endl;
	Utils::out << "lw $t2,4($sp)" << endl;
	Utils::out << "and $t3,$t1,$t2" << endl;
	Utils::out << "sw $t3,8($sp)" << endl;
	Utils::out << "addi $sp,$sp,4" << endl;



}