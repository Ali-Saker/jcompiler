#include"Defn.h"


Defn::Defn(char *DefnName)
{
	this->DefnName = DefnName;
}

char* Defn::getDefnName(){
	return this->DefnName;
}
