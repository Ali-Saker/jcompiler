%output ="yacc.cpp"
%{
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

%}

%union{
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
}


%token ABSTRACT ANNOTATION
%token BOOLEAN BREAK BYTE BYVALUE
%token CASE CAST CATCH CHAR CLASS CONST CONTINUE
%token DEFAULT DO DOUBLE
%token ELSE EXTENDS ERROR STATEMENT
%token FINAL FINALLY FLOAT FOR FUTURE
%token GENERIC GOTO
%token IF IMPLEMENTS IMPORT INNER INSTANCEOF INT INTERFACE
%token LONG
%token NATIVE NEW JNULL
%token OPERATOR OUTER
%token PACKAGE PRIVATE PROTECTED PUBLIC PRINT
%token REST RETURN STRICTFP
%token SHORT STATIC SUPER SWITCH SYNCHRONIZED STRING
%token THIS THROW THROWS TRANSIENT TRY
%token VAR VOID VOLATILE METHOD 
%token WHILE
%token OP_INC OP_DEC
%token OP_SHL OP_SHR OP_SHRR
%token OP_GE OP_LE OP_EQ OP_NE
%token OP_LAND OP_LOR
%token OP_DIM
%token ASS_MUL ASS_DIV ASS_MOD ASS_ADD ASS_SUB
%token ASS_SHL ASS_SHR ASS_SHRR ASS_AND ASS_XOR ASS_OR
%token IDENTIFIER BOOLLIT FIELD
%token INT_LITERAL LONG_LITERAL FLOAT_LITERAL CHAR_LITERAL STRING_LITERAL DOUBLE_LITERAL
%token ENDF 0
%nonassoc IfStmt QualifiedNameId
%nonassoc ELSE '('


%start CompilationUnit

%error-verbose


%%

TypeSpecifier
   : TypeName		{yaccActions::typeSpecifier(1, yyvsp, yyval);}
	| TypeName Dims	{yaccActions::typeSpecifier(2, yyvsp, yyval);}
	;

TypeName
	: PrimitiveType	{yaccActions::typeName(1, yyvsp, yyval);}
	| QualifiedName	{yaccActions::typeName(2, yyvsp, yyval);}
	;

ClassNameList
        : QualifiedName						{yaccActions::classNameList(1, yyvsp, yyval);}
        | ClassNameList ',' QualifiedName	{yaccActions::classNameList(2, yyvsp, yyval);}
	;

PrimitiveType
	: BOOLEAN	{yaccActions::primitiveType(1, yyvsp, yyval);}
	| CHAR		{yaccActions::primitiveType(2, yyvsp, yyval);}
	| BYTE		{yaccActions::primitiveType(3, yyvsp, yyval);}
	| SHORT		{yaccActions::primitiveType(4, yyvsp, yyval);}
	| INT		{yaccActions::primitiveType(5, yyvsp, yyval);}
	| LONG		{yaccActions::primitiveType(6, yyvsp, yyval);}
	| FLOAT		{yaccActions::primitiveType(7, yyvsp, yyval);}
	| DOUBLE	{yaccActions::primitiveType(8, yyvsp, yyval);}
	| VOID		{yaccActions::primitiveType(9, yyvsp, yyval);}
	| STRING	{yaccActions::primitiveType(10, yyvsp, yyval);}
	;

SemiColons
	: ';'
        | SemiColons ';'
        ;

CompilationUnit
	: ProgramFile ENDF{yaccActions::compilationUnit(); YYACCEPT;}
        ;

ProgramFile
	: PackageStatement ImportStatements TypeDeclarations 	{yaccActions::programFile(1, yyvsp, compilationUnit);}
	| PackageStatement ImportStatements					 	{yaccActions::programFile(2, yyvsp, compilationUnit);}
	| PackageStatement                  TypeDeclarations 	{yaccActions::programFile(3, yyvsp, compilationUnit);}
	|                  ImportStatements TypeDeclarations 	{yaccActions::programFile(4, yyvsp, compilationUnit);}
	| PackageStatement									 	{yaccActions::programFile(5, yyvsp, compilationUnit);}
	|                  ImportStatements					 	{yaccActions::programFile(6, yyvsp, compilationUnit);}
	|                                   TypeDeclarations 	{yaccActions::programFile(7, yyvsp, compilationUnit);}
	;

PackageStatement
	: PACKAGE QualifiedName SemiColons  { yaccActions::packageStatement(1, yyvsp, yyval); }
	| PACKAGE error						{ yaccActions::packageStatement(2, yyvsp, yyval); yyerrok; skipFrom(PACKAGE); }
	;


TypeDeclarations
	: TypeDeclarationOptSemi					 { yaccActions::typeDeclarations(1,yyvsp, compilationUnit, previousModifiers); skipToClass();}
	| TypeDeclarations TypeDeclarationOptSemi	 { yaccActions::typeDeclarations(2,yyvsp, compilationUnit, previousModifiers); skipToClass();}
	;

