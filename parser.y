%{
	#include <iostream>
	#include <memory>
	#include <map>
	#include "Types/Node.h"
	#include "Types/Variable.h"
	#include "Types/Bools/Bool.h"
	#include "Types/Ints/Int.h"
	#include "Types/Operations/Add.h"
	#include "Types/Operations/And.h"
	#include "Types/Operations/Compare.h"
	#include "Types/Operations/ElemMult.h"
	#include "Types/Operations/MatrixMult.h"
	#include "Types/Operations/Not.h"
	#include "Types/Operations/Shift.h"
	#include "Types/Operations/Subtract.h"
	#include "Types/Operations/Sum.h"
	#include "Types/Operations/Transposition.h"
	#include "Types/Functions.h"
	std::map<std::string, Node*> varTable;
	int yylex(void);
	void yyerror(const char*);
	extern FILE * yyin;
%}

%union {
	Node* node; 
	ConstInt* intValue;
	ConstBool* boolValue;
	std::string* name;
}
%token <intValue> INTEGER
%token <boolValue> BOOLEAN
%token <name> VAR BOOL INT BEG END
%token ASSIGN LSHIFT RSHIFT AND ELEMMUL SUM IF FOR FUN
%left AND
%left '+' '-'
%left '*' '/'
%right UMINUS
%type <node> expr appeal expr_sequence//args exprs

%destructor { delete $$; } <node>
%destructor { delete $$; } <intValue>
%destructor { delete $$; } <boolValue>
%destructor { delete $$; } <name>

%%

program:
		program sentence_sequence	
		| sentence	
		;
sentence_sequence:
		sentence_sequence sentence
		| sentence		
		;
sentence:
		declaration '\n'

		| assignment '\n'

		;
declaration:

		INT VAR '=' expr			{ 
											if(*$1 == "") {
															$$ = new Declare(t::VARINT,$2,$4,varTable);
														}
											else if(*$1 == "c") {
															$$ = new Declare(t::CONSTINT,$2,$4,varTable);	
														}
											else if(*$1 == "v") {
															$$ = new Declare(t::INTARR,$2,$4,varTable);
														}
											else if(*$1 == "cv") {
															$$ = new Declare(t::CONSTINTARR,$2,$4,varTable);
														}
											else if(*$1 == "m") {
															$$ = new Declare(t::INTMATRIX,$2,$4,varTable);
														}
											else if(*$1 == "cm") {
															$$ = new Declare(t::CONSTINTMATRIX,$2,$4,varTable);
														}
									}

		| BOOL VAR '=' expr			{ 
											if(*$1 == "") {
															$$ = new Declare(t::VARBOOL,$2,$4,varTable);
														}
											else if(*$1 == "c") {
															$$ = new Declare(t::CONSTBOOL,$2,$4,varTable);	
														}
											else if(*$1 == "v") {
															$$ = new Declare(t::BOOLARR,$2,$4,varTable);
														}
											else if(*$1 == "cv") {
															$$ = new Declare(t::CONSTBOOLARR,$2,$4,varTable);
														}
											else if(*$1 == "m") {
															$$ = new Declare(t::BOOLMATRIX,$2,$4,varTable);
														}
											else if(*$1 == "cm") {
															$$ = new Declare(t::CONSTBOOLMATRIX,$2,$4,varTable);
														}
								}

		;


assignment:
		VAR ASSIGN expr		{ $$ = new Assign($1, $3, varTable); }

		| appeal ASSIGN expr	{ $$ = new Assign($1, $3, varTable);  }

		;

expr:

		INTEGER							{ $$ = $1; }

		| BOOLEAN						{ $$ = $1; }

		| VAR							{
											try{
												$$ = varTable.at(*$1)->clone();
											}
											catch(std::exception& ex){
												//...
											}
										}

		| appeal						{ $$ = $1->clone(); $1->dump(); delete $1;}
		
		| '-' expr %prec UMINUS			{ 
											try{
												$$ = minus($2);
												delete $2;
											}
											catch(std::exception& ex){
												//...
											}
										}

		| '{' expr_sequence '}'			{ $$ = $2; }
		
		| expr '+' expr					{  $$ = new Add($1,$3); }

		| expr '-' expr					{ $$ = new Subtract($1,$3); }

		| '!' expr						{ $$ = new Not($2); }

		| expr '*' expr					{ $$ = new MatrixMult($1,$3); }

		| expr ELEMMUL expr				{ $$ = new ElemMult($1,$3); }

		| SUM '(' expr ')'				{ $$ = new Sum($3); }

		| expr '\''						{ $$ = new Transposition($1); }

		| expr LSHIFT					{ $$ = new Shift($1,true); }

		| expr RSHIFT					{ $$ = new Shift($1,false); }

		| expr AND expr					{ $$ = new And($1,$3); }

		| expr '>' expr					{ $$ = new Compare($1,$3,true); }

		| expr '<' expr					{ $$ = new Compare($1,$3,false); }

appeal:

		VAR '(' expr ',' expr ')'		{ $$ = new Appeal($1, $3, $5, varTable, APPEAL::COORDINATES); }

		| VAR '(' expr ',' colon ')'	{ $$ = new Appeal($1, $3, nullptr, varTable, APPEAL::COLUMNS); }

		| VAR '(' colon ',' expr ')'	{ $$ = new Appeal($1, $5, nullptr, varTable, APPEAL::ROWS); }

		| VAR '(' expr ')'				{ $$ = new Appeal($1, $3, nullptr, varTable, APPEAL::LOGICAL); }

		;

colon:
		':'

		|

		;
expr_sequence:

		expr_sequence ',' expr		{ 
										try {
												addElementToContainer($1, $3);
												$$ = $1;
										}
										catch(std::exception& ex){
											//...
										}			
									}

		| expr						{ $$ = createContainer($1); }

		;
%%

void yyerror(const char* s) {
	std::cerr << s << std::endl;
}

int main(int argc, const char* argv) {
	fopen_s (&yyin, "appeal.txt", "r");
	if (!yyin)        
		yyin = stdin;
	yyparse();
	printVarTable(varTable);
	return 0;
}
