/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ENDF = 0,
     ABSTRACT = 258,
     ANNOTATION = 259,
     BOOLEAN = 260,
     BREAK = 261,
     BYTE = 262,
     BYVALUE = 263,
     CASE = 264,
     CAST = 265,
     CATCH = 266,
     CHAR = 267,
     CLASS = 268,
     CONST = 269,
     CONTINUE = 270,
     DEFAULT = 271,
     DO = 272,
     DOUBLE = 273,
     ELSE = 274,
     EXTENDS = 275,
     ERROR = 276,
     STATEMENT = 277,
     FINAL = 278,
     FINALLY = 279,
     FLOAT = 280,
     FOR = 281,
     FUTURE = 282,
     GENERIC = 283,
     GOTO = 284,
     IF = 285,
     IMPLEMENTS = 286,
     IMPORT = 287,
     INNER = 288,
     INSTANCEOF = 289,
     INT = 290,
     INTERFACE = 291,
     LONG = 292,
     NATIVE = 293,
     NEW = 294,
     JNULL = 295,
     OPERATOR = 296,
     OUTER = 297,
     PACKAGE = 298,
     PRIVATE = 299,
     PROTECTED = 300,
     PUBLIC = 301,
     PRINT = 302,
     REST = 303,
     RETURN = 304,
     STRICTFP = 305,
     SHORT = 306,
     STATIC = 307,
     SUPER = 308,
     SWITCH = 309,
     SYNCHRONIZED = 310,
     STRING = 311,
     THIS = 312,
     THROW = 313,
     THROWS = 314,
     TRANSIENT = 315,
     TRY = 316,
     VAR = 317,
     VOID = 318,
     VOLATILE = 319,
     METHOD = 320,
     WHILE = 321,
     OP_INC = 322,
     OP_DEC = 323,
     OP_SHL = 324,
     OP_SHR = 325,
     OP_SHRR = 326,
     OP_GE = 327,
     OP_LE = 328,
     OP_EQ = 329,
     OP_NE = 330,
     OP_LAND = 331,
     OP_LOR = 332,
     OP_DIM = 333,
     ASS_MUL = 334,
     ASS_DIV = 335,
     ASS_MOD = 336,
     ASS_ADD = 337,
     ASS_SUB = 338,
     ASS_SHL = 339,
     ASS_SHR = 340,
     ASS_SHRR = 341,
     ASS_AND = 342,
     ASS_XOR = 343,
     ASS_OR = 344,
     IDENTIFIER = 345,
     BOOLLIT = 346,
     FIELD = 347,
     INT_LITERAL = 348,
     LONG_LITERAL = 349,
     FLOAT_LITERAL = 350,
     CHAR_LITERAL = 351,
     STRING_LITERAL = 352,
     DOUBLE_LITERAL = 353,
     QualifiedNameId = 354,
     IfStmt = 355
   };
#endif
/* Tokens.  */
#define ENDF 0
#define ABSTRACT 258
#define ANNOTATION 259
#define BOOLEAN 260
#define BREAK 261
#define BYTE 262
#define BYVALUE 263
#define CASE 264
#define CAST 265
#define CATCH 266
#define CHAR 267
#define CLASS 268
#define CONST 269
#define CONTINUE 270
#define DEFAULT 271
#define DO 272
#define DOUBLE 273
#define ELSE 274
#define EXTENDS 275
#define ERROR 276
#define STATEMENT 277
#define FINAL 278
#define FINALLY 279
#define FLOAT 280
#define FOR 281
#define FUTURE 282
#define GENERIC 283
#define GOTO 284
#define IF 285
#define IMPLEMENTS 286
#define IMPORT 287
#define INNER 288
#define INSTANCEOF 289
#define INT 290
#define INTERFACE 291
#define LONG 292
#define NATIVE 293
#define NEW 294
#define JNULL 295
#define OPERATOR 296
#define OUTER 297
#define PACKAGE 298
#define PRIVATE 299
#define PROTECTED 300
#define PUBLIC 301
#define PRINT 302
#define REST 303
#define RETURN 304
#define STRICTFP 305
#define SHORT 306
#define STATIC 307
#define SUPER 308
#define SWITCH 309
#define SYNCHRONIZED 310
#define STRING 311
#define THIS 312
#define THROW 313
#define THROWS 314
#define TRANSIENT 315
#define TRY 316
#define VAR 317
#define VOID 318
#define VOLATILE 319
#define METHOD 320
#define WHILE 321
#define OP_INC 322
#define OP_DEC 323
#define OP_SHL 324
#define OP_SHR 325
#define OP_SHRR 326
#define OP_GE 327
#define OP_LE 328
#define OP_EQ 329
#define OP_NE 330
#define OP_LAND 331
#define OP_LOR 332
#define OP_DIM 333
#define ASS_MUL 334
#define ASS_DIV 335
#define ASS_MOD 336
#define ASS_ADD 337
#define ASS_SUB 338
#define ASS_SHL 339
#define ASS_SHR 340
#define ASS_SHRR 341
#define ASS_AND 342
#define ASS_XOR 343
#define ASS_OR 344
#define IDENTIFIER 345
#define BOOLLIT 346
#define FIELD 347
#define INT_LITERAL 348
#define LONG_LITERAL 349
#define FLOAT_LITERAL 350
#define CHAR_LITERAL 351
#define STRING_LITERAL 352
#define DOUBLE_LITERAL 353
#define QualifiedNameId 354
#define IfStmt 355




/* Copy the first part of user declarations.  */
#line 2 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"

	#include"global.h"
	#include"Scanner.h"
	#include"FollowSets.h"
	#include"ASTfiles.h"
	#include"SymbolTableFiles.h"
	#include"ASTgraphics.h"
	#include "Utils.h"
	#include"yaccActions.h"
	#include"WorkingWithFiles.h"

	int yylex(void);
	int yyparse();
	void yyerror(char *);
	ofstream tokenListening("tokenListening.txt",std::ios::out);
	FlexLexer * lexer;
	void skipFrom(int token);
	void skipFromHeaderErrors();
	void skipToClass();
	ofstream grammarListening;
	class Parser
	{
		public:
		int	parse()
		{
			return yyparse();
		}
	};

	Parser* p;
	JProject *project;
	JCompilationUnit* compilationUnit;
	stack<char*> previousModifiers;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 38 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
