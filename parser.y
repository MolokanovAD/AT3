%{
	#include <iostream>
	#include <memory>
	#include <map>
	#include <stack>
	#include "Types/Node.h"
	#include "Types/Variable.h"
	#include "Types/Bools/Bool.h"
	#include "Types/Ints/Int.h"
	#include "Types/Operations/Add.h"
	#include "Types/Operations/And.h"
	#include "Types/Operations/Appeal.h"
	#include "Types/Operations/Assign.h"
	#include "Types/Operations/Call.h"
	#include "Types/Operations/Compare.h"
	#include "Types/Operations/Declare.h"
	#include "Types/Operations/ElemMult.h"
	#include "Types/Operations/ExprSequence.h"
	#include "Types/Operations/For.h"
	#include "Types/Operations/Function.h"
	#include "Types/Operations/Id.h"
	#include "Types/Operations/If.h"
	#include "Types/Operations/MatrixMult.h"
	#include "Types/Operations/Negative.h"
	#include "Types/Operations/Not.h"
	#include "Types/Operations/Parameters.h"
	#include "Types/Operations/SentenceSequence.h"
	#include "Types/Operations/Shift.h"
	#include "Types/Operations/Subtract.h"
	#include "Types/Operations/Sum.h"
	#include "Types/Operations/Transposition.h"
	#include "Types/Robot/Exit.h"
	#include "Types/Robot/Move.h"
	#include "Types/Robot/Turn.h"
	#include "Types/Robot/Wall.h"
	#include "Types/Functions.h"

	std::vector<std::vector<char>> labyrinth;
	int x;
	int y;
	int dir;
	std::stack<std::map<std::string, Node*>*> callStack;
	std::stack<std::map<std::string, Function*>*> funStack;
	int yylex(void);
	bool errorFlag = false;
	void yyerror(const char*);
	extern FILE * yyin;
%}

%union {
	Node* node; 
	ConstInt* intValue;
	ConstBool* boolValue;
	std::string* name;
	int type;
}
%token <intValue> INTEGER 
%token <type> BOOL INT TURN
%token <boolValue> BOOLEAN
%token <name> VAR BEG END
%token ASSIGN LSHIFT RSHIFT AND ELEMMUL SUM IF FOR FUN MOVE WALL EXIT
%left AND
%left '+' '-'
%left '*' '/'
%right UMINUS
%type <type> type
%type <node> expr expr_sequence declaration assignment appeal sentence sentence_sequence if for parameter parameters return_value return_values function funcall

%destructor { delete $$; } <node>
%destructor { delete $$; } <intValue>
%destructor { delete $$; } <boolValue>
%destructor { delete $$;} <name>

%%

program:
		sentence_sequence	{
								if (!errorFlag) {
									funStack.push(new std::map<std::string, Function*>());
									callStack.push(new std::map<std::string, Node*>());
									try {
										$1->execute();
									} catch(std::exception& ex) {
										std::cout << ex.what() << std::endl;
									}
									printVarTable(callStack.top());
									freeStacks(&callStack,&funStack);
								}
							}

		;

sentence_sequence:
		sentence_sequence sentence		{ 
											if (!errorFlag) {
												dynamic_cast<SentenceSequence*>($1)->pushSentence($2);
												$$ = $1; 
											}
										}

		| sentence						{ if(!errorFlag) $$ = new SentenceSequence($1, $1->getLine()); }

		| sentence_sequence error '\n'  { errorFlag = true; std::cout << "Syntax error: line " << @2.first_line << std::endl; yyerrok; }

		| error '\n'					{ errorFlag = true; std::cout << "Syntax error: line " << @1.first_line << std::endl; yyerrok; }

		;

sentence:
		declaration '\n'			{ $$ = $1; }

		| assignment '\n'			{ $$ = $1; }

		| if '\n'					{ $$ = $1; }

		| for '\n'					{ $$ = $1; }

		| function '\n'				{ $$ = new Declare(dynamic_cast<Function*>($1)->getName(), &funStack, $1, $1->getLine()); }		/*functionTable.insert({dynamic_cast<Function*>($1)->getName(), dynamic_cast<Function*>($1)});*/

		| funcall '\n'				{ $$ = $1; }

		| TURN '\n'					{ $$ = new Turn($1+1, dir, @1.first_line); }

		;

function: 
		type VAR '=' FUN VAR '(' parameters ')' BEG '\n' sentence_sequence END			{ 
																							if(*$9 != "" || *$12 != "") {
																								//...
																							}
																							$$ = new Function(new Parameters(new Declare($1,*$2,&callStack, @2.first_line)), *$5, $7, $11, &callStack,@4.first_line);
																							delete $2; delete $5; delete $9; delete $12;
																						}
		
		| return_values '=' FUN VAR '(' parameters ')' BEG '\n' sentence_sequence END	{ 
																							if(*$8 != "" || *$11 != ""){
																								//...
																							}
																							$$ = new Function($1, *$4, $6, $10, &callStack,@3.first_line);
																							delete $4; delete $8; delete $11;
																						}

		| FUN VAR '(' parameters ')' BEG '\n' sentence_sequence END						{ 
																							if(*$6 != "" || *$9 != ""){
																								//...
																							}
																							$$ = new Function(new Parameters(@1.first_line), *$2, $4, $8, &callStack,@1.first_line);
																							delete $2; delete $6; delete $9;
																						}

		;

