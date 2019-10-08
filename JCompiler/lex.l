%{
		#include <iostream>
		#include <istream>
		#include <ostream>		
		#include <FlexLexer.h>		
%}
%option c++
%option noyywrap
%%
"abstract"				{cout<<"\t abstract\n";}
"else"					{cout<<"\t else \n";}
"long"					{;}
"short"					{;}
"extends"				{;}
"static"				{;}
[a-zA-Z_][0-9a-zA-Z_]*	{cout<<"\t it is varibale:"<<yytext<<"\n";}
%%
int main()
{	
	FlexLexer* lexer = new yyFlexLexer;
	lexer->yylex();
    return 0;
}
