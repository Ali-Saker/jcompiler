#include"yaccActions.h"

void yaccActions::typeSpecifier(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout<<"TypeName"<<endl;
		yyval.tokenInfo.type = yyvsp[0].tokenInfo.type;
		break;
	case 2:  
		cout<<"TypeName Dims"<<endl;
		yyval.tokenInfo.type = new ArrayType( yyvsp[-1].tokenInfo.type, yyvsp[0].tokenInfo.emptyDimsCount);
		break;
	}
}

void yaccActions::typeName(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout<<"PrimitiveType"<<endl;
		yyval.tokenInfo.type = yyvsp[0].tokenInfo.type;
		break;
	case 2:
		cout<<"QualifiedName"<<endl;
		yyval.tokenInfo.type = new ReferenceType(yyvsp[0].tokenInfo.typeName);
		break;
	}
}

void yaccActions::primitiveType(int grammar, YYSTYPE *yyvsp, YYSTYPE &yyval){
	switch (grammar)
	{
	case 1:
		cout<<"BOOLEAN"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JBOOLEAN;
		break;
	case 2:
		cout<<"CHAR"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JCHAR;
		break;
	case 3:
		cout<<"BYTE"<<endl;
		break;
	case 4:
		cout<<"SHORT"<<endl;
		break;
	case 5:
		cout<<"INT"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JINTEGER;
		break;
	case 6:
		cout<<"LONG"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JLONG;
		break;
	case 7:
		cout<<"FLOAT"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JFLOAT;
		break;
	case 8:
		cout<<"DOUBLE"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JDOUBLE;
		break;
	case 9:
		cout<<"VOID"<<endl;
		yyval.tokenInfo.type = PrimitiveType::JVOID;
		break;
	case 10:
		cout << "STRING" << endl;
		yyval.tokenInfo.type = PrimitiveType::JSTRING;
	}
}


void yaccActions::compilationUnit(){
	cout << "ProgramFile" << endl;
} 


void yaccActions::programFile(int grammar, YYSTYPE* yyvsp, JCompilationUnit* compilationUnit){;
	switch (grammar){
	case 1:
		cout << "PackageStatement ImportStatements TypeDeclarations" << endl;
		compilationUnit->packageName = yyvsp[-2].tokenInfo.typeName;
		break;
	case 2:
		cout << "PackageStatement ImportStatements " << endl;
		compilationUnit->packageName = yyvsp[-1].tokenInfo.typeName;
		break;
	case 3:
		cout << "PackageStatement TypeDeclarations" << endl;
		compilationUnit->packageName = yyvsp[-1].tokenInfo.typeName;
		break;
	case 4:
		cout << "ImportStatements TypeDeclarations" << endl;
		break;
	case 5:
		cout << "PackageStatement" << endl;
		compilationUnit->packageName = yyvsp[0].tokenInfo.typeName;
		break;
	case 6:
		cout << "ImportStatements" << endl;
		break;
	case 7:
		cout << "TypeDeclarations" << endl;
		break;
	}
}