funcall:

		VAR expr_sequence			{ $$ = new Call(*$1, $2, &callStack, &funStack, @1.first_line); delete $1; }

		| VAR						{ $$ = new Call(*$1, new ExprSequence(@1.first_line), &callStack, &funStack, @1.first_line); }

		;
		
return_values:
				return_values ',' return_value		{ dynamic_cast<Parameters*>($1)->addParameter($3); $$ = $1; }

				| return_value						{ $$ = new Parameters($1,$1->getLine()); }

				;

return_value:
				type VAR						{ $$ = new Declare($1,*$2,&callStack, @2.first_line); delete $2; }
			
				;
		
parameters:
				parameters ',' parameter	{ dynamic_cast<Parameters*>($1)->addParameter($3); $$ = $1; }

				| parameter					{ $$ = new Parameters($1, $1->getLine()); }

				|							{ $$ = new Parameters(); }
		
				;

parameter:
				return_value			{ $$ = $1; }

				| declaration			{ $$ = $1; }

				;

declaration: 
		type VAR '=' expr			{ $$ = new Declare($1,*$2,$4,&callStack, @2.first_line);  delete $2;}

		;

type: 
		INT			{$$ = $1;}

		| BOOL		{$$ = $1;}
		
		;

assignment: 
		VAR ASSIGN expr				{ $$ = new Assign(*$1, $3, &callStack,@1.first_line); delete $1; }
		
		| appeal ASSIGN expr		{ $$ = new Assign($1, $3, &callStack,$1->getLine()); }

		;

expr: 
		INTEGER							{ $$ = $1; }

		| BOOLEAN						{ $$ = $1; }

		| VAR							{ $$ = new Id(*$1,&callStack,@1.first_line); delete $1; }

		| appeal						{ $$ = $1; }
		
		| '-' expr %prec UMINUS			{ $$ = new Negative($2, $2->getLine()); }

		| '{' expr_sequence '}'			{ $$ = $2; }
		
		| expr '+' expr					{ $$ = new Add($1,$3,$1->getLine()); }

		| expr '-' expr					{ $$ = new Subtract($1,$3,$1->getLine()); }

		| '!' expr						{ $$ = new Not($2,$2->getLine()); }

		| expr '*' expr					{ $$ = new MatrixMult($1,$3,$1->getLine()); }

		| expr ELEMMUL expr				{ $$ = new ElemMult($1,$3,$1->getLine()); }

		| SUM '(' expr ')'				{ $$ = new Sum($3,@1.first_line); }

		| expr '\''						{ $$ = new Transposition($1,$1->getLine()); }

		| expr LSHIFT					{ $$ = new Shift($1,true,$1->getLine()); }

		| expr RSHIFT					{ $$ = new Shift($1,false,$1->getLine()); }

		| expr AND expr					{ $$ = new And($1,$3,$1->getLine()); }

		| expr '>' expr					{ $$ = new Compare($1,$3,true,$1->getLine()); }

		| expr '<' expr					{ $$ = new Compare($1,$3,false,$1->getLine()); }

		| WALL							{ $$ = new Wall(labyrinth, x, y, dir, @1.first_line); }

		| EXIT							{ $$ = new Exit(labyrinth, x, y, dir, @1.first_line); }

		| MOVE '(' expr ')'				{ $$ = new Move($3, labyrinth, x, y, dir, @1.first_line); }

		;

appeal: 
		VAR '(' expr ',' expr ')'		{ $$ = new Appeal(*$1, $3, $5, &callStack, APPEAL::COORDINATES, @1.first_line); delete $1; }

		| VAR '(' expr ',' colon ')'	{ $$ = new Appeal(*$1, $3, &callStack, APPEAL::COLUMNS, @1.first_line); delete $1; }

		| VAR '(' colon ',' expr ')'	{ $$ = new Appeal(*$1, $5, &callStack, APPEAL::ROWS, @1.first_line); delete $1; }

		| VAR '(' expr ')'				{ $$ = new Appeal(*$1, $3, &callStack, APPEAL::LOGICAL, @1.first_line); delete $1; }

		;

colon:
		':'

		|

		;

if: 
		IF expr BEG '\n' sentence_sequence END  {
															if (*$3 == "for" || *$6 == "for") {
																//..
															}
															else
																$$ = new If($2, $5, @1.first_line);
															delete $3;
															delete $6;
														}

		;

for: 
		FOR VAR '=' expr ':' expr BEG '\n' sentence_sequence END	{
																				if (*$7 == "if" || *$10 == "if") {
																					//...
																				}
																				else
																					$$ = new For(*$2, $4, $6, $9, &callStack, @1.first_line);
																				delete $2;
																				delete $7;
																				delete $10;
																			}

expr_sequence: 
				expr_sequence ',' expr		{ dynamic_cast<ExprSequence*>($1)->pushExpr($3); $$ = $1; }

				| expr						{ $$ = new ExprSequence($1,$1->getLine()); }

				;
%%

void yyerror(const char* s) {
	std::cerr << s << std::endl;
}

int main(int argc, const char* argv) {
	try{
		labyrinth = parseMap("Programs/labyrinth.txt", x, y, dir);
	}
	catch(std::exception& ex){
		std::cout << ex.what();
	}
	fopen_s (&yyin, "Programs/algorithm.txt", "r");
	if (yyin)   
		yyparse();
	return 0;
}
