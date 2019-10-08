#include"yaccActions.h"

void yaccActions::localVariableDeclarationsAndStatements(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"LocalVariableDeclarationOrStatement"<<endl;
		yyval.tokenInfo.stmtList = new StatementsList();
		if (yyvsp[0].tokenInfo.stmt != 0){
			yyval.tokenInfo.stmtList->insert(yyvsp[0].tokenInfo.stmt);
		}
		break;
	case 2:
		cout<<"LocalVariableDeclarationsAndStatements LocalVariableDeclarationOrStatement"<<endl;
		if (yyvsp[0].tokenInfo.stmt != 0){
			yyval.tokenInfo.stmtList->insert(yyvsp[0].tokenInfo.stmt);
		}
		break;
	}

}

void yaccActions::localVariableDeclarationOrStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"LocalVariableDeclarationStatement"<<endl;
		yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.variableDeclaration;
		break;
	case 2:
		cout<<"Statement"<<endl;
		yyval.tokenInfo.stmt = yyvsp[0].tokenInfo.stmt;
		break;
	case 3:
		cout<<"ErrorStatement"<<endl;
		yyval.tokenInfo.stmt = 0;
		break;
	}
}

void yaccActions::localVariableDeclarationStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"TypeSpecifier VariableDeclarators \';\'"<<endl;
		yyval.tokenInfo.variableDeclaration = new JVariableDeclaration(yyvsp[-2].tokenInfo.type->typeName->getLine(), yyvsp[-2].tokenInfo.type->typeName->getCol(),
			yyvsp[-2].tokenInfo.type, 0, yyvsp[-1].tokenInfo.declaratorList->toVector());
		break;
	case 2:
		cout<<"FINAL TypeSpecifier VariableDeclarators \';\'"<<endl;
		yyval.tokenInfo.variableDeclaration = new JVariableDeclaration(yyvsp[-2].tokenInfo.type->typeName->getLine(), yyvsp[-2].tokenInfo.type->typeName->getCol(),
			yyvsp[-2].tokenInfo.type, new AccessProperty, yyvsp[-1].tokenInfo.declaratorList->toVector());
		yyval.tokenInfo.variableDeclaration->accessProperty->setAccessProperty(2);
		break;
	}
}

void yaccActions::constructorDeclaration(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"Modifiers ConstructorDeclarator Throws AnyBlock"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-2].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->accessProperty = yyvsp[-3].tokenInfo.accessProperty;
		yyval.tokenInfo.constructorDeclaration->throws = yyvsp[-1].tokenInfo.typeList->toVector();
		yyval.tokenInfo.constructorDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 2:
		cout<<"Modifiers ConstructorDeclarator        AnyBlock"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-1].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->accessProperty = yyvsp[-2].tokenInfo.accessProperty;
		yyval.tokenInfo.constructorDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 3:
		cout<<"ConstructorDeclarator Throws AnyBlock"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-2].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->throws = yyvsp[-1].tokenInfo.typeList->toVector();
		yyval.tokenInfo.constructorDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 4:
		cout<<"ConstructorDeclarator        AnyBlock"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-1].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 5:
		cout<<"Modifiers ConstructorDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-4].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->accessProperty = yyvsp[-5].tokenInfo.accessProperty;
		yyval.tokenInfo.constructorDeclaration->throws = yyvsp[-3].tokenInfo.typeList->toVector();
		yyval.tokenInfo.constructorDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 6:
		cout<<"Modifiers ConstructorDeclarator        '{' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-3].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->accessProperty = yyvsp[-4].tokenInfo.accessProperty;
		yyval.tokenInfo.constructorDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 7:
		cout<<"ConstructorDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-4].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->throws = yyvsp[-3].tokenInfo.typeList->toVector();
		yyval.tokenInfo.constructorDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 8:
		cout<<"ConstructorDeclarator        '{' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.constructorDeclaration = yyvsp[-3].tokenInfo.constructorDeclaration;
		yyval.tokenInfo.constructorDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	}
}

void yaccActions::constructorDeclarator(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"IDENTIFIER \'(\' ParameterList \')\'"<<endl;
		yyval.tokenInfo.constructorDeclaration = 
			new JConstructorDeclaration(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-3].tokenInfo.tokenImage,
			0, 0, PrimitiveType::JVOID, yyvsp[-1].tokenInfo.parameterList->toVector(), 0, 0);
		break;
	case 2:
		cout<<"IDENTIFIER \'(\' \')\'"<<endl;
		yyval.tokenInfo.constructorDeclaration = 
			new JConstructorDeclaration(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage,
			0, 0, PrimitiveType::JVOID, 0, 0, 0);
		break;
	}
}

void yaccActions::staticInitializer(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){

	switch (grammar){
	case 1:
		cout<<"STATIC Block"<<endl;
		yyval.tokenInfo.initializerDeclaration =
			new JInitializerDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, true, yyvsp[0].tokenInfo.block);
		break;
	case 2:
		cout<<"STATIC \'{\' ENDF"<<endl;
		yyval.tokenInfo.initializerDeclaration = 0;
		break;
	case 3:
		cout<<"STATIC \'{\' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.initializerDeclaration = new JInitializerDeclaration(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, true,
			new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector(), 0));
		break;
	}
}


void yaccActions::nonStaticInitializer(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){

	switch (grammar){
	case 1:
		cout<<"Block"<<endl;
		yyval.tokenInfo.initializerDeclaration =
			new JInitializerDeclaration(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, false, yyvsp[0].tokenInfo.block);
		break;
	case 2:
		cout<<"\'{\' ENDF"<<endl;
		yyval.tokenInfo.initializerDeclaration = 0;
		break;
	case 3:
		cout<<"\'{\' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.initializerDeclaration = new JInitializerDeclaration(yyvsp[-2].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, false,
			new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector(), 0));
		break;
	}
}