#include"JExpression.h"
#include"Context.h"
#include"IncrementExpression.h"

/**/
#include"LHSExpressionInterface.h"
#include"ConversionTable.h"
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"PrimitiveType.h"
#include"typeName.h"
IncrementExpression::IncrementExpression(int line, int col, char *op, JExpression* arg)
: JUnaryExpression(line, col, op, arg)
{
}

void IncrementExpression::preAnalyze(Context* surrounding)
{
	if (this->arg != 0){
		this->arg->preAnalyze(surrounding);
	}
}
void IncrementExpression::analyze()
{
	string errMsg;
	int errLine, errCol;
	bool errAppear = false;

	/*check lhs expression, must be a variable*/
	if (this->arg != 0){
		this->arg->analyze();
		if (!dynamic_cast<LHSExpressionInterface*>(this->arg)){
			errLine = this->arg->getLine();
			errCol = this->arg->getCol();
			errMsg = "Invalid argument to operation ++/--";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			this->expressionType = nullptr;
			errAppear = true;
		}
	}
	if (!errAppear && this->arg != 0 && this->arg->expressionType != nullptr){
		if (strcmp(this->arg->expressionType->typeName->name, "int") != 0 &&
			strcmp(this->arg->expressionType->typeName->name, "char") != 0){
			errLine = this->arg->getLine();
			errCol = this->arg->getCol();
			errMsg = "Type mismatch: cannot convert from " + Utils::toString(this->arg->expressionType->typeName->name)
				+ " to int";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}else{
			this->expressionType = this->arg->expressionType;
		}
	}
}