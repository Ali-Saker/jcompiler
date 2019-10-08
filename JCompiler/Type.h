#pragma once
#include<iostream>
using namespace std;
class TypeName;
class Type{
public:
	/* name of the type*/
	TypeName *typeName;

	Type(TypeName *);

	virtual pair<char *, int> getName();
};