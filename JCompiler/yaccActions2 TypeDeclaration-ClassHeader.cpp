#include"yaccActions.h"

void yaccActions::typeDeclaration(int grammar, YYSTYPE *yyvsp, YYSTYPE &yyval){
	JClassDeclaration* classDec = 0;
	JInterfaceDeclaration* interfaceDec = 0;

	switch (grammar){
	case 1:
		cout << "ClassHeader \'{\' FieldDeclarations  \'}\'" << endl;
		if (yyvsp[-3].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-3].tokenInfo.classDeclaration;
			classDec->classBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}else if (yyvsp[-3].tokenInfo.interfaceDeclaration != 0){
				interfaceDec = yyvsp[-3].tokenInfo.interfaceDeclaration;
			interfaceDec->interfaceBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		break;
	case 2:
		cout << "ClassHeader \'{\' FieldDeclarations  ENDF" << endl;
		if (yyvsp[-3].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-3].tokenInfo.classDeclaration;
			classDec->classBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		else if (yyvsp[-3].tokenInfo.interfaceDeclaration != 0){
			interfaceDec = yyvsp[-3].tokenInfo.interfaceDeclaration;
			interfaceDec->interfaceBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		break;
	case 3:
		cout << "ClassHeader \'{\' \'}\'" << endl;
		if (yyvsp[-2].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-2].tokenInfo.classDeclaration;
		}
		else if (yyvsp[-3].tokenInfo.interfaceDeclaration != 0){
			interfaceDec = yyvsp[-2].tokenInfo.interfaceDeclaration;
		}

		break;
	case 4:
		cout << "ClassHeader \'{\' ENDF" << endl;
		if (yyvsp[-2].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-2].tokenInfo.classDeclaration;
		}
		else{
			if (yyvsp[-2].tokenInfo.interfaceDeclaration!=0)
				interfaceDec = yyvsp[-2].tokenInfo.interfaceDeclaration;
		}
		break;
	case 5:
		cout << "ClassHeader error FieldDeclarations \'}\'" << endl;
		if (yyvsp[-3].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-3].tokenInfo.classDeclaration;
			classDec->classBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		else if (yyvsp[-3].tokenInfo.interfaceDeclaration != 0){
			interfaceDec = yyvsp[-3].tokenInfo.interfaceDeclaration;
			interfaceDec->interfaceBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		break;
	case 6:
		cout << "ClassHeader error FieldDeclarations ENDF" << endl;
		if (yyvsp[-3].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-3].tokenInfo.classDeclaration;
			classDec->classBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		else if (yyvsp[-3].tokenInfo.interfaceDeclaration != 0){
			interfaceDec = yyvsp[-3].tokenInfo.interfaceDeclaration;
			interfaceDec->interfaceBlock = yyvsp[-1].tokenInfo.memberList->toVector();
		}
		break;
	case 7:
		cout << "ClassHeader \'}\'" << endl;
		if (yyvsp[-1].tokenInfo.classDeclaration != 0){
			classDec = yyvsp[-1].tokenInfo.classDeclaration;
		}
		else if (yyvsp[-3].tokenInfo.interfaceDeclaration != 0){
			interfaceDec = yyvsp[-1].tokenInfo.interfaceDeclaration;
		}
		break;
	}

	if (classDec != 0)
		yyval.tokenInfo.classDeclaration = classDec;
	else if (interfaceDec != 0)
		yyval.tokenInfo.interfaceDeclaration = interfaceDec;

}

