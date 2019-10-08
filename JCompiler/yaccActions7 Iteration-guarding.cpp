#include"yaccActions.h"

void yaccActions::iterationStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"WHILE \'(\' Expression \')\' Statement"<<endl;
		yyval.tokenInfo.iterationStatement = new JWhileStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol, yyvsp[0].tokenInfo.stmt,
			yyvsp[-2].tokenInfo.expr);
		break; 
	case 2:
		cout<<"DO Statement WHILE \'(\' Expression \')\' \';\'"<<endl;
		yyval.tokenInfo.iterationStatement = new JWhileStatement(yyvsp[-6].tokenInfo.tokenLine, yyvsp[-6].tokenInfo.tokenCol, yyvsp[-5].tokenInfo.stmt,
			yyvsp[-2].tokenInfo.expr);
		break;
	case 3:
		cout<<"FOR \'(\' ForInit ForExpr ForIncr \')\' Statement"<<endl;
		if (yyvsp[-4].tokenInfo.exprStmtsList != 0){
			yyval.tokenInfo.iterationStatement = new JForStatement(yyvsp[-6].tokenInfo.tokenLine, yyvsp[-6].tokenInfo.tokenCol, yyvsp[0].tokenInfo.stmt,
				yyvsp[-4].tokenInfo.exprStmtsList->toVector(), 0, yyvsp[-3].tokenInfo.expr, yyvsp[-2].tokenInfo.exprStmtsList->toVector());
		}
		else{
			yyval.tokenInfo.iterationStatement = new JForStatement(yyvsp[-6].tokenInfo.tokenLine, yyvsp[-6].tokenInfo.tokenCol, yyvsp[0].tokenInfo.stmt,
				0, yyvsp[-4].tokenInfo.variableDeclaration, yyvsp[-3].tokenInfo.expr, yyvsp[-2].tokenInfo.exprStmtsList->toVector());
		}

		break;
	case 4:
		cout<<"FOR \'(\' ForInit ForExpr         \')\' Statement"<<endl;
		if (yyvsp[-3].tokenInfo.exprStmtsList != 0){
			yyval.tokenInfo.iterationStatement = new JForStatement(yyvsp[-5].tokenInfo.tokenLine, yyvsp[-5].tokenInfo.tokenCol, yyvsp[0].tokenInfo.stmt,
				yyvsp[-3].tokenInfo.exprStmtsList->toVector(), 0, yyvsp[-2].tokenInfo.expr, 0);
		}
		else{
			yyval.tokenInfo.iterationStatement = new JForStatement(yyvsp[-5].tokenInfo.tokenLine, yyvsp[-5].tokenInfo.tokenCol, yyvsp[0].tokenInfo.stmt,
				0, yyvsp[-3].tokenInfo.variableDeclaration, yyvsp[-2].tokenInfo.expr, 0);
		}
		break;
	case 5:
		cout << "FOR '(' TypeSpecifier IDENTIFIER ':' Expression ')' Statement" << endl;
		JVariableDeclaration *var = new JVariableDeclaration(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol,
			yyvsp[-5].tokenInfo.type, 0, 0);
		var->decls = new vector<JVariableDeclarator *>;
		var->decls->push_back(new JVariableDeclarator(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol,
			yyvsp[-4].tokenInfo.tokenImage, 0, 0));
		yyval.tokenInfo.iterationStatement = new JForeachStatement(yyvsp[-7].tokenInfo.tokenCol, yyvsp[-7].tokenInfo.tokenCol, yyvsp[0].tokenInfo.stmt,
			var, yyvsp[-2].tokenInfo.expr);
	}
}
void yaccActions::forInit(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"ExpressionStatements \';\'"<<endl;
		yyval.tokenInfo.exprStmtsList = yyvsp[-1].tokenInfo.exprStmtsList;
		yyval.tokenInfo.variableDeclaration = 0;
		break;
	case 2:
		cout<<"LocalVariableDeclarationStatement"<<endl;
		yyval.tokenInfo.exprStmtsList = 0;
		yyval.tokenInfo.variableDeclaration = yyvsp[0].tokenInfo.variableDeclaration;
		break;
	case 3:
		cout<<" \';\'"<<endl;
		yyval.tokenInfo.exprStmtsList = 0;
		yyval.tokenInfo.variableDeclaration = 0;
		break;
	}
}

void yaccActions::forExpr(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"Expression \';\'"<<endl;
		yyval.tokenInfo.expr = yyvsp[-1].tokenInfo.expr;
		break;
	case 2:
		cout<<"\';\'"<<endl;
		yyval.tokenInfo.expr = 0;
		break;
	}
}

void yaccActions::forIncr(YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout<<"ExpressionStatements"<<endl;
	yyval.tokenInfo.exprStmtsList = yyvsp[0].tokenInfo.exprStmtsList;
}

void yaccActions::guardingStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JGuardingStatement* jGuardingStatement = 0;
	switch (grammar)
	{
	case 1:
		cout << "TRY AnyBlock Finally" << endl;
		jGuardingStatement = new JGuardingStatement(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.block,
			0, yyvsp[0].tokenInfo.block);
		break;
	case 2:
		cout << "TRY AnyBlock Catches" << endl;
		jGuardingStatement = new JGuardingStatement(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.block,
			yyvsp[0].tokenInfo.catchesList->toVector(), 0);
		break;
	case 3:
		cout << "TRY AnyBlock Catches Finally" << endl;
		jGuardingStatement = new JGuardingStatement(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.block,
			yyvsp[-1].tokenInfo.catchesList->toVector(), yyvsp[0].tokenInfo.block);
		break;
	/*case 4:
		cout << "TRY \'{\' LocalVariableDeclarationsAndStatements ENDF Finally" << endl;
		jGuardingStatement = new JGuardingStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol,
			new JBlock(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.stmtList->toVector(), 0),
			0, yyvsp[0].tokenInfo.block);
		break;
	case 5:
		cout << "TRY \'{\' LocalVariableDeclarationsAndStatements ENDF Catches" << endl;
		jGuardingStatement = new JGuardingStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol,
			new JBlock(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.stmtList->toVector(), 0),
			yyvsp[0].tokenInfo.catchesList->toVector(), 0);
		break;
	case 6:
		cout << "TRY \'{\' LocalVariableDeclarationsAndStatements ENDF Catches Finally" << endl;
		jGuardingStatement = new JGuardingStatement(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol,
			new JBlock(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.stmtList->toVector(), 0),
			yyvsp[0].tokenInfo.catchesList->toVector(), 0);
		break;*/
	}
	yyval.tokenInfo.guardingStatement = jGuardingStatement;
}


void yaccActions::catches(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout << "Catch" << endl;
		yyval.tokenInfo.catchesList = new CatchesList();
		yyval.tokenInfo.catchesList->insert(yyvsp[0].tokenInfo.jCatch);
		break;
	case 2:
		cout << "Catches Catch" << endl;
		yyval.tokenInfo.catchesList = yyvsp[-1].tokenInfo.catchesList;
		yyval.tokenInfo.catchesList->insert(yyvsp[0].tokenInfo.jCatch);
		break;
	}
}

void yaccActions::jCatch(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout << "CatchHeader Block" << endl;
		yyval.tokenInfo.jCatch = yyvsp[-1].tokenInfo.jCatch;
		yyval.tokenInfo.jCatch->catchBlock = yyvsp[0].tokenInfo.block;
		break;
	/*case 2:
		cout << "CatchHeader \'{\' LocalVariableDeclarationsAndStatements ENDF" << endl;
		yyval.tokenInfo.jCatch = yyvsp[-3].tokenInfo.jCatch;
		yyval.tokenInfo.jCatch->catchBlock = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector());
		break;*/
	}
}

void yaccActions::catchHeader(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout << "CATCH \'(\' TypeSpecifier IDENTIFIER \')\'" << endl;
		yyval.tokenInfo.jCatch = new JCatch(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol,
			new JFormalParameter(yyvsp[-2].tokenInfo.type->typeName->getLine(), yyvsp[-2].tokenInfo.type->typeName->getCol(), 0, 
			new JVariableDeclarator(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage, 0, 0),
			yyvsp[-2].tokenInfo.type), 0);
		break;
	/*case 2:
		cout << "CATCH \'(\' TypeSpecifier \')\'" << endl;
		yyval.tokenInfo.jCatch = new JCatch(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.typeName, yyvsp[-1].tokenInfo.typeName->name, 0);
		break;*/
	}
}

void yaccActions::jFinally(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout << "FINALLY Block" << endl;
		yyval.tokenInfo.block = yyvsp[0].tokenInfo.block;
		break;
	/*case 2:
		cout << "FINALLY '{' LocalVariableDeclarationsAndStatements ENDF" << endl;
		yyval.tokenInfo.block = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector());
		break;*/
	}
}
