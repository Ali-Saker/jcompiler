#include"JExpression.h"
#include"Context.h"
#include"JAssignment.h"
/**/
#include"LHSExpressionInterface.h"
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
JAssignment::JAssignment(int line, int col, JExpression* lhs, JExpression* rhs, char* op)
: JBinaryExpression(line, col, lhs, rhs, op)
{
}

void JAssignment::preAnalyze(Context *surrounding){
	if (this->lhs != 0){
		this->lhs->preAnalyze(surrounding);
	}
	if (this->rhs != 0){
		this->rhs->preAnalyze(surrounding);
	}
}
void JAssignment::analyze(){
	string errMsg;
	int errLine, errCol;
	bool errAppear = false;

	/*check lhs expression, must be a variable*/
	if (this->lhs != 0){
		this->lhs->analyze();
		if (!dynamic_cast<LHSExpressionInterface*>(this->lhs)){
			errLine = this->lhs->getLine();
			errCol = this->lhs->getCol();
			errMsg = "The left-hand side of an assignment must be a variable";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			errAppear = true;
		}
	}

	if (this->rhs != 0){
		this->rhs->analyze();
	}

	if (!errAppear && this->lhs != 0 && this->rhs != 0 && this->lhs->expressionType != 0 && this->rhs->expressionType != 0){
		pair<char *, int> lhsName, rhsName;
		lhsName = this->lhs->expressionType->getName();
		rhsName = this->rhs->expressionType->getName();

		if (lhsName.first != nullptr && rhsName.first != nullptr){
			errLine = this->lhs->getLine();
			errCol = this->lhs->getCol();
			/*define the two operations*/
			string operation1 = Utils::toString(this->op).substr(0, 1), operation2 = "";
			if (Utils::toString(this->op).length() > 1){
				string operation2 = Utils::toString(this->op).substr(1, 1);
			}
			int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhsName.first),
				Utils::toString(rhsName.first), operation1);
			if (status == 0){
				errMsg = "The operator " + Utils::toString(this->op) + " is undefined for the argument type(s) " +
					Utils::toString(lhsName.first) + ", " + Utils::toString(rhsName.first);
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				errAppear = true;
			}
			if (status == 2){
				errMsg = "Incompatible operand types " + Utils::toString(lhsName.first)
					+ " and " + Utils::toString(rhsName.first);
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				errAppear = true;
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
					errAppear = true;
				}
				else{
					this->expressionType =Utils::getNewType(this->lhs->expressionType);
				}
			}

			/*check for second operation*/
			if (!errAppear && operation2 != ""){
				int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhsName.first),
					Utils::toString(rhsName.first), operation2);
				if (status == 0){
					errMsg = "The operator " + Utils::toString(this->op) + " is undefined for the argument type(s) " +
						Utils::toString(lhsName.first) + ", " + Utils::toString(rhsName.first);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					errAppear = true;
				}
				if (status == 2){
					errMsg = "Incompatible operand types " + Utils::toString(lhsName.first)
						+ " and " + Utils::toString(rhsName.first);
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
					errAppear = true;
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
						errAppear = true;
					}
					else{
						this->expressionType =Utils::getNewType(this->lhs->expressionType);
					}
				}
			}
		}
	}
}