void yaccActions::classHeader(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JClassDeclaration* classDec = 0;
	JInterfaceDeclaration* interfaceDec = 0;

	switch (grammar){
	case 1:
		cout << "Modifiers ClassWord IDENTIFIER Extends Interfaces" << endl;
		if (strcmpi(yyvsp[-3].tokenInfo.tokenImage, "class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage,
				yyvsp[-4].tokenInfo.accessProperty, 0, 0, 0, 0);
			vector<Type*>* extends = yyvsp[-1].tokenInfo.typeList->toVector();
			classDec->superType = (*extends)[0];
			if (extends->size() > 1){
				char* errMsg = "can't extends more than one class.";
				ErrorRecovery::reportSemanticError(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, errMsg);
			}
			classDec->implementedInterfaces = yyvsp[0].tokenInfo.typeList->toVector();
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage,
				yyvsp[-4].tokenInfo.accessProperty, 0, 0, 0);
			interfaceDec->superTypes = yyvsp[-1].tokenInfo.typeList->toVector();
			char* errMsg = "can't use 'implements' keyword with interface declaration.";
			ErrorRecovery::reportSemanticError(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, errMsg);

		}
		break;
	case 2:
		cout << "Modifiers ClassWord IDENTIFIER Extends" << endl;
		if (strcmpi(yyvsp[-2].tokenInfo.tokenImage, "class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				yyvsp[-3].tokenInfo.accessProperty, 0, 0, 0, 0);
			vector<Type*> *extends = yyvsp[0].tokenInfo.typeList->toVector();
			classDec->superType = (*extends)[0];
			if (extends->size() > 1){
				char* errMsg = "can't extends more than one class.";
				ErrorRecovery::reportSemanticError(yyvsp[0].tokenInfo.tokenLine, yyvsp[-0].tokenInfo.tokenCol, errMsg);
			}
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				yyvsp[-3].tokenInfo.accessProperty, 0, 0, 0);
			interfaceDec->superTypes = yyvsp[0].tokenInfo.typeList->toVector();
		}
		break;
	case 3:
		cout << "Modifiers ClassWord IDENTIFIER       Interfaces" << endl;
		if (strcmpi(yyvsp[-2].tokenInfo.tokenImage, "class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				yyvsp[-3].tokenInfo.accessProperty, 0, 0, 0, 0);
			classDec->implementedInterfaces = yyvsp[0].tokenInfo.typeList->toVector();

		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				yyvsp[-3].tokenInfo.accessProperty, 0, 0, 0);
			char* errMsg = "can't use 'implements' keyword with interface declaration.";
			ErrorRecovery::reportSemanticError(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, errMsg);
		}
		break;
	case 4:
		cout << "ClassWord IDENTIFIER Extends Interfaces	" << endl;
		if (strcmpi(yyvsp[-3].tokenInfo.tokenImage ,"class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage,
				0, 0, 0, 0, 0);
			vector<Type *>* extends = yyvsp[-1].tokenInfo.typeList->toVector();
			classDec->superType = (*extends)[0];
			if (extends->size() > 1){
				char* errMsg = "can't extends more than one class.";
				ErrorRecovery::reportSemanticError(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, errMsg);
			}
			classDec->implementedInterfaces = yyvsp[0].tokenInfo.typeList->toVector();
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage,
				0, 0, 0, 0);
			interfaceDec->superTypes = yyvsp[-1].tokenInfo.typeList->toVector();
			char* errMsg = "can't use 'implements' keyword with interface declaration.";
			ErrorRecovery::reportSemanticError(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, errMsg);
		}
		break;
	case 5:
		cout << "Modifiers ClassWord IDENTIFIER" << endl;
		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage , "class")==0){
			classDec =
				new JClassDeclaration(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage,
				yyvsp[-2].tokenInfo.accessProperty, 0, 0, 0, 0);
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage,
				yyvsp[-2].tokenInfo.accessProperty, 0, 0, 0);
		}
		break;
	case 6:
		cout << "ClassWord IDENTIFIER Extends" << endl;
		if (strcmpi(yyvsp[-2].tokenInfo.tokenImage, "class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				0, 0, 0, 0, 0);
			vector<Type*> *extends = yyvsp[0].tokenInfo.typeList->toVector();
			classDec->superType = (*extends)[0];
			if (extends->size() > 1){
				char* errMsg = "can't extends more than one class.";
				ErrorRecovery::reportSemanticError(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, errMsg);
			}
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				0, 0, 0, 0);
			interfaceDec->superTypes = yyvsp[0].tokenInfo.typeList->toVector();
		}
		break;
	case 7:
		cout << "ClassWord IDENTIFIER       Interfaces" << endl;
		if (strcmpi(yyvsp[-2].tokenInfo.tokenImage ,"class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				0, 0, 0, 0, 0);
			classDec->implementedInterfaces = yyvsp[0].tokenInfo.typeList->toVector();
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.tokenImage,
				0, 0, 0, 0);
			char* errMsg = "can't use 'implements' keyword with interface declaration.";
			ErrorRecovery::reportSemanticError(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, errMsg);
		}
		break;
	case 8:
		cout << "ClassWord IDENTIFIER" << endl;
		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage , "class") == 0){
			classDec =
				new JClassDeclaration(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage,
				0, 0, 0, 0, 0);
		}
		else{
			interfaceDec =
				new JInterfaceDeclaration(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage,
				0, 0, 0, 0);
		}
		break;
	case 9:
		cout << "Modifiers ClassWord error" << endl;
		classDec = 0;
		interfaceDec = 0;
		break;
	case 10:
		cout << "ClassWord error" << endl;
		classDec = 0;
		interfaceDec = 0;
		break;
	}
	yyval.tokenInfo.classDeclaration = classDec;
	yyval.tokenInfo.interfaceDeclaration = interfaceDec;
}