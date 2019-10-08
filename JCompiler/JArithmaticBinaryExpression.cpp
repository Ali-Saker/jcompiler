#include"JExpression.h"
#include"Context.h"
#include"JArithmaticBinaryExpression.h"
/**/
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
JArithmaticBinaryExpression::JArithmaticBinaryExpression(int line, int col, JExpression* lhs, JExpression* rhs, char* op)
: JBinaryExpression(line, col, lhs, rhs, op)
{
}

void JArithmaticBinaryExpression::preAnalyze(Context *surrounding){
	if (this->lhs != 0){
		this->lhs->preAnalyze(surrounding);
	}
	if (this->rhs != 0){
		this->rhs->preAnalyze(surrounding);
	}
}
void JArithmaticBinaryExpression::analyze(){
	string errMsg;
	int errLine, errCol;
	if (this->lhs != 0){
		this->lhs->analyze();
	}

	if (this->rhs != 0){
		this->rhs->analyze();
	}
	if (this->lhs != 0 && this->rhs != 0 && this->lhs->expressionType != 0 && this->rhs->expressionType != 0){
		pair<char *, int> lhsName, rhsName;
		lhsName = this->lhs->expressionType->getName();
		rhsName = this->rhs->expressionType->getName();

		if (lhsName.first != nullptr && rhsName.first != nullptr){
			errLine = this->lhs->getLine();
			errCol = this->lhs->getCol();
			int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhsName.first),
				Utils::toString(rhsName.first), Utils::toString(this->op));
			if (status == 0){
				errMsg = "The operator " + Utils::toString(this->op)  + " is undefined for the argument type(s) " +
					Utils::toString(lhsName.first) + ", " + Utils::toString(rhsName.first);
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
					this->expressionType = Utils::getNewType(this->lhs->expressionType);
				}
			}
		}
	}
}