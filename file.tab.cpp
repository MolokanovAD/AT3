/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

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

/* Line 371 of yacc.c  */
#line 117 "file.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "file.tab.h".  */
#ifndef YY_YY_FILE_TAB_H_INCLUDED
# define YY_YY_FILE_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     BOOL = 259,
     INT = 260,
     TURN = 261,
     BOOLEAN = 262,
     VAR = 263,
     BEG = 264,
     END = 265,
     ASSIGN = 266,
     LSHIFT = 267,
     RSHIFT = 268,
     AND = 269,
     ELEMMUL = 270,
     SUM = 271,
     IF = 272,
     FOR = 273,
     FUN = 274,
     MOVE = 275,
     WALL = 276,
     EXIT = 277,
     UMINUS = 278
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 50 "parser.y"

	Node* node; 
	ConstInt* intValue;
	ConstBool* boolValue;
	std::string* name;
	int type;


/* Line 387 of yacc.c  */
#line 192 "file.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_FILE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 233 "file.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,     2,     2,    36,
      30,    31,    25,    23,    32,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      38,    29,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    17,    20,    23,
      26,    29,    32,    35,    38,    51,    63,    73,    76,    78,
      82,    84,    87,    91,    93,    94,    96,    98,   103,   105,
     107,   111,   115,   117,   119,   121,   123,   126,   130,   134,
     138,   141,   145,   149,   154,   157,   160,   163,   167,   171,
     175,   177,   179,   184,   191,   198,   205,   210,   212,   213,
     220,   231,   235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    43,    -1,    43,    -1,
      42,     1,    28,    -1,     1,    28,    -1,    50,    28,    -1,
      52,    28,    -1,    56,    28,    -1,    57,    28,    -1,    44,
      28,    -1,    45,    28,    -1,     6,    28,    -1,    51,     8,
      29,    19,     8,    30,    48,    31,     9,    28,    42,    10,
      -1,    46,    29,    19,     8,    30,    48,    31,     9,    28,
      42,    10,    -1,    19,     8,    30,    48,    31,     9,    28,
      42,    10,    -1,     8,    58,    -1,     8,    -1,    46,    32,
      47,    -1,    47,    -1,    51,     8,    -1,    48,    32,    49,
      -1,    49,    -1,    -1,    47,    -1,    50,    -1,    51,     8,
      29,    53,    -1,     5,    -1,     4,    -1,     8,    11,    53,
      -1,    54,    11,    53,    -1,     3,    -1,     7,    -1,     8,
      -1,    54,    -1,    24,    53,    -1,    33,    58,    34,    -1,
      53,    23,    53,    -1,    53,    24,    53,    -1,    35,    53,
      -1,    53,    25,    53,    -1,    53,    15,    53,    -1,    16,
      30,    53,    31,    -1,    53,    36,    -1,    53,    12,    -1,
      53,    13,    -1,    53,    14,    53,    -1,    53,    37,    53,
      -1,    53,    38,    53,    -1,    21,    -1,    22,    -1,    20,
      30,    53,    31,    -1,     8,    30,    53,    32,    53,    31,
      -1,     8,    30,    53,    32,    55,    31,    -1,     8,    30,
      55,    32,    53,    31,    -1,     8,    30,    53,    31,    -1,
      39,    -1,    -1,    17,    53,     9,    28,    42,    10,    -1,
      18,     8,    29,    53,    39,    53,     9,    28,    42,    10,
      -1,    58,    32,    53,    -1,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    94,   101,   103,   105,   110,   112,   114,
     116,   118,   120,   122,   127,   135,   143,   155,   157,   162,
     164,   169,   174,   176,   178,   183,   185,   190,   195,   197,
     202,   204,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   237,   239,   241,   243,
     245,   247,   249,   254,   256,   258,   260,   265,   267,   272,
     285,   297,   299
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "BOOL", "INT", "TURN",
  "BOOLEAN", "VAR", "BEG", "END", "ASSIGN", "LSHIFT", "RSHIFT", "AND",
  "ELEMMUL", "SUM", "IF", "FOR", "FUN", "MOVE", "WALL", "EXIT", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "'\\n'", "'='", "'('", "')'", "','",
  "'{'", "'}'", "'!'", "'\\''", "'>'", "'<'", "':'", "$accept", "program",
  "sentence_sequence", "sentence", "function", "funcall", "return_values",
  "return_value", "parameters", "parameter", "declaration", "type",
  "assignment", "expr", "appeal", "colon", "if", "for", "expr_sequence", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    43,    45,    42,    47,   278,    10,    61,
      40,    41,    44,   123,   125,    33,    39,    62,    60,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    44,    45,    45,    46,
      46,    47,    48,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    56,
      57,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     2,    12,    11,     9,     2,     1,     3,
       1,     2,     3,     1,     0,     1,     1,     4,     1,     1,
       3,     3,     1,     1,     1,     1,     2,     3,     3,     3,
       2,     3,     3,     4,     2,     2,     2,     3,     3,     3,
       1,     1,     4,     6,     6,     6,     4,     1,     0,     6,
      10,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    29,    28,     0,    18,     0,     0,     0,     0,
       0,     4,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     6,    13,    32,    33,    34,     0,     0,     0,
      50,    51,     0,    58,     0,     0,    62,    35,    17,     0,
       0,     0,     1,     0,     3,    11,    12,     0,     0,     7,
      21,     8,     0,     9,    10,    30,     0,     0,    36,    57,
       0,     0,     0,    40,    45,    46,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    24,     5,     0,
      19,     0,     0,    31,     0,     0,    56,    58,     0,    37,
      47,    42,    38,    39,    41,    48,    49,    61,     0,     0,
      25,     0,    23,    26,     0,     0,    21,     0,    27,    43,
      52,     0,     0,     0,     0,     0,     0,     0,    21,    24,
       0,    53,    54,    55,    59,     0,     0,    22,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    60,     0,     0,    15,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    15,   101,   102,
      16,    17,    18,    36,    37,    61,    20,    21,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
     437,   -19,  -115,  -115,   -10,   146,   175,    15,    21,    31,
       7,  -115,     8,    13,   -12,  -115,    20,    42,    26,    55,
      56,    59,  -115,  -115,  -115,  -115,    40,   175,    58,    60,
    -115,  -115,   175,    73,   175,   175,   328,  -115,    64,   189,
      62,    69,  -115,    74,  -115,  -115,  -115,    90,    34,  -115,
      63,  -115,   175,  -115,  -115,   328,   175,   175,    22,  -115,
     239,    79,   -13,   328,  -115,  -115,   175,   175,   175,   175,
     175,  -115,   175,   175,   175,    91,   175,    34,  -115,   112,
    -115,   113,   153,   328,   266,   270,  -115,    73,   175,  -115,
      92,   328,    88,    88,    22,   328,   328,   328,   437,   222,
    -115,    14,  -115,  -115,   114,    97,  -115,   123,   328,  -115,
    -115,   297,   102,   301,   353,   175,   125,    34,   108,    34,
     116,  -115,  -115,  -115,  -115,   206,   110,  -115,   175,    25,
      34,   122,   437,   133,    47,   437,   372,   124,   149,   391,
    -115,   437,   127,  -115,   410,   437,  -115,   429,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   -92,     4,  -115,  -115,  -115,   -45,  -114,    46,
     -75,   -44,  -115,    -5,     0,    72,  -115,  -115,   130
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      19,    39,   103,    80,    81,   129,   114,    -2,    43,    22,
      19,     2,     3,     4,    44,     5,   134,    47,    23,    74,
      48,    89,    55,    40,     6,     7,     8,    58,    60,    41,
      63,    42,   100,   104,    64,    65,    45,    67,     2,     3,
     136,    46,   103,   139,   103,   116,   117,    83,    49,   144,
      50,    84,    85,   147,    51,   103,   133,   117,    71,    72,
      73,    90,    91,    92,    93,    94,    52,    95,    96,    97,
      33,    99,   100,   104,   100,   104,    24,   108,   138,   117,
      25,    26,   111,   113,    53,   100,   104,    54,    56,    28,
      57,    76,    82,    29,    30,    31,    74,    32,    19,    77,
      64,    65,    78,    67,    64,    65,    34,    67,    35,    79,
     125,    88,    59,    70,    19,    68,    69,    70,    44,    98,
     105,   106,   118,   108,    71,    72,    73,   119,    71,    72,
      73,   120,    19,   122,   126,    19,    19,   128,   132,    19,
      44,    19,   137,    44,    19,    19,   130,    19,    44,    24,
     135,    44,   141,    25,    26,   145,    24,    27,   142,   112,
      25,    26,    28,   127,    62,     0,    29,    30,    31,    28,
      32,     0,   107,    29,    30,    31,    33,    32,    24,    34,
       0,    35,    25,    26,     0,     0,    34,     0,    35,     0,
       0,    28,     0,     0,     0,    29,    30,    31,    75,    32,
       0,    64,    65,    66,    67,     0,     0,     0,    34,     0,
      35,     0,    68,    69,    70,   131,     0,     0,    64,    65,
      66,    67,     0,     0,     0,    71,    72,    73,     0,    68,
      69,    70,     0,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    71,    72,    73,    68,    69,    70,     0,     0,
       0,    64,    65,    66,    67,     0,     0,     0,    71,    72,
      73,   115,    68,    69,    70,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,    71,    72,    73,    64,    65,
      66,    67,    64,    65,    66,    67,     0,     0,     0,    68,
      69,    70,     0,    68,    69,    70,     0,   109,     0,     0,
       0,   110,    71,    72,    73,     0,    71,    72,    73,    64,
      65,    66,    67,    64,    65,    66,    67,     0,     0,     0,
      68,    69,    70,     0,    68,    69,    70,     0,   121,     0,
       0,     0,   123,    71,    72,    73,     0,    71,    72,    73,
      64,    65,    66,    67,     0,     0,     0,     0,     0,     0,
       0,    68,    69,    70,    43,     0,     0,     2,     3,     4,
       0,     5,     0,   124,    71,    72,    73,     0,     0,     0,
       6,     7,     8,    43,     0,     0,     2,     3,     4,     0,
       5,     0,   140,     0,     0,     0,     0,     0,     0,     6,
       7,     8,    43,     0,     0,     2,     3,     4,     0,     5,
       0,   143,     0,     0,     0,     0,     0,     0,     6,     7,
       8,    43,     0,     0,     2,     3,     4,     0,     5,     0,
     146,     0,     0,     0,     0,     0,     0,     6,     7,     8,
      43,     0,     0,     2,     3,     4,     0,     5,     1,   148,
       0,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     6,     7,     8
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     6,    77,    48,    48,   119,    98,     0,     1,    28,
      10,     4,     5,     6,    10,     8,   130,    29,    28,    32,
      32,    34,    27,     8,    17,    18,    19,    32,    33,     8,
      35,     0,    77,    77,    12,    13,    28,    15,     4,     5,
     132,    28,   117,   135,   119,    31,    32,    52,    28,   141,
       8,    56,    57,   145,    28,   130,    31,    32,    36,    37,
      38,    66,    67,    68,    69,    70,    11,    72,    73,    74,
      30,    76,   117,   117,   119,   119,     3,    82,    31,    32,
       7,     8,    87,    88,    28,   130,   130,    28,    30,    16,
      30,    29,    29,    20,    21,    22,    32,    24,    98,    30,
      12,    13,    28,    15,    12,    13,    33,    15,    35,    19,
     115,    32,    39,    25,   114,    23,    24,    25,   114,    28,
       8,     8,     8,   128,    36,    37,    38,    30,    36,    37,
      38,     8,   132,    31,     9,   135,   136,    29,    28,   139,
     136,   141,     9,   139,   144,   145,    30,   147,   144,     3,
      28,   147,    28,     7,     8,    28,     3,    11,     9,    87,
       7,     8,    16,   117,    34,    -1,    20,    21,    22,    16,
      24,    -1,    19,    20,    21,    22,    30,    24,     3,    33,
      -1,    35,     7,     8,    -1,    -1,    33,    -1,    35,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,     9,    24,
      -1,    12,    13,    14,    15,    -1,    -1,    -1,    33,    -1,
      35,    -1,    23,    24,    25,     9,    -1,    -1,    12,    13,
      14,    15,    -1,    -1,    -1,    36,    37,    38,    -1,    23,
      24,    25,    -1,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    36,    37,    38,    23,    24,    25,    -1,    -1,
      -1,    12,    13,    14,    15,    -1,    -1,    -1,    36,    37,
      38,    39,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    36,    37,    38,    12,    13,
      14,    15,    12,    13,    14,    15,    -1,    -1,    -1,    23,
      24,    25,    -1,    23,    24,    25,    -1,    31,    -1,    -1,
      -1,    31,    36,    37,    38,    -1,    36,    37,    38,    12,
      13,    14,    15,    12,    13,    14,    15,    -1,    -1,    -1,
      23,    24,    25,    -1,    23,    24,    25,    -1,    31,    -1,
      -1,    -1,    31,    36,    37,    38,    -1,    36,    37,    38,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,     1,    -1,    -1,     4,     5,     6,
      -1,     8,    -1,    10,    36,    37,    38,    -1,    -1,    -1,
      17,    18,    19,     1,    -1,    -1,     4,     5,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,     1,    -1,    -1,     4,     5,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,     1,    -1,    -1,     4,     5,     6,    -1,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
       1,    -1,    -1,     4,     5,     6,    -1,     8,     1,    10,
      -1,     4,     5,     6,    -1,     8,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     8,    17,    18,    19,    41,
      42,    43,    44,    45,    46,    47,    50,    51,    52,    54,
      56,    57,    28,    28,     3,     7,     8,    11,    16,    20,
      21,    22,    24,    30,    33,    35,    53,    54,    58,    53,
       8,     8,     0,     1,    43,    28,    28,    29,    32,    28,
       8,    28,    11,    28,    28,    53,    30,    30,    53,    39,
      53,    55,    58,    53,    12,    13,    14,    15,    23,    24,
      25,    36,    37,    38,    32,     9,    29,    30,    28,    19,
      47,    51,    29,    53,    53,    53,    31,    32,    32,    34,
      53,    53,    53,    53,    53,    53,    53,    53,    28,    53,
      47,    48,    49,    50,    51,     8,     8,    19,    53,    31,
      31,    53,    55,    53,    42,    39,    31,    32,     8,    30,
       8,    31,    31,    31,    10,    53,     9,    49,    29,    48,
      30,     9,    28,    31,    48,    28,    42,     9,    31,    42,
      10,    28,     9,    10,    42,    28,    10,    42,    10
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* INTEGER */
/* Line 1398 of yacc.c  */
#line 70 "parser.y"
        { delete ((*yyvaluep).intValue); };
/* Line 1398 of yacc.c  */
#line 1408 "file.tab.cpp"
        break;
      case 7: /* BOOLEAN */
/* Line 1398 of yacc.c  */
#line 71 "parser.y"
        { delete ((*yyvaluep).boolValue); };
/* Line 1398 of yacc.c  */
#line 1415 "file.tab.cpp"
        break;
      case 8: /* VAR */
/* Line 1398 of yacc.c  */
#line 72 "parser.y"
        { delete ((*yyvaluep).name); };
/* Line 1398 of yacc.c  */
#line 1422 "file.tab.cpp"
        break;
      case 9: /* BEG */
/* Line 1398 of yacc.c  */
#line 72 "parser.y"
        { delete ((*yyvaluep).name); };
/* Line 1398 of yacc.c  */
#line 1429 "file.tab.cpp"
        break;
      case 10: /* END */
/* Line 1398 of yacc.c  */
#line 72 "parser.y"
        { delete ((*yyvaluep).name); };
/* Line 1398 of yacc.c  */
#line 1436 "file.tab.cpp"
        break;
      case 42: /* sentence_sequence */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1443 "file.tab.cpp"
        break;
      case 43: /* sentence */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1450 "file.tab.cpp"
        break;
      case 44: /* function */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1457 "file.tab.cpp"
        break;
      case 45: /* funcall */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1464 "file.tab.cpp"
        break;
      case 46: /* return_values */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1471 "file.tab.cpp"
        break;
      case 47: /* return_value */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1478 "file.tab.cpp"
        break;
      case 48: /* parameters */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1485 "file.tab.cpp"
        break;
      case 49: /* parameter */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1492 "file.tab.cpp"
        break;
      case 50: /* declaration */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1499 "file.tab.cpp"
        break;
      case 52: /* assignment */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1506 "file.tab.cpp"
        break;
      case 53: /* expr */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1513 "file.tab.cpp"
        break;
      case 54: /* appeal */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1520 "file.tab.cpp"
        break;
      case 56: /* if */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1527 "file.tab.cpp"
        break;
      case 57: /* for */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1534 "file.tab.cpp"
        break;
      case 58: /* expr_sequence */
/* Line 1398 of yacc.c  */
#line 69 "parser.y"
        { delete ((*yyvaluep).node); };
/* Line 1398 of yacc.c  */
#line 1541 "file.tab.cpp"
        break;

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 77 "parser.y"
    {
								if (!errorFlag) {
									funStack.push(new std::map<std::string, Function*>());
									callStack.push(new std::map<std::string, Node*>());
									try {
										(yyvsp[(1) - (1)].node)->execute();
									} catch(std::exception& ex) {
										std::cerr << ex.what() << std::endl;
									}
									printVarTable(callStack.top());
									freeStacks(&callStack,&funStack);
								}
							}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    { 
											if (!errorFlag) {
												dynamic_cast<SentenceSequence*>((yyvsp[(1) - (2)].node))->pushSentence((yyvsp[(2) - (2)].node));
												(yyval.node) = (yyvsp[(1) - (2)].node); 
											}
										}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    { if(!errorFlag) (yyval.node) = new SentenceSequence((yyvsp[(1) - (1)].node), (yyvsp[(1) - (1)].node)->getLine()); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    { errorFlag = true; std::cout << "Syntax error: line " << (yylsp[(2) - (3)]).first_line << std::endl; yyerrok; }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    { errorFlag = true; std::cout << "Syntax error: line " << (yylsp[(1) - (2)]).first_line << std::endl; yyerrok; }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    { (yyval.node) = new Declare(dynamic_cast<Function*>((yyvsp[(1) - (2)].node))->getName(), &funStack, (yyvsp[(1) - (2)].node), (yyvsp[(1) - (2)].node)->getLine()); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    { (yyval.node) = new Turn((yyvsp[(1) - (2)].type)+1, dir, (yylsp[(1) - (2)]).first_line); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    { 
																							if(*(yyvsp[(9) - (12)].name) != "" || *(yyvsp[(12) - (12)].name) != "") {
																								//...
																							}
																							(yyval.node) = new Function(new Parameters(new Declare((yyvsp[(1) - (12)].type),*(yyvsp[(2) - (12)].name),&callStack, (yylsp[(2) - (12)]).first_line)), *(yyvsp[(5) - (12)].name), (yyvsp[(7) - (12)].node), (yyvsp[(11) - (12)].node), &callStack,(yylsp[(4) - (12)]).first_line);
																							delete (yyvsp[(2) - (12)].name); delete (yyvsp[(5) - (12)].name); delete (yyvsp[(9) - (12)].name); delete (yyvsp[(12) - (12)].name);
																						}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { 
																							if(*(yyvsp[(8) - (11)].name) != "" || *(yyvsp[(11) - (11)].name) != ""){
																								//...
																							}
																							(yyval.node) = new Function((yyvsp[(1) - (11)].node), *(yyvsp[(4) - (11)].name), (yyvsp[(6) - (11)].node), (yyvsp[(10) - (11)].node), &callStack,(yylsp[(3) - (11)]).first_line);
																							delete (yyvsp[(4) - (11)].name); delete (yyvsp[(8) - (11)].name); delete (yyvsp[(11) - (11)].name);
																						}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 143 "parser.y"
    { 
																							if(*(yyvsp[(6) - (9)].name) != "" || *(yyvsp[(9) - (9)].name) != ""){
																								//...
																							}
																							(yyval.node) = new Function(new Parameters((yylsp[(1) - (9)]).first_line), *(yyvsp[(2) - (9)].name), (yyvsp[(4) - (9)].node), (yyvsp[(8) - (9)].node), &callStack,(yylsp[(1) - (9)]).first_line);
																							delete (yyvsp[(2) - (9)].name); delete (yyvsp[(6) - (9)].name); delete (yyvsp[(9) - (9)].name);
																						}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 155 "parser.y"
    { (yyval.node) = new Call(*(yyvsp[(1) - (2)].name), (yyvsp[(2) - (2)].node), &callStack, &funStack, (yylsp[(1) - (2)]).first_line); delete (yyvsp[(1) - (2)].name); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    { (yyval.node) = new Call(*(yyvsp[(1) - (1)].name), new ExprSequence((yylsp[(1) - (1)]).first_line), &callStack, &funStack, (yylsp[(1) - (1)]).first_line); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    { dynamic_cast<Parameters*>((yyvsp[(1) - (3)].node))->addParameter((yyvsp[(3) - (3)].node)); (yyval.node) = (yyvsp[(1) - (3)].node); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    { (yyval.node) = new Parameters((yyvsp[(1) - (1)].node),(yyvsp[(1) - (1)].node)->getLine()); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    { (yyval.node) = new Declare((yyvsp[(1) - (2)].type),*(yyvsp[(2) - (2)].name),&callStack, (yylsp[(2) - (2)]).first_line); delete (yyvsp[(2) - (2)].name); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    { dynamic_cast<Parameters*>((yyvsp[(1) - (3)].node))->addParameter((yyvsp[(3) - (3)].node)); (yyval.node) = (yyvsp[(1) - (3)].node); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    { (yyval.node) = new Parameters((yyvsp[(1) - (1)].node), (yyvsp[(1) - (1)].node)->getLine()); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    { (yyval.node) = new Parameters(); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { (yyval.node) = new Declare((yyvsp[(1) - (4)].type),*(yyvsp[(2) - (4)].name),(yyvsp[(4) - (4)].node),&callStack, (yylsp[(2) - (4)]).first_line);  delete (yyvsp[(2) - (4)].name);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    { (yyval.node) = new Assign(*(yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].node), &callStack,(yylsp[(1) - (3)]).first_line); delete (yyvsp[(1) - (3)].name); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    { (yyval.node) = new Assign((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), &callStack,(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].intValue); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 211 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].boolValue); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    { (yyval.node) = new Id(*(yyvsp[(1) - (1)].name),&callStack,(yylsp[(1) - (1)]).first_line); delete (yyvsp[(1) - (1)].name); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    { (yyval.node) = new Negative((yyvsp[(2) - (2)].node), (yyvsp[(2) - (2)].node)->getLine()); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 219 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    { (yyval.node) = new Add((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 223 "parser.y"
    { (yyval.node) = new Subtract((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    { (yyval.node) = new Not((yyvsp[(2) - (2)].node),(yyvsp[(2) - (2)].node)->getLine()); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    { (yyval.node) = new MatrixMult((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    { (yyval.node) = new ElemMult((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    { (yyval.node) = new Sum((yyvsp[(3) - (4)].node),(yylsp[(1) - (4)]).first_line); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    { (yyval.node) = new Transposition((yyvsp[(1) - (2)].node),(yyvsp[(1) - (2)].node)->getLine()); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 235 "parser.y"
    { (yyval.node) = new Shift((yyvsp[(1) - (2)].node),true,(yyvsp[(1) - (2)].node)->getLine()); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 237 "parser.y"
    { (yyval.node) = new Shift((yyvsp[(1) - (2)].node),false,(yyvsp[(1) - (2)].node)->getLine()); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    { (yyval.node) = new And((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 241 "parser.y"
    { (yyval.node) = new Compare((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),true,(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 243 "parser.y"
    { (yyval.node) = new Compare((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),false,(yyvsp[(1) - (3)].node)->getLine()); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 245 "parser.y"
    { (yyval.node) = new Wall(labyrinth, x, y, dir, (yylsp[(1) - (1)]).first_line); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 247 "parser.y"
    { (yyval.node) = new Exit(labyrinth, x, y, dir, (yylsp[(1) - (1)]).first_line); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 249 "parser.y"
    { (yyval.node) = new Move((yyvsp[(3) - (4)].node), labyrinth, x, y, dir, (yylsp[(1) - (4)]).first_line); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    { (yyval.node) = new Appeal(*(yyvsp[(1) - (6)].name), (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node), &callStack, APPEAL::COORDINATES, (yylsp[(1) - (6)]).first_line); delete (yyvsp[(1) - (6)].name); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 256 "parser.y"
    { (yyval.node) = new Appeal(*(yyvsp[(1) - (6)].name), (yyvsp[(3) - (6)].node), &callStack, APPEAL::COLUMNS, (yylsp[(1) - (6)]).first_line); delete (yyvsp[(1) - (6)].name); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 258 "parser.y"
    { (yyval.node) = new Appeal(*(yyvsp[(1) - (6)].name), (yyvsp[(5) - (6)].node), &callStack, APPEAL::ROWS, (yylsp[(1) - (6)]).first_line); delete (yyvsp[(1) - (6)].name); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 260 "parser.y"
    { (yyval.node) = new Appeal(*(yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].node), &callStack, APPEAL::LOGICAL, (yylsp[(1) - (4)]).first_line); delete (yyvsp[(1) - (4)].name); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
    {
															if (*(yyvsp[(3) - (6)].name) == "for" || *(yyvsp[(6) - (6)].name) == "for") {
																std::cerr << "Warning: beginfor and endfor shouldn't be used with if, line " << (yylsp[(1) - (6)]).first_line << std::endl;
															}
															else
																(yyval.node) = new If((yyvsp[(2) - (6)].node), (yyvsp[(5) - (6)].node), (yylsp[(1) - (6)]).first_line);
															delete (yyvsp[(3) - (6)].name);
															delete (yyvsp[(6) - (6)].name);
														}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 285 "parser.y"
    {
																				if (*(yyvsp[(7) - (10)].name) == "if" || *(yyvsp[(10) - (10)].name) == "if") {
																					std::cerr << "Warning: beginif and endif shouldn't be used with for, line " << (yylsp[(1) - (10)]).first_line << std::endl;
																				}
																				else
																					(yyval.node) = new For(*(yyvsp[(2) - (10)].name), (yyvsp[(4) - (10)].node), (yyvsp[(6) - (10)].node), (yyvsp[(9) - (10)].node), &callStack, (yylsp[(1) - (10)]).first_line);
																				delete (yyvsp[(2) - (10)].name);
																				delete (yyvsp[(7) - (10)].name);
																				delete (yyvsp[(10) - (10)].name);
																			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 297 "parser.y"
    { dynamic_cast<ExprSequence*>((yyvsp[(1) - (3)].node))->pushExpr((yyvsp[(3) - (3)].node)); (yyval.node) = (yyvsp[(1) - (3)].node); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 299 "parser.y"
    { (yyval.node) = new ExprSequence((yyvsp[(1) - (1)].node),(yyvsp[(1) - (1)].node)->getLine()); }
    break;


/* Line 1792 of yacc.c  */
#line 2263 "file.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 302 "parser.y"


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
	fopen_s (&yyin, "Programs/appeal.txt", "r");
	if (yyin)   
		yyparse();
	return 0;
}