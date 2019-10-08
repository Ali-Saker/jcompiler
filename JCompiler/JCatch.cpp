#include"JFormalParameter.h"
#include"JBlock.h"
#include"Context.h"
#include"JCatch.h"

JCatch::JCatch(int line, int col, JFormalParameter* param, JBlock* catchBlock){
	this->line = line;
	this->col = col;
	this->param = param;
	this->catchBlock = catchBlock;
}

void JCatch::preAnalyze(Context *surrounding){

}

void JCatch::analyze(){
	//string errMsg;

	//Defn * defnType = context->lookUp(Utils::hashCodeCat(name, 1));

	///* if local variable defined before */
	//if (name != 0){
	//	if (defnType != 0 && strcmpi(defnType->getDefnName(), "LocalVariableNameDefn") == 0){
	//		errMsg = "Duplicate local variable '" + Utils::toString(name) + "'.";
	//		ErrorRecovery::reportSemanticError(typeSpecifier->getLine(), typeSpecifier->getCol(),
	//			Utils::toCharArray(errMsg));
	//	}
	//	else{
	//		context->add(Utils::hashCodeCat(name, 1),
	//			new LocalVariableNameDefn(typeSpecifier),
	//			typeSpecifier->getLine(), typeSpecifier->getCol());
	//	}
	//}

	///* if type exist */
	//if (typeSpecifier != 0){
	//	defnType = context->lookUp(Utils::hashCodeCat(typeSpecifier->name, 0));
	//}

	//if (defnType == 0){
	//	errMsg = Utils::toString(typeSpecifier->name) + " cannot be resolved to a type.";
	//	ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
	//}

	///* analyze block */
	//if (catchBlock != 0){
	//	catchBlock = (JBlock*)catchBlock->analyze(context);
	//}

	//return this;
}