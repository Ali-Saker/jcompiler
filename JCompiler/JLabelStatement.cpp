#include"JExpression.h"
#include"Context.h"
#include"JLabelStatement.h"

/**/
#include"Utils.h"
#include"ErrorRecovery.h"
#include"ConstantExpressionInterface.h"

JLabelStatement::JLabelStatement(int line, int col, char *lableName , JExpression* constantExpression)
: JStatement(line, col, "JLabelStatement")
{
	this->lableName = lableName;
	this->constantExpression = constantExpression;
}

void JLabelStatement::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	if (this->constantExpression != 0){
		this->constantExpression->preAnalyze(surrounding);
	}
}

void JLabelStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	if (this->constantExpression != 0){
		this->constantExpression->analyze();
		if (!dynamic_cast<ConstantExpressionInterface*>(this->constantExpression)){
			errMsg = "case expressions must be constant expressions";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));

		}
	}
}
void JLabelStatement::codegen(){
	if (this->constantExpression != 0){
		this->constantExpression->codegen();
	}
}