typedef union YYSTYPE {
	struct TokenInfo{
		char* tokenImage;
		int tokenLine;
		int tokenCol;
		class JClassDeclaration* classDeclaration;
		class JInterfaceDeclaration* interfaceDeclaration;
		class AccessProperty *accessProperty;
		class Type* type;
		class TypeName *typeName;
		class JVariableDeclaration *variableDeclaration;
		class JVariableDeclarator *variableDeclarator;
		class JFieldDeclaration *fieldDeclaration;
		class JMethodDeclaration *methodDeclaration;
		class JFormalParameter *formalParameter;
		class JExpression *expr;
		class JStatement *stmt;
		class JConstructorDeclaration *constructorDeclaration;
		class JInitializerDeclaration *initializerDeclaration;

		/* statements */
		class JIterationStatement *iterationStatement;
		class JEmptyStatement* emptyStatement;
		class JLabelStatement* labelStatement;
		class Printer *printStatement;
		class JExpressionStatement* expressionStatement;
		class JSelectionStatement* selectionStatement;
		class JJumpStatement* jumpStatement;
		class JGuardingStatement* guardingStatement;
		class CatchesList* catchesList;
		class JCatch *jCatch;

		/* Expressions */
		class JBinaryExpression *binaryExpr;

		/* Lists */
		class MemberList *memberList;
		class JAST *member;
		class JBlock* block;
		class ExpressionsList *expressionsList;
		class DeclaratorList *declaratorList;
		
		class StatementsList *stmtList;
		class ParameterList *parameterList;
		class ExprStmtsList *exprStmtsList;
		class TypeList* typeList;

		
		int property;
		int emptyDimsCount;

	}tokenInfo;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 377 "yacc.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 389 "yacc.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  527
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4425

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  106
/* YYNRULES -- Number of rules. */
#define YYNRULES  326
/* YYNRULES -- Number of states. */
#define YYNSTATES  536

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,     2,     2,     2,   118,   121,     2,
     101,   109,   105,   115,   102,   116,   104,   117,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   103,
     119,   108,   120,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   111,     2,   112,   122,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   106,   123,   107,   113,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    38,    40,
      43,    46,    50,    53,    56,    59,    61,    63,    65,    69,
      72,    74,    77,    79,    82,    84,    86,    88,    91,    94,
      98,   104,   106,   110,   115,   120,   124,   128,   133,   138,
     141,   147,   152,   157,   162,   166,   170,   174,   177,   181,
     184,   186,   189,   191,   193,   195,   197,   199,   201,   203,
     205,   207,   209,   211,   213,   216,   218,   221,   223,   226,
     229,   231,   233,   235,   237,   239,   241,   245,   248,   250,
     254,   256,   260,   262,   265,   269,   271,   275,   281,   286,
     291,   295,   301,   308,   316,   323,   328,   333,   337,   341,
     343,   347,   350,   354,   356,   359,   362,   364,   366,   368,
     373,   377,   381,   384,   391,   397,   403,   408,   413,   417,
     420,   424,   429,   431,   434,   438,   441,   443,   445,   449,
     452,   456,   460,   463,   466,   469,   471,   474,   476,   478,
     480,   484,   489,   491,   493,   496,   498,   500,   502,   504,
     506,   508,   513,   515,   518,   522,   525,   527,   533,   541,
     547,   553,   561,   569,   576,   585,   588,   590,   592,   595,
     597,   599,   601,   605,   609,   612,   616,   619,   623,   626,
     630,   636,   640,   644,   649,   651,   654,   657,   663,   668,
     671,   673,   675,   677,   679,   681,   685,   687,   689,   691,
     693,   695,   697,   699,   701,   703,   705,   707,   709,   711,
     716,   721,   725,   729,   733,   737,   741,   746,   750,   752,
     754,   756,   763,   771,   778,   786,   788,   790,   792,   794,
     798,   800,   804,   806,   808,   812,   816,   821,   826,   832,
     837,   842,   846,   850,   852,   855,   859,   861,   864,   866,
     868,   871,   874,   877,   880,   883,   885,   887,   890,   892,
     894,   896,   898,   900,   905,   910,   915,   917,   920,   923,
     925,   929,   933,   937,   939,   943,   947,   949,   953,   957,
     961,   963,   967,   971,   975,   979,   983,   985,   989,   993,
     995,   999,  1001,  1005,  1007,  1011,  1013,  1017,  1019,  1023,
    1025,  1031,  1033,  1037,  1039,  1041,  1043,  1045,  1047,  1049,
    1051,  1053,  1055,  1057,  1059,  1061,  1063
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     131,     0,    -1,   127,    -1,   127,   206,    -1,   129,    -1,
     138,    -1,   138,    -1,   128,   102,   138,    -1,     5,    -1,
      12,    -1,     7,    -1,    51,    -1,    35,    -1,    37,    -1,
      25,    -1,    18,    -1,    63,    -1,    56,    -1,   103,    -1,
     130,   103,    -1,   132,     0,    -1,   133,   136,   134,    -1,
     133,   136,    -1,   133,   134,    -1,   136,   134,    -1,   133,
      -1,   136,    -1,   134,    -1,    43,   138,   130,    -1,    43,
       1,    -1,   135,    -1,   134,   135,    -1,   139,    -1,   139,
     130,    -1,   140,    -1,   137,    -1,     1,    -1,   136,   137,
      -1,   136,     1,    -1,    32,   138,   130,    -1,    32,   138,
     104,   105,   130,    -1,    90,    -1,   138,   104,    90,    -1,
     140,   106,   145,   107,    -1,   140,   106,   145,     0,    -1,
     140,   106,   107,    -1,   140,   106,     0,    -1,   140,     1,
     145,   107,    -1,   140,     1,   145,     0,    -1,   140,   107,
      -1,   141,   143,    90,   164,   144,    -1,   141,   143,    90,
     164,    -1,   141,   143,    90,   144,    -1,   143,    90,   164,
     144,    -1,   141,   143,    90,    -1,   143,    90,   164,    -1,
     143,    90,   144,    -1,   143,    90,    -1,   141,   143,     1,
      -1,   143,     1,    -1,   142,    -1,   141,   142,    -1,     3,
      -1,    23,    -1,    46,    -1,    45,    -1,    44,    -1,    52,
      -1,    60,    -1,    64,    -1,    38,    -1,    55,    -1,    13,
      -1,    36,    -1,    31,   128,    -1,   146,    -1,   145,   146,
      -1,   147,    -1,   147,   130,    -1,   148,   103,    -1,   153,
      -1,   160,    -1,   162,    -1,   163,    -1,   139,    -1,     1,
      -1,   141,   126,   149,    -1,   126,   149,    -1,   150,    -1,
     149,   102,   150,    -1,   157,    -1,   157,   108,   151,    -1,
     229,    -1,   106,   107,    -1,   106,   152,   107,    -1,   151,
      -1,   152,   102,   151,    -1,   141,   126,   154,   158,   159,
      -1,   141,   126,   154,   159,    -1,   126,   154,   158,   159,
      -1,   126,   154,   159,    -1,   126,   154,   106,   168,     0,
      -1,   141,   126,   154,   106,   168,     0,    -1,   141,   126,
     154,   158,   106,   168,     0,    -1,   126,   154,   158,   106,
     168,     0,    -1,   157,   101,   155,   109,    -1,   157,   101,
     155,     1,    -1,   157,   101,   109,    -1,   157,   101,     1,
      -1,   156,    -1,   155,   102,   156,    -1,   126,   150,    -1,
      23,   126,   150,    -1,    90,    -1,   157,    78,    -1,    59,
     128,    -1,   166,    -1,   167,    -1,   103,    -1,   141,   161,
     158,   165,    -1,   141,   161,   165,    -1,   161,   158,   165,
      -1,   161,   165,    -1,   141,   161,   158,   106,   168,     0,
      -1,   141,   161,   106,   168,     0,    -1,   161,   158,   106,
     168,     0,    -1,   161,   106,   168,     0,    -1,    90,   101,
     155,   109,    -1,    90,   101,   109,    -1,    52,   166,    -1,
      52,   106,     0,    -1,    52,   106,   168,     0,    -1,   166,
      -1,   106,     0,    -1,   106,   168,     0,    -1,    20,   128,
      -1,   166,    -1,   167,    -1,   106,   168,   107,    -1,   106,
     107,    -1,     1,   168,   107,    -1,     1,   168,     0,    -1,
       1,   107,    -1,     1,     0,    -1,   106,     0,    -1,   169,
      -1,   168,   169,    -1,   170,    -1,   171,    -1,     1,    -1,
     126,   149,   103,    -1,    23,   126,   149,   103,    -1,   173,
      -1,   174,    -1,   175,   103,    -1,   176,    -1,   177,    -1,
     182,    -1,   183,    -1,   166,    -1,   172,    -1,    47,   101,
     229,   109,    -1,   103,    -1,    90,   110,    -1,     9,   230,
     110,    -1,    16,   110,    -1,   229,    -1,    30,   101,   229,
     109,   171,    -1,    30,   101,   229,   109,   171,    19,   171,
      -1,    54,   101,   229,   109,   166,    -1,    66,   101,   229,
     109,   171,    -1,    17,   171,    66,   101,   229,   109,   103,
      -1,    26,   101,   178,   179,   180,   109,   171,    -1,    26,
     101,   178,   179,   109,   171,    -1,    26,   101,   126,    90,
     110,   229,   109,   171,    -1,   181,   103,    -1,   170,    -1,
     103,    -1,   229,   103,    -1,   103,    -1,   181,    -1,   175,
      -1,   181,   102,   175,    -1,     6,    90,   103,    -1,     6,
     103,    -1,    15,    90,   103,    -1,    15,   103,    -1,    49,
     229,   103,    -1,    49,   103,    -1,    58,   229,   103,    -1,
      55,   101,   229,   109,   171,    -1,    61,   166,   187,    -1,
      61,   166,   184,    -1,    61,   166,   184,   187,    -1,   185,
      -1,   184,   185,    -1,   186,   166,    -1,    11,   101,   126,
      90,   109,    -1,    11,   101,   126,   109,    -1,    24,   166,
      -1,   138,    -1,   189,    -1,   198,    -1,   200,    -1,   190,
      -1,   101,   229,   109,    -1,   191,    -1,   192,    -1,   193,
      -1,   194,    -1,   195,    -1,   197,    -1,    93,    -1,    94,
      -1,    98,    -1,    95,    -1,    97,    -1,    96,    -1,    91,
      -1,   138,   111,   229,   112,    -1,   190,   111,   229,   112,
      -1,   189,   104,    90,    -1,   208,   104,    90,    -1,   138,
     104,    57,    -1,   138,   104,    13,    -1,   129,   104,    13,
      -1,   196,   101,   199,   109,    -1,   196,   101,   109,    -1,
     191,    -1,   198,    -1,   138,    -1,   189,   104,    39,    90,
     101,   109,    -1,   189,   104,    39,    90,   101,   199,   109,
      -1,   138,   104,    39,    90,   101,   109,    -1,   138,   104,
      39,    90,   101,   199,   109,    -1,    57,    -1,    53,    -1,
      40,    -1,   229,    -1,   199,   102,   229,    -1,   201,    -1,
     138,   104,   201,    -1,   203,    -1,   202,    -1,   203,   106,
     107,    -1,   202,   106,   107,    -1,   203,   106,   152,   107,
      -1,   202,   106,   145,   107,    -1,    39,   127,   101,   199,
     109,    -1,    39,   127,   101,   109,    -1,    39,   127,   204,
     206,    -1,    39,   127,   204,    -1,    39,   127,   206,    -1,
     205,    -1,   204,   205,    -1,   111,   229,   112,    -1,    78,
      -1,   206,    78,    -1,   188,    -1,   208,    -1,   207,    67,
      -1,   207,    68,    -1,    67,   209,    -1,    68,   209,    -1,
     212,   213,    -1,   210,    -1,   207,    -1,   211,   209,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   209,    -1,
     101,   214,   109,   213,    -1,   101,   215,   109,   213,    -1,
     101,   229,   109,   210,    -1,   129,    -1,   129,   206,    -1,
     138,   206,    -1,   213,    -1,   216,   105,   213,    -1,   216,
     117,   213,    -1,   216,   118,   213,    -1,   216,    -1,   217,
     115,   216,    -1,   217,   116,   216,    -1,   217,    -1,   218,
      69,   217,    -1,   218,    70,   217,    -1,   218,    71,   217,
      -1,   218,    -1,   219,   119,   218,    -1,   219,   120,   218,
      -1,   219,    73,   218,    -1,   219,    72,   218,    -1,   219,
      34,   126,    -1,   219,    -1,   220,    74,   219,    -1,   220,
      75,   219,    -1,   220,    -1,   221,   121,   220,    -1,   221,
      -1,   222,   122,   221,    -1,   222,    -1,   223,   123,   222,
      -1,   223,    -1,   224,    76,   223,    -1,   224,    -1,   225,
      77,   224,    -1,   225,    -1,   225,   124,   229,   110,   226,
      -1,   226,    -1,   209,   228,   227,    -1,   108,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,   227,    -1,   226,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   132,   132,   133,   137,   138,   142,   143,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   160,   161,
     165,   169,   170,   171,   172,   173,   174,   175,   179,   180,
     185,   186,   190,   191,   192,   196,   197,   198,   199,   203,
     204,   208,   209,   213,   214,   215,   216,   217,   218,   219,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     237,   238,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   255,   256,   260,   264,   265,   269,   270,   274,
     275,   276,   277,   278,   279,   280,   284,   285,   290,   291,
     295,   296,   300,   301,   302,   306,   307,   311,   312,   313,
     314,   315,   316,   317,   318,   322,   323,   324,   325,   329,
     330,   334,   335,   339,   340,   344,   348,   349,   350,   354,
     355,   356,   357,   358,   359,   360,   361,   365,   366,   370,
     371,   372,   376,   377,   378,   382,   386,   387,   392,   393,
     397,   398,   399,   400,   401,   405,   406,   410,   411,   412,
     416,   417,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   433,   437,   441,   442,   443,   447,   451,   452,   453,
     457,   458,   459,   460,   461,   465,   466,   467,   471,   472,
     476,   480,   481,   485,   486,   487,   488,   489,   490,   491,
     495,   496,   497,   498,   502,   503,   507,   511,   512,   516,
     520,   521,   525,   526,   527,   531,   532,   536,   537,   538,
     539,   540,   544,   545,   546,   547,   548,   549,   550,   553,
     554,   558,   559,   560,   561,   562,   566,   567,   571,   572,
     573,   577,   578,   579,   580,   584,   585,   586,   590,   591,
     595,   596,   600,   601,   602,   603,   604,   605,   609,   610,
     614,   615,   616,   620,   621,   625,   629,   630,   634,   635,
     639,   640,   644,   645,   646,   647,   651,   652,   656,   657,
     661,   662,   666,   667,   668,   669,   673,   674,   678,   682,
     683,   684,   685,   689,   690,   691,   695,   696,   697,   698,
     702,   703,   704,   705,   706,   707,   711,   712,   713,   717,
     718,   722,   723,   727,   728,   732,   733,   737,   738,   742,
     743,   747,   748,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,   767,   771
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "ENDF", "error", "$undefined", "ABSTRACT", "ANNOTATION", "BOOLEAN",
  "BREAK", "BYTE", "BYVALUE", "CASE", "CAST", "CATCH", "CHAR", "CLASS",
  "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "EXTENDS",
  "ERROR", "STATEMENT", "FINAL", "FINALLY", "FLOAT", "FOR", "FUTURE",
  "GENERIC", "GOTO", "IF", "IMPLEMENTS", "IMPORT", "INNER", "INSTANCEOF",
  "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "JNULL", "OPERATOR",
  "OUTER", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "PRINT", "REST",
  "RETURN", "STRICTFP", "SHORT", "STATIC", "SUPER", "SWITCH",
  "SYNCHRONIZED", "STRING", "THIS", "THROW", "THROWS", "TRANSIENT", "TRY",
  "VAR", "VOID", "VOLATILE", "METHOD", "WHILE", "OP_INC", "OP_DEC",
  "OP_SHL", "OP_SHR", "OP_SHRR", "OP_GE", "OP_LE", "OP_EQ", "OP_NE",
  "OP_LAND", "OP_LOR", "OP_DIM", "ASS_MUL", "ASS_DIV", "ASS_MOD",
  "ASS_ADD", "ASS_SUB", "ASS_SHL", "ASS_SHR", "ASS_SHRR", "ASS_AND",
  "ASS_XOR", "ASS_OR", "IDENTIFIER", "BOOLLIT", "FIELD", "INT_LITERAL",
  "LONG_LITERAL", "FLOAT_LITERAL", "CHAR_LITERAL", "STRING_LITERAL",
  "DOUBLE_LITERAL", "QualifiedNameId", "IfStmt", "'('", "','", "';'",
  "'.'", "'*'", "'{'", "'}'", "'='", "')'", "':'", "'['", "']'", "'~'",
  "'!'", "'+'", "'-'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'",
  "'?'", "$accept", "TypeSpecifier", "TypeName", "ClassNameList",
  "PrimitiveType", "SemiColons", "CompilationUnit", "ProgramFile",
  "PackageStatement", "TypeDeclarations", "TypeDeclarationOptSemi",
  "ImportStatements", "ImportStatement", "QualifiedName",
  "TypeDeclaration", "ClassHeader", "Modifiers", "Modifier", "ClassWord",
  "Interfaces", "FieldDeclarations", "FieldDeclarationOptSemi",
  "FieldDeclaration", "FieldVariableDeclaration", "VariableDeclarators",
  "VariableDeclarator", "VariableInitializer", "ArrayInitializers",
  "MethodDeclaration", "MethodDeclarator", "ParameterList", "Parameter",
  "DeclaratorName", "Throws", "MethodBody", "ConstructorDeclaration",
  "ConstructorDeclarator", "StaticInitializer", "NonStaticInitializer",
  "Extends", "AnyBlock", "Block", "WrongBlock",
  "LocalVariableDeclarationsAndStatements",
  "LocalVariableDeclarationOrStatement",
  "LocalVariableDeclarationStatement", "Statement", "PrintStatement",
  "EmptyStatement", "LabelStatement", "ExpressionStatement",
  "SelectionStatement", "IterationStatement", "ForInit", "ForExpr",
  "ForIncr", "ExpressionStatements", "JumpStatement", "GuardingStatement",
  "Catches", "Catch", "CatchHeader", "Finally", "PrimaryExpression",
  "NotJustName", "ComplexPrimary", "ComplexPrimaryNoParenthesis",
  "Literals", "ArrayAccess", "FieldAccess", "MethodCall", "MethodAccess",
  "NewInner", "SpecialName", "ArgumentList", "NewAllocationExpression",
  "PlainNewAllocationExpression", "ClassAllocationExpression",
  "ArrayAllocationExpression", "DimExprs", "DimExpr", "Dims",
  "PostfixExpression", "RealPostfixExpression", "UnaryExpression",
  "LogicalUnaryExpression", "LogicalUnaryOperator",
  "ArithmeticUnaryOperator", "CastExpression", "PrimitiveTypeExpression",
  "ClassTypeExpression", "MultiplicativeExpression", "AdditiveExpression",
  "ShiftExpression", "RelationalExpression", "EqualityExpression",
  "AndExpression", "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "AssignmentOperator",
  "Expression", "ConstantExpression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,    40,    44,    59,    46,    42,   123,   125,    61,    41,
      58,    91,    93,   126,    33,    43,    45,    47,    37,    60,
      62,    38,    94,   124,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     131,   132,   132,   132,   132,   132,   132,   132,   133,   133,
     134,   134,   135,   135,   135,   136,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   143,   143,   144,   145,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   151,   152,   152,   153,   153,   153,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   159,   159,   159,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   161,   162,
     162,   162,   163,   163,   163,   164,   165,   165,   166,   166,
     167,   167,   167,   167,   167,   168,   168,   169,   169,   169,
     170,   170,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   172,   173,   174,   174,   174,   175,   176,   176,   176,
     177,   177,   177,   177,   177,   178,   178,   178,   179,   179,
     180,   181,   181,   182,   182,   182,   182,   182,   182,   182,
     183,   183,   183,   183,   184,   184,   185,   186,   186,   187,
     188,   188,   189,   189,   189,   190,   190,   191,   191,   191,
     191,   191,   192,   192,   192,   192,   192,   192,   192,   193,
     193,   194,   194,   194,   194,   194,   195,   195,   196,   196,
     196,   197,   197,   197,   197,   198,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   201,   201,   202,   202,
     203,   203,   203,   204,   204,   205,   206,   206,   207,   207,
     208,   208,   209,   209,   209,   209,   210,   210,   211,   211,
     212,   212,   213,   213,   213,   213,   214,   214,   215,   216,
     216,   216,   216,   217,   217,   217,   218,   218,   218,   218,
     219,   219,   219,   219,   219,   219,   220,   220,   220,   221,
     221,   222,   222,   223,   223,   224,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   229,   230
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     2,     2,     1,     1,     1,     3,     2,
       1,     2,     1,     2,     1,     1,     1,     2,     2,     3,
       5,     1,     3,     4,     4,     3,     3,     4,     4,     2,
       5,     4,     4,     4,     3,     3,     3,     2,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     3,
       1,     3,     1,     2,     3,     1,     3,     5,     4,     4,
       3,     5,     6,     7,     6,     4,     4,     3,     3,     1,
       3,     2,     3,     1,     2,     2,     1,     1,     1,     4,
       3,     3,     2,     6,     5,     5,     4,     4,     3,     2,
       3,     4,     1,     2,     3,     2,     1,     1,     3,     2,
       3,     3,     2,     2,     2,     1,     2,     1,     1,     1,
       3,     4,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     4,     1,     2,     3,     2,     1,     5,     7,     5,
       5,     7,     7,     6,     8,     2,     1,     1,     2,     1,
       1,     1,     3,     3,     2,     3,     2,     3,     2,     3,
       5,     3,     3,     4,     1,     2,     2,     5,     4,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     3,     3,     3,     3,     4,     3,     1,     1,
       1,     6,     7,     6,     7,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     3,     3,     4,     4,     5,     4,
       4,     3,     3,     1,     2,     3,     1,     2,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     4,     1,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,    36,    62,    72,    63,     0,    73,    70,     0,    66,
      65,    64,    67,    71,    68,    69,     0,     0,     0,    27,
      30,     0,    35,    32,     0,     0,    60,     0,    41,     0,
      29,     0,     1,    20,    23,     0,    31,    38,    24,    37,
      18,    33,     0,     0,    49,    61,     0,    59,    57,     0,
      39,     0,    28,    21,    19,    85,     8,    10,     9,    15,
      14,    12,    13,    11,    67,    17,    16,    41,     0,     0,
       2,     4,     5,    84,     0,     0,     0,    75,    77,     0,
      80,    81,     0,    82,    83,   132,    46,    45,     0,    58,
      54,     0,     0,    56,    55,    42,     0,     0,   129,     0,
     133,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,     0,     0,   236,     0,     0,   235,     0,     0,
       0,     0,     0,    41,   218,   212,   213,   215,   217,   216,
     214,     0,   162,     0,   139,   268,   269,   270,   271,     0,
       4,   200,   159,     0,   145,   147,   148,   160,   152,   153,
       0,   155,   156,   157,   158,   258,   201,   204,   206,   207,
     208,   209,   210,     0,   211,   202,   203,   240,   243,   242,
     266,   259,   272,   265,     0,     0,   279,   283,   286,   290,
     296,   299,   301,   303,   305,   307,   309,   311,   325,   166,
     113,    87,    88,     0,    90,   256,     3,     0,     0,    48,
      47,    76,    78,    79,     0,     0,     0,     0,   122,   136,
     137,    44,    43,    52,    51,   135,     6,    74,    53,    40,
     130,     0,     0,   128,     0,     0,   109,     0,   184,     0,
     200,   272,   326,     0,     0,   186,   165,     0,     0,     0,
       0,     0,     0,   188,     0,     0,     0,     0,     0,     0,
       0,   262,   263,   163,   276,   200,     0,     0,     0,     0,
       0,    90,     0,     0,     0,   134,   138,   146,   154,     0,
       0,     0,     0,     0,   260,   261,     0,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   313,     0,
     267,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,     0,   100,   116,   117,
     114,     0,     0,   257,    86,     0,     0,     0,   120,   143,
     142,     0,   115,   144,     0,     0,   121,    50,     0,   131,
       0,   111,     0,   127,   183,   164,   185,     0,     0,   177,
       0,   176,   181,     0,     0,     0,     0,     0,   251,   253,
     252,     0,   187,     0,     0,   189,     0,     0,   192,   194,
       0,   191,     0,     0,   277,   278,     0,     0,   205,   150,
     225,   224,     0,   223,   241,     0,     0,   221,     0,   227,
       0,   238,   245,     0,     0,   244,    95,     0,    92,   222,
     312,   280,   281,   282,   284,   285,   287,   288,   289,   295,
     294,   293,   291,   292,   297,   298,   300,   302,   304,   306,
     308,     0,    89,     0,     0,    99,   108,   107,     0,    91,
       0,     0,    98,     0,     0,   119,   141,   140,   126,     0,
       7,   112,   110,     0,   151,   113,   179,     0,     0,     0,
     175,     0,   249,     0,     0,   254,   250,   161,     0,     0,
       0,   199,   195,   193,   196,     0,   205,   273,   274,   275,
      41,   219,     0,   220,     0,   226,   247,    93,     0,     0,
     246,     0,   101,     0,   106,   105,     0,     0,    97,   124,
       0,   125,     0,     0,     0,     0,   180,   178,   182,   167,
     248,   255,   169,   190,     0,   170,     0,     0,   239,    94,
      96,   310,   104,   102,     0,   123,     0,     0,   173,     0,
       0,     0,   198,   233,     0,   231,     0,   103,   171,     0,
     172,   168,   197,   234,   232,   174
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,   139,    70,   215,   229,    41,    16,    17,    18,    19,
      20,    21,    22,   230,    23,    24,    25,    26,    27,    93,
      76,    77,    78,    79,   260,   192,   396,   397,    80,   193,
     225,   226,   261,   207,   317,    81,    82,    83,    84,    94,
     208,   142,   210,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   353,   447,   495,   354,   153,   154,   368,
     369,   370,   371,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   390,   166,   167,   168,   169,   358,
     359,   196,   170,   171,   172,   173,   174,   175,   176,   256,
     257,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   289,   189,   233
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -341
static const short int yypact[] =
{
     399,  -341,  -341,  -341,  -341,   -18,  -341,  -341,    31,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,    89,    95,  4294,  2697,
    -341,  4321,  -341,     7,  3980,  2697,  -341,    34,  -341,    90,
    -341,   194,  -341,  -341,  2697,  4361,  -341,  -341,  2697,  -341,
    -341,    28,  4166,  3790,  -341,  -341,   100,  -341,   182,    -2,
      28,    85,    28,  2697,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,    43,  -341,  -341,    67,   624,   122,
     145,  -341,   142,  -341,    58,  4229,  3856,  -341,     7,   160,
    -341,  -341,    54,  -341,  -341,  -341,  -341,  -341,  3922,  -341,
     182,   -18,   -18,  -341,   242,  -341,     7,   746,  -341,  2892,
    -341,  -341,    19,  3557,    56,   165,  2611,  4060,   176,   181,
    4060,  -341,   183,  2988,  -341,   188,   199,  -341,  3557,   196,
     203,  3624,  3624,   214,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  3557,  -341,  2383,  -341,  -341,  -341,  -341,  -341,   122,
     205,   120,  -341,   863,  -341,  -341,  -341,  -341,  -341,  -341,
     209,  -341,  -341,  -341,  -341,  -341,   227,   195,   234,  -341,
    -341,  -341,  -341,   244,  -341,   252,  -341,  -341,   237,   255,
     247,   251,   385,  -341,  3624,  3557,  -341,    86,   202,   190,
     136,   245,   257,   236,   253,   291,    -1,  -341,  -341,  -341,
    -341,   270,  -341,    66,   -17,  -341,   304,   122,    76,  -341,
    -341,  -341,    28,  -341,   980,   -18,  1097,    78,  -341,  -341,
    -341,  -341,  -341,  -341,   242,   281,   142,   281,  -341,    28,
    -341,  1214,  4060,  -341,   122,    25,  -341,   283,  -341,   205,
     146,  -341,  -341,   274,   284,  -341,  -341,   325,   122,  2711,
    3557,   161,  3557,  -341,   289,  3557,  3557,   290,   219,  3557,
    3557,  -341,  -341,  -341,    26,   118,   285,   287,   292,  2499,
     239,   -12,   390,    72,  3557,  -341,  -341,  -341,  -341,     0,
    3557,  3055,  4038,  2778,  -341,  -341,   314,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  3557,
    -341,  -341,  3557,  3557,  3557,  3557,  3557,  3557,  3557,  3557,
    4060,  3557,  3557,  3557,  3557,  3557,  3557,  3557,  3557,  3557,
    3557,  3557,  3557,   122,  -341,  1097,    73,  -341,  -341,  -341,
    -341,   558,  3122,  -341,   270,    74,  1097,    79,  -341,  -341,
    -341,  1331,   281,  -341,  1448,  1097,  -341,  -341,   -18,  -341,
     122,  -341,   276,  -341,  -341,  -341,  -341,   306,   246,  -341,
     315,  -341,  -341,  3222,   249,   299,  3289,  3557,     4,  -341,
     304,   307,  -341,   311,   312,  -341,   322,   196,   219,  -341,
     196,  -341,   321,   323,   304,   304,  3557,  3557,  3691,  -341,
    -341,  -341,  4124,  -341,  -341,   301,   346,  -341,   327,  -341,
     131,  -341,  -341,  4102,  2883,  -341,  -341,   130,  -341,  -341,
    -341,  -341,  -341,  -341,    86,    86,   202,   202,   202,  -341,
     190,   190,   190,   190,   136,   136,   245,   257,   236,   253,
     291,   330,  -341,  1565,  1097,  -341,  -341,  -341,    49,  -341,
    1097,    80,  -341,  1682,  1097,  -341,  -341,  -341,  -341,  1799,
     142,  -341,  -341,  3557,  -341,   331,  -341,  3356,   344,  3557,
    -341,  2611,  -341,   140,   336,  -341,   304,  -341,   196,  2611,
    4060,  -341,  -341,  -341,  -341,  2611,  -341,  -341,  -341,  -341,
     348,  -341,   349,  -341,  3557,  -341,  -341,  -341,   167,  3122,
    -341,  3557,  -341,  1916,  -341,  -341,  2033,  1097,  -341,  -341,
    2150,  -341,   343,  3557,  2611,   347,   351,  -341,  -341,   439,
    -341,  -341,  -341,  -341,     8,  -341,  3423,  3490,  -341,  -341,
    -341,  -341,  -341,  -341,  2267,  -341,   357,   352,  -341,  2611,
    2611,   353,  -341,  -341,   156,  -341,   162,  -341,  -341,  2611,
    -341,  -341,  -341,  -341,  -341,  -341
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -341,   -34,  -106,   -64,    64,    22,  -341,  -341,  -341,   193,
      59,   457,   171,    -5,   -31,   -28,   -24,    33,    44,   -60,
     -37,   -71,  -341,  -341,   -49,  -193,  -298,    82,  -341,   282,
     168,   141,   -40,  -172,  -276,  -341,   411,  -341,  -341,   401,
    -171,   -20,  -180,   -90,    -6,   262,  -105,  -341,  -341,  -341,
    -229,  -341,  -341,  -341,  -341,  -341,    55,  -341,  -341,  -341,
     137,  -341,   138,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -340,  -341,   241,  -341,  -341,  -341,
     149,  -208,  -341,  -341,   235,   132,  -341,  -341,  -150,  -341,
    -341,    75,   -19,   -11,    69,   204,   207,   208,   206,   201,
    -341,  -101,   224,  -341,   250,  -341
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -231
static const short int yytable[] =
{
      29,   237,   232,    31,   241,   201,    88,   221,    69,    69,
     352,    73,    73,   319,    74,    74,   453,   201,    75,    75,
     191,   316,    85,    85,   429,   291,   327,   328,   217,   194,
     213,   341,    30,   360,   218,    47,   336,    72,    72,   386,
     425,   197,    69,   259,    98,    73,   374,   375,    74,   432,
     484,    50,    75,    52,    69,   204,    85,    73,    45,    42,
      74,   320,   209,   141,    75,   224,   320,   204,    85,    46,
      72,    72,    28,   238,   204,   204,   311,   204,    36,   204,
     204,   204,   195,    72,   321,   381,   216,   216,    95,    32,
     387,   322,   141,    36,    72,    33,   322,    36,   521,   248,
     202,    89,    72,    96,   195,    72,    71,    71,    45,   227,
      40,   382,    36,   205,   331,   357,   334,   522,   219,    46,
     422,    28,   228,   312,    48,   205,   255,   342,   141,   383,
     262,    54,   140,   205,   343,   205,   319,   267,   141,    71,
      71,   332,   401,   402,   403,   319,   234,   441,   324,    97,
     456,   342,    71,   431,   337,   488,   435,   194,   485,   235,
     206,   140,    95,    71,    43,    44,   524,   526,    99,   314,
     300,    71,   315,   318,    71,    95,   314,   314,   209,   424,
     430,   510,   326,   314,   335,   434,   487,   209,   340,   348,
      90,   292,    39,    40,    49,   254,   195,   140,    -5,   141,
     216,   141,    91,   293,   294,   350,    39,   140,   301,   302,
      -5,    34,   190,    92,    38,   267,   141,    72,   352,  -230,
     498,  -230,   263,   195,   263,   423,   467,   468,    53,   264,
     366,   264,   479,   474,   141,   393,   433,   480,    69,   195,
     475,    73,   474,   367,    74,   439,    51,  -230,    75,   500,
     263,   319,    85,   267,   141,   303,   304,   264,   474,   297,
     298,   299,   356,   203,   474,   533,   409,    72,   140,   479,
     140,   534,   357,    92,   509,   236,   241,   239,   406,   407,
     408,    56,   240,    57,   242,   140,    71,   224,    58,   245,
     410,   411,   412,   413,    59,    72,   318,    40,    51,   222,
     246,    60,   133,   140,   249,   318,   270,   209,   224,   262,
     141,    61,   268,    62,   274,   275,    72,   295,   296,   305,
     306,   141,   201,   140,   253,   267,   141,    63,   267,   141,
     141,   269,    65,   440,   483,  -228,    71,    72,   231,    66,
     486,   313,   379,   272,   490,   271,   499,   461,   313,   444,
     464,   449,   450,  -229,   503,   276,   251,   252,   308,    69,
     505,   273,    73,   244,    71,    74,    28,   310,   247,    75,
     404,   405,   313,    85,   414,   415,   309,    72,   307,   140,
     511,   258,   323,   338,   345,    71,   344,   346,    72,   518,
     140,   347,   362,   365,   376,   140,   377,   514,   140,   140,
       1,   378,     2,   380,   399,   445,    71,   443,   451,   290,
     231,   318,     3,   471,   530,   531,   457,   267,   141,   141,
     458,   459,     4,   460,   535,   141,   504,   267,   141,   141,
     465,     5,   466,   267,   141,     6,   472,     7,   502,   473,
     481,   493,     8,     9,    10,    11,    71,   497,   501,   506,
     507,    12,   516,   449,    13,    72,   519,    71,   520,    14,
     528,   529,   532,    15,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,    35,   478,   267,   141,   325,
     267,   141,   141,   442,   267,   141,   198,   140,   140,   428,
     355,   214,   361,   288,   140,   363,   364,   140,   140,   372,
     373,   351,   496,   140,   384,   462,   463,   455,   267,   141,
     469,   416,   420,   400,   385,   417,   419,   418,     0,     0,
     388,   391,     0,   398,    71,     0,     0,   231,   231,   231,
     231,   231,   231,   231,   231,     0,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   140,     0,     0,
     140,   140,     0,     0,   140,     0,     0,     0,     0,   426,
       0,     0,   421,    56,     0,    57,     0,     0,     0,     0,
      58,     0,   398,     0,     0,     0,    59,     0,   140,     0,
       0,   222,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    62,     0,     0,     0,     0,
       0,     0,     0,   448,     0,     0,   391,   454,     0,    63,
       0,   231,   231,     0,    65,     0,     0,     0,     0,     0,
       0,    66,     0,     0,   100,   101,     0,     0,     0,    56,
     102,    57,     0,   103,     0,     0,    58,     0,     0,   104,
     105,   106,    59,     0,   398,     0,     0,   107,    28,    60,
     108,     0,     0,     0,   109,     0,     0,     0,     0,    61,
       0,    62,     0,   110,   111,     0,     0,   427,     0,     0,
       0,   112,     0,   113,     0,    63,     0,   114,   115,   116,
      65,   117,   118,     0,     0,   119,     0,    66,     0,     0,
     120,   121,   122,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   231,   125,   126,   127,
     128,   129,   130,     0,   508,   131,     0,   132,     0,   398,
     133,   134,     0,     0,     0,     0,     0,   135,   136,   137,
     138,     0,     0,   517,     0,     0,   220,   101,     0,     0,
       0,    56,   102,    57,     0,   103,   391,   391,    58,     0,
       0,   104,   105,   106,    59,     0,     0,     0,     0,   107,
       0,    60,   108,     0,     0,     0,   109,     0,     0,     0,
       0,    61,     0,    62,     0,   110,   111,     0,     0,     0,
       0,     0,     0,   112,     0,   113,     0,    63,     0,   114,
     115,   116,    65,   117,   118,     0,     0,   119,     0,    66,
       0,     0,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,     0,   125,
     126,   127,   128,   129,   130,     0,     0,   131,     0,   132,
       0,     0,   133,   134,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   265,   101,     0,     0,     0,    56,   102,
      57,     0,   103,     0,     0,    58,     0,     0,   104,   105,
     106,    59,     0,     0,     0,     0,   107,     0,    60,   108,
       0,     0,     0,   109,     0,     0,     0,     0,    61,     0,
      62,     0,   110,   111,     0,     0,     0,     0,     0,     0,
     112,     0,   113,     0,    63,     0,   114,   115,   116,    65,
     117,   118,     0,     0,   119,     0,    66,     0,     0,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   124,     0,   125,   126,   127,   128,
     129,   130,     0,     0,   131,     0,   132,     0,     0,   133,
     266,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     329,   101,     0,     0,     0,    56,   102,    57,     0,   103,
       0,     0,    58,     0,     0,   104,   105,   106,    59,     0,
       0,     0,     0,   107,     0,    60,   108,     0,     0,     0,
     109,     0,     0,     0,     0,    61,     0,    62,     0,   110,
     111,     0,     0,     0,     0,     0,     0,   112,     0,   113,
       0,    63,     0,   114,   115,   116,    65,   117,   118,     0,
       0,   119,     0,    66,     0,     0,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,   127,   128,   129,   130,     0,
       0,   131,     0,   132,     0,     0,   133,   330,     0,     0,
       0,     0,     0,   135,   136,   137,   138,   333,   101,     0,
       0,     0,    56,   102,    57,     0,   103,     0,     0,    58,
       0,     0,   104,   105,   106,    59,     0,     0,     0,     0,
     107,     0,    60,   108,     0,     0,     0,   109,     0,     0,
       0,     0,    61,     0,    62,     0,   110,   111,     0,     0,
       0,     0,     0,     0,   112,     0,   113,     0,    63,     0,
     114,   115,   116,    65,   117,   118,     0,     0,   119,     0,
      66,     0,     0,   120,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   124,     0,
     125,   126,   127,   128,   129,   130,     0,     0,   131,     0,
     132,     0,     0,   133,   134,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   339,   101,     0,     0,     0,    56,
     102,    57,     0,   103,     0,     0,    58,     0,     0,   104,
     105,   106,    59,     0,     0,     0,     0,   107,     0,    60,
     108,     0,     0,     0,   109,     0,     0,     0,     0,    61,
       0,    62,     0,   110,   111,     0,     0,     0,     0,     0,
       0,   112,     0,   113,     0,    63,     0,   114,   115,   116,
      65,   117,   118,     0,     0,   119,     0,    66,     0,     0,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,     0,   125,   126,   127,
     128,   129,   130,     0,     0,   131,     0,   132,     0,     0,
     133,   266,     0,     0,     0,     0,     0,   135,   136,   137,
     138,   436,   101,     0,     0,     0,    56,   102,    57,     0,
     103,     0,     0,    58,     0,     0,   104,   105,   106,    59,
       0,     0,     0,     0,   107,     0,    60,   108,     0,     0,
       0,   109,     0,     0,     0,     0,    61,     0,    62,     0,
     110,   111,     0,     0,     0,     0,     0,     0,   112,     0,
     113,     0,    63,     0,   114,   115,   116,    65,   117,   118,
       0,     0,   119,     0,    66,     0,     0,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,     0,   125,   126,   127,   128,   129,   130,
       0,     0,   131,     0,   132,     0,     0,   133,   437,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   438,   101,
       0,     0,     0,    56,   102,    57,     0,   103,     0,     0,
      58,     0,     0,   104,   105,   106,    59,     0,     0,     0,
       0,   107,     0,    60,   108,     0,     0,     0,   109,     0,
       0,     0,     0,    61,     0,    62,     0,   110,   111,     0,
       0,     0,     0,     0,     0,   112,     0,   113,     0,    63,
       0,   114,   115,   116,    65,   117,   118,     0,     0,   119,
       0,    66,     0,     0,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
       0,   125,   126,   127,   128,   129,   130,     0,     0,   131,
       0,   132,     0,     0,   133,   266,     0,     0,     0,     0,
       0,   135,   136,   137,   138,   482,   101,     0,     0,     0,
      56,   102,    57,     0,   103,     0,     0,    58,     0,     0,
     104,   105,   106,    59,     0,     0,     0,     0,   107,     0,
      60,   108,     0,     0,     0,   109,     0,     0,     0,     0,
      61,     0,    62,     0,   110,   111,     0,     0,     0,     0,
       0,     0,   112,     0,   113,     0,    63,     0,   114,   115,
     116,    65,   117,   118,     0,     0,   119,     0,    66,     0,
       0,   120,   121,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,   124,     0,   125,   126,
     127,   128,   129,   130,     0,     0,   131,     0,   132,     0,
       0,   133,   266,     0,     0,     0,     0,     0,   135,   136,
     137,   138,   489,   101,     0,     0,     0,    56,   102,    57,
       0,   103,     0,     0,    58,     0,     0,   104,   105,   106,
      59,     0,     0,     0,     0,   107,     0,    60,   108,     0,
       0,     0,   109,     0,     0,     0,     0,    61,     0,    62,
       0,   110,   111,     0,     0,     0,     0,     0,     0,   112,
       0,   113,     0,    63,     0,   114,   115,   116,    65,   117,
     118,     0,     0,   119,     0,    66,     0,     0,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,     0,   125,   126,   127,   128,   129,
     130,     0,     0,   131,     0,   132,     0,     0,   133,   266,
       0,     0,     0,     0,     0,   135,   136,   137,   138,   491,
     101,     0,     0,     0,    56,   102,    57,     0,   103,     0,
       0,    58,     0,     0,   104,   105,   106,    59,     0,     0,
       0,     0,   107,     0,    60,   108,     0,     0,     0,   109,
       0,     0,     0,     0,    61,     0,    62,     0,   110,   111,
       0,     0,     0,     0,     0,     0,   112,     0,   113,     0,
      63,     0,   114,   115,   116,    65,   117,   118,     0,     0,
     119,     0,    66,     0,     0,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     124,     0,   125,   126,   127,   128,   129,   130,     0,     0,
     131,     0,   132,     0,     0,   133,   266,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   512,   101,     0,     0,
       0,    56,   102,    57,     0,   103,     0,     0,    58,     0,
       0,   104,   105,   106,    59,     0,     0,     0,     0,   107,
       0,    60,   108,     0,     0,     0,   109,     0,     0,     0,
       0,    61,     0,    62,     0,   110,   111,     0,     0,     0,
       0,     0,     0,   112,     0,   113,     0,    63,     0,   114,
     115,   116,    65,   117,   118,     0,     0,   119,     0,    66,
       0,     0,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,     0,   125,
     126,   127,   128,   129,   130,     0,     0,   131,     0,   132,
       0,     0,   133,   266,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   513,   101,     0,     0,     0,    56,   102,
      57,     0,   103,     0,     0,    58,     0,     0,   104,   105,
     106,    59,     0,     0,     0,     0,   107,     0,    60,   108,
       0,     0,     0,   109,     0,     0,     0,     0,    61,     0,
      62,     0,   110,   111,     0,     0,     0,     0,     0,     0,
     112,     0,   113,     0,    63,     0,   114,   115,   116,    65,
     117,   118,     0,     0,   119,     0,    66,     0,     0,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   124,     0,   125,   126,   127,   128,
     129,   130,     0,     0,   131,     0,   132,     0,     0,   133,
     266,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     515,   101,     0,     0,     0,    56,   102,    57,     0,   103,
       0,     0,    58,     0,     0,   104,   105,   106,    59,     0,
       0,     0,     0,   107,     0,    60,   108,     0,     0,     0,
     109,     0,     0,     0,     0,    61,     0,    62,     0,   110,
     111,     0,     0,     0,     0,     0,     0,   112,     0,   113,
       0,    63,     0,   114,   115,   116,    65,   117,   118,     0,
       0,   119,     0,    66,     0,     0,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,   127,   128,   129,   130,     0,
       0,   131,     0,   132,     0,     0,   133,   266,     0,     0,
       0,     0,     0,   135,   136,   137,   138,   527,   101,     0,
       0,     0,    56,   102,    57,     0,   103,     0,     0,    58,
       0,     0,   104,   105,   106,    59,     0,     0,     0,     0,
     107,     0,    60,   108,     0,     0,     0,   109,     0,     0,
       0,     0,    61,     0,    62,     0,   110,   111,     0,     0,
       0,     0,     0,     0,   112,     0,   113,     0,    63,     0,
     114,   115,   116,    65,   117,   118,     0,     0,   119,     0,
      66,     0,     0,   120,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   124,     0,
     125,   126,   127,   128,   129,   130,     0,     0,   131,     0,
     132,     0,     0,   133,   266,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   101,     0,     0,     0,    56,   102,
      57,     0,   103,     0,     0,    58,     0,     0,   104,   105,
     106,    59,     0,     0,     0,     0,   107,     0,    60,   108,
       0,     0,     0,   109,     0,     0,     0,     0,    61,     0,
      62,     0,   110,   111,     0,     0,     0,     0,     0,     0,
     112,     0,   113,     0,    63,     0,   114,   115,   116,    65,
     117,   118,     0,     0,   119,     0,    66,     0,     0,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   124,     0,   125,   126,   127,   128,
     129,   130,     0,     0,   131,     0,   132,     0,     0,   133,
     134,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     101,     0,     0,     0,    56,   102,    57,     0,   103,     0,
       0,    58,     0,     0,   104,   105,   106,    59,     0,     0,
       0,     0,   107,     0,    60,   108,     0,     0,     0,   109,
       0,     0,     0,     0,    61,     0,    62,     0,   110,   111,
       0,     0,     0,     0,     0,     0,   112,     0,   113,     0,
      63,     0,   114,   115,   116,    65,   117,   118,     0,     0,
     119,     0,    66,     0,     0,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     124,     0,   125,   126,   127,   128,   129,   130,     0,     0,
     131,     0,   132,     0,     0,   133,   266,     0,     0,     0,
       0,     0,   135,   136,   137,   138,    56,   102,    57,     0,
     103,     0,     0,    58,     0,     0,   104,   105,   106,    59,
       0,     0,     0,     0,     0,     0,    60,   108,     0,     0,
       0,   109,     0,     0,     0,     0,    61,     0,    62,     0,
     110,   111,     0,     0,     0,     0,     0,     0,   112,     0,
     113,     0,    63,     0,   114,   115,   116,    65,   117,   118,
       0,     0,   119,     0,    66,     0,     0,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,   123,   124,     0,   125,   126,   127,   128,   129,   130,
       3,     0,   131,     0,   132,     0,    56,   133,    57,     0,
       4,     0,     0,    58,   135,   136,   137,   138,     0,    59,
       0,     0,     0,     6,   107,     7,    60,     0,     0,     0,
       0,     9,    10,    11,     0,     0,    61,     0,    62,    12,
     110,   111,    13,     0,     0,     0,     0,    14,     0,     0,
       0,    15,    63,     0,   114,     0,     0,    65,   117,     0,
       0,     0,     0,     0,    66,     0,     0,     0,   121,   122,
       0,     0,     0,    56,     0,    57,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,    28,   124,    60,   125,   126,   127,   128,   129,   130,
       0,     0,   131,    61,   349,    62,     0,   110,   111,     0,
       0,     0,     0,     0,   135,   136,   137,   138,     0,    63,
       0,   114,     0,     0,    65,   117,     0,     0,     0,     0,
       0,    66,     0,     0,     0,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,   124,
       0,   125,   126,   127,   128,   129,   130,     0,     0,   131,
       0,     0,     0,     0,   394,   395,     0,     0,    56,     0,
      57,   135,   136,   137,   138,    58,     0,    56,     0,    57,
       0,    59,     0,     0,    58,     0,     0,     0,    60,     0,
      59,     0,     0,     0,     0,   222,     0,    60,    61,     0,
      62,     0,   110,   111,     0,     0,     0,    61,     0,    62,
       0,     0,     0,     0,    63,     0,   114,     0,     0,    65,
     117,     0,     0,    63,     0,     0,    66,     0,    65,     0,
     121,   122,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,   124,     0,   125,   126,   127,   128,
     129,   130,    28,     0,   131,     0,     0,     0,     0,   394,
     477,     0,     0,    56,     0,    57,   135,   136,   137,   138,
      58,   223,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    62,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,   114,     0,     0,    65,   117,     0,     0,     0,     0,
       0,    66,     0,     0,     0,   121,   122,     0,     0,     0,
      56,     0,    57,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,    28,   124,
      60,   125,   126,   127,   128,   129,   130,     0,     0,   131,
      61,   243,    62,     0,   110,   111,     0,     0,     0,     0,
       0,   135,   136,   137,   138,     0,    63,     0,   114,     0,
       0,    65,   117,     0,     0,     0,     0,     0,    66,     0,
       0,     0,   121,   122,     0,     0,     0,    56,     0,    57,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,    28,   124,    60,   125,   126,
     127,   128,   129,   130,     0,     0,   131,    61,     0,    62,
       0,   110,   111,     0,   389,     0,     0,     0,   135,   136,
     137,   138,     0,    63,     0,   114,     0,     0,    65,   117,
       0,     0,     0,     0,     0,    66,     0,     0,     0,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,   124,     0,   125,   126,   127,   128,   129,
     130,     0,     0,   131,     0,     0,     0,    56,   394,    57,
       0,     0,     0,     0,    58,   135,   136,   137,   138,     0,
      59,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    62,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,   114,     0,     0,    65,   117,
       0,     0,     0,     0,     0,    66,     0,     0,     0,   121,
     122,     0,     0,     0,    56,     0,    57,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,    28,   124,    60,   125,   126,   127,   128,   129,
     130,     0,     0,   131,    61,   446,    62,     0,   110,   111,
       0,     0,     0,     0,     0,   135,   136,   137,   138,     0,
      63,     0,   114,     0,     0,    65,   117,     0,     0,     0,
       0,     0,    66,     0,     0,     0,   121,   122,     0,     0,
       0,    56,     0,    57,     0,     0,     0,     0,    58,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,    28,
     124,    60,   125,   126,   127,   128,   129,   130,     0,     0,
     131,    61,     0,    62,     0,   110,   111,     0,   452,     0,
       0,     0,   135,   136,   137,   138,     0,    63,     0,   114,
       0,     0,    65,   117,     0,     0,     0,     0,     0,    66,
       0,     0,     0,   121,   122,     0,     0,     0,    56,     0,
      57,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,    28,   124,    60,   125,
     126,   127,   128,   129,   130,     0,     0,   131,    61,     0,
      62,     0,   110,   111,     0,   494,     0,     0,     0,   135,
     136,   137,   138,     0,    63,     0,   114,     0,     0,    65,
     117,     0,     0,     0,     0,     0,    66,     0,     0,     0,
     121,   122,     0,     0,     0,    56,     0,    57,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,    28,   124,    60,   125,   126,   127,   128,
     129,   130,     0,     0,   131,    61,     0,    62,     0,   110,
     111,     0,   523,     0,     0,     0,   135,   136,   137,   138,
       0,    63,     0,   114,     0,     0,    65,   117,     0,     0,
       0,     0,     0,    66,     0,     0,     0,   121,   122,     0,
       0,     0,    56,     0,    57,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
      28,   124,    60,   125,   126,   127,   128,   129,   130,     0,
       0,   131,    61,     0,    62,     0,   110,   111,     0,   525,
       0,     0,     0,   135,   136,   137,   138,     0,    63,     0,
     114,     0,     0,    65,   117,     0,     0,     0,     0,     0,
      66,     0,     0,     0,   121,   122,     0,     0,     0,    56,
       0,    57,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,    59,     0,     0,     0,     0,    28,   124,    60,
     125,   126,   127,   128,   129,   130,     0,     0,   131,    61,
       0,    62,     0,   110,   111,     0,     0,     0,     0,     0,
     135,   136,   137,   138,     0,    63,     0,   114,     0,     0,
      65,   117,     0,     0,     0,     0,     0,    66,     0,     0,
       0,   121,   122,     0,     0,     0,    56,     0,    57,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,    28,   124,    60,   125,   126,   127,
     128,   129,   130,     0,     0,   250,    61,     0,    62,     0,
     110,   111,     0,     0,     0,     0,     0,   135,   136,   137,
     138,     0,    63,     0,   114,     0,     0,    65,   117,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,   124,     0,   125,   126,   127,   128,   129,   130,
      86,    55,   250,     2,     0,    56,     0,    57,     0,     0,
       0,     0,    58,     3,   135,   136,     0,     0,    59,     0,
       0,     0,     0,     4,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     6,    62,     7,     0,
       0,     0,     0,     0,     9,    10,    11,     0,     0,     0,
       0,    63,    64,     0,     0,    13,    65,     0,     0,     0,
      14,     0,     0,    66,    15,     0,   199,    55,     0,     2,
       0,    56,     0,    57,     0,     0,     0,     0,    58,     3,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     4,
      67,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     6,    62,     7,     0,    68,    87,     0,     0,
       9,    10,    11,     0,     0,     0,     0,    63,    64,     0,
       0,    13,    65,     0,     0,     0,    14,     0,     0,    66,
      15,     0,   211,    55,     0,     2,     0,    56,     0,    57,
       0,     0,     0,     0,    58,     3,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     4,    67,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     6,    62,
       7,     0,    68,   200,     0,     0,     9,    10,    11,     0,
       0,     0,     0,    63,    64,     0,     0,    13,    65,     0,
     -34,    42,    14,   -34,     0,    66,    15,     0,     0,     0,
       0,     0,     0,   -34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -34,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,   -34,     0,   -34,     0,
       0,     0,     0,     0,   -34,   -34,   -34,     0,    68,   212,
       0,     0,   -34,     0,     0,   -34,     0,     0,     0,    55,
     -34,     2,     0,    56,   -34,    57,     0,     0,     0,     0,
      58,     3,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     4,     0,    60,     0,    56,     0,    57,     0,     0,
       0,     0,    58,    61,     6,    62,     7,     0,    59,     0,
       0,     0,     9,    10,    11,    60,    43,    44,     0,    63,
      64,     0,     0,    13,    65,    61,     0,    62,    14,     0,
       0,    66,    15,    55,     0,     2,     0,    56,     0,    57,
       0,    63,     0,     0,    58,     3,    65,     0,     0,     0,
      59,     0,     0,    66,     0,     4,     0,    60,    67,    56,
       0,    57,     0,     0,     0,     0,    58,    61,     6,    62,
       7,     0,    59,     0,    68,   392,     9,    10,    11,    60,
      28,     0,     0,    63,    64,     0,     0,    13,    65,    61,
       0,    62,    14,     0,     0,    66,    15,    55,     0,     2,
       0,    56,     0,    57,     0,    63,     0,     0,    58,     3,
      65,     0,     0,     0,    59,     0,     0,    66,     0,     4,
       0,    60,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     6,    62,     7,     0,     0,     0,    68,   476,
       9,    10,    11,     0,   470,     0,     0,    63,    64,     0,
       0,    13,    65,     0,     0,     0,    14,     0,     0,    66,
      15,     0,     2,     0,    56,     0,    57,     0,     0,     0,
       0,    58,     3,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     4,     0,    60,     0,    67,     0,     0,     0,
       0,     0,     0,     0,    61,     6,    62,     7,     0,     0,
       0,     0,    68,     9,    10,    11,     0,     0,     0,     0,
      63,    12,     0,     0,    13,    65,     0,     0,     0,    14,
       0,     0,    66,    15,   -25,     1,     0,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,    67,
       0,   -26,    37,     0,     2,     0,     5,     0,     0,     0,
       6,     0,     7,     0,     3,     0,     0,     0,     9,    10,
      11,     0,     0,     0,     4,     0,    12,     0,     0,    13,
       0,     0,     0,     5,    14,     0,     0,     6,    15,     7,
       0,   -22,    37,     0,     2,     9,    10,    11,     0,     0,
       0,     0,     0,    12,     3,     0,    13,     0,     0,     0,
       0,    14,     0,     0,     4,    15,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     9,    10,    11,     0,     0,
       0,     0,     0,    12,     0,     0,    13,     0,     0,     0,
       0,    14,     0,     0,     0,    15
};

static const short int yycheck[] =
{
       5,   106,   103,     8,   110,    76,    43,    97,    42,    43,
     239,    42,    43,   193,    42,    43,   356,    88,    42,    43,
      69,   193,    42,    43,   322,   175,   198,   198,    92,    69,
      90,   224,     1,   241,    94,     1,   207,    42,    43,    39,
     316,    75,    76,   133,    64,    76,   254,   255,    76,   325,
       1,    29,    76,    31,    88,     1,    76,    88,    25,     1,
      88,    78,    82,    68,    88,    99,    78,     1,    88,    25,
      75,    76,    90,   107,     1,     1,    77,     1,    19,     1,
       1,     1,    78,    88,   101,    13,    91,    92,    90,     0,
      90,   108,    97,    34,    99,     0,   108,    38,    90,   119,
      78,     1,   107,   105,    78,   110,    42,    43,    75,    90,
     103,    39,    53,    59,   204,   111,   206,   109,    96,    75,
     313,    90,   103,   124,    90,    59,   131,   102,   133,    57,
     104,   103,    68,    59,   109,    59,   316,   143,   143,    75,
      76,   205,   292,   293,   294,   325,    90,   340,   197,   106,
     358,   102,    88,   325,   214,   431,   327,   197,   109,   103,
     106,    97,    90,    99,   106,   107,   506,   507,   101,   103,
      34,   107,   106,   193,   110,    90,   103,   103,   198,   106,
     106,   479,   106,   103,   106,   106,   106,   207,   222,   238,
      90,   105,    21,   103,   104,   131,    78,   133,    78,   204,
     205,   206,    20,   117,   118,   239,    35,   143,    72,    73,
      90,    18,    90,    31,    21,   221,   221,   222,   447,   101,
     449,   101,   104,    78,   104,   315,   376,   377,    35,   111,
      11,   111,   102,   102,   239,   272,   326,   107,   272,    78,
     109,   272,   102,    24,   272,   335,   104,   101,   272,   109,
     104,   431,   272,   259,   259,   119,   120,   111,   102,    69,
      70,    71,   101,   103,   102,   109,   300,   272,   204,   102,
     206,   109,   111,    31,   107,   110,   382,   101,   297,   298,
     299,     5,   101,     7,   101,   221,   222,   321,    12,   101,
     301,   302,   303,   304,    18,   300,   316,   103,   104,    23,
     101,    25,   106,   239,   101,   325,   111,   327,   342,   104,
     315,    35,   103,    37,    67,    68,   321,   115,   116,    74,
      75,   326,   393,   259,   110,   331,   331,    51,   334,   334,
     335,   104,    56,   338,   424,   101,   272,   342,   103,    63,
     430,   102,   103,   106,   434,   101,   451,   367,   102,   103,
     370,   102,   103,   101,   459,   104,   121,   122,   122,   393,
     465,   106,   393,   113,   300,   393,    90,    76,   118,   393,
     295,   296,   102,   393,   305,   306,   123,   382,   121,   315,
     481,   131,    78,   102,   110,   321,   103,   103,   393,   494,
     326,    66,   103,   103,   109,   331,   109,   487,   334,   335,
       1,   109,     3,    13,    90,    90,   342,   101,   109,   174,
     175,   431,    13,   112,   519,   520,   109,   423,   423,   424,
     109,   109,    23,   101,   529,   430,   460,   433,   433,   434,
     109,    32,   109,   439,   439,    36,    90,    38,   458,   112,
     110,   110,    43,    44,    45,    46,   382,   103,   112,   101,
     101,    52,   109,   102,    55,   460,   109,   393,    19,    60,
     103,   109,   109,    64,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    18,   394,   483,   483,   197,
     486,   486,   487,   342,   490,   490,    75,   423,   424,   321,
     240,    90,   242,   108,   430,   245,   246,   433,   434,   249,
     250,   239,   447,   439,   263,   368,   368,   358,   514,   514,
     378,   307,   311,   289,   264,   308,   310,   309,    -1,    -1,
     270,   271,    -1,   273,   460,    -1,    -1,   292,   293,   294,
     295,   296,   297,   298,   299,    -1,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   483,    -1,    -1,
     486,   487,    -1,    -1,   490,    -1,    -1,    -1,    -1,     1,
      -1,    -1,   312,     5,    -1,     7,    -1,    -1,    -1,    -1,
      12,    -1,   322,    -1,    -1,    -1,    18,    -1,   514,    -1,
      -1,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,    -1,    -1,   356,   357,    -1,    51,
      -1,   376,   377,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,     0,     1,    -1,    -1,    -1,     5,
       6,     7,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,
      16,    17,    18,    -1,   394,    -1,    -1,    23,    90,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,    39,    40,    -1,    -1,   109,    -1,    -1,
      -1,    47,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,
      66,    67,    68,   443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,   481,    93,    94,    95,
      96,    97,    98,    -1,   474,   101,    -1,   103,    -1,   479,
     106,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    -1,   493,    -1,    -1,     0,     1,    -1,    -1,
      -1,     5,     6,     7,    -1,     9,   506,   507,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    61,    -1,    63,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,    -1,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,     0,     1,    -1,    -1,    -1,     5,     6,
       7,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,    -1,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
       0,     1,    -1,    -1,    -1,     5,     6,     7,    -1,     9,
      -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    61,    -1,    63,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,    -1,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,     0,     1,    -1,
      -1,    -1,     5,     6,     7,    -1,     9,    -1,    -1,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    -1,    61,    -1,
      63,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,    -1,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,     0,     1,    -1,    -1,    -1,     5,
       6,     7,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,    -1,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,     0,     1,    -1,    -1,    -1,     5,     6,     7,    -1,
       9,    -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    -1,    61,    -1,    63,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      -1,    -1,   101,    -1,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,     0,     1,
      -1,    -1,    -1,     5,     6,     7,    -1,     9,    -1,    -1,
      12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
      -1,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,     0,     1,    -1,    -1,    -1,
       5,     6,     7,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    49,    -1,    51,    -1,    53,    54,
      55,    56,    57,    58,    -1,    -1,    61,    -1,    63,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,   101,    -1,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,     0,     1,    -1,    -1,    -1,     5,     6,     7,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    51,    -1,    53,    54,    55,    56,    57,
      58,    -1,    -1,    61,    -1,    63,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,    -1,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,     0,
       1,    -1,    -1,    -1,     5,     6,     7,    -1,     9,    -1,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,
      51,    -1,    53,    54,    55,    56,    57,    58,    -1,    -1,
      61,    -1,    63,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,    -1,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,     0,     1,    -1,    -1,
      -1,     5,     6,     7,    -1,     9,    -1,    -1,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    61,    -1,    63,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,    -1,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,     0,     1,    -1,    -1,    -1,     5,     6,
       7,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,    -1,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
       0,     1,    -1,    -1,    -1,     5,     6,     7,    -1,     9,
      -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    61,    -1,    63,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,    -1,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,     0,     1,    -1,
      -1,    -1,     5,     6,     7,    -1,     9,    -1,    -1,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    -1,    61,    -1,
      63,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,    -1,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,     1,    -1,    -1,    -1,     5,     6,
       7,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    58,    -1,    -1,    61,    -1,    63,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,    -1,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
       1,    -1,    -1,    -1,     5,     6,     7,    -1,     9,    -1,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,
      51,    -1,    53,    54,    55,    56,    57,    58,    -1,    -1,
      61,    -1,    63,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,    -1,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,     5,     6,     7,    -1,
       9,    -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    -1,    61,    -1,    63,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      13,    -1,   101,    -1,   103,    -1,     5,   106,     7,    -1,
      23,    -1,    -1,    12,   113,   114,   115,   116,    -1,    18,
      -1,    -1,    -1,    36,    23,    38,    25,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    35,    -1,    37,    52,
      39,    40,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    64,    51,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,     5,    -1,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    90,    91,    25,    93,    94,    95,    96,    97,    98,
      -1,    -1,   101,    35,   103,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,    -1,    51,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
      -1,    -1,    -1,    -1,   106,   107,    -1,    -1,     5,    -1,
       7,   113,   114,   115,   116,    12,    -1,     5,    -1,     7,
      -1,    18,    -1,    -1,    12,    -1,    -1,    -1,    25,    -1,
      18,    -1,    -1,    -1,    -1,    23,    -1,    25,    35,    -1,
      37,    -1,    39,    40,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    51,    -1,    -1,    63,    -1,    56,    -1,
      67,    68,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    90,    -1,   101,    -1,    -1,    -1,    -1,   106,
     107,    -1,    -1,     5,    -1,     7,   113,   114,   115,   116,
      12,   109,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
       5,    -1,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    90,    91,
      25,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
      35,   103,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,    51,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,     5,    -1,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    90,    91,    25,    93,    94,
      95,    96,    97,    98,    -1,    -1,   101,    35,    -1,    37,
      -1,    39,    40,    -1,   109,    -1,    -1,    -1,   113,   114,
     115,   116,    -1,    51,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,    -1,    -1,    -1,     5,   106,     7,
      -1,    -1,    -1,    -1,    12,   113,   114,   115,   116,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,     5,    -1,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    90,    91,    25,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,    35,   103,    37,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,    -1,
      51,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,     5,    -1,     7,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    90,
      91,    25,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,    35,    -1,    37,    -1,    39,    40,    -1,   109,    -1,
      -1,    -1,   113,   114,   115,   116,    -1,    51,    -1,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,     5,    -1,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    90,    91,    25,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,    35,    -1,
      37,    -1,    39,    40,    -1,   109,    -1,    -1,    -1,   113,
     114,   115,   116,    -1,    51,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,     5,    -1,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    90,    91,    25,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,    35,    -1,    37,    -1,    39,
      40,    -1,   109,    -1,    -1,    -1,   113,   114,   115,   116,
      -1,    51,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,     5,    -1,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      90,    91,    25,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,    35,    -1,    37,    -1,    39,    40,    -1,   109,
      -1,    -1,    -1,   113,   114,   115,   116,    -1,    51,    -1,
      53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,     5,
      -1,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    90,    91,    25,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,    35,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,    -1,    51,    -1,    53,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,     5,    -1,     7,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    90,    91,    25,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,    35,    -1,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    51,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
       0,     1,   101,     3,    -1,     5,    -1,     7,    -1,    -1,
      -1,    -1,    12,    13,   113,   114,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    -1,    -1,    63,    64,    -1,     0,     1,    -1,     3,
      -1,     5,    -1,     7,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      90,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    -1,   106,   107,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    -1,    -1,    63,
      64,    -1,     0,     1,    -1,     3,    -1,     5,    -1,     7,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    23,    90,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    -1,   106,   107,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,
       0,     1,    60,     3,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    -1,   106,   107,
      -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,     1,
      60,     3,    -1,     5,    64,     7,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    23,    -1,    25,    -1,     5,    -1,     7,    -1,    -1,
      -1,    -1,    12,    35,    36,    37,    38,    -1,    18,    -1,
      -1,    -1,    44,    45,    46,    25,   106,   107,    -1,    51,
      52,    -1,    -1,    55,    56,    35,    -1,    37,    60,    -1,
      -1,    63,    64,     1,    -1,     3,    -1,     5,    -1,     7,
      -1,    51,    -1,    -1,    12,    13,    56,    -1,    -1,    -1,
      18,    -1,    -1,    63,    -1,    23,    -1,    25,    90,     5,
      -1,     7,    -1,    -1,    -1,    -1,    12,    35,    36,    37,
      38,    -1,    18,    -1,   106,   107,    44,    45,    46,    25,
      90,    -1,    -1,    51,    52,    -1,    -1,    55,    56,    35,
      -1,    37,    60,    -1,    -1,    63,    64,     1,    -1,     3,
      -1,     5,    -1,     7,    -1,    51,    -1,    -1,    12,    13,
      56,    -1,    -1,    -1,    18,    -1,    -1,    63,    -1,    23,
      -1,    25,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,   106,   107,
      44,    45,    46,    -1,    90,    -1,    -1,    51,    52,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    -1,    -1,    63,
      64,    -1,     3,    -1,     5,    -1,     7,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    25,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,   106,    44,    45,    46,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      -1,    -1,    63,    64,     0,     1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    90,
      -1,     0,     1,    -1,     3,    -1,    32,    -1,    -1,    -1,
      36,    -1,    38,    -1,    13,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    23,    -1,    52,    -1,    -1,    55,
      -1,    -1,    -1,    32,    60,    -1,    -1,    36,    64,    38,
      -1,     0,     1,    -1,     3,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    13,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    23,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,     3,    13,    23,    32,    36,    38,    43,    44,
      45,    46,    52,    55,    60,    64,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   142,   143,    90,   138,
       1,   138,     0,     0,   134,   136,   135,     1,   134,   137,
     103,   130,     1,   106,   107,   142,   143,     1,    90,   104,
     130,   104,   130,   134,   103,     1,     5,     7,    12,    18,
      25,    35,    37,    51,    52,    56,    63,    90,   106,   126,
     127,   129,   138,   139,   140,   141,   145,   146,   147,   148,
     153,   160,   161,   162,   163,   166,     0,   107,   145,     1,
      90,    20,    31,   144,   164,    90,   105,   106,   166,   101,
       0,     1,     6,     9,    15,    16,    17,    23,    26,    30,
      39,    40,    47,    49,    53,    54,    55,    57,    58,    61,
      66,    67,    68,    90,    91,    93,    94,    95,    96,    97,
      98,   101,   103,   106,   107,   113,   114,   115,   116,   126,
     129,   138,   166,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   182,   183,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   200,   201,   202,   203,
     207,   208,   209,   210,   211,   212,   213,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   229,
      90,   149,   150,   154,   157,    78,   206,   126,   161,     0,
     107,   146,   130,   103,     1,    59,   106,   158,   165,   166,
     167,     0,   107,   144,   164,   128,   138,   128,   144,   130,
       0,   168,    23,   109,   126,   155,   156,    90,   103,   129,
     138,   209,   226,   230,    90,   103,   110,   171,   126,   101,
     101,   127,   101,   103,   229,   101,   101,   229,   166,   101,
     101,   209,   209,   110,   129,   138,   214,   215,   229,   168,
     149,   157,   104,   104,   111,     0,   107,   169,   103,   104,
     111,   101,   106,   106,    67,    68,   104,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   108,   228,
     209,   213,   105,   117,   118,   115,   116,    69,    70,    71,
      34,    72,    73,   119,   120,    74,    75,   121,   122,   123,
      76,    77,   124,   102,   103,   106,   158,   159,   166,   167,
      78,   101,   108,    78,   149,   154,   106,   158,   165,     0,
     107,   168,   128,     0,   168,   106,   165,   144,   102,     0,
     126,   150,   102,   109,   103,   110,   103,    66,   149,   103,
     126,   170,   175,   178,   181,   229,   101,   111,   204,   205,
     206,   229,   103,   229,   229,   103,    11,    24,   184,   185,
     186,   187,   229,   229,   206,   206,   109,   109,   109,   103,
      13,    13,    39,    57,   201,   229,    39,    90,   229,   109,
     199,   229,   107,   145,   106,   107,   151,   152,   229,    90,
     227,   213,   213,   213,   216,   216,   217,   217,   217,   126,
     218,   218,   218,   218,   219,   219,   220,   221,   222,   223,
     224,   229,   150,   168,   106,   159,     1,   109,   155,   151,
     106,   158,   159,   168,   106,   165,     0,   107,     0,   168,
     138,   150,   156,   101,   103,    90,   103,   179,   229,   102,
     103,   109,   109,   199,   229,   205,   206,   109,   109,   109,
     101,   166,   185,   187,   166,   109,   109,   213,   213,   210,
      90,   112,    90,   112,   102,   109,   107,   107,   152,   102,
     107,   110,     0,   168,     1,   109,   168,   106,   159,     0,
     168,     0,   229,   110,   109,   180,   181,   103,   175,   171,
     109,   112,   166,   171,   126,   171,   101,   101,   229,   107,
     151,   226,     0,     0,   168,     0,   109,   229,   171,   109,
      19,    90,   109,   109,   199,   109,   199,     0,   103,   109,
     171,   171,   109,   109,   109,   171
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 132 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeSpecifier(1, yyvsp, yyval);;}
    break;

  case 3:
#line 133 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeSpecifier(2, yyvsp, yyval);;}
    break;

  case 4:
#line 137 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeName(1, yyvsp, yyval);;}
    break;

  case 5:
#line 138 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeName(2, yyvsp, yyval);;}
    break;

  case 6:
#line 142 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::classNameList(1, yyvsp, yyval);;}
    break;

  case 7:
#line 143 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::classNameList(2, yyvsp, yyval);;}
    break;

  case 8:
#line 147 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(1, yyvsp, yyval);;}
    break;

  case 9:
#line 148 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(2, yyvsp, yyval);;}
    break;

  case 10:
#line 149 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(3, yyvsp, yyval);;}
    break;

  case 11:
#line 150 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(4, yyvsp, yyval);;}
    break;

  case 12:
#line 151 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(5, yyvsp, yyval);;}
    break;

  case 13:
#line 152 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(6, yyvsp, yyval);;}
    break;

  case 14:
#line 153 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(7, yyvsp, yyval);;}
    break;

  case 15:
#line 154 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(8, yyvsp, yyval);;}
    break;

  case 16:
#line 155 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(9, yyvsp, yyval);;}
    break;

  case 17:
#line 156 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveType(10, yyvsp, yyval);;}
    break;

  case 20:
#line 165 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::compilationUnit(); YYACCEPT;;}
    break;

  case 21:
#line 169 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(1, yyvsp, compilationUnit);;}
    break;

  case 22:
#line 170 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(2, yyvsp, compilationUnit);;}
    break;

  case 23:
#line 171 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(3, yyvsp, compilationUnit);;}
    break;

  case 24:
#line 172 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(4, yyvsp, compilationUnit);;}
    break;

  case 25:
#line 173 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(5, yyvsp, compilationUnit);;}
    break;

  case 26:
#line 174 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(6, yyvsp, compilationUnit);;}
    break;

  case 27:
#line 175 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::programFile(7, yyvsp, compilationUnit);;}
    break;

  case 28:
#line 179 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::packageStatement(1, yyvsp, yyval); ;}
    break;

  case 29:
#line 180 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::packageStatement(2, yyvsp, yyval); yyerrok; skipFrom(PACKAGE); ;}
    break;

  case 30:
#line 185 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::typeDeclarations(1,yyvsp, compilationUnit, previousModifiers); skipToClass();;}
    break;

  case 31:
#line 186 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::typeDeclarations(2,yyvsp, compilationUnit, previousModifiers); skipToClass();;}
    break;

  case 32:
#line 190 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::typeDeclarationOptSemi(1, yyvsp, yyval); ;}
    break;

  case 33:
#line 191 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::typeDeclarationOptSemi(2, yyvsp, yyval); ;}
    break;

  case 34:
#line 192 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::typeDeclarationOptSemi(3, yyvsp, yyval); yyerror("syntax error, expecting  \'}\'");;}
    break;

  case 35:
#line 196 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::importStatements(1, yyvsp, compilationUnit);;}
    break;

  case 36:
#line 197 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::importStatements(2, yyvsp, compilationUnit); yyerrok; yyclearin;;}
    break;

  case 37:
#line 198 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::importStatements(3, yyvsp, compilationUnit);;}
    break;

  case 38:
#line 199 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::importStatements(4, yyvsp, compilationUnit); yyerrok; yyclearin;;}
    break;

  case 39:
#line 203 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::importStatement(1, yyvsp, yyval);;}
    break;

  case 40:
#line 204 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::importStatement(2, yyvsp, yyval);;}
    break;

  case 41:
#line 208 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::QualifiedName(1, yyvsp, yyval);;}
    break;

  case 42:
#line 209 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::QualifiedName(2, yyvsp, yyval);;}
    break;

  case 43:
#line 213 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(1, yyvsp, yyval); ;}
    break;

  case 44:
#line 214 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(2, yyvsp, yyval);  yyerror("syntax error, unexpected end of file, expecting \'}\'"); ;}
    break;

  case 45:
#line 215 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(3, yyvsp, yyval);;}
    break;

  case 46:
#line 216 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(4, yyvsp, yyval); yyerror("syntax error, unexpected end of file, expecting \'}\'");;}
    break;

  case 47:
#line 217 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(5, yyvsp, yyval); yyerrok; ;}
    break;

  case 48:
#line 218 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(6, yyvsp, yyval); yyerrok; yyerror("syntax error, unexpected end of file, expecting \'}\'"); ;}
    break;

  case 49:
#line 219 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::typeDeclaration(7, yyvsp, yyval);;}
    break;

  case 50:
#line 224 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(1, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 51:
#line 225 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(2, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 52:
#line 226 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(3, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 53:
#line 227 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(4, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 54:
#line 228 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(5, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 55:
#line 229 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(6, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 56:
#line 230 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(7, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 57:
#line 231 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(8, yyvsp, yyval); skipFromHeaderErrors(); ;}
    break;

  case 58:
#line 232 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(9, yyvsp, yyval); yyerrok; skipFrom(CLASS); ;}
    break;

  case 59:
#line 233 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classHeader(10, yyvsp, yyval); yyerrok; skipFrom(CLASS); ;}
    break;

  case 60:
#line 237 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifiers(1, yyvsp, yyval);;}
    break;

  case 61:
#line 238 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifiers(2, yyvsp, yyval);;}
    break;

  case 62:
#line 242 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(1, yyvsp, yyval);;}
    break;

  case 63:
#line 243 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(2, yyvsp, yyval);;}
    break;

  case 64:
#line 244 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(3, yyvsp, yyval);;}
    break;

  case 65:
#line 245 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(4, yyvsp, yyval);;}
    break;

  case 66:
#line 246 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(5, yyvsp, yyval);;}
    break;

  case 67:
#line 247 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(6, yyvsp, yyval);;}
    break;

  case 68:
#line 248 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(7, yyvsp, yyval);;}
    break;

  case 69:
#line 249 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(8, yyvsp, yyval);;}
    break;

  case 70:
#line 250 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(9, yyvsp, yyval);;}
    break;

  case 71:
#line 251 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::modifier(10, yyvsp, yyval);;}
    break;

  case 72:
#line 255 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::classWord(1,yyval);;}
    break;

  case 73:
#line 256 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::classWord(2,yyval);;}
    break;

  case 74:
#line 260 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::interfaces(yyvsp, yyval);}
    break;

  case 75:
#line 264 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclarations(1, yyvsp, yyval);;}
    break;

  case 76:
#line 265 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclarations(2, yyvsp, yyval);;}
    break;

  case 79:
#line 274 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclaration(1, yyvsp, yyval);;}
    break;

  case 80:
#line 275 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclaration(2, yyvsp, yyval);;}
    break;

  case 81:
#line 276 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclaration(3, yyvsp, yyval);;}
    break;

  case 82:
#line 277 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclaration(4, yyvsp, yyval);;}
    break;

  case 83:
#line 278 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclaration(5, yyvsp, yyval);;}
    break;

  case 84:
#line 279 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldDeclaration(6, yyvsp, yyval);;}
    break;

  case 85:
#line 280 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yyerrok; skipFrom(FIELD); yaccActions::fieldDeclaration(7, yyvsp, yyval);;}
    break;

  case 86:
#line 284 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldVariableDeclaration(1, yyvsp , yyval);;}
    break;

  case 87:
#line 285 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::fieldVariableDeclaration(2, yyvsp , yyval);;}
    break;

  case 88:
#line 290 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableDeclarators(1, yyvsp, yyval);;}
    break;

  case 89:
#line 291 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableDeclarators(2, yyvsp, yyval);;}
    break;

  case 90:
#line 295 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableDeclarator(1, yyvsp, yyval);;}
    break;

  case 91:
#line 296 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableDeclarator(2, yyvsp, yyval);;}
    break;

  case 92:
#line 300 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableInitializer(1, yyvsp, yyval);;}
    break;

  case 93:
#line 301 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableInitializer(2, yyvsp, yyval);;}
    break;

  case 94:
#line 302 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::variableInitializer(3, yyvsp, yyval);;}
    break;

  case 95:
#line 306 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::arrayInitializers(1 ,yyvsp, yyval);;}
    break;

  case 96:
#line 307 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::arrayInitializers(2 ,yyvsp, yyval);;}
    break;

  case 97:
#line 311 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(1, yyvsp, yyval);;}
    break;

  case 98:
#line 312 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(2, yyvsp, yyval);;}
    break;

  case 99:
#line 313 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(3, yyvsp, yyval);;}
    break;

  case 100:
#line 314 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(4, yyvsp, yyval);;}
    break;

  case 101:
#line 315 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(5, yyvsp, yyval);;}
    break;

  case 102:
#line 316 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(6, yyvsp, yyval);;}
    break;

  case 103:
#line 317 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(7, yyvsp, yyval);;}
    break;

  case 104:
#line 318 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclaration(8, yyvsp, yyval);;}
    break;

  case 105:
#line 322 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclarator(1, yyvsp, yyval);;}
    break;

  case 106:
#line 323 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclarator(2, yyvsp, yyval); yyerrok; skipFrom(METHOD);;}
    break;

  case 107:
#line 324 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclarator(3, yyvsp, yyval);;}
    break;

  case 108:
#line 325 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodDeclarator(4, yyvsp, yyval); yyerrok; skipFrom(METHOD);;}
    break;

  case 109:
#line 329 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::parameterList(1, yyvsp, yyval);;}
    break;

  case 110:
#line 330 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::parameterList(2, yyvsp, yyval);;}
    break;

  case 111:
#line 334 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::parameter(1, yyvsp, yyval);;}
    break;

  case 112:
#line 335 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::parameter(2, yyvsp, yyval);;}
    break;

  case 113:
#line 339 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::declaratorName(1, yyvsp, yyval);;}
    break;

  case 114:
#line 340 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::declaratorName(2, yyvsp, yyval);;}
    break;

  case 116:
#line 348 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodBody(1, yyvsp, yyval);;}
    break;

  case 117:
#line 349 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodBody(2, yyvsp, yyval);;}
    break;

  case 118:
#line 350 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::methodBody(3, yyvsp, yyval);;}
    break;

  case 119:
#line 354 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(1, yyvsp, yyval);;}
    break;

  case 120:
#line 355 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(2, yyvsp, yyval);;}
    break;

  case 121:
#line 356 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(3, yyvsp, yyval);;}
    break;

  case 122:
#line 357 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(4, yyvsp, yyval);;}
    break;

  case 123:
#line 358 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(5, yyvsp, yyval); YYACCEPT;;}
    break;

  case 124:
#line 359 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(6, yyvsp, yyval); YYACCEPT;;}
    break;

  case 125:
#line 360 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(7, yyvsp, yyval); YYACCEPT;;}
    break;

  case 126:
#line 361 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclaration(8, yyvsp, yyval); YYACCEPT;;}
    break;

  case 127:
#line 365 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclarator(1, yyvsp, yyval);;}
    break;

  case 128:
#line 366 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::constructorDeclarator(2, yyvsp, yyval);;}
    break;

  case 129:
#line 370 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::staticInitializer(1, yyvsp, yyval);;}
    break;

  case 130:
#line 371 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::staticInitializer(2, yyvsp, yyval); YYACCEPT;;}
    break;

  case 131:
#line 372 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::staticInitializer(3, yyvsp, yyval); YYACCEPT;;}
    break;

  case 132:
#line 376 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::nonStaticInitializer(1, yyvsp, yyval);;}
    break;

  case 133:
#line 377 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::nonStaticInitializer(2, yyvsp, yyval);;}
    break;

  case 134:
#line 378 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::nonStaticInitializer(3, yyvsp, yyval);;}
    break;

  case 135:
#line 382 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::extends(yyvsp, yyval);;}
    break;

  case 136:
#line 386 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::anyBlock(1, yyvsp, yyval);;}
    break;

  case 137:
#line 387 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::anyBlock(2, yyvsp, yyval);;}
    break;

  case 138:
#line 392 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::block(1, yyvsp, yyval);;}
    break;

  case 139:
#line 393 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::block(2, yyvsp, yyval);;}
    break;

  case 140:
#line 397 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::wrongBlock(1, yyvsp, yyval);;}
    break;

  case 141:
#line 398 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::wrongBlock(2, yyvsp, yyval); YYACCEPT;;}
    break;

  case 142:
#line 399 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yyerrok; yaccActions::wrongBlock(3, yyvsp, yyval);;}
    break;

  case 143:
#line 400 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yyerrok; yaccActions::wrongBlock(4, yyvsp, yyval); YYACCEPT;;}
    break;

  case 144:
#line 401 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yyerror("syntax error, unexpected end of file, expecting \'}\'"); yaccActions::wrongBlock(5, yyvsp, yyval); YYACCEPT;;}
    break;

  case 145:
#line 405 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationsAndStatements(1, yyvsp, yyval);;}
    break;

  case 146:
#line 406 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationsAndStatements(2, yyvsp, yyval);;}
    break;

  case 147:
#line 410 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationOrStatement(1, yyvsp, yyval);;}
    break;

  case 148:
#line 411 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationOrStatement(2, yyvsp, yyval);;}
    break;

  case 149:
#line 412 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationOrStatement(3, yyvsp, yyval); yyerrok; skipFrom(STATEMENT);;}
    break;

  case 150:
#line 416 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationStatement(1, yyvsp, yyval);;}
    break;

  case 151:
#line 417 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::localVariableDeclarationStatement(2, yyvsp, yyval);;}
    break;

  case 152:
#line 421 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(1, yyvsp, yyval); ;}
    break;

  case 153:
#line 422 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(2, yyvsp, yyval); ;}
    break;

  case 154:
#line 423 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(3, yyvsp, yyval); ;}
    break;

  case 155:
#line 424 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(4, yyvsp, yyval); ;}
    break;

  case 156:
#line 425 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(5, yyvsp, yyval); ;}
    break;

  case 157:
#line 426 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(6, yyvsp, yyval); ;}
    break;

  case 158:
#line 427 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(7, yyvsp, yyval); ;}
    break;

  case 159:
#line 428 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::statement(8, yyvsp, yyval); ;}
    break;

  case 160:
#line 429 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::statement(9, yyvsp, yyval);;}
    break;

  case 161:
#line 433 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::printStatement(yyvsp, yyval);;}
    break;

  case 162:
#line 437 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::emptyStatement(yyvsp, yyval);;}
    break;

  case 163:
#line 441 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::labelStatement(1, yyvsp, yyval);;}
    break;

  case 164:
#line 442 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::labelStatement(2, yyvsp, yyval);;}
    break;

  case 165:
#line 443 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::labelStatement(3, yyvsp, yyval);;}
    break;

  case 166:
#line 447 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::expressionStatement(yyvsp, yyval);;}
    break;

  case 167:
#line 451 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::selectionStatement(1, yyvsp, yyval);;}
    break;

  case 168:
#line 452 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::selectionStatement(2, yyvsp, yyval);;}
    break;

  case 169:
#line 453 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::selectionStatement(3, yyvsp, yyval);;}
    break;

  case 170:
#line 457 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::iterationStatement(1, yyvsp, yyval);;}
    break;

  case 171:
#line 458 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::iterationStatement(2, yyvsp, yyval);;}
    break;

  case 172:
#line 459 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::iterationStatement(3, yyvsp, yyval);;}
    break;

  case 173:
#line 460 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::iterationStatement(4, yyvsp, yyval);;}
    break;

  case 174:
#line 461 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::iterationStatement(5, yyvsp, yyval);;}
    break;

  case 175:
#line 465 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::forInit(1, yyvsp, yyval);;}
    break;

  case 176:
#line 466 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::forInit(2, yyvsp, yyval);;}
    break;

  case 177:
#line 467 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::forInit(3, yyvsp, yyval);;}
    break;

  case 178:
#line 471 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::forExpr(1, yyvsp, yyval);;}
    break;

  case 179:
#line 472 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::forExpr(2, yyvsp, yyval);;}
    break;

  case 180:
#line 476 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::forIncr(yyvsp, yyval);;}
    break;

  case 181:
#line 480 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::expressionStatements(1, yyvsp, yyval);;}
    break;

  case 182:
#line 481 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::expressionStatements(2, yyvsp, yyval);;}
    break;

  case 183:
#line 485 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(1, yyvsp, yyval); ;}
    break;

  case 184:
#line 486 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(2, yyvsp, yyval); ;}
    break;

  case 185:
#line 487 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(3, yyvsp, yyval); ;}
    break;

  case 186:
#line 488 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(4, yyvsp, yyval); ;}
    break;

  case 187:
#line 489 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(5, yyvsp, yyval); ;}
    break;

  case 188:
#line 490 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(6, yyvsp, yyval); ;}
    break;

  case 189:
#line 491 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::jumpStatement(7, yyvsp, yyval); ;}
    break;

  case 191:
#line 496 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::guardingStatement(1, yyvsp, yyval);;}
    break;

  case 192:
#line 497 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::guardingStatement(2, yyvsp, yyval);;}
    break;

  case 193:
#line 498 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::guardingStatement(3, yyvsp, yyval);;}
    break;

  case 194:
#line 502 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::catches(1, yyvsp, yyval);;}
    break;

  case 195:
#line 503 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::catches(2, yyvsp, yyval);;}
    break;

  case 196:
#line 507 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::jCatch(1, yyvsp, yyval);;}
    break;

  case 197:
#line 511 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::catchHeader(1, yyvsp, yyval);;}
    break;

  case 198:
#line 512 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::catchHeader(2, yyvsp, yyval);;}
    break;

  case 199:
#line 516 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::jFinally(1, yyvsp, yyval);;}
    break;

  case 200:
#line 520 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::primaryExpression(1,yyvsp,yyval); ;}
    break;

  case 201:
#line 521 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::primaryExpression(2,yyvsp,yyval); ;}
    break;

  case 202:
#line 525 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::notJustName(1,yyvsp,yyval); ;}
    break;

  case 203:
#line 526 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::notJustName(2,yyvsp,yyval); ;}
    break;

  case 204:
#line 527 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::notJustName(3,yyvsp,yyval); ;}
    break;

  case 205:
#line 531 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::complexPrimary(1,yyvsp,yyval); ;}
    break;

  case 206:
#line 532 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::complexPrimary(2,yyvsp,yyval); ;}
    break;

  case 207:
#line 536 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::complexPrimaryNoParenthesis(1,yyvsp,yyval); ;}
    break;

  case 208:
#line 537 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::complexPrimaryNoParenthesis(2,yyvsp,yyval); ;}
    break;

  case 209:
#line 538 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::complexPrimaryNoParenthesis(3,yyvsp,yyval); ;}
    break;

  case 210:
#line 539 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::complexPrimaryNoParenthesis(4,yyvsp,yyval); ;}
    break;

  case 212:
#line 544 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(1,yyvsp,yyval);  ;}
    break;

  case 213:
#line 545 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(2,yyvsp,yyval);  ;}
    break;

  case 214:
#line 546 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(3,yyvsp,yyval);  ;}
    break;

  case 215:
#line 547 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(4,yyvsp,yyval);  ;}
    break;

  case 216:
#line 548 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(5,yyvsp,yyval);  ;}
    break;

  case 217:
#line 549 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(6,yyvsp,yyval);  ;}
    break;

  case 218:
#line 550 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::literals(7,yyvsp,yyval);  ;}
    break;

  case 219:
#line 553 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::arrayAccess(1,yyvsp,yyval); ;}
    break;

  case 220:
#line 554 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::arrayAccess(2,yyvsp,yyval); ;}
    break;

  case 221:
#line 558 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::fieldAccess(1,yyvsp,yyval); ;}
    break;

  case 222:
#line 559 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::fieldAccess(2,yyvsp,yyval); ;}
    break;

  case 223:
#line 560 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::fieldAccess(3,yyvsp,yyval); ;}
    break;

  case 224:
#line 561 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::fieldAccess(4,yyvsp,yyval); ;}
    break;

  case 225:
#line 562 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::fieldAccess(5,yyvsp,yyval); ;}
    break;

  case 226:
#line 566 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::methodCall(1,yyvsp,yyval); ;}
    break;

  case 227:
#line 567 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::methodCall(2,yyvsp,yyval); ;}
    break;

  case 228:
#line 571 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::methodAccess(1,yyvsp,yyval); ;}
    break;

  case 229:
#line 572 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::methodAccess(2,yyvsp,yyval); ;}
    break;

  case 230:
#line 573 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::methodAccess(3,yyvsp,yyval); ;}
    break;

  case 231:
#line 577 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::NewInner(1,yyvsp,yyval);;}
    break;

  case 232:
#line 578 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::NewInner(2,yyvsp,yyval);;}
    break;

  case 233:
#line 579 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::NewInner(3,yyvsp,yyval);;}
    break;

  case 234:
#line 580 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::NewInner(4,yyvsp,yyval);;}
    break;

  case 235:
#line 584 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::specialName(1 ,yyvsp, yyval); ;}
    break;

  case 236:
#line 585 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::specialName(2 ,yyvsp, yyval); ;}
    break;

  case 237:
#line 586 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::specialName(3 ,yyvsp, yyval); ;}
    break;

  case 238:
#line 590 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::argumentList(1,yyvsp,yyval); ;}
    break;

  case 239:
#line 591 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::argumentList(2,yyvsp,yyval); ;}
    break;

  case 240:
#line 595 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::newAllocationExpression(1, yyvsp, yyval); ;}
    break;

  case 241:
#line 596 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::newAllocationExpression(2, yyvsp, yyval); ;}
    break;

  case 242:
#line 600 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::plainNewAllocationExpression(1,yyvsp,yyval); ;}
    break;

  case 243:
#line 601 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::plainNewAllocationExpression(2,yyvsp,yyval); ;}
    break;

  case 244:
#line 602 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::plainNewAllocationExpression(3,yyvsp,yyval); ;}
    break;

  case 245:
#line 603 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::plainNewAllocationExpression(4,yyvsp,yyval); ;}
    break;

  case 246:
#line 604 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::plainNewAllocationExpression(5,yyvsp,yyval); ;}
    break;

  case 247:
#line 605 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::plainNewAllocationExpression(6,yyvsp,yyval); ;}
    break;

  case 248:
#line 609 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classAllocationExpression(1,  yyvsp, yyval); ;}
    break;

  case 249:
#line 610 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::classAllocationExpression(2,  yyvsp, yyval); ;}
    break;

  case 250:
#line 614 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::arrayAllocationExpression(1, yyvsp, yyval); ;}
    break;

  case 251:
#line 615 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::arrayAllocationExpression(2, yyvsp, yyval); ;}
    break;

  case 252:
#line 616 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::arrayAllocationExpression(3, yyvsp, yyval); ;}
    break;

  case 253:
#line 620 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::dimExprs(1, yyvsp, yyval); ;}
    break;

  case 254:
#line 621 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::dimExprs(2, yyvsp, yyval); ;}
    break;

  case 255:
#line 625 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::dimExpr(1, yyvsp, yyval); ;}
    break;

  case 256:
#line 629 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::dims(1, yyvsp, yyval); ;}
    break;

  case 257:
#line 630 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::dims(2, yyvsp, yyval); ;}
    break;

  case 258:
#line 634 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::postfixExpression(1, yyvsp, yyval); ;}
    break;

  case 259:
#line 635 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::postfixExpression(2, yyvsp, yyval); ;}
    break;

  case 260:
#line 639 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::realPostfixExpression(1, yyvsp, yyval); ;}
    break;

  case 261:
#line 640 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::realPostfixExpression(2, yyvsp, yyval); ;}
    break;

  case 262:
#line 644 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::unaryExpression(1, yyvsp, yyval); ;}
    break;

  case 263:
#line 645 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::unaryExpression(2, yyvsp, yyval); ;}
    break;

  case 264:
#line 646 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::unaryExpression(3, yyvsp, yyval); ;}
    break;

  case 265:
#line 647 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::unaryExpression(4, yyvsp, yyval); ;}
    break;

  case 266:
#line 651 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::logicalUnaryExpression(1, yyvsp, yyval); ;}
    break;

  case 267:
#line 652 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::logicalUnaryExpression(2, yyvsp, yyval); ;}
    break;

  case 273:
#line 667 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::castExpression(1, yyvsp, yyval);;}
    break;

  case 274:
#line 668 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::castExpression(2, yyvsp, yyval);;}
    break;

  case 275:
#line 669 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::castExpression(3, yyvsp, yyval);;}
    break;

  case 276:
#line 673 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveTypeExpression(1, yyvsp,yyval);;}
    break;

  case 277:
#line 674 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveTypeExpression(2, yyvsp,yyval);;}
    break;

  case 278:
#line 678 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::primitiveTypeExpression(3, yyvsp,yyval);;}
    break;

  case 279:
#line 682 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::multiplicativeExpression(1,yyvsp,yyval); ;}
    break;

  case 280:
#line 683 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::multiplicativeExpression(2,yyvsp,yyval); ;}
    break;

  case 281:
#line 684 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::multiplicativeExpression(3,yyvsp,yyval); ;}
    break;

  case 282:
#line 685 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::multiplicativeExpression(4,yyvsp,yyval); ;}
    break;

  case 283:
#line 689 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::additiveExpression(1,yyvsp,yyval);  ;}
    break;

  case 284:
#line 690 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::additiveExpression(2,yyvsp,yyval);  ;}
    break;

  case 285:
#line 691 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::additiveExpression(3,yyvsp,yyval);  ;}
    break;

  case 286:
#line 695 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::shiftExpression(1,yyvsp,yyval); ;}
    break;

  case 290:
#line 702 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::relationalExpression(1,yyvsp,yyval); ;}
    break;

  case 291:
#line 703 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::relationalExpression(2,yyvsp,yyval); ;}
    break;

  case 292:
#line 704 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::relationalExpression(3,yyvsp,yyval); ;}
    break;

  case 293:
#line 705 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::relationalExpression(4,yyvsp,yyval); ;}
    break;

  case 294:
#line 706 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::relationalExpression(5,yyvsp,yyval); ;}
    break;

  case 295:
#line 707 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::relationalExpression(6,yyvsp,yyval); ;}
    break;

  case 296:
#line 711 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::equalityExpression(1,yyvsp,yyval); ;}
    break;

  case 297:
#line 712 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::equalityExpression(2,yyvsp,yyval); ;}
    break;

  case 298:
#line 713 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::equalityExpression(3,yyvsp,yyval); ;}
    break;

  case 299:
#line 717 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::andExpression(1,yyvsp,yyval); ;}
    break;

  case 300:
#line 718 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::andExpression(2,yyvsp,yyval); ;}
    break;

  case 301:
#line 722 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::exclusiveOrExpression(1,yyvsp,yyval); ;}
    break;

  case 302:
#line 723 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::exclusiveOrExpression(2,yyvsp,yyval); ;}
    break;

  case 303:
#line 727 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::inclusiveOrExpression(1,yyvsp,yyval); ;}
    break;

  case 304:
#line 728 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::inclusiveOrExpression(2,yyvsp,yyval); ;}
    break;

  case 305:
#line 732 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::conditionalAndExpression(1,yyvsp,yyval); ;}
    break;

  case 306:
#line 733 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    { yaccActions::conditionalAndExpression(2,yyvsp,yyval); ;}
    break;

  case 307:
#line 737 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::conditionalOrExpression(1,yyvsp,yyval); ;}
    break;

  case 308:
#line 738 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::conditionalOrExpression(2,yyvsp,yyval); ;}
    break;

  case 309:
#line 742 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::conditionalExpression(1,yyvsp,yyval); ;}
    break;

  case 310:
#line 743 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::conditionalExpression(2,yyvsp,yyval); ;}
    break;

  case 311:
#line 747 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::assignmentExpression(1,yyvsp,yyval);;}
    break;

  case 312:
#line 748 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {yaccActions::assignmentExpression(2,yyvsp,yyval);;}
    break;

  case 325:
#line 767 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"
    {;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 4215 "yacc.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 774 "F:\\Compiler-6-1-2017\\Compiler\\JCompiler\\JCompiler\\yacc_final.y"




void yyerror(char *s) 
{
	ErrorRecovery::ErrorList->push(make_pair(make_pair(yylval.tokenInfo.tokenLine,yylval.tokenInfo.tokenCol),Utils::give_Me_Token_Image(s)));
}


int yylex()
{

	int currentToken =  lexer->yylex();
	if(currentToken == ENDF)
		tokenListening<<"ENDF"<<endl;

	yylval.tokenInfo.tokenCol = give_Me_Token_Col();
	yylval.tokenInfo.tokenLine = give_Me_Token_Line();
	yylval.tokenInfo.tokenImage = Utils::give_Me_Token_Image(lexer->YYText());

	tokenListening<<yylval.tokenInfo.tokenImage<<" "<<yylval.tokenInfo.tokenLine<<" "<<yylval.tokenInfo.tokenCol<<endl;

	int t = strlen(yylval.tokenInfo.tokenImage);
	Update_Col(t);
	return currentToken;
}

void skipFrom(int token){
	int currentToken = yychar;
	while(true){
		cout<<token<<" "<<currentToken<<endl;
		if(currentToken == ENDF || followSet[token].find(currentToken) != followSet[token].end()){
			if(currentToken == ENDF){
				yyerror("syntax error, unexpected end of file.");
				//YYACCEPT;
			}
			yychar = currentToken;
			return;
		}

		currentToken = yylex();
	}
}

void skipToClass(){
	stack<int> yymodifier;
	int currentToken = yychar;
	while(true){
		if(currentToken == ENDF || currentToken == CLASS || currentToken == INTERFACE){
			if(currentToken == ENDF){
				yyerror("syntax error, unexpected end of file.");
				//YYACCEPT;
			}
			yychar = currentToken;
			return;
		}
		if(Modifiers.find(currentToken) != Modifiers.end()){
			yymodifier.push(currentToken);
			previousModifiers.push(yylval.tokenInfo.tokenImage);
		}
		else{
			while(!previousModifiers.empty())
				previousModifiers.pop();
				
			while(!yymodifier.empty())
				yymodifier.pop();
			}

		 currentToken = yylex();	
	}

}

void skipFromHeaderErrors(){
	if(yychar != '{'){
		yyerror("syntax error, expecting\'{\'");
		skipFrom(CLASS);
	}
}


void initPackages(char* dir, char* dirForCommand, char* packageName = "default"){
	WorkingWithFiles::changeDirAndGetDirs(dirForCommand);
	WorkingWithFiles::changeDirAndGetFiles(dirForCommand);
	vector<char*> dirs;
	dirs.insert(dirs.begin(), WorkingWithFiles::dirs.begin(), WorkingWithFiles::dirs.end());

	int n = WorkingWithFiles::files.size();
	int m = WorkingWithFiles::dirs.size();

	JPackage *package =  0;
	Parser* p;
	
	if (n > 0){
		package  = new JPackage(packageName, dir, 0, 0, 0);
		package->compilationUnits = new vector<JCompilationUnit *>;
		project->projectContext->add(Utils::hashKey(packageName, strlen(packageName)), new PackageNameDefn(package));
	}

	
	//loop on files
	char *file;
	for (int i = 0; i < n; i++){
		//code for scanning and parsing
		file = new char[300];
		strcpy(file, dir);
		strcat(file, "/");
		strcat(file, WorkingWithFiles::files[i]);
		filebuf fb;
		fb.open(file, std::ios::in);
		istream is(&fb);
		lexer = new yyFlexLexer(&is);
		p = new Parser();
		compilationUnit = new JCompilationUnit(WorkingWithFiles::files[i], file, 0, 0, 0, 0, 0);
		p->parse();
		package->compilationUnits->push_back(compilationUnit);
		cout<<"========================"<<WorkingWithFiles::files[i]<<"===================="<<endl;
		delete[] file;
	}

	if(package != 0 && project->packages == 0){
		project->packages = new vector<JPackage*>;
	}

	if(package != 0){
		project->packages->push_back(package);
	}
	
	//loop on directories
	char *newDir;
	for (int i = 0; i < m; i++){
		newDir = new char[300];
		char *newDirForCommand = new char[300];
		strcpy(newDir, dir);
		strcat(newDir, "/");
		strcat(newDir, dirs[i]);

		strcpy(newDirForCommand, dirForCommand);
		strcat(newDirForCommand, "/");
		strcat(newDirForCommand, "\"");
		strcat(newDirForCommand, dirs[i]);
		strcat(newDirForCommand, "\"");

		if (strcmp(packageName, "default") == 0){
			initPackages(newDir, newDirForCommand, dirs[i]);
		}
		else{
			char *newPackageName = new char[300];
			strcpy(newPackageName, packageName);
			strcat(newPackageName, ".");
			strcat(newPackageName, dirs[i]);
			initPackages(newDir, newDirForCommand, newPackageName);
		}
	}
}

void main(void)
{

	freopen("grammarListening.txt","w", stdout);

	initFollowSets();

	project = new JProject("FirstJavaProject", "F:/Packages", 0, 0);
	project->projectContext = new ProjectContext(project);
	initPackages("F:/Packages","F:/Packages");

	project->preAnalyze();
	project->getparent();
	project->analyze();
	Utils:: out << ".text" <<endl;
	Utils::out << ".globl main" <<endl;


	Utils::codegen();

	project->precodegen();


	ErrorRecovery::printErrorList();

	//VisualizeSymbolTable(compilationUnit);
	system("\"c:/Program Files (x86)/QtSpim/QtSpim.exe\"  F:/Compiler-6-1-2017/Compiler/JCompiler/JCompiler/assembly.asm");
}

