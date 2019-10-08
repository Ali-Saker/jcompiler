#pragma once
#include "JUnaryExpressions.h"
class JPositOp :
	public JUnaryExpressions
{
public:

	JPositOp(int line, int col, JExpression* arg) : JUnaryExpressions(line, col, "+", arg){}

	virtual JExpression* analyze(Context* surrounding){
		arg = arg->analyze(surrounding);

		string errMsg;

		if (!arg->expressionType->isNumber()){
			errMsg = "The operator + is undefined for the argument type " +
				Utils::toString(arg->expressionType->name) + ".";

			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}

		expressionType = TypeName::INTYPE;
		return this;
	}

	~JPositOp()
	{
	}
};



