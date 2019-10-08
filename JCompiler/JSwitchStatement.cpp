#include"JBlock.h"
#include"JExpression.h"
#include"Context.h"
#include"JSwitchStatement.h"

/**/
#include"Type.h"
#include"Utils.h"
#include"ErrorRecovery.h"
#include"JLabelStatement.h"
JSwitchStatement::JSwitchStatement(int line, int col, JExpression *condition, JBlock *block)
: JSelectionStatement(line, col, "JSwitchStatement", condition)
{
	this->block = block;
}

void JSwitchStatement::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;


	int switch_num = Utils::SwitchCount++;

	if (dynamic_cast<JBlock *>(this->block)){
		JBlock *block = (JBlock *)this->block;
		block->id = switch_num;
		block->kind = 2;
	}

	this->id = switch_num;


	if (this->condition != 0){
		this->condition->preAnalyze(surrounding);
	}

	if (this->block != 0){
		this->block->preAnalyze(surrounding);
	}
}
 void JSwitchStatement::analyze(){
	 if (this->analyzed) return;
	 this->analyzed = true;
	string errMsg;
	if (this->condition != 0){
		this->condition->analyze();
	}
	if (this->condition != 0 && this->condition->expressionType != 0){
		pair<char *, int> lhs = this->condition->expressionType->getName();
		if (lhs.first != nullptr && strcmp(lhs.first, "boolean") != 0){
			errMsg = "Cannot switch on a value of type " + Utils::toString(lhs.first) +
				". Only convertible int values, strings or enum variables are permitted";
			ErrorRecovery::reportSemanticError(this->condition->getLine(), this->condition->getCol(),
				Utils::toCharArray(errMsg));
		}
	}

	/*check if this block has statements of types different from case and default.*/
	if (block != 0){
		this->block->analyze();
	}
}

 void JSwitchStatement::codegen(){
	 this->condition->codegen();
	 int switch_num = this->id;
	 int case_count = 0;
	 for (int i = 0; i < this->block->statements->size(); i++){
		 if (dynamic_cast<JLabelStatement *> (this->block->statements->at(i))){
			 JLabelStatement * jls = (JLabelStatement *) this->block->statements->at(i);
			 if (!strcmp(jls->lableName, "case")){
				 jls->codegen();
				 Utils::out << "lw $t2,4($sp)" << endl;
				 Utils::out << "addi $sp,$sp,4" << endl;
				 Utils::out << "lw $t1,4($sp)" << endl;
				 Utils::out << "beq $t1,$t2,case" << switch_num << "n" << case_count++ << endl;
			 }
			 else{
				 Utils::out << "j case" << switch_num << "n" << case_count++ << endl;
			 }
		 }
	 }
	 case_count = 0;
	 for (int i = 0; i < this->block->statements->size(); i++){
		 if (dynamic_cast<JLabelStatement *> (this->block->statements->at(i))){

			 Utils::out << "case" << switch_num << "n" << case_count++ << ":" << endl;

		 }
		 else{
			 this->block->statements->at(i)->codegen();
		 }
	 }

	 Utils::out << "endswitch" << switch_num << ":" << endl;
	 Utils::out << "addi $sp,$sp,4" << endl;
 }