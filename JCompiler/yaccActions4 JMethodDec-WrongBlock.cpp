#include"yaccActions.h"

void yaccActions::methodDeclaration(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"Modifiers TypeSpecifier MethodDeclarator Throws MethodBody"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-2].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->accessProperty = yyvsp[-4].tokenInfo.accessProperty;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-3].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->throws = yyvsp[-1].tokenInfo.typeList->toVector();
		yyval.tokenInfo.methodDeclaration->body = yyvsp[0].tokenInfo.block;

		break;
	case 2:
		cout<<"Modifiers TypeSpecifier MethodDeclarator        MethodBody"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-1].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->accessProperty = yyvsp[-3].tokenInfo.accessProperty;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-2].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 3:
		cout<<"TypeSpecifier MethodDeclarator Throws MethodBody"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-2].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-3].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->throws = yyvsp[-1].tokenInfo.typeList->toVector();
		yyval.tokenInfo.methodDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 4:
		cout<<"TypeSpecifier MethodDeclarator MethodBody"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-1].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-2].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->body = yyvsp[0].tokenInfo.block;
		break;
	case 5:
		cout<<"TypeSpecifier MethodDeclarator		  \'{\' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-3].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-4].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);

		break;
	case 6:
		cout<<"Modifiers	TypeSpecifier MethodDeclarator		  \'{\' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-3].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->accessProperty = yyvsp[-5].tokenInfo.accessProperty;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-4].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 7:
		cout<<"Modifiers	TypeSpecifier MethodDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-4].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->accessProperty = yyvsp[-6].tokenInfo.accessProperty;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-5].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->throws = yyvsp[-3].tokenInfo.typeList->toVector();
		yyval.tokenInfo.methodDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 8:
		cout<<"TypeSpecifier MethodDeclarator Throws '{' LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.methodDeclaration = yyvsp[-4].tokenInfo.methodDeclaration;
		yyval.tokenInfo.methodDeclaration->returnType = yyvsp[-5].tokenInfo.type;
		yyval.tokenInfo.methodDeclaration->throws = yyvsp[-3].tokenInfo.typeList->toVector();
		yyval.tokenInfo.methodDeclaration->body = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol,
			yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	}
}


void yaccActions::methodDeclarator(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"DeclaratorName \'(\' ParameterList \')\'"<<endl;
		yyval.tokenInfo.methodDeclaration =
			new JMethodDeclaration(yyvsp[-3].tokenInfo.variableDeclarator->getLine(), yyvsp[-3].tokenInfo.variableDeclarator->getCol(),
			yyvsp[-3].tokenInfo.variableDeclarator->name, 0, 0, 0, yyvsp[-1].tokenInfo.parameterList->toVector(), 0, 0);
		break;
	case 2:
		cout<<"DeclaratorName '(' ParameterList error"<<endl;
		yyval.tokenInfo.methodDeclaration =
			new JMethodDeclaration(yyvsp[-3].tokenInfo.variableDeclarator->getLine(), yyvsp[-3].tokenInfo.variableDeclarator->getCol(),
			yyvsp[-3].tokenInfo.variableDeclarator->name, 0, 0, 0, yyvsp[-1].tokenInfo.parameterList->toVector(), 0, 0);
		break;
	case 3:
		cout<<"DeclaratorName \'(\'  \')\'"<<endl;
		yyval.tokenInfo.methodDeclaration =
			new JMethodDeclaration(yyvsp[-2].tokenInfo.variableDeclarator->getLine(), yyvsp[-2].tokenInfo.variableDeclarator->getCol(),
			yyvsp[-2].tokenInfo.variableDeclarator->name, 0, 0, 0, 0, 0, 0);
		break;
	case 4:
		cout<<"DeclaratorName \'(\'  error"<<endl;
		yyval.tokenInfo.methodDeclaration =
			new JMethodDeclaration(yyvsp[-2].tokenInfo.variableDeclarator->getLine(), yyvsp[-2].tokenInfo.variableDeclarator->getCol(),
			yyvsp[-2].tokenInfo.variableDeclarator->name, 0, 0, 0, 0, 0, 0);
		break;
	}
}

void yaccActions::parameterList(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"Parameter"<<endl;
		yyval.tokenInfo.parameterList = new ParameterList();
		yyval.tokenInfo.parameterList->insert(yyvsp[0].tokenInfo.formalParameter);
		break;
	case 2:
		cout<<"ParameterList \',\' Parameter"<<endl;
		yyval.tokenInfo.parameterList = yyvsp[-2].tokenInfo.parameterList;
		yyval.tokenInfo.parameterList->insert(yyvsp[0].tokenInfo.formalParameter);
		break;
	}
}

void yaccActions::parameter(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"TypeSpecifier VariableDeclarator"<<endl;
		yyval.tokenInfo.formalParameter = 
			new JFormalParameter(yyvsp[-1].tokenInfo.type->typeName->getLine(), yyvsp[-1].tokenInfo.type->typeName->getCol(),
			 0, yyvsp[0].tokenInfo.variableDeclarator, yyvsp[-1].tokenInfo.type);
		break;
	case 2:
		cout<<"FINAL TypeSpecifier VariableDeclarator"<<endl;
		yyval.tokenInfo.formalParameter =
			new JFormalParameter(yyvsp[-1].tokenInfo.type->typeName->getLine(), yyvsp[-1].tokenInfo.type->typeName->getCol(),
			new AccessProperty(), yyvsp[0].tokenInfo.variableDeclarator, yyvsp[-1].tokenInfo.type);
		yyval.tokenInfo.formalParameter->accessProperty->setAccessProperty(2);
		break;
	}
}

void yaccActions::methodBody(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"Block"<<endl;
		yyval.tokenInfo.block = yyvsp[0].tokenInfo.block;
		break;
	case 2:
		cout<<"WrongBlock"<<endl;
		yyval.tokenInfo.block = yyvsp[0].tokenInfo.block;
		break;
	case 3:
		cout<<"\';\'"<<endl;
		yyval.tokenInfo.block = 0;
		break;
	}
}

void yaccActions::anyBlock(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"Block"<<endl;
		yyval.tokenInfo.block = yyvsp[0].tokenInfo.block;
		break;
	case 2:
		cout<<"WrongBlock"<<endl;
		yyval.tokenInfo.block = yyvsp[0].tokenInfo.block;
		break;
	}
}

void yaccActions::block(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JBlock *jBlock = 0;
	switch (grammar){
	case 1:
		cout<<"\'{\' LocalVariableDeclarationsAndStatements \'}\'"<<endl;
		jBlock = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 2:
		cout<<"\'{\' \'}\'"<<endl;
		jBlock = new JBlock(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, 0, 0);
		break;
	}
	yyval.tokenInfo.block = jBlock;
}

void yaccActions::wrongBlock(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout<<"error LocalVariableDeclarationsAndStatements \'}\'"<<endl;
		yyval.tokenInfo.block = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 2:
		cout<<"error LocalVariableDeclarationsAndStatements ENDF"<<endl;
		yyval.tokenInfo.block = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector(), 0);
		break;
	case 3:
		cout<<"error \'}\'"<<endl;
		yyval.tokenInfo.block = 0;
		break;
	case 4:
		cout<<"error ENDF"<<endl;
		yyval.tokenInfo.block = 0;
		break;
	case 5:
		cout<<"\'{\'   ENDF"<<endl;
		yyval.tokenInfo.block = 0;
		break;
	}
}