void yaccActions::packageStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval ){
	switch (grammar)
	{
	case 1:
		cout << "PACKAGE QualifiedName SemiColons" << endl;
		yyval.tokenInfo.typeName = yyvsp[-1].tokenInfo.typeName;
		break;
	case 2:
		cout << "PACKAGE error" << endl;
		yyval.tokenInfo.typeName = 0;
		break;
	}
}
void yaccActions::typeDeclarations(int grammar, YYSTYPE* yyvsp, JCompilationUnit* compilationUnit, stack<char*>& prevMods){
	switch (grammar){
	case 1:
		cout << "TypeDeclarationOptSemi" << endl;
		compilationUnit->typeDeclarations = new vector<JAST*>;
		if (yyvsp[0].tokenInfo.classDeclaration != 0){
			/*if (yyvsp[0].tokenInfo.classDeclaration->mods == 0)
				yyvsp[0].tokenInfo.classDeclaration->mods = Utils::toVector(prevMods);*/
			compilationUnit->typeDeclarations->push_back(yyvsp[0].tokenInfo.classDeclaration);
		}
		else if (yyvsp[0].tokenInfo.interfaceDeclaration != 0){
			/*if (yyvsp[0].tokenInfo.interfaceDeclaration->mods == 0)
				yyvsp[0].tokenInfo.interfaceDeclaration->mods = Utils::toVector(prevMods);*/
			compilationUnit->typeDeclarations->push_back(yyvsp[0].tokenInfo.interfaceDeclaration);
		}

		break;
	case 2:
		cout << "TypeDeclarations TypeDeclarationOptSemi" << endl;
		if (yyvsp[0].tokenInfo.classDeclaration != 0){
			/*if (yyvsp[0].tokenInfo.classDeclaration->mods == 0)
				yyvsp[0].tokenInfo.classDeclaration->mods = Utils::toVector(prevMods);*/
			compilationUnit->typeDeclarations->push_back(yyvsp[0].tokenInfo.classDeclaration);
		}
		else if (yyvsp[0].tokenInfo.interfaceDeclaration != 0){
			/*if (yyvsp[0].tokenInfo.interfaceDeclaration->mods == 0)
				yyvsp[0].tokenInfo.interfaceDeclaration->mods = Utils::toVector(prevMods);*/
			compilationUnit->typeDeclarations->push_back(yyvsp[0].tokenInfo.interfaceDeclaration);
		}
		break;
	}

	/*while (!prevMods.empty())
		prevMods.pop();*/
}

void yaccActions::typeDeclarationOptSemi(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "TypeDeclaration" << endl;
		yyval.tokenInfo.classDeclaration = yyvsp[0].tokenInfo.classDeclaration;
		yyval.tokenInfo.interfaceDeclaration = yyvsp[0].tokenInfo.interfaceDeclaration;
		break;
	case 2:
		cout << "TypeDeclaration SemiColons" << endl;
		yyval.tokenInfo.classDeclaration = yyvsp[-1].tokenInfo.classDeclaration;
		yyval.tokenInfo.interfaceDeclaration = yyvsp[-1].tokenInfo.interfaceDeclaration;
		break;
	case 3:
		cout << "ClassHeader" << endl;
		yyval.tokenInfo.classDeclaration = yyvsp[0].tokenInfo.classDeclaration;
		yyval.tokenInfo.interfaceDeclaration = yyvsp[0].tokenInfo.interfaceDeclaration;
		break;
	}
}

void yaccActions::importStatements(int grammar, YYSTYPE* yyvsp, JCompilationUnit* compilationUnit){
	switch (grammar){
	case 1:
		cout << "ImportStatement" << endl;
		compilationUnit->imports = new vector<Type*>;
		compilationUnit->imports->push_back(yyvsp[0].tokenInfo.type);
		break;
	case 2:
		cout << "error" << endl;
		break;
	case 3:
		cout << "ImportStatements ImportStatement" << endl;
		compilationUnit->imports->push_back(yyvsp[0].tokenInfo.type);
		break;
	case 4:
		cout << "ImportStatements error" << endl;
		break;
	}
}

void yaccActions::importStatement(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "IMPORT QualifiedName SemiColons" << endl;
		yyval.tokenInfo.type = new ReferenceType(yyvsp[-1].tokenInfo.typeName);
		break;
	case 2:
		cout << "IMPORT QualifiedName \'.\' \'*\' SemiColons" << endl;
		strcat(yyvsp[-3].tokenInfo.typeName->name, ".*");
		yyval.tokenInfo.type = new ReferenceType(yyvsp[-3].tokenInfo.typeName);
		break;
	}
}

void yaccActions::QualifiedName(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "IDENTIFIER" << endl;
		yyval.tokenInfo.typeName = new TypeName(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol,
			yyvsp[0].tokenInfo.tokenImage);
		break;
	case 2:
		cout << "QualifiedName \'.\' IDENTIFIER" << endl;
		strcat(yyvsp[-2].tokenInfo.typeName->name, ".");
		strcat(yyvsp[-2].tokenInfo.typeName->name, yyvsp[0].tokenInfo.tokenImage);
		yyval.tokenInfo.typeName = yyvsp[-2].tokenInfo.typeName;
		break;
	}
}

