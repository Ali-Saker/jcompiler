%{
		#include "yacc.hpp"
		#include "Scanner.h"
		int lineNo = 1;
		int colNo = 1;
%}
%option c++
%option noyywrap
identifier [a-zA-Z_$][a-zA-Z0-9_$]*



int_literal 0|([1-9][0-9]*)|0[0-7][0-7]*|0[xX][0-9a-fA-F][0-9a-fA-F]*



long_literal {int_literal}[lL]




double_literal [0-9]+"."?[0-9]*([eE][-+]?[0-9]+)?[dD]?|[0-9]*"."?[0-9]+([eE][-+]?[0-9]+)?[dD]?


ESC "\\"["n""t""f""r""b""\"""\'""\\"]


string_literal "\""({ESC}|[^\"\n\r\\])*"\""


char_literal	"\'"({ESC}|[^\'\n\r\\])"\'"


float_literal [0-9]+[fF]?|[0-9]*"."[0-9]+([eE][-+]?[0-9]+)?[fF]|[0-9]+"."[0-9]*([eE][-+]?[0-9]+)?[fF]

annotation "@"[A-Z][a-z]*

whiteSpace " "

tab \t

newLine \n

error .

%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT

%%



"abstract"		{return ABSTRACT;}
"const"			{return CONST;}
"finally"		{return FINALLY;}	
"int"			{return INT;}
"public"		{return PUBLIC;}
"this"			{return THIS;}
"boolean"		{return BOOLEAN;}
"continue"		{return CONTINUE;}
"String"		{return STRING;}
"float"			{return FLOAT;}
"System.out.println"	{return PRINT;}
"interface"		{return INTERFACE;}
"return"		{return RETURN;}
"throw"			{return THROW;}
"break"			{return BREAK;}
"default"		{return DEFAULT;}
"for"			{return FOR;}
"long"			{return LONG;}
"short"			{return SHORT;}
"throws"		{return THROWS;}
"byte"			{return BYTE;}
"do"			{return DO;}
"goto"			{return GOTO;}
"native"		{return NATIVE;}
"static"		{return STATIC;}
"transient"		{return TRANSIENT;}
"case"			{return CASE;}
"double"		{return DOUBLE;}
"if"			{return IF;}
"new"			{return NEW;}
"null"			{return JNULL;}
"strictfp"		{return STRICTFP;}
"try"			{return TRY;}
"catch"			{return CATCH;}
"else"			{return ELSE;}
"implements"	{return IMPLEMENTS;}
"package"		{return PACKAGE;}
"super"			{return SUPER;}
"void"			{return VOID;}
"char"			{return CHAR;}
"extends"		{return EXTENDS;}
"import"		{return IMPORT;}
"private"		{return PRIVATE;}
"switch"		{return SWITCH;}
"volatile"		{return VOLATILE;}
"class"			{return CLASS;}
"final"			{return FINAL;}
"instanceof"	{return INSTANCEOF;}
"protected"		{return PROTECTED;}
"synchronized"	{return SYNCHRONIZED;}
"while"			{return WHILE;}
"true"			{return BOOLLIT;}
"false"			{return BOOLLIT;}






"?"			{return * yytext;}
"="			{return * yytext;}
"=="		{return OP_EQ;}
"!"			{return * yytext;}
"!="		{return OP_NE;}
"+"			{return * yytext;}
"+="		{return ASS_ADD;}
"++"		{return OP_INC;}
"-"			{return * yytext;}
"-="		{return ASS_SUB;}
"--"		{return OP_DEC;}
"*"			{return * yytext;}
"*="		{return ASS_MUL;}
"%"			{return * yytext;}
"%="		{return ASS_MOD;}
">="		{return OP_GE;}
">"			{return * yytext;}
"<="		{return OP_LE;}
"<"			{return * yytext;}
"^"			{return * yytext;}
"^="		{return ASS_XOR;}
"|"			{return * yytext;}
"|="		{return ASS_OR;}
"||"		{return OP_LOR;}
"&"			{return * yytext;}
"&="		{return ASS_AND;}
"&&"		{return OP_LAND;}
">>"		{return OP_SHR;}
">>="		{return ASS_SHR;}
"<<"		{return OP_SHL;}
"<<="		{return ASS_SHL;}
">>>"		{return OP_SHRR;}
">>>="		{return ASS_SHRR;}
"/"			{return * yytext;}
"/="		{return ASS_DIV;}
"[]"		{return OP_DIM;}


","			{/*yylval = ','; */return * yytext;}
"."			{/*yylval = '.'; */return * yytext;}
"["			{/*yylval = '['; */return * yytext;}
"{"			{/*yylval = '{'; */return * yytext;}
"("			{/*yylval = '('; */return * yytext;}
")"			{/*yylval = ')'; */return * yytext;}
"}"			{/*yylval = '}';*/ return * yytext;}
"]"			{/*yylval = ']';*/ return * yytext;}
";"			{/*yylval = ';'; */return * yytext;}
":"			{/*yylval = ';'; */return * yytext;}



"/*"		BEGIN(MULTI_LINE_COMMENT);
<MULTI_LINE_COMMENT>[^*\n]* {colNo += strlen(yytext);}
<MULTI_LINE_COMMENT>"*"+[^*/\n]* {colNo += strlen(yytext);}
<MULTI_LINE_COMMENT>\n		{++lineNo; colNo=1;}
<MULTI_LINE_COMMENT>"*"+"/"        {colNo+=2; BEGIN(INITIAL);}


"//"		BEGIN(SINGLE_LINE_COMMENT);
<SINGLE_LINE_COMMENT>[^\n]*
<SINGLE_LINE_COMMENT>\n		{++lineNo; colNo=1; BEGIN(INITIAL);}



{whiteSpace}	{colNo += 1;}
{tab}		{colNo += 4;}
{newLine}	{++lineNo; colNo = 1;}


{identifier}	{return IDENTIFIER;}




{int_literal}	 {return INT_LITERAL;}
{long_literal} 	 {return LONG_LITERAL;}
{char_literal}	 {return CHAR_LITERAL;}
{double_literal} {return DOUBLE_LITERAL;}
{float_literal}	 {return FLOAT_LITERAL;}
{string_literal} {return STRING_LITERAL;}

{annotation}	 {return ANNOTATION;}
{error}			 {return ERROR;}

%%
int give_Me_Token_Col(){
	return colNo;
}
int give_Me_Token_Line(){
	return lineNo;
}
void Update_Col(int x){
	colNo += x;
}
