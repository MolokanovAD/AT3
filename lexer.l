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
				yylloc.last_line = yylloc.first_line = yylineno; 
				yylval.intValue = new ConstInt(new int(std::stoi(yytext)));
				return INTEGER;
				}

0[01]*		{
				yylloc.last_line = yylloc.first_line = yylineno; 
				yylval.intValue = new ConstInt(new int(std::stoi(yytext, nullptr, 2)));
				return INTEGER;
			}

"false"		{
				yylloc.last_line = yylloc.first_line = yylineno; 
				yylval.boolValue = new ConstBool(new bool(false));
				return BOOLEAN;
			}

"true"		{
				yylloc.last_line = yylloc.first_line = yylineno; 
				yylval.boolValue = new ConstBool(new bool(true));
				return BOOLEAN;
			}
"bool"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 0; return BOOL;}
"cbool"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 1; return BOOL;}
"vbool"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 6; return BOOL;}
"cvbool"	{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 7; return BOOL;}
"mbool"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 10; return BOOL;}
"cmbool"	{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 11; return BOOL;}
"int"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 2; return INT;}
"cint"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 3; return INT;}
"vint"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 4; return INT;}
"cvint"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 5; return INT;}
"mint"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 8; return INT;}
"cmint"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = 9; return INT;}
"for"		{ yylloc.last_line = yylloc.first_line = yylineno; return FOR;}
"beginfor"	{ yylloc.last_line = yylloc.first_line = yylineno; yylval.name = new std::string("for");return BEG;}
"beginif"	{ yylloc.last_line = yylloc.first_line = yylineno; yylval.name = new std::string("if");return BEG;}
"begin"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.name = new std::string("");return BEG;}
"endfor"	{ yylloc.last_line = yylloc.first_line = yylineno; yylval.name = new std::string("for");return END;}
"endif"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.name = new std::string("if");return END;}
"end"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.name = new std::string("");return END;}
"if"		{ yylloc.last_line = yylloc.first_line = yylineno; return IF;}
"function"	{ yylloc.last_line = yylloc.first_line = yylineno; return FUN;}
"<-"		{ yylloc.last_line = yylloc.first_line = yylineno; return ASSIGN;}
"<<"		{ yylloc.last_line = yylloc.first_line = yylineno; return LSHIFT;}
">>"		{ yylloc.last_line = yylloc.first_line = yylineno; return RSHIFT;}
and|&&		{ yylloc.last_line = yylloc.first_line = yylineno; return AND;}
".*"		{ yylloc.last_line = yylloc.first_line = yylineno; return ELEMMUL; }
"sum"		{ yylloc.last_line = yylloc.first_line = yylineno; return SUM;}
"move"		{ yylloc.last_line = yylloc.first_line = yylineno; return MOVE;}
"left"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = -1; return TURN;}
"right"		{ yylloc.last_line = yylloc.first_line = yylineno; yylval.type = -2; return TURN;}
"wall"		{ yylloc.last_line = yylloc.first_line = yylineno; return WALL;}
"exit"		{ yylloc.last_line = yylloc.first_line = yylineno; return EXIT;}
"...\n"		;

[a-zA-Z][a-zA-Z0-9_]*	{
							yylloc.last_line = yylloc.first_line = yylineno;
							yylval.name = new std::string(yytext);
							return VAR;
						}

[-\+\=*\!\,:\{\}\<\>\(\)\[\]\']	{ yylloc.last_line = yylloc.first_line = yylineno; return *yytext;}

\n			{ yylloc.last_line = yylloc.first_line = yylineno; return *yytext;}

[ \t]		;

.			yyerror("Unknown character");

%%

int yywrap(void) {
	return 1;
}