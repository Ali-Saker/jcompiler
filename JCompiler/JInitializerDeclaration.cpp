#include"JBlock.h"
#include"Context.h"
#include"JInitializerDeclaration.h"

JInitializerDeclaration::JInitializerDeclaration(int line, int col, bool is_static_Initializer, JBlock* block)
:JAST(line, col)
{
	this->is_static_Initializer = is_static_Initializer;
	this->block = block;
}

void JInitializerDeclaration::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
}
void JInitializerDeclaration::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;

}