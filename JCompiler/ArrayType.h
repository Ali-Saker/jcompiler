#pragma once
#include<iostream>
using namespace std;
#include"Type.h"
class ArrayType : public Type{
public:
	int dimensions;
	Type *type;
	ArrayType(Type *, int);
	virtual pair<char *, int> getName();
};