TypeDeclarationOptSemi
        : TypeDeclaration				{ yaccActions::typeDeclarationOptSemi(1, yyvsp, yyval); }
        | TypeDeclaration SemiColons	{ yaccActions::typeDeclarationOptSemi(2, yyvsp, yyval); }
		| ClassHeader					{ yaccActions::typeDeclarationOptSemi(3, yyvsp, yyval); yyerror("syntax error, expecting  \'}\'");}
        ;

ImportStatements
	: ImportStatement							{yaccActions::importStatements(1, yyvsp, compilationUnit);}
	| error										{yaccActions::importStatements(2, yyvsp, compilationUnit); yyerrok; yyclearin;}
	| ImportStatements ImportStatement			{yaccActions::importStatements(3, yyvsp, compilationUnit);}
	| ImportStatements error					{yaccActions::importStatements(4, yyvsp, compilationUnit); yyerrok; yyclearin;}
	;

ImportStatement
	: IMPORT QualifiedName SemiColons			{yaccActions::importStatement(1, yyvsp, yyval);}
	| IMPORT QualifiedName '.' '*' SemiColons	{yaccActions::importStatement(2, yyvsp, yyval);}
	;

QualifiedName
	: IDENTIFIER	%prec QualifiedNameId	{yaccActions::QualifiedName(1, yyvsp, yyval);}
	| QualifiedName '.' IDENTIFIER			{yaccActions::QualifiedName(2, yyvsp, yyval);}
	;

TypeDeclaration	
	: ClassHeader '{' FieldDeclarations '}'		{yaccActions::typeDeclaration(1, yyvsp, yyval); }
	| ClassHeader '{' FieldDeclarations ENDF	{yaccActions::typeDeclaration(2, yyvsp, yyval);  yyerror("syntax error, unexpected end of file, expecting \'}\'"); }
	| ClassHeader '{' '}'						{yaccActions::typeDeclaration(3, yyvsp, yyval);}
	| ClassHeader '{' ENDF						{yaccActions::typeDeclaration(4, yyvsp, yyval); yyerror("syntax error, unexpected end of file, expecting \'}\'");}
	| ClassHeader error FieldDeclarations '}'	{yaccActions::typeDeclaration(5, yyvsp, yyval); yyerrok; }
	| ClassHeader error FieldDeclarations ENDF  {yaccActions::typeDeclaration(6, yyvsp, yyval); yyerrok; yyerror("syntax error, unexpected end of file, expecting \'}\'"); }
	| ClassHeader '}'							{yaccActions::typeDeclaration(7, yyvsp, yyval);}
	;


ClassHeader
	: Modifiers ClassWord IDENTIFIER Extends Interfaces		{ yaccActions::classHeader(1, yyvsp, yyval); skipFromHeaderErrors(); }
	| Modifiers ClassWord IDENTIFIER Extends				{ yaccActions::classHeader(2, yyvsp, yyval); skipFromHeaderErrors(); }
	| Modifiers ClassWord IDENTIFIER       Interfaces		{ yaccActions::classHeader(3, yyvsp, yyval); skipFromHeaderErrors(); }
	|           ClassWord IDENTIFIER Extends Interfaces		{ yaccActions::classHeader(4, yyvsp, yyval); skipFromHeaderErrors(); }
	| Modifiers ClassWord IDENTIFIER						{ yaccActions::classHeader(5, yyvsp, yyval); skipFromHeaderErrors(); }
	|           ClassWord IDENTIFIER Extends				{ yaccActions::classHeader(6, yyvsp, yyval); skipFromHeaderErrors(); }
	|           ClassWord IDENTIFIER       Interfaces		{ yaccActions::classHeader(7, yyvsp, yyval); skipFromHeaderErrors(); }
	|           ClassWord IDENTIFIER						{ yaccActions::classHeader(8, yyvsp, yyval); skipFromHeaderErrors(); }
	| Modifiers ClassWord error								{ yaccActions::classHeader(9, yyvsp, yyval); yyerrok; skipFrom(CLASS); }
	|           ClassWord error								{ yaccActions::classHeader(10, yyvsp, yyval); yyerrok; skipFrom(CLASS); }
	;

Modifiers
	: Modifier				{yaccActions::modifiers(1, yyvsp, yyval);}
	| Modifiers Modifier	{yaccActions::modifiers(2, yyvsp, yyval);}
	;

Modifier
	: ABSTRACT		{yaccActions::modifier(1, yyvsp, yyval);}
	| FINAL			{yaccActions::modifier(2, yyvsp, yyval);}
	| PUBLIC		{yaccActions::modifier(3, yyvsp, yyval);}
	| PROTECTED		{yaccActions::modifier(4, yyvsp, yyval);}
	| PRIVATE		{yaccActions::modifier(5, yyvsp, yyval);}
	| STATIC		{yaccActions::modifier(6, yyvsp, yyval);}
	| TRANSIENT		{yaccActions::modifier(7, yyvsp, yyval);}
	| VOLATILE		{yaccActions::modifier(8, yyvsp, yyval);}
	| NATIVE		{yaccActions::modifier(9, yyvsp, yyval);}
	| SYNCHRONIZED	{yaccActions::modifier(10, yyvsp, yyval);}
	;

ClassWord
	: CLASS			{yaccActions::classWord(1,yyval);}
	| INTERFACE		{yaccActions::classWord(2,yyval);}
	;

Interfaces
	: IMPLEMENTS ClassNameList	{yaccActions::interfaces(yyvsp, yyval)};
	;

FieldDeclarations
	: FieldDeclarationOptSemi					{yaccActions::fieldDeclarations(1, yyvsp, yyval);}
    | FieldDeclarations FieldDeclarationOptSemi	{yaccActions::fieldDeclarations(2, yyvsp, yyval);}
	;

FieldDeclarationOptSemi
        : FieldDeclaration
        | FieldDeclaration SemiColons
        ;

FieldDeclaration
	: FieldVariableDeclaration ';'		{yaccActions::fieldDeclaration(1, yyvsp, yyval);}
	| MethodDeclaration					{yaccActions::fieldDeclaration(2, yyvsp, yyval);}
	| ConstructorDeclaration			{yaccActions::fieldDeclaration(3, yyvsp, yyval);}
	| StaticInitializer					{yaccActions::fieldDeclaration(4, yyvsp, yyval);}
    | NonStaticInitializer				{yaccActions::fieldDeclaration(5, yyvsp, yyval);}
    | TypeDeclaration					{yaccActions::fieldDeclaration(6, yyvsp, yyval);}
	| error								{yyerrok; skipFrom(FIELD); yaccActions::fieldDeclaration(7, yyvsp, yyval);}
	;

FieldVariableDeclaration
	: Modifiers TypeSpecifier VariableDeclarators	{yaccActions::fieldVariableDeclaration(1, yyvsp , yyval);}
	|           TypeSpecifier VariableDeclarators	{yaccActions::fieldVariableDeclaration(2, yyvsp , yyval);}
	;


VariableDeclarators
	: VariableDeclarator							{yaccActions::variableDeclarators(1, yyvsp, yyval);}
	| VariableDeclarators ',' VariableDeclarator	{yaccActions::variableDeclarators(2, yyvsp, yyval);}
	;

VariableDeclarator
	: DeclaratorName							{yaccActions::variableDeclarator(1, yyvsp, yyval);}
	| DeclaratorName '=' VariableInitializer	{yaccActions::variableDeclarator(2, yyvsp, yyval);}
	;

VariableInitializer
	: Expression								{yaccActions::variableInitializer(1, yyvsp, yyval);}
	| '{' '}'									{yaccActions::variableInitializer(2, yyvsp, yyval);}
    | '{' ArrayInitializers '}'					{yaccActions::variableInitializer(3, yyvsp, yyval);}
    ;

ArrayInitializers
	: VariableInitializer							{yaccActions::arrayInitializers(1 ,yyvsp, yyval);}
	| ArrayInitializers ',' VariableInitializer		{yaccActions::arrayInitializers(2 ,yyvsp, yyval);}
	;

MethodDeclaration
	: Modifiers TypeSpecifier MethodDeclarator Throws MethodBody										{yaccActions::methodDeclaration(1, yyvsp, yyval);}
	| Modifiers TypeSpecifier MethodDeclarator        MethodBody										{yaccActions::methodDeclaration(2, yyvsp, yyval);}
	|           TypeSpecifier MethodDeclarator Throws MethodBody										{yaccActions::methodDeclaration(3, yyvsp, yyval);}
	|           TypeSpecifier MethodDeclarator        MethodBody										{yaccActions::methodDeclaration(4, yyvsp, yyval);}
	|			TypeSpecifier MethodDeclarator		  '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::methodDeclaration(5, yyvsp, yyval);}
	| Modifiers	TypeSpecifier MethodDeclarator		  '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::methodDeclaration(6, yyvsp, yyval);}
	| Modifiers	TypeSpecifier MethodDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::methodDeclaration(7, yyvsp, yyval);}
	|			TypeSpecifier MethodDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::methodDeclaration(8, yyvsp, yyval);}
	;

MethodDeclarator
	: DeclaratorName '(' ParameterList ')'		{yaccActions::methodDeclarator(1, yyvsp, yyval);}
	| DeclaratorName '(' ParameterList error	{yaccActions::methodDeclarator(2, yyvsp, yyval); yyerrok; skipFrom(METHOD);}
	| DeclaratorName '(' ')'					{yaccActions::methodDeclarator(3, yyvsp, yyval);}
	| DeclaratorName '(' error					{yaccActions::methodDeclarator(4, yyvsp, yyval); yyerrok; skipFrom(METHOD);}
	;

ParameterList
	: Parameter						{yaccActions::parameterList(1, yyvsp, yyval);}
	| ParameterList ',' Parameter	{yaccActions::parameterList(2, yyvsp, yyval);}
	;

Parameter
	: TypeSpecifier VariableDeclarator			{yaccActions::parameter(1, yyvsp, yyval);}
    | FINAL TypeSpecifier VariableDeclarator	{yaccActions::parameter(2, yyvsp, yyval);}
	;

DeclaratorName
	: IDENTIFIER			{yaccActions::declaratorName(1, yyvsp, yyval);}
    | DeclaratorName OP_DIM	{yaccActions::declaratorName(2, yyvsp, yyval);}
    ;

Throws
	: THROWS ClassNameList
	;

MethodBody
	: Block			{yaccActions::methodBody(1, yyvsp, yyval);}
	| WrongBlock	{yaccActions::methodBody(2, yyvsp, yyval);}
	| ';'			{yaccActions::methodBody(3, yyvsp, yyval);}
	;

ConstructorDeclaration
	: Modifiers ConstructorDeclarator Throws AnyBlock	{yaccActions::constructorDeclaration(1, yyvsp, yyval);}
	| Modifiers ConstructorDeclarator        AnyBlock	{yaccActions::constructorDeclaration(2, yyvsp, yyval);}
	|           ConstructorDeclarator Throws AnyBlock	{yaccActions::constructorDeclaration(3, yyvsp, yyval);}
	|           ConstructorDeclarator        AnyBlock	{yaccActions::constructorDeclaration(4, yyvsp, yyval);}
	| Modifiers ConstructorDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::constructorDeclaration(5, yyvsp, yyval); YYACCEPT;}
	| Modifiers ConstructorDeclarator        '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::constructorDeclaration(6, yyvsp, yyval); YYACCEPT;}
	|           ConstructorDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::constructorDeclaration(7, yyvsp, yyval); YYACCEPT;}
	|           ConstructorDeclarator        '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::constructorDeclaration(8, yyvsp, yyval); YYACCEPT;}
	;

ConstructorDeclarator
	: IDENTIFIER '(' ParameterList ')'	{yaccActions::constructorDeclarator(1, yyvsp, yyval);}
	| IDENTIFIER '(' ')'				{yaccActions::constructorDeclarator(2, yyvsp, yyval);}
	;

StaticInitializer
	: STATIC Block		{yaccActions::staticInitializer(1, yyvsp, yyval);}
	| STATIC '{' ENDF	{yaccActions::staticInitializer(2, yyvsp, yyval); YYACCEPT;}
	| STATIC '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::staticInitializer(3, yyvsp, yyval); YYACCEPT;}
	;

NonStaticInitializer
        : Block		{yaccActions::nonStaticInitializer(1, yyvsp, yyval);}
		| '{' ENDF	{yaccActions::nonStaticInitializer(2, yyvsp, yyval);}
		| '{' LocalVariableDeclarationsAndStatements ENDF	{yaccActions::nonStaticInitializer(3, yyvsp, yyval);}
        ;

Extends
	: EXTENDS ClassNameList	{yaccActions::extends(yyvsp, yyval);}
	;


AnyBlock: Block			{ yaccActions::anyBlock(1, yyvsp, yyval);}
		| WrongBlock	{ yaccActions::anyBlock(2, yyvsp, yyval);}
		;


Block
	: '{' LocalVariableDeclarationsAndStatements '}'	{yaccActions::block(1, yyvsp, yyval);}
	| '{' '}'											{yaccActions::block(2, yyvsp, yyval);}
    ;

WrongBlock
	: error LocalVariableDeclarationsAndStatements '}'	{yaccActions::wrongBlock(1, yyvsp, yyval);}
	| error LocalVariableDeclarationsAndStatements ENDF	{yaccActions::wrongBlock(2, yyvsp, yyval); YYACCEPT;}
	| error '}'											{yyerrok; yaccActions::wrongBlock(3, yyvsp, yyval);}
	| error ENDF										{yyerrok; yaccActions::wrongBlock(4, yyvsp, yyval); YYACCEPT;}
	| '{'   ENDF										{yyerror("syntax error, unexpected end of file, expecting \'}\'"); yaccActions::wrongBlock(5, yyvsp, yyval); YYACCEPT;}
	;

LocalVariableDeclarationsAndStatements
	: LocalVariableDeclarationOrStatement						{yaccActions::localVariableDeclarationsAndStatements(1, yyvsp, yyval);}
	| LocalVariableDeclarationsAndStatements LocalVariableDeclarationOrStatement {yaccActions::localVariableDeclarationsAndStatements(2, yyvsp, yyval);}
	;

LocalVariableDeclarationOrStatement
	: LocalVariableDeclarationStatement		{yaccActions::localVariableDeclarationOrStatement(1, yyvsp, yyval);}
	| Statement								{yaccActions::localVariableDeclarationOrStatement(2, yyvsp, yyval);}
	| error									{yaccActions::localVariableDeclarationOrStatement(3, yyvsp, yyval); yyerrok; skipFrom(STATEMENT);}
	;

LocalVariableDeclarationStatement
	: TypeSpecifier VariableDeclarators ';'			{yaccActions::localVariableDeclarationStatement(1, yyvsp, yyval);}
    | FINAL TypeSpecifier VariableDeclarators ';'	{yaccActions::localVariableDeclarationStatement(2, yyvsp, yyval);}
	;

Statement
	: EmptyStatement			{ yaccActions::statement(1, yyvsp, yyval); }
	| LabelStatement			{ yaccActions::statement(2, yyvsp, yyval); }
	| ExpressionStatement ';'	{ yaccActions::statement(3, yyvsp, yyval); }
    | SelectionStatement		{ yaccActions::statement(4, yyvsp, yyval); }
    | IterationStatement		{ yaccActions::statement(5, yyvsp, yyval); }
	| JumpStatement				{ yaccActions::statement(6, yyvsp, yyval); }
	| GuardingStatement			{ yaccActions::statement(7, yyvsp, yyval); }
	| Block						{ yaccActions::statement(8, yyvsp, yyval); }
	| PrintStatement			{yaccActions::statement(9, yyvsp, yyval);}
	;

PrintStatement
	: PRINT '(' Expression ')'	{yaccActions::printStatement(yyvsp, yyval);}
	;

EmptyStatement
	: ';'		{yaccActions::emptyStatement(yyvsp, yyval);}
    ;

LabelStatement
	: IDENTIFIER ':'				{yaccActions::labelStatement(1, yyvsp, yyval);}
    | CASE ConstantExpression ':'	{yaccActions::labelStatement(2, yyvsp, yyval);}
	| DEFAULT ':'					{yaccActions::labelStatement(3, yyvsp, yyval);}
    ;

ExpressionStatement
	: Expression		{yaccActions::expressionStatement(yyvsp, yyval);}
	;

SelectionStatement
	: IF '(' Expression ')' Statement	%prec IfStmt			{yaccActions::selectionStatement(1, yyvsp, yyval);}
    | IF '(' Expression ')' Statement ELSE Statement			{yaccActions::selectionStatement(2, yyvsp, yyval);}
    | SWITCH '(' Expression ')' Block							{yaccActions::selectionStatement(3, yyvsp, yyval);}
    ;

IterationStatement
	: WHILE '(' Expression ')' Statement						{yaccActions::iterationStatement(1, yyvsp, yyval);}
	| DO Statement WHILE '(' Expression ')' ';'					{yaccActions::iterationStatement(2, yyvsp, yyval);}
	| FOR '(' ForInit ForExpr ForIncr ')' Statement				{yaccActions::iterationStatement(3, yyvsp, yyval);}
	| FOR '(' ForInit ForExpr         ')' Statement				{yaccActions::iterationStatement(4, yyvsp, yyval);}
	| FOR '(' TypeSpecifier IDENTIFIER ':' Expression ')' Statement {yaccActions::iterationStatement(5, yyvsp, yyval);}
	;

ForInit
	: ExpressionStatements ';'				{yaccActions::forInit(1, yyvsp, yyval);}
	| LocalVariableDeclarationStatement		{yaccActions::forInit(2, yyvsp, yyval);}
	| ';'									{yaccActions::forInit(3, yyvsp, yyval);}
	;

ForExpr
	: Expression ';'						{yaccActions::forExpr(1, yyvsp, yyval);}
	| ';'									{yaccActions::forExpr(2, yyvsp, yyval);}
	;

ForIncr
	: ExpressionStatements					{yaccActions::forIncr(yyvsp, yyval);}
	;

ExpressionStatements
	: ExpressionStatement							{yaccActions::expressionStatements(1, yyvsp, yyval);}
	| ExpressionStatements ',' ExpressionStatement	{yaccActions::expressionStatements(2, yyvsp, yyval);}
	;

JumpStatement
	: BREAK IDENTIFIER ';'		{ yaccActions::jumpStatement(1, yyvsp, yyval); }
	| BREAK            ';'		{ yaccActions::jumpStatement(2, yyvsp, yyval); }
    | CONTINUE IDENTIFIER ';'	{ yaccActions::jumpStatement(3, yyvsp, yyval); }
	| CONTINUE            ';'	{ yaccActions::jumpStatement(4, yyvsp, yyval); }
	| RETURN Expression ';'		{ yaccActions::jumpStatement(5, yyvsp, yyval); }
	| RETURN            ';'		{ yaccActions::jumpStatement(6, yyvsp, yyval); }
	| THROW Expression ';'		{ yaccActions::jumpStatement(7, yyvsp, yyval); }
	;

GuardingStatement
	: SYNCHRONIZED '(' Expression ')' Statement
	| TRY Block Finally				{yaccActions::guardingStatement(1, yyvsp, yyval);}
	| TRY Block Catches				{yaccActions::guardingStatement(2, yyvsp, yyval);}
	| TRY Block Catches Finally		{yaccActions::guardingStatement(3, yyvsp, yyval);}
	;

Catches
	: Catch			{yaccActions::catches(1, yyvsp, yyval);}
	| Catches Catch	{yaccActions::catches(2, yyvsp, yyval);}
	;

Catch
	: CatchHeader Block											{yaccActions::jCatch(1, yyvsp, yyval);}
	;

CatchHeader
	: CATCH '(' TypeSpecifier IDENTIFIER ')'	{yaccActions::catchHeader(1, yyvsp, yyval);}
	| CATCH '(' TypeSpecifier ')'				{yaccActions::catchHeader(2, yyvsp, yyval);}
	;

Finally
	: FINALLY Block											{yaccActions::jFinally(1, yyvsp, yyval);}
	;

PrimaryExpression
	: QualifiedName { yaccActions::primaryExpression(1,yyvsp,yyval); }
	| NotJustName	{ yaccActions::primaryExpression(2,yyvsp,yyval); }
	;

NotJustName
	: SpecialName				{ yaccActions::notJustName(1,yyvsp,yyval); }
	| NewAllocationExpression	{ yaccActions::notJustName(2,yyvsp,yyval); }
	| ComplexPrimary			{ yaccActions::notJustName(3,yyvsp,yyval); }
	;

ComplexPrimary
	: '(' Expression ')'			{ yaccActions::complexPrimary(1,yyvsp,yyval); }
	| ComplexPrimaryNoParenthesis	{ yaccActions::complexPrimary(2,yyvsp,yyval); }
	;

ComplexPrimaryNoParenthesis
	: Literals		{ yaccActions::complexPrimaryNoParenthesis(1,yyvsp,yyval); }
	| ArrayAccess	{ yaccActions::complexPrimaryNoParenthesis(2,yyvsp,yyval); }
	| FieldAccess	{ yaccActions::complexPrimaryNoParenthesis(3,yyvsp,yyval); }
	| MethodCall	{ yaccActions::complexPrimaryNoParenthesis(4,yyvsp,yyval); }
	| NewInner
	;

Literals
	: INT_LITERAL		{ yaccActions::literals(1,yyvsp,yyval);  }
	| LONG_LITERAL		{ yaccActions::literals(2,yyvsp,yyval);  }
	| DOUBLE_LITERAL	{ yaccActions::literals(3,yyvsp,yyval);  }
	| FLOAT_LITERAL		{ yaccActions::literals(4,yyvsp,yyval);  }
	| STRING_LITERAL	{ yaccActions::literals(5,yyvsp,yyval);  }
	| CHAR_LITERAL		{ yaccActions::literals(6,yyvsp,yyval);  }
	| BOOLLIT			{ yaccActions::literals(7,yyvsp,yyval);  }
	;
ArrayAccess
	: QualifiedName '[' Expression ']'		{ yaccActions::arrayAccess(1,yyvsp,yyval); }
	| ComplexPrimary '[' Expression ']'		{ yaccActions::arrayAccess(2,yyvsp,yyval); }
	;

FieldAccess
	: NotJustName '.' IDENTIFIER				{ yaccActions::fieldAccess(1,yyvsp,yyval); }
	| RealPostfixExpression '.' IDENTIFIER		{ yaccActions::fieldAccess(2,yyvsp,yyval); }
    | QualifiedName '.' THIS					{ yaccActions::fieldAccess(3,yyvsp,yyval); }
    | QualifiedName '.' CLASS					{ yaccActions::fieldAccess(4,yyvsp,yyval); }
    | PrimitiveType '.' CLASS					{ yaccActions::fieldAccess(5,yyvsp,yyval); }
	;

MethodCall
	: MethodAccess '(' ArgumentList ')'			{ yaccActions::methodCall(1,yyvsp,yyval); }
	| MethodAccess '(' ')'						{ yaccActions::methodCall(2,yyvsp,yyval); }
	;

MethodAccess
	: ComplexPrimaryNoParenthesis		{ yaccActions::methodAccess(1,yyvsp,yyval); }
	| SpecialName						{ yaccActions::methodAccess(2,yyvsp,yyval); }
	| QualifiedName						{ yaccActions::methodAccess(3,yyvsp,yyval); }
	;

NewInner
	: NotJustName '.' NEW IDENTIFIER '(' ')'				{yaccActions::NewInner(1,yyvsp,yyval);}
	| NotJustName '.' NEW IDENTIFIER '(' ArgumentList ')'	{yaccActions::NewInner(2,yyvsp,yyval);}
	| QualifiedName '.' NEW IDENTIFIER '(' ')'				{yaccActions::NewInner(3,yyvsp,yyval);}
	| QualifiedName '.' NEW IDENTIFIER '(' ArgumentList ')'	{yaccActions::NewInner(4,yyvsp,yyval);}
	;
		
SpecialName
	: THIS		{ yaccActions::specialName(1 ,yyvsp, yyval); }
	| SUPER		{ yaccActions::specialName(2 ,yyvsp, yyval); }
	| JNULL		{ yaccActions::specialName(3 ,yyvsp, yyval); }
	;

ArgumentList
	: Expression						{ yaccActions::argumentList(1,yyvsp,yyval); }
	| ArgumentList ',' Expression		{ yaccActions::argumentList(2,yyvsp,yyval); }
	;

NewAllocationExpression	
        : PlainNewAllocationExpression						{ yaccActions::newAllocationExpression(1, yyvsp, yyval); }
        | QualifiedName '.' PlainNewAllocationExpression	{ yaccActions::newAllocationExpression(2, yyvsp, yyval); }
        ;

PlainNewAllocationExpression
    	: ArrayAllocationExpression								{ yaccActions::plainNewAllocationExpression(1,yyvsp,yyval); }
    	| ClassAllocationExpression								{ yaccActions::plainNewAllocationExpression(2,yyvsp,yyval); }
    	| ArrayAllocationExpression '{' '}'						{ yaccActions::plainNewAllocationExpression(3,yyvsp,yyval); }
    	| ClassAllocationExpression '{' '}'						{ yaccActions::plainNewAllocationExpression(4,yyvsp,yyval); }
    	| ArrayAllocationExpression '{' ArrayInitializers '}'	{ yaccActions::plainNewAllocationExpression(5,yyvsp,yyval); }
    	| ClassAllocationExpression '{' FieldDeclarations '}'	{ yaccActions::plainNewAllocationExpression(6,yyvsp,yyval); }
    	;

ClassAllocationExpression
	: NEW TypeName '(' ArgumentList ')'		{ yaccActions::classAllocationExpression(1,  yyvsp, yyval); }
	| NEW TypeName '('              ')'		{ yaccActions::classAllocationExpression(2,  yyvsp, yyval); }
        ;

ArrayAllocationExpression
	: NEW TypeName DimExprs Dims		{ yaccActions::arrayAllocationExpression(1, yyvsp, yyval); }
	| NEW TypeName DimExprs				{ yaccActions::arrayAllocationExpression(2, yyvsp, yyval); }
    | NEW TypeName Dims					{ yaccActions::arrayAllocationExpression(3, yyvsp, yyval); }
	;

DimExprs
	: DimExpr			{ yaccActions::dimExprs(1, yyvsp, yyval); }
	| DimExprs DimExpr	{ yaccActions::dimExprs(2, yyvsp, yyval); }
	;

DimExpr
	: '[' Expression ']'	{ yaccActions::dimExpr(1, yyvsp, yyval); }
	;

Dims
	: OP_DIM		{ yaccActions::dims(1, yyvsp, yyval); }
	| Dims OP_DIM	{ yaccActions::dims(2, yyvsp, yyval); }
	;

PostfixExpression
	: PrimaryExpression			{ yaccActions::postfixExpression(1, yyvsp, yyval); }
	| RealPostfixExpression		{ yaccActions::postfixExpression(2, yyvsp, yyval); }
	;

RealPostfixExpression
	: PostfixExpression OP_INC		{ yaccActions::realPostfixExpression(1, yyvsp, yyval); }
	| PostfixExpression OP_DEC		{ yaccActions::realPostfixExpression(2, yyvsp, yyval); }
	;

UnaryExpression
	: OP_INC UnaryExpression					{ yaccActions::unaryExpression(1, yyvsp, yyval); }
	| OP_DEC UnaryExpression					{ yaccActions::unaryExpression(2, yyvsp, yyval); }
	| ArithmeticUnaryOperator CastExpression	{ yaccActions::unaryExpression(3, yyvsp, yyval); }
	| LogicalUnaryExpression					{ yaccActions::unaryExpression(4, yyvsp, yyval); }
	;

LogicalUnaryExpression
	: PostfixExpression							{ yaccActions::logicalUnaryExpression(1, yyvsp, yyval); }
	| LogicalUnaryOperator UnaryExpression		{ yaccActions::logicalUnaryExpression(2, yyvsp, yyval); }
	;

LogicalUnaryOperator
	: '~'
	| '!'
	;

ArithmeticUnaryOperator
	: '+'
	| '-'
	;

CastExpression
	: UnaryExpression
	| '(' PrimitiveTypeExpression ')' CastExpression { yaccActions::castExpression(1, yyvsp, yyval);}
	| '(' ClassTypeExpression ')' CastExpression { yaccActions::castExpression(2, yyvsp, yyval);}
	| '(' Expression ')' LogicalUnaryExpression	{yaccActions::castExpression(3, yyvsp, yyval);}
	;

	PrimitiveTypeExpression
	: PrimitiveType {yaccActions::primitiveTypeExpression(1, yyvsp,yyval);}
        | PrimitiveType Dims  {yaccActions::primitiveTypeExpression(2, yyvsp,yyval);}
        ;

ClassTypeExpression
    :  QualifiedName Dims  {yaccActions::primitiveTypeExpression(3, yyvsp,yyval);}
        ;

MultiplicativeExpression
	: CastExpression								{ yaccActions::multiplicativeExpression(1,yyvsp,yyval); }
	| MultiplicativeExpression '*' CastExpression	{ yaccActions::multiplicativeExpression(2,yyvsp,yyval); }
	| MultiplicativeExpression '/' CastExpression	{ yaccActions::multiplicativeExpression(3,yyvsp,yyval); }
	| MultiplicativeExpression '%' CastExpression	{ yaccActions::multiplicativeExpression(4,yyvsp,yyval); }
	;

AdditiveExpression
	: MultiplicativeExpression							{ yaccActions::additiveExpression(1,yyvsp,yyval);  }
    | AdditiveExpression '+' MultiplicativeExpression	{ yaccActions::additiveExpression(2,yyvsp,yyval);  }
	| AdditiveExpression '-' MultiplicativeExpression	{ yaccActions::additiveExpression(3,yyvsp,yyval);  }
        ;

ShiftExpression
	: AdditiveExpression							{ yaccActions::shiftExpression(1,yyvsp,yyval); }
    | ShiftExpression OP_SHL AdditiveExpression
    | ShiftExpression OP_SHR AdditiveExpression
    | ShiftExpression OP_SHRR AdditiveExpression
	;

RelationalExpression
	: ShiftExpression									{ yaccActions::relationalExpression(1,yyvsp,yyval); }
    | RelationalExpression '<' ShiftExpression			{ yaccActions::relationalExpression(2,yyvsp,yyval); }
	| RelationalExpression '>' ShiftExpression			{ yaccActions::relationalExpression(3,yyvsp,yyval); }
	| RelationalExpression OP_LE ShiftExpression		{ yaccActions::relationalExpression(4,yyvsp,yyval); }
	| RelationalExpression OP_GE ShiftExpression		{ yaccActions::relationalExpression(5,yyvsp,yyval); }
	| RelationalExpression INSTANCEOF TypeSpecifier		{ yaccActions::relationalExpression(6,yyvsp,yyval); }
	;

EqualityExpression
	: RelationalExpression								{ yaccActions::equalityExpression(1,yyvsp,yyval); }
    | EqualityExpression OP_EQ RelationalExpression		{ yaccActions::equalityExpression(2,yyvsp,yyval); }
    | EqualityExpression OP_NE RelationalExpression		{ yaccActions::equalityExpression(3,yyvsp,yyval); }
    ;

AndExpression
	: EqualityExpression					{ yaccActions::andExpression(1,yyvsp,yyval); }
    | AndExpression '&' EqualityExpression	{ yaccActions::andExpression(2,yyvsp,yyval); }
    ;

ExclusiveOrExpression
	: AndExpression								{ yaccActions::exclusiveOrExpression(1,yyvsp,yyval); }
	| ExclusiveOrExpression '^' AndExpression	{ yaccActions::exclusiveOrExpression(2,yyvsp,yyval); }
	;

InclusiveOrExpression
	: ExclusiveOrExpression								{ yaccActions::inclusiveOrExpression(1,yyvsp,yyval); }
	| InclusiveOrExpression '|' ExclusiveOrExpression	{ yaccActions::inclusiveOrExpression(2,yyvsp,yyval); }
	;

ConditionalAndExpression
	: InclusiveOrExpression										{ yaccActions::conditionalAndExpression(1,yyvsp,yyval); }
	| ConditionalAndExpression OP_LAND InclusiveOrExpression	{ yaccActions::conditionalAndExpression(2,yyvsp,yyval); }
	;

ConditionalOrExpression
	: ConditionalAndExpression									{yaccActions::conditionalOrExpression(1,yyvsp,yyval); }
	| ConditionalOrExpression OP_LOR ConditionalAndExpression	{yaccActions::conditionalOrExpression(2,yyvsp,yyval); }
	;

ConditionalExpression
	: ConditionalOrExpression											{yaccActions::conditionalExpression(1,yyvsp,yyval); }
	| ConditionalOrExpression '?' Expression ':' ConditionalExpression	{yaccActions::conditionalExpression(2,yyvsp,yyval); }
	;

AssignmentExpression
	: ConditionalExpression										{yaccActions::assignmentExpression(1,yyvsp,yyval);}
	| UnaryExpression AssignmentOperator AssignmentExpression	{yaccActions::assignmentExpression(2,yyvsp,yyval);}
	;

AssignmentOperator
	: '='
	| ASS_MUL
	| ASS_DIV
	| ASS_MOD
	| ASS_ADD
	| ASS_SUB
	| ASS_SHL
	| ASS_SHR
	| ASS_SHRR
	| ASS_AND
	| ASS_XOR
	| ASS_OR
	;

Expression
	: AssignmentExpression	{}
        ;

ConstantExpression
	: ConditionalExpression
	;

%%



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
