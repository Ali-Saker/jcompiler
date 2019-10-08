#include"Context.h"
#include"typeName.h"
#include"JClassDeclaration.h"
#include"JClass.h"

#include"ReferenceType.h"
JClass::JClass(TypeName *typeName, JClassDeclaration *classDeclaration)
:JExpression(typeName->getLine(), this->getCol(), "JClass", 0){
	this->typeName = typeName;
	this->classDeclaration = classDeclaration;
	this->isClassName = 1;
}
void JClass::preAnalyze(Context *surrounding){
	this->setContext(surrounding);
}
void JClass::analyze(){
	Context *surrounding = this->getContext();
	this->expressionType = new ReferenceType(this->typeName);
	((ReferenceType *)this->expressionType)->resolve((Context *)surrounding->getClassContext());
	this->classDeclaration = (JClassDeclaration *)((ReferenceType *)this->expressionType)->referenceTypeDecl;
}