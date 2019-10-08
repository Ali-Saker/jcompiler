#include"Context.h"
#include"JAST.h"

JAST::JAST(int line, int col){
	this->line = line;
	this->col = col;
	this->analyzed = false;
	this->preAnalyzed = false;
	this->parentChecked = false;
}

int JAST::getLine(){
	return line;
}

int JAST::getCol(){
	return col;
}

void JAST::setContext(Context *surrounding){
	this->surrounding = surrounding;
}
Context *JAST::getContext(){
	return surrounding;
}