%{
	#include <string>
	#include <memory>
	#include <iostream>
	#include "Types/Node.h"
	#include "Types/Bools/Bool.h"
	#include "Types/Ints/Int.h"
	#include "file.tab.h"
	void yyerror(const char*);
%}

%option yylineno

%%


[1-9][0-9]*	{
				yylval.intValue = new ConstInt(new int(std::stoi(yytext)));
				return INTEGER;
				}

0[01]*	{
				yylval.intValue = new ConstInt(new int(std::stoi(yytext, nullptr, 2)));
				return INTEGER;
			}

"false"		{
				yylval.boolValue = new ConstBool(new bool(false));
				return BOOLEAN;
			}

"true"		{
				yylval.boolValue = new ConstBool(new bool(true));
				return BOOLEAN;
			}
"bool"		{ yylval.name = new std::string("");return BOOL;}
"cbool"		{ yylval.name = new std::string("c");return BOOL;}
"vbool"		{ yylval.name = new std::string("v");return BOOL;}
"cvbool"	{ yylval.name = new std::string("cv");return BOOL;}
"mbool"		{ yylval.name = new std::string("m");return BOOL;}
"cmbool"	{ yylval.name = new std::string("cm");return BOOL;}
"int"		{ yylval.name = new std::string("");return INT;}
"cint"		{ yylval.name = new std::string("c");return INT;}
"vint"		{ yylval.name = new std::string("v");return INT;}
"cvint"		{ yylval.name = new std::string("cv");return INT;}
"mint"		{ yylval.name = new std::string("m");return INT;}
"cmint"		{ yylval.name = new std::string("cm");return INT;}
"for"		{return FOR;}
"beginfor"	{yylval.name = new std::string("for");return BEG;}
"beginif"	{yylval.name = new std::string("if");return BEG;}
"begin"		{yylval.name = new std::string("");return BEG;}
"endfor"	{yylval.name = new std::string("for");return END;}
"endif"		{yylval.name = new std::string("if");return END;}
"end"		{yylval.name = new std::string("");return END;}
"if"		{return IF;}
"function"	{return FUN;}
"<-"		return ASSIGN;
"<<"		return LSHIFT;
">>"		return RSHIFT;
and|&&		return AND;
".*"		return ELEMMUL;
"sum"		return SUM;
"...\n"		;

[a-zA-Z][a-zA-Z0-9_]*	{
							yylval.name = new std::string(yytext);
							return VAR;
						}

[-\+\=*\!\,:\{\}\<\>\(\)\[\]\'\n]	{return *yytext;}

[ \t]		;

.			yyerror("Unknown character");

%%

int yywrap(void) {
	return 1;
}