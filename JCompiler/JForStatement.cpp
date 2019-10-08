#include"JExpressionStatement.h"
#include"JVariableDeclaration.h"
#include"JForStatement.h"
#include"JExpression.h"
#include"JStatement.h"
#include"Context.h"

/**/
#include"Type.h"
#include"PrimitiveType.h"
#include"Utils.h"
#include"JBlock.h"
JForStatement::JForStatement(int line, int col, JStatement* statement, vector<JExpressionStatement*> *forInitExpressionStatements,
	JVariableDeclaration* forInitVariableDeclaration, JExpression* forExpr,
	vector<JExpressionStatement*> *forIncr) : JIterationStatement(line, col, "JForStatement", statement){
	this->forInitExpressionStatements = forInitExpressionStatements;
	this->forInitVariableDeclaration = forInitVariableDeclaration;
	this->forExpr = forExpr;
	this->forIncr = forIncr;
}


void JForStatement::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;

	int loop_num = Utils::LoopCount++;
	if (dynamic_cast<JBlock *>(this->statement)){
		JBlock *block = (JBlock *)this->statement;
		block->id = loop_num;
		block->kind = 1;
	}
	this->id = loop_num;

	if (this->forInitExpressionStatements != 0){
		for (int i = 0; i < this->forInitExpressionStatements->size(); i++){
			this->forInitExpressionStatements->at(i)->preAnalyze(surrounding);
		}
	}

	if (this->forInitVariableDeclaration != 0){
		this->forInitVariableDeclaration->preAnalyze(surrounding);
	}

	if (this->forExpr != 0){
		this->forExpr->preAnalyze(surrounding);
	}

	if (this->forIncr != 0){
		for (int i = 0; i < this->forIncr->size(); i++){
			this->forIncr->at(i)->preAnalyze(surrounding);
		}
	}

	if (this->statement != 0){
		this->statement->preAnalyze(surrounding);
	}
}
//forInitExpressionStatements
void JForStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	/* analyze forInitExpressionStatements part*/
	for (int i = 0; this->forInitExpressionStatements != 0 && i < this->forInitExpressionStatements->size(); i++){

		this->forInitExpressionStatements->at(i)->analyze();

	}
	/* forInitVariableDeclaration */
	if (this->forInitVariableDeclaration != 0)
		this->forInitVariableDeclaration->analyze();

	/* analyze forExpr*/
	if (this->forExpr != 0){
		this->forExpr->analyze();
	}

	if (this->forExpr != 0 && this->forExpr->expressionType != 0){
		pair<char *, int> lhs = this->forExpr->expressionType->getName();
		if (lhs.first != nullptr && strcmp(lhs.first, "boolean") != 0){
			errMsg = "Type mismatch: cannot convert from " +
				Utils::toString(lhs.first) + " to boolean.";
			ErrorRecovery::reportSemanticError(this->forExpr->getLine(), this->forExpr->getCol(),
				Utils::toCharArray(errMsg));
		}

	}

	/* analyze forIncr*/

	for (int i = 0; this->forIncr != 0 && i < this->forIncr->size(); i++){
		this->forIncr->at(i)->analyze();
	}

	if (statement != 0){
		this->statement->analyze();
	}
}

void JForStatement::codegen(){
	int loop_num = this->id;
	if (this->forInitVariableDeclaration != 0){
		this->forInitVariableDeclaration->codegen();
	}
	else if (this->forInitExpressionStatements != 0){
		for (int i = 0; i < this->forInitExpressionStatements->size(); i++){
			this->forInitExpressionStatements->at(i)->codegen();
		}
	}
	Utils::out << "loop" << loop_num << ":" << endl;
	if (this->forExpr != 0){
		this->forExpr->codegen();
		Utils::out << "lw $t1,4($sp)" << endl;
		Utils::out << "addiu $sp,$sp,4" << endl;
		Utils::out << "beq $t1,$zero,endloop" << loop_num << endl;
	}
	this->statement->codegen();

	Utils::out << "loopinc"<< loop_num << ":"<<  endl;
	if (this->forIncr != 0){
		for (int i = 0; i < this->forIncr->size(); i++){
			this->forIncr->at(i)->codegen();
		}
	}
	Utils::out << "j loop" << loop_num << endl;
	Utils::out << "endloop" << loop_num << ":" << endl;

}