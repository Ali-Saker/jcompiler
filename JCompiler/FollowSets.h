#pragma once

#include"global.h"
#include"yacc.hpp"
set<int> followSet[N];
set<int> Modifiers;

void initFollowSets(){

	int modifiers[] = {PUBLIC, PRIVATE, PROTECTED, ABSTRACT, FINAL, TRANSIENT, VOLATILE, NATIVE, SYNCHRONIZED, STATIC};

	Modifiers = set<int> (modifiers, modifiers+10);

	int a[] = {IMPORT, CLASS, INTERFACE, ABSTRACT, FINAL, PUBLIC, PROTECTED, PRIVATE,
	 STATIC, TRANSIENT, VOLATILE, NATIVE, SYNCHRONIZED};

	int b[] = {BOOLEAN, CHAR, BYTE, SHORT, INT, LONG, FLOAT, DOUBLE, VOID, ABSTRACT, FINAL, PUBLIC,
	 PROTECTED, PRIVATE, STATIC, TRANSIENT, VOLATILE, NATIVE, SYNCHRONIZED, CLASS, INTERFACE, '{', '}'};

	int c[] = {BOOLEAN, CHAR, BYTE, SHORT, INT, LONG, FLOAT, DOUBLE, VOID, ABSTRACT, FINAL, PUBLIC,
	 PROTECTED, PRIVATE, STATIC, TRANSIENT, VOLATILE, NATIVE, SYNCHRONIZED, CLASS, INTERFACE, '{', '}', ';' , ',' };

	int d[] = {';', '{', '}', IF, WHILE, DO, TRY, IDENTIFIER, CASE, DEFAULT, SWITCH, BREAK, CONTINUE, RETURN, THROW, SYNCHRONIZED,
	 OP_INC, OP_DEC, NEW, THIS, SUPER, INT, LONG, DOUBLE, FLOAT, FINAL, BOOLEAN, CHAR, BYTE, SHORT, FOR};

	followSet[PACKAGE] = set<int>(a , a+13);
	followSet[IMPORT] = set<int>(a , a+13);
	followSet[CLASS] = set<int>(b , b+23);
	followSet[VAR] = set<int>(c , c+26);
	followSet[FIELD] = set<int>(b, b+23);
	followSet[METHOD] = set<int> (d, d+31);
	followSet[STATEMENT] = set<int> (d, d+31);

}
