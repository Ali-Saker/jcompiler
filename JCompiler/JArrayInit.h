//#pragma once
//#include "JExpression.h"
//#include "typeName.h"
//#include<vector>
//class JArrayInit :
//	public JExpression
//{
//public:
//	vector<JExpression*>* initials;
//	JArrayInit(int line, int col, TypeName* typeExpected, vector<JExpression*>* initials)
//		: JExpression(line, col, typeExpected)
//	{
//		this->initials = initials;
//		this->isStatementExpression = true;
//	}
//
//	virtual JExpression* analyze(Context* surrounding){
//
//		string errMsg;
//
//		if (expressionType == 0) return this;
//
//		if ( !this->expressionType->isArrayType ) {
//			errMsg = "Type mismatch: cannot convert from " +
//				Utils::toString(this->expressionType->name) + "[] to " +
//				Utils::toString(this->expressionType->name)+  ".";
//
//			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
//			return this; // un-analyzed
//		}
//		// analyze every expression in initializer
//		TypeName* arrayType = expressionType;
//		for (int i = 0; i < initials->size(); i++) {
//			JExpression* component = initials->at(i);
//			component = component->analyze(surrounding);
//			(*initials)[i] = component;
//			if (!(dynamic_cast<JArrayInit*>(component) )) {
//				// must match expected --kenan
//			}
//		}
//		return this;
//	}
//
//	~JArrayInit()
//	{
//	}
//};
