#include"Context.h"
#include"JBlock.h"
#include"JJumpStatement.h"
/**/
#include"MethodContext.h"
#include"LocalContext.h"
JBlock::JBlock(int line, int col, vector<JStatement*> *statements, Context *blockContext) 
: JStatement(line, col, "JBlock")
{

	this->statements = statements;
	this->blockContext = blockContext;
	this->hasReturnStatement = false;
	this->id = -1;
	this->kind = -1;
}

   
void JBlock::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	this->blockContext = new LocalContext(surrounding, this);

	for (int i = 0; this->statements != 0 && i < this->statements->size(); i++){
		this->statements->at(i)->preAnalyze(this->blockContext);
	}
}

void JBlock::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;

	for (int i = 0; this->statements != 0 && i < this->statements->size(); i++){
		this->statements->at(i)->analyze();
		if ((dynamic_cast<JJumpStatement *> (this->statements->at(i)))){
			JJumpStatement * jjump = (JJumpStatement *)(this->statements->at(i));
			if (jjump->returnExpression != 0){
				this->hasReturn = true;
			}
		}
	}
}

void JBlock::codegen(){
	for (int i = 0; this->statements != 0 && i < this->statements->size(); i++){
		this->statements->at(i)->codegen();
	}
}