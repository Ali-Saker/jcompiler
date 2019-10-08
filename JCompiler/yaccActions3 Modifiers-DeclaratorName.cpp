#include"yaccActions.h"

void yaccActions::modifiers(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "Modifier" << endl;
		yyval.tokenInfo.accessProperty = new AccessProperty();
		yyval.tokenInfo.accessProperty->setAccessProperty(yyvsp[0].tokenInfo.property);
		break;
	case 2:
		cout << "Modifiers Modifier" << endl;
		yyvsp[-1].tokenInfo.accessProperty->setAccessProperty(yyvsp[0].tokenInfo.property);
		yyval.tokenInfo.accessProperty = yyvsp[-1].tokenInfo.accessProperty;
		
		break;
	}
}

void yaccActions::modifier(int grammar,YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "ABSTRACT" << endl;
		yyval.tokenInfo.property = 1;
		break;
	case 2:
		cout << "FINAL" << endl;
		yyval.tokenInfo.property = 2;
		break;
	case 3:
		cout << "PUBLIC" << endl;
		yyval.tokenInfo.property = 3;
		break;
	case 4:
		cout << "PROTECTED" << endl;
		yyval.tokenInfo.property = 4;
		break;
	case 5:
		cout << "PRIVATE" << endl;
		yyval.tokenInfo.property = 5;
		break;
	case 6:
		cout << "STATIC" << endl;
		yyval.tokenInfo.property = 6;
		break;
	case 7:
		cout << "TRANSIENT" << endl;
		yyval.tokenInfo.property = 7;
		break;
	case 8:
		cout << "VOLATILE" << endl;
		yyval.tokenInfo.property = 8;
		break;
	case 9:
		cout << "NATIVE" << endl;
		yyval.tokenInfo.property = 9;
		break;
	case 10:
		cout << "SYNCHRONIZED" << endl;
		yyval.tokenInfo.property = 10;
		break;
	}
}

void yaccActions::classWord(int grammar, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "CLASS" << endl;
		yyval.tokenInfo.tokenImage = "class";
		break;
	case 2:
		cout << "INTERFACE" << endl;
		yyval.tokenInfo.tokenImage = "interface";
		break;
	}
}


void yaccActions::interfaces(YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "IMPLEMENTS ClassNameList" << endl;
	yyval.tokenInfo.typeList = yyvsp[0].tokenInfo.typeList;
}

void yaccActions::extends(YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "EXTENDS ClassNameList" << endl;
	yyval.tokenInfo.typeList = yyvsp[0].tokenInfo.typeList;
}

void yaccActions::classNameList(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "QualifiedName" << endl;
		yyval.tokenInfo.typeList = new TypeList();
		yyval.tokenInfo.typeList->insert(new ReferenceType(yyvsp[0].tokenInfo.typeName));
		break;
	case 2:
		cout << "ClassNameList \',\' QualifiedName" << endl;
		yyval.tokenInfo.typeList->insert(new ReferenceType(yyvsp[0].tokenInfo.typeName));
		break;
	}
}

void yaccActions::fieldDeclarations(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "FieldDeclarationOptSemi" << endl;
		yyval.tokenInfo.memberList = new MemberList();
		if (yyvsp[0].tokenInfo.member != 0){
			yyval.tokenInfo.memberList->insert(yyvsp[0].tokenInfo.member);
		}
		break;
	case 2:
		cout << "FieldDeclarations FieldDeclarationOptSemi" << endl;
		if (yyvsp[0].tokenInfo.member != 0){
			yyval.tokenInfo.memberList->insert(yyvsp[0].tokenInfo.member);
		}
		break;
	}
}

void yaccActions::fieldDeclaration(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "FieldVariableDeclaration \';\'" << endl;
		yyval.tokenInfo.member = yyvsp[-1].tokenInfo.fieldDeclaration;
		break;
	case 2:
		cout << "MethodDeclaration" << endl;
		yyval.tokenInfo.member = yyvsp[0].tokenInfo.methodDeclaration;
		break;
	case 3:
		cout << "ConstructorDeclaration" << endl;
		yyval.tokenInfo.member = yyvsp[0].tokenInfo.constructorDeclaration;
		break;
	case 4:
		cout << "StaticInitializer" << endl;
		yyval.tokenInfo.member = yyvsp[0].tokenInfo.initializerDeclaration;
		break;
	case 5:
		cout << "NonStaticInitializer" << endl;
		yyval.tokenInfo.member = yyvsp[0].tokenInfo.initializerDeclaration;
		break;
	case 6:
		cout << "TypeDeclaration" << endl;
			yyval.tokenInfo.member = yyvsp[0].tokenInfo.classDeclaration;
		break;
	case 7:
		cout << "ErrorFieldDeclaration" << endl;
		yyval.tokenInfo.member = 0;
		break;
	}
}


void yaccActions::fieldVariableDeclaration(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "Modifiers TypeSpecifier VariableDeclarators" << endl;
		yyval.tokenInfo.fieldDeclaration = 
			new JFieldDeclaration(yyvsp[-1].tokenInfo.type->typeName->getLine(), yyvsp[-1].tokenInfo.type->typeName->getCol(),
			yyvsp[-1].tokenInfo.type, yyvsp[-2].tokenInfo.accessProperty, yyvsp[0].tokenInfo.declaratorList->toVector());
		break;
	case 2:
		cout << "TypeSpecifier VariableDeclarators" << endl;
		yyval.tokenInfo.fieldDeclaration =
			new JFieldDeclaration(yyvsp[-1].tokenInfo.type->typeName->getLine(), yyvsp[-1].tokenInfo.type->typeName->getCol(),
			yyvsp[-1].tokenInfo.type, 0, yyvsp[0].tokenInfo.declaratorList->toVector());
		break;
	}
}

void yaccActions::variableDeclarators(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "VariableDeclarator" << endl;
		yyval.tokenInfo.declaratorList = new DeclaratorList();
		yyval.tokenInfo.declaratorList->insert(yyvsp[0].tokenInfo.variableDeclarator);
		break;
	case 2:
		cout << "VariableDeclarators \',\' VariableDeclarator" << endl;
		yyval.tokenInfo.declaratorList->insert(yyvsp[0].tokenInfo.variableDeclarator);
		break;
	}
}

void yaccActions::variableDeclarator(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "DeclaratorName" << endl;
		yyval.tokenInfo.variableDeclarator = yyvsp[0].tokenInfo.variableDeclarator;
		break;
	case 2:
		cout << "DeclaratorName \'=\' VariableInitializer" << endl;
		yyval.tokenInfo.variableDeclarator = yyvsp[-2].tokenInfo.variableDeclarator;
		yyval.tokenInfo.variableDeclarator->initializer = yyvsp[0].tokenInfo.expr;
		break;
	}
}

void yaccActions::declaratorName(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "IDENTIFIER" << endl;
		yyval.tokenInfo.variableDeclarator = 
			new JVariableDeclarator(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage,
			0, 0);
		break;
	case 2:
		cout << "DeclaratorName OP_DIM" << endl;
		if (yyval.tokenInfo.variableDeclarator->type == 0){
			yyval.tokenInfo.variableDeclarator->type  = new ArrayType(0, 1);
		}
		else{
			((ArrayType *)yyval.tokenInfo.variableDeclarator->type)->dimensions++;
		}
		break;
	}
}

void yaccActions::variableInitializer(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout<<"Expression"<<endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout<<"'{' '}'"<<endl;
		//yyval.tokenInfo.expr = new JArrayInit(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, 0, 0);
		break;
	case 3:
		cout<<"'{' ArrayInitializers '}'"<<endl;
		//yyval.tokenInfo.expr = new JArrayInit(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, 0, yyvsp[-1].tokenInfo.expressionsList->toVector());
		break;
	}
}

void yaccActions::arrayInitializers(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "VariableInitializer" << endl;
		//yyval.tokenInfo.expressionsList = new ExpressionsList();
		//yyval.tokenInfo.expressionsList->insert(yyvsp[0].tokenInfo.expr);
		break;
	case 2:
		cout << "ArrayInitializers ',' VariableInitializer" << endl;
		//yyval.tokenInfo.expressionsList->insert(yyvsp[0].tokenInfo.expr);
		break;
	}
}