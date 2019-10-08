#include "Type.h"
#include"Context.h"
#include"JExpression.h"
#include"PrimitiveType.h"
#include"ReferenceType.h"
#include "Type.h"
JExpression::JExpression(int line, int col, char *expressionName, Type* expressionType)
:JStatement(line, col, "JExpression")
{
	this->expressionName = expressionName;
	this->expressionType = expressionType;
	this->isClassName = 0;
	this->isVarName = 0;
	this->isPackageName = 0;
}

bool JExpression::isString(){
	return ( ( dynamic_cast<PrimitiveType *>(this->expressionType) )&& (this->expressionType == PrimitiveType::JSTRING ) );
}
bool JExpression::isIntegral(){
	return !(this->isString() || this->isRef() || this->isFP());
}
bool JExpression::isFP(){
	return ( (dynamic_cast<PrimitiveType *>(this->expressionType)) &&
		   ( (this->expressionType == PrimitiveType::JFLOAT) ||
		     (this->expressionType == PrimitiveType::JDOUBLE) ) );
}
bool JExpression::isRef(){
	return (dynamic_cast<ReferenceType *>(this->expressionType));
}
bool JExpression::isChar(){
	return ((dynamic_cast<PrimitiveType *>(this->expressionType)) &&
		((this->expressionType == PrimitiveType::JCHAR)) );
}