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
%type <node> program sentence_sequence sentence expr declaration expr_sequence //args exprs

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
															try{
																insertVar(t::VARINT, $2, $4->execute(), varTable);
																}
															catch(...){}
															break;
														}
											else if(*$1 == "c") {
															try{
																insertVar(t::CONSTINT, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "v") {
															try{
																insertVar(t::INTARR, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "cv") {
															try{
																insertVar(t::CONSTINTARR, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "m") {
															try{
																insertVar(t::INTMATRIX, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "cm") {
															try{
																insertVar(t::CONSTINTMATRIX, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
									}

		| BOOL VAR '=' expr			{ 
											if(*$1 == "") {
															try{
																insertVar(t::VARBOOL, $2, $4->execute(), varTable);
																}
															catch(...){}
															break;
														}
											else if(*$1 == "c") {
															try{
																insertVar(t::CONSTBOOL, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "v") {
															try{
																insertVar(t::BOOLARR, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "cv") {
															try{
																insertVar(t::CONSTBOOLARR, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "m") {
															try{
																insertVar(t::BOOLMATRIX, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
											else if(*$1 == "cm") {
															try{
																insertVar(t::CONSTBOOLMATRIX, $2, $4->execute(), varTable);
																}
															catch(...){} 
															break;
														}
								}

		;


assignment:
		VAR ASSIGN expr {
							Node* n3 = $3->execute();
							try {
								Node* var = varTable.at(*$1);
								Node* newVal = assignVar(var->type(), n3);
								delete var;
								varTable[*$1] = newVal;
							}
							catch(...){
								//...
							}
						}
		;

expr:

		INTEGER							{ $$ = $1; }

		| BOOLEAN						{ $$ = $1; }

		| '-' expr %prec UMINUS			{ 
											try{
												$$ = minus($2);
											}
											catch(std::exception& ex){
												//...
											}
										}

		| VAR							{
											try{
												$$ = varTable.at(*$1);
											}
											catch(std::exception& ex){
												//...
											}
										}

		| '{' expr_sequence '}'			{ $$ = $2->execute(); }

		| VAR '(' expr ',' expr ')'	{ 
										auto it = varTable.find(*$1);
										if(it != varTable.end()){
											if(dynamic_cast<ConstIntMatrix*>(it->second)){
												try {
													$$ = getIntValue(it->second, $3->execute(), $5->execute());		
												}
												catch(std::exception& ex){
													//...
												}
											}
											else if (dynamic_cast<ConstBoolMatrix*>(it->second)){
												try {
													$$ = getBoolValue(it->second, $3->execute(), $5->execute());		
												}
												catch(std::exception& ex){
													//...
												}
											}
										}
									}
		| VAR '(' expr ',' colon ')'	{
											auto it = varTable.find(*$1);
											if(it != varTable.end()){
												if(compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
													Node* p = $3->execute();
													if (castToInt(p)) {
														try {
															$$ = getVec(it->second,p,0);
														}
														catch(std::exception& ex) {
															//...
														}
													}
													else{
														if(dynamic_cast<ConstIntArray*>(p)){
															try {
																$$ = getMatrix(it->second,p,0);
															}
															catch(...){
																//... error!
															}
														}
													}
												}
											}
										}

		| VAR '(' colon ',' expr ')'	{
											auto it = varTable.find(*$1);
											if(it != varTable.end()){
												if(compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
													Node* p = $5->execute();
													auto i = castToInt(p);
													if (i) {
														try {
															$$ = getVec(it->second,p,1);
														}
														catch(std::exception& ex) {
															//...
														}
													}
													else{
														if(dynamic_cast<ConstIntArray*>(p)){
															try {
																$$ = getMatrix(it->second,p,1);
															}
															catch(...){
																//... error!
															}
														}
													}
												}
											}
										}

		| VAR '(' expr ')'				{
											auto it = varTable.find(*$1);
											if(it != varTable.end()){
												try {
													$$ = matrixFromLogical(it->second,$3->execute());
												}
												catch(...){
													//...
												}
											}
										}
		
		| expr '+' expr					{
											Node* n1 = $1->execute();
											Node* n3 = $3->execute();
											if(addable(n1, n3)) {
												$$ = new Add(n1,n3);
											}
											else{
												//...
											}
										}

		| expr '-' expr					{
											Node* n1 = $1->execute();
											Node* n3 = $3->execute();
											if(addable(n1, n3)) {
												$$ = new Subtract(n1,n3);
											}
											else{
												//...
											}
										}

		| '!' expr						{
											Node* n2 = $2->execute();
											if(compatible(t::CONSTBOOL, n2)) {
												$$ = new Not(n2);
											}
											else{
												//...
											}
										}

		| expr '*' expr					{
											Node* n1 = $1->execute();
											Node* n3 = $3->execute();
											if(compatible(t::CONSTINTMATRIX, n1, n3)) {
												$$ = new MatrixMult(n1,n3);
											}
										}

		| expr ELEMMUL expr				{
											Node* n1 = $1->execute();
											Node* n3 = $3->execute();
											if(compatible(t::CONSTINTMATRIX, n1, n3) || compatible(t::CONSTINTARR, n1, n3)) {
												$$ = new ElemMult(n1,n3);
											}
										}

		| SUM '(' expr ')'				{
											Node* n3 = $3->execute();
											if(compatible(t::CONSTINTMATRIX, n3) || compatible(t::CONSTINTARR, n3)) {
												$$ = new Sum(n3);
											}
										}

		| expr '\''				{
											Node* n1 = $1->execute();
											if(compatible(t::CONSTINTMATRIX, n1) || compatible(t::CONSTBOOLMATRIX, n1)) {
												$$ = new Transposition(n1);
											}
										}

		| expr LSHIFT			{
									Node* n1 = $1->execute();
									if(compatible(t::CONSTINTARR, n1) || compatible(t::CONSTBOOLARR, n1)) {
												$$ = new Shift(n1,true);
									}
								}

		| expr RSHIFT			{
									Node* n1 = $1->execute();
									if(compatible(t::CONSTINTARR, n1) || compatible(t::CONSTBOOLARR, n1)) {
												$$ = new Shift(n1,false);
									}
								}

		| expr AND expr			{
									Node* n1 = $1->execute();
									Node* n3 = $3->execute();
									if (compatible(t::CONSTBOOL, n1, n3)) {
										$$ = new And(n1,n3);
									}
								}

		| expr '>' expr			{
									Node* n1 = $1->execute();
									Node* n3 = $3->execute();
									if(compatible(t::CONSTINT, n1, n3)) {
										$$ = new Compare(n1,n3,true);
									}
								}

		| expr '<' expr			{
									Node* n1 = $1->execute();
									Node* n3 = $3->execute();
									if(compatible(t::CONSTINT, n1, n3)) {
										$$ = new Compare(n1,n3,false);
									}
								}

colon:
		':'
		|
		;
expr_sequence:

		expr_sequence ',' expr		{ 
										try {
												addElementToContainer($1, $3->execute());
												$$ = $1;
										}
										catch(std::exception& ex){
											//...
										}			
									}

		| expr						{ $$ = createContainer($1->execute()); }

		;
%%

void yyerror(const char* s) {
	std::cerr << s << std::endl;
}

int main(int argc, const char* argv) {
	fopen_s (&yyin, "operations.txt", "r");
	if (!yyin)        
		yyin = stdin;
	yyparse();
	printVarTable(varTable);
	return 0;
}
