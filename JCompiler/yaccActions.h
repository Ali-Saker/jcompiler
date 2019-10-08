#ifndef _yaccActions_
#define _yaccActions_

#include"global.h"
#include"ASTfiles.h"
#include<stdio.h>
#include<stdlib.h>
#include"ErrorRecovery.h"

class yaccActions{
public:

	static YYSTYPE* yyvsp;
	static YYSTYPE yyval;

	/* types */
	static void typeSpecifier(int, YYSTYPE*, YYSTYPE&);
	static void typeName(int, YYSTYPE*, YYSTYPE&);
	static void primitiveType(int, YYSTYPE*, YYSTYPE&);

	/* go for it */
	static void compilationUnit();
	static void programFile(int, YYSTYPE*, JCompilationUnit*);
	static void packageStatement(int, YYSTYPE*, YYSTYPE&);
	static void typeDeclarations(int, YYSTYPE*, JCompilationUnit*, stack<char*>&);
	static void typeDeclarationOptSemi(int, YYSTYPE*, YYSTYPE&);
	static void importStatements(int, YYSTYPE*, JCompilationUnit*);
	static void importStatement(int, YYSTYPE*, YYSTYPE&);
	static void QualifiedName(int, YYSTYPE*, YYSTYPE&);
	static void typeDeclaration(int, YYSTYPE*, YYSTYPE&);
	static void classHeader(int, YYSTYPE*, YYSTYPE& );
	static void modifiers(int, YYSTYPE*, YYSTYPE&);
	static void modifier(int, YYSTYPE*, YYSTYPE&);
	static void classWord(int, YYSTYPE&);
	static void interfaces(YYSTYPE*, YYSTYPE&);
	static void extends(YYSTYPE*, YYSTYPE&);
	static void classNameList(int, YYSTYPE*, YYSTYPE&);
	static void fieldDeclarations(int, YYSTYPE*, YYSTYPE&);
	static void fieldDeclaration(int, YYSTYPE*, YYSTYPE&);
	static void fieldVariableDeclaration(int, YYSTYPE*, YYSTYPE&);
	static void variableDeclarators(int, YYSTYPE*, YYSTYPE&);
	static void	variableDeclarator(int, YYSTYPE*, YYSTYPE&);
	static void declaratorName(int, YYSTYPE*, YYSTYPE&);
	static void variableInitializer(int , YYSTYPE*, YYSTYPE&);
	static void methodDeclaration(int , YYSTYPE*, YYSTYPE&);
	static void methodDeclarator(int , YYSTYPE*, YYSTYPE&);
	static void	parameterList(int , YYSTYPE*, YYSTYPE&);
	static void parameter(int , YYSTYPE*, YYSTYPE&);
	static void methodBody(int , YYSTYPE*, YYSTYPE&);
	static void anyBlock(int , YYSTYPE*, YYSTYPE&);
	static void block(int , YYSTYPE*, YYSTYPE&);
	static void wrongBlock(int , YYSTYPE*, YYSTYPE&);
	static void localVariableDeclarationsAndStatements(int , YYSTYPE*, YYSTYPE&);
	static void localVariableDeclarationOrStatement(int, YYSTYPE*, YYSTYPE&);
	static void localVariableDeclarationStatement(int, YYSTYPE*, YYSTYPE&);
	static void constructorDeclaration(int, YYSTYPE*, YYSTYPE&);
	static void constructorDeclarator(int, YYSTYPE*, YYSTYPE&);
	static void staticInitializer(int, YYSTYPE*, YYSTYPE&);
	static void nonStaticInitializer(int, YYSTYPE*, YYSTYPE&);


	/* statements */
	static void statement(int, YYSTYPE*, YYSTYPE&);
	static void emptyStatement(YYSTYPE*, YYSTYPE&);
	static void printStatement(YYSTYPE*, YYSTYPE&);
	static void labelStatement(int, YYSTYPE*, YYSTYPE&);
	static void expressionStatement(YYSTYPE*, YYSTYPE&);
	static void expressionStatements(int, YYSTYPE*, YYSTYPE&);
	static void selectionStatement(int , YYSTYPE* , YYSTYPE&);
	static void iterationStatement(int, YYSTYPE*, YYSTYPE&);
	static void forInit(int, YYSTYPE*, YYSTYPE&);
	static void forExpr(int, YYSTYPE*, YYSTYPE&);
	static void forIncr(YYSTYPE*, YYSTYPE&);
	static void jumpStatement(int, YYSTYPE*, YYSTYPE&);
	static void guardingStatement(int, YYSTYPE*, YYSTYPE&);
	static void catches(int, YYSTYPE*, YYSTYPE&);
	static void jCatch(int, YYSTYPE*, YYSTYPE&);
	static void catchHeader(int, YYSTYPE*, YYSTYPE&);
	static void jFinally(int, YYSTYPE*, YYSTYPE&);
	


	/* expressions */
	static void literals(int, YYSTYPE*, YYSTYPE&);
	static void multiplicativeExpression(int, YYSTYPE*, YYSTYPE&);
	static void additiveExpression(int, YYSTYPE*, YYSTYPE&);
	static void shiftExpression(int, YYSTYPE*, YYSTYPE&);
	static void relationalExpression(int, YYSTYPE*, YYSTYPE&);
	static void equalityExpression(int, YYSTYPE*, YYSTYPE&);
	static void andExpression(int, YYSTYPE*, YYSTYPE&);
	static void exclusiveOrExpression(int, YYSTYPE*, YYSTYPE&);
	static void inclusiveOrExpression(int, YYSTYPE*, YYSTYPE&);
	static void conditionalAndExpression(int, YYSTYPE*, YYSTYPE&);
	static void conditionalOrExpression(int, YYSTYPE*, YYSTYPE&);
	static void conditionalExpression(int, YYSTYPE*, YYSTYPE&);
	static void assignmentExpression(int, YYSTYPE*, YYSTYPE&);
	static void expression(int, YYSTYPE*, YYSTYPE&);
	static void unaryExpression(int, YYSTYPE*, YYSTYPE&);
	static void logicalUnaryExpression(int, YYSTYPE*, YYSTYPE&);
	static void postfixExpression(int, YYSTYPE*, YYSTYPE&);
	static void realPostfixExpression(int, YYSTYPE*, YYSTYPE&);
	static void primaryExpression(int, YYSTYPE*, YYSTYPE&);
	static void notJustName(int, YYSTYPE*, YYSTYPE&);
	static void specialName(int, YYSTYPE*, YYSTYPE&);
	static void newAllocationExpression(int, YYSTYPE*, YYSTYPE&);
	static void plainNewAllocationExpression(int, YYSTYPE*, YYSTYPE&);
	static void classAllocationExpression(int, YYSTYPE*, YYSTYPE&);
	static void arrayAllocationExpression(int, YYSTYPE*, YYSTYPE&);
	static void complexPrimary(int, YYSTYPE*, YYSTYPE&);
	static void complexPrimaryNoParenthesis(int, YYSTYPE*, YYSTYPE&);
	static void arrayAccess(int, YYSTYPE*, YYSTYPE&);
	static void fieldAccess(int, YYSTYPE*, YYSTYPE&);
	static void methodCall(int, YYSTYPE*, YYSTYPE&);
	static void methodAccess(int, YYSTYPE*, YYSTYPE&);
	static void argumentList(int, YYSTYPE*, YYSTYPE&);
	static void dimExprs(int, YYSTYPE*, YYSTYPE&);
	static void dimExpr(int, YYSTYPE*, YYSTYPE&);
	static void dims(int, YYSTYPE*, YYSTYPE&);
	static void constantExpression(int, YYSTYPE*, YYSTYPE&);
	static void primitiveTypeExpression(int, YYSTYPE*, YYSTYPE&);
	static void arrayInitializers(int, YYSTYPE*, YYSTYPE&);
	static void castExpression(int, YYSTYPE*, YYSTYPE&);
	static void NewInner(int, YYSTYPE*, YYSTYPE&);
	

};

#endif