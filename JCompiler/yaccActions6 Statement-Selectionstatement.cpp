#include"yaccActions.h"


void yaccActions::statement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
		case 1:
			cout << "EmptyStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.emptyStatement;
			break;
		case 2:
			cout << "LabelStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.labelStatement;
			break;
		case 3:
			cout << "ExpressionStatement ';'" << endl;
			yyval.tokenInfo.stmt = yyvsp[-1].tokenInfo.expressionStatement;
			break;
		case 4:
			cout << "SelectionStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.selectionStatement;
			break;
		case 5:
			cout << "IterationStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.iterationStatement;
			break;
		case 6:
			cout << "JumpStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.jumpStatement;
			break;
		case 7:
			cout << "GuardingStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.guardingStatement;
			break;
		case 8:
			cout << "Block" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.block;
			break;
		case 9:
			cout << "PrintStatement" << endl;
			yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.printStatement;
			break;
	}
}

void yaccActions::printStatement(YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "PRINT \'(\' Expression \')\' " << endl;
	yyval.tokenInfo.printStatement = new Printer(yyvsp[-1].tokenInfo.expr);
}

void yaccActions::emptyStatement(YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << ';' << endl;
	yyval.tokenInfo.emptyStatement = new JEmptyStatement(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol);
}

void yaccActions::labelStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JLabelStatement* jLabelStatement = 0;
	switch (grammar){
	case 1:
		cout << "IDENTIFIER \':\'" << endl;
		jLabelStatement = new JLabelStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage, 0);
		break;
	case 2:
		cout << "CASE ConstantExpression \':\'" << endl;
		jLabelStatement = new JLabelStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "case", yyvsp[-1].tokenInfo.expr);
		break;
	case 3:
		cout << "DEFAULT \':\'" << endl;
		jLabelStatement = new JLabelStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "default", 0);
		break;
	}
	yyval.tokenInfo.labelStatement = jLabelStatement;
}

void yaccActions::expressionStatement(YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "Expression" << endl;
	yyval.tokenInfo.expressionStatement = new JExpressionStatement(yyvsp[0].tokenInfo.expr);
}

void yaccActions::selectionStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JSelectionStatement* jSelectionStatement = 0;
	switch (grammar)
	{
	case 1:
		cout << "IF \'(\' Expression \')\' Statement" << endl;
		jSelectionStatement = new JIfStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr,
			yyvsp[0].tokenInfo.stmt, 0);
		break;
	case 2:
		cout << "IF \'(\' Expression \')\' Statement ELSE Statement" << endl;
		jSelectionStatement = new JIfStatement(yyvsp[-6].tokenInfo.tokenLine, yyvsp[-6].tokenInfo.tokenCol, yyvsp[-4].tokenInfo.expr,
			yyvsp[-2].tokenInfo.stmt, yyvsp[0].tokenInfo.stmt);
		break;
	case 3:
		cout << "SWITCH \'(\' Expression \')\' Block" << endl;
		jSelectionStatement = new JSwitchStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr,
			yyvsp[0].tokenInfo.block);
		break;
	//case 4:
	//	cout << "SWITCH \'(\' Expression \')\' WrongBlock" << endl;
	//	jSelectionStatement = new JSwitchStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr,
	//		yyvsp[0].tokenInfo.block);
	//	break;
	//case 5:
	//	cout << "SWITCH \'(\' Expression \')\' \'{\' LocalVariableDeclarationsAndStatements ENDF" << endl;
	//	jSelectionStatement = new JSwitchStatement(yyvsp[-6].tokenInfo.tokenLine, yyvsp[-6].tokenInfo.tokenCol, 
	//	yyvsp[-4].tokenInfo.expr,
	//	new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector(), 0));
	//	break;
	}
	yyval.tokenInfo.selectionStatement = jSelectionStatement;
}


void yaccActions::jumpStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JJumpStatement* jJumpStatement = 0;
	switch (grammar)
	{
	case 1:
		cout << "BREAK IDENTIFIER \';\'" << endl;
		jJumpStatement = 0;
		break;
	case 2:
		cout << "BREAK			  \';\'" << endl;
		jJumpStatement = new JJumpStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "break", 0);
		break;
	case 3:
		cout << "CONTINUE IDENTIFIER \';\'" << endl;
		jJumpStatement = 0;
		break;
	case 4:
		cout << "CONTINUE			 \';\'" << endl;
		jJumpStatement = new JJumpStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "continue", 0);
		break;
	case 5:
		cout << "RETURN Expression \';\'" << endl;
		jJumpStatement = new JJumpStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "return",
			yyvsp[-1].tokenInfo.expr);
		break;
	case 6:
		cout << "RETURN			   \';\'" << endl;
		jJumpStatement = new JJumpStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "return", 0);
		break;
	case 7:
		cout << "THROW Expression \';\'" << endl;
		jJumpStatement = new JJumpStatement(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, "throw",
			yyvsp[-1].tokenInfo.expr);
		break;
	}
	yyval.tokenInfo.jumpStatement = jJumpStatement;
}

void yaccActions::expressionStatements(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"ExpressionStatement"<<endl;
		yyval.tokenInfo.exprStmtsList = new ExprStmtsList();
		yyval.tokenInfo.exprStmtsList->insert(yyvsp[0].tokenInfo.expressionStatement);
		break;
	case 2:
		cout<<"ExpressionStatements ',' ExpressionStatement"<<endl;
		yyval.tokenInfo.exprStmtsList = yyvsp[-2].tokenInfo.exprStmtsList;
		yyval.tokenInfo.exprStmtsList->insert(yyvsp[0].tokenInfo.expressionStatement);
		break;
	}
}