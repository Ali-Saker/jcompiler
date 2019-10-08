#include"JExpression.h"
#include"Context.h"
#include"JExpressionStatement.h"
/**/
#include"ExpressionStatementInterface.h"
#include"ErrorRecovery.h"
#include"Utils.h"
#include"PrimitiveType.h"
JExpressionStatement::JExpressionStatement(JExpression* expression)
:JStatement(expression->getLine(), expression->getCol(), "JExpressionStatement"){
	this->expression = expression;
}

void JExpressionStatement::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	if (this->expression != 0){
		this->expression->preAnalyze(surrounding);
	}
}

void JExpressionStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	/* analyze expression*/
	this->expression->analyze();

	if (!dynamic_cast<ExpressionStatementInterface*>(this->expression)){
		errMsg = "expression must be a statement.";
		ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));

	}
}

void JExpressionStatement::codegen(){
	this->expression->codegen();
	if (!(dynamic_cast<PrimitiveType *> (this->expression->expressionType)
		&& this->expression->expressionType == PrimitiveType::JVOID)){
		Utils::out << "addiu $sp, $sp, 4" << endl;
	}
}