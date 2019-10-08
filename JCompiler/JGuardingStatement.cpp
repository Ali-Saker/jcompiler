#include"JBlock.h"
#include"JCatch.h"
#include"JGuardingStatement.h"

JGuardingStatement::JGuardingStatement(int line, int col, JBlock* tryBlock, vector<JCatch*>* catches, JBlock* finallyBlock)
	:JStatement(line, col,"JGuardingStatement") {
	this->tryBlock = tryBlock;
	this->catches = catches;
	this->finallyBlock = finallyBlock;
}

void JGuardingStatement::preAnalyze(Context *surrounding){

}
void JGuardingStatement::analyze(){
/*
	if (tryBlock != 0){
		tryBlock = (JBlock*)tryBlock->analyze(context);
	}

	if (finallyBlock != 0){
		finallyBlock = (JBlock*)finallyBlock->analyze(context);
	}

	for (int i = 0; catches != 0 && i < catches->size(); i++){
		if (catches->at(i) != 0){
			(*catches)[i] = catches->at(i)->analyze(context);
		}
	}

	return this;*/
}