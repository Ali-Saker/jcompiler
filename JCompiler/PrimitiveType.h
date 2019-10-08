#pragma once
#include"Type.h"
class PrimitiveType : public Type{

public:
	static PrimitiveType * JINTEGER;
	static PrimitiveType * JLONG;
	static PrimitiveType * JCHAR;
	static PrimitiveType * JFLOAT;
	static PrimitiveType * JDOUBLE;
	static PrimitiveType * JBOOLEAN;
	static PrimitiveType * JNUL;
	static PrimitiveType * JSTRING;
	static PrimitiveType * JANY;
	static PrimitiveType * JVOID;

	PrimitiveType(char *);
};