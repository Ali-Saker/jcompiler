#include"ArrayType.h"

ArrayType::ArrayType(Type *type, int dimensions) : Type(type == 0 ? 0 : type->typeName){
	this->type = type;
	this->dimensions = dimensions;
}

pair<char *, int> ArrayType::getName(){
	if (this->type->getName().first == nullptr){
		return make_pair(nullptr, 0);
	}
	return make_pair(this->type->getName().first, this->dimensions);
}