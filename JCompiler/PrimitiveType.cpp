#include"typeName.h"
#include"PrimitiveType.h"


PrimitiveType * PrimitiveType::JINTEGER = new PrimitiveType("int");
PrimitiveType * PrimitiveType::JLONG = new PrimitiveType("long");
PrimitiveType * PrimitiveType::JCHAR = new PrimitiveType("char");
PrimitiveType * PrimitiveType::JFLOAT = new PrimitiveType("float");
PrimitiveType * PrimitiveType::JDOUBLE = new PrimitiveType("double");
PrimitiveType * PrimitiveType::JBOOLEAN = new PrimitiveType("boolean");
PrimitiveType * PrimitiveType::JNUL = new PrimitiveType("null");
PrimitiveType * PrimitiveType::JSTRING = new PrimitiveType("String");
PrimitiveType * PrimitiveType::JANY = new PrimitiveType("any");
PrimitiveType * PrimitiveType::JVOID = new PrimitiveType("void");
 
PrimitiveType::PrimitiveType(char *name) : Type(new TypeName(0, 0, name)){
}