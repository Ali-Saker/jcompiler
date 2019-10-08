#include"JExpression.h"
#include"Context.h"
#include"JNotEqualOp.h"

/**/
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"PrimitiveType.h"
JNotEqualOp::JNotEqualOp(int line, int col, JExpression *lhs, JExpression *rhs)
: JBoolBinaryExpression(line, col, lhs, rhs, "!=")
{
}
void JNotEqualOp::preAnalyze(Context *surrounding){
	if (this->lhs != 0){
		this->lhs->preAnalyze(surrounding);
	}
	if (this->rhs != 0){
		this->rhs->preAnalyze(surrounding);
	}
}
void JNotEqualOp::analyze(){
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
				Utils::toString(rhsName.first), "==");
			if (status == 0){
				errMsg = "The operator != is undefined for the argument type(s) " + Utils::toString(lhsName.first)
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
					this->expressionType = PrimitiveType::JBOOLEAN;
				}
			}
		}
	}
}
//virtual JExpression* analyze(Context* surrounding){
//	lhs = (JExpression*)lhs->analyze(surrounding);
//	rhs = (JExpression*)rhs->analyze(surrounding);
//
//	string errMsg;
//
//	if (!lhs->expressionType->matchesExpected(rhs->expressionType, "==")){
//		errMsg = "Incompatible operand types " +
//			Utils::toString(lhs->expressionType->name) + " and " +
//			Utils::toString(rhs->expressionType->name) + ".";
//
//		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//		expressionType = TypeName::ANYTYPE;
//		return this;
//	}
//
//	expressionType = TypeName::BOOLTYPE;
//	return this;
//}

void JNotEqualOp::codegen(){
	this->rhs->codegen();
	this->lhs->codegen();

	//$sp +4 // $sp+8
	if (this->isFP()){
		Utils::out << "lwc1  $f1,4($sp)" << endl;
		Utils::out << "lwc1  $f2,8($sp)" << endl;
		Utils::out << "c.eq.s $f1, $f2" << endl;
		Utils::out << "cfc1   $t3, $25" << endl;
		Utils::out << "xori $t3,$t3,1" << endl;
		Utils::out << "sw $t3,8($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;

	}
	else if (this->isIntegral() || this->isString() || this->isRef()){
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "lw $t2,8($sp)" << endl;
		Utils::out << "snq $t3,$t1,$t2" << endl;
		Utils::out << "sw $t3,8($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;
	}
}