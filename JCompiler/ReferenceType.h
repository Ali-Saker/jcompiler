#pragma once
#include<iostream>
using namespace std;
#include"Type.h"
class JAST;
class TypeName;
class Context;
class ReferenceType : public Type{
public:
	JAST *referenceTypeDecl;

	ReferenceType(TypeName *);

	virtual pair<char *, int> getName();

	bool routedResolve(Context *);

	bool resolve(Context *);

	bool resolveAsInterface(Context *);

	bool resolveAsRoutedInterface(Context *);
};