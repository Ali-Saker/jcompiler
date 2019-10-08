#include"JExpression.h"
#include"Context.h"
#include"JIfStatement.h"
#include"PrimitiveType.h"
#include"JBlock.h"
#include"Utils.h"
JIfStatement::JIfStatement(int line, int col, JExpression* condition, JStatement* thenPart, JStatement* elsePart)
:JSelectionStatement(line, col, "JIfStatement", condition)
{
	this->thenPart = thenPart;
	this->elsePart = elsePart;
}

void JIfStatement::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	if (this->condition != 0){
		this->condition->preAnalyze(surrounding);
	}
	if (this->thenPart != 0){
		thenPart->preAnalyze(surrounding);
	}

	if (this->elsePart != 0){
		elsePart->preAnalyze(surrounding);
	}
}

void JIfStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	if (this->condition != 0){
		this->condition->analyze();
	}
	if (this->condition != 0 && this->condition->expressionType != 0){
		pair<char *, int> lhs = this->condition->expressionType->getName();
		if (lhs.first != nullptr && strcmp(lhs.first, "boolean") != 0){
			errMsg = "Type mismatch: cannot convert from " +
				Utils::toString(lhs.first) + " to boolean.";
			ErrorRecovery::reportSemanticError(this->condition->getLine(), this->condition->getCol(),
				Utils::toCharArray(errMsg));
		}
	}

	if (thenPart != 0){
		thenPart->analyze();
	}

	if (elsePart != 0){
		elsePart->analyze();
	}


}

void JIfStatement::codegen(){
	this->condition->codegen();
	int else_num = Utils::ElseCount; Utils::ElseCount++;
	Utils::out << "lw $t1,4($sp)" << endl;
	Utils::out << "add $sp,$sp,4" << endl;
	Utils::out << "beq $t1,$zero," << "else" << else_num << endl;
	if (this->thenPart != 0){
		this->thenPart->codegen();
	}
	Utils::out << "j endif" << else_num << endl;
	Utils::out << "else" << else_num << ":" << endl;
	if (this->elsePart != 0){
		this->elsePart->codegen();
	}
	Utils::out << "endif" << else_num << ":" << endl;


}