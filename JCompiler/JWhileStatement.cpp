#include"JExpression.h"
#include"JStatement.h"
#include"Context.h"
#include"JWhileStatement.h"

/**/
#include"Type.h"
#include"PrimitiveType.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"JBlock.h"
JWhileStatement::JWhileStatement(int line, int col, JStatement* statement, JExpression* condition) :
	JIterationStatement(line, col, "JWhileStatement", statement){
	this->condition = condition;
}
	

void JWhileStatement::preAnalyze(Context *surrounding){


	if (this->preAnalyzed) return;
	this->preAnalyzed = true;

	int loop_num = Utils::LoopCount++;
	if (dynamic_cast<JBlock *>(this->statement)){
		JBlock *block = (JBlock *)this->statement;
		block->id = loop_num;
		block->kind = 1;
	}
	this->id = loop_num;
	if (this->condition != 0){
		this->condition->preAnalyze(surrounding);
	}
	if (this->statement != 0){
		this->statement->preAnalyze(surrounding);
	}

}
void JWhileStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;

	if (condition != 0){
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

	if (statement != 0){
		this->statement->analyze();
	}
}

void JWhileStatement::codegen(){
	int loop_num = this->id;
	Utils::out << "loop" << loop_num << " :" << endl;
	this->condition->codegen();
	Utils::out << "lw $t1, 4($sp)" << endl;
	Utils::out << "addi $sp, $sp, 4" << endl;
	Utils::out << "beq $t1 $zero endloop" << loop_num << endl;
	this->statement->codegen();
	Utils::out << "loopinc" << loop_num << ":" << endl;
	Utils::out << "j loop" << loop_num << endl;
	Utils::out << "endloop" << loop_num << " :" << endl;
}