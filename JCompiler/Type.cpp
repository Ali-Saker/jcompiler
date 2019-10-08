#include"typeName.h"
#include"Type.h"
#include<iostream>
Type::Type(TypeName *typeName){
	this->typeName = typeName;
}
pair<char *, int> Type::getName(){
	return std::make_pair(this->typeName->name, 0);
}
