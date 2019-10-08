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
/* Line 1447 of yacc.c.  */
#line 294 "yacc.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



