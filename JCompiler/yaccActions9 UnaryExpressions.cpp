#include"yaccActions.h"

void yaccActions::unaryExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "OP_INC UnaryExpression" << endl;
		yyval.tokenInfo.expr = new JPreIncrementOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[0].tokenInfo.expr);
		break;
	case 2:
		cout << "OP_DEC UnaryExpression" << endl;
		yyval.tokenInfo.expr = new JPreDecrementOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[0].tokenInfo.expr);
		break;
	case 3:
	//	cout << "ArithmeticUnaryOperator CastExpression" << endl;
	//	if (strcmpi(yyvsp[-1].tokenInfo.tokenImage ,"+")==0){
	//		yyval.tokenInfo.expr = new JPositOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[0].tokenInfo.expr);
	//	}
	//	// negate
	//	else{
	//		yyval.tokenInfo.expr = new JNegateOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[0].tokenInfo.expr);
	//	}
	//	break;
	case 4:
		cout << "LogicalUnaryExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	}
}


void yaccActions::logicalUnaryExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){

	switch (grammar){
	case 1:
		cout << "PostfixExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "LogicalUnaryOperator UnaryExpression" << endl;
		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage ,"!")==0)
			yyval.tokenInfo.expr = new JLogicalNotOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[0].tokenInfo.expr);
		break;
	}

}

void yaccActions::postfixExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "PrimaryExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "RealPostfixExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	}
}

void yaccActions::realPostfixExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar)
	{
	case 1:
		cout << "PostfixExpression OP_INC" << endl;
		yyval.tokenInfo.expr = new JPostIncrementOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.expr);
		break;
	case 2:
		cout << "PostfixExpression OP_DEC" << endl;
		yyval.tokenInfo.expr = new JPostDecrementOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.expr);
		break;
	}
}

void yaccActions::primaryExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "QualifiedName" << endl;
		if (yyvsp[0].tokenInfo.typeName->numberOfParts() == 0){
			yyval.tokenInfo.expr = new JVariable(yyvsp[0].tokenInfo.typeName, 0);
		}
		else{
			yyval.tokenInfo.expr = new JFieldSelection(yyvsp[0].tokenInfo.typeName->getLine(), yyvsp[0].tokenInfo.typeName->getCol(),
				0, yyvsp[0].tokenInfo.typeName->nameAfterLastPeriod(), yyvsp[0].tokenInfo.typeName->nameBeforeLastPeriod());
		}
		break;
	case 2:
		cout << "NotJustName" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	}
}

void yaccActions::notJustName(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "SpecialName" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "NewAllocationExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 3:
		cout << "ComplexPrimary" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;		
	}
}

void yaccActions::specialName(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "THIS" << endl;
		yyval.tokenInfo.expr = new JThis(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol);
		break;
	case 2:
		cout << "SUPER" << endl;
		yyval.tokenInfo.expr = new JSuper(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol);
		break;
	case 3:
		cout << "JNULL" << endl;
		yyval.tokenInfo.expr = new JLiteralNull(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, "null");
		break;
	}
}

void yaccActions::newAllocationExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JNewOp *newOp;
	switch (grammar){
	case 1:
		cout << "PlainNewAllocationExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "QualifiedName '.' PlainNewAllocationExpression" << endl;
		newOp = (JNewOp *)yyvsp[0].tokenInfo.expr;
		newOp->routedName = yyvsp[-2].tokenInfo.typeName;
		yyval.tokenInfo.expr = newOp;
		break;
	}
}



void yaccActions::plainNewAllocationExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "ArrayAllocationExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "ClassAllocationExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	/*case 3:
		cout << "ArrayAllocationExpression '{' '}'" << endl;
		newArrayOpExpr = (JNewArrayOp*) yyvsp[-2].tokenInfo.expr;
		newArrayOpExpr->arrayInit = new JArrayInit(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, 0, 0);
		yyval.tokenInfo.expr = newArrayOpExpr;
		break;
	case 4:
		cout << "ClassAllocationExpression '{' '}'" << endl;
		yyval.tokenInfo.expr = yyvsp[-2].tokenInfo.expr;
		break;
	case 5:
		cout << "ArrayAllocationExpression '{' ArrayInitializers '}'" << endl;
		newArrayOpExpr = (JNewArrayOp*)yyvsp[-3].tokenInfo.expr;
		newArrayOpExpr->arrayInit = new JArrayInit(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, 0, yyvsp[-1].tokenInfo.expressionsList->toVector());
		yyval.tokenInfo.expr = newArrayOpExpr;
		break;
	case 6:
		cout << "ClassAllocationExpression '{' FieldDeclarations '}'" << endl;
		newClassOpExpr = (JNewOp*) yyvsp[-3].tokenInfo.expr;
		newClassOpExpr->block = new JBlock(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.stmtList->toVector());
		yyval.tokenInfo.expr = newClassOpExpr;
		break;*/
	}
}

void yaccActions::classAllocationExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JNewOp* newOp = 0;
	switch (grammar){
	case 1:
		cout << "NEW TypeName '(' ArgumentList ')'" << endl;
		newOp = new JNewOp(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol, yyvsp[-3].tokenInfo.type,
			yyvsp[-1].tokenInfo.expressionsList->toVector(), 0);
		break;
	case 2:
		cout << "NEW TypeName '('              ')'" << endl;
		newOp = new JNewOp(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.type, 0, 0);
		break;
	}
	yyval.tokenInfo.expr = newOp;
}

void yaccActions::arrayAllocationExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "NEW TypeName DimExprs Dims" << endl;
		yyval.tokenInfo.expr = new JNewArrayOp(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.type,
			yyvsp[-1].tokenInfo.expressionsList->toVector(), yyvsp[0].tokenInfo.emptyDimsCount);
		break;
	case 2:
		cout << "NEW TypeName DimExprs" << endl;
		yyval.tokenInfo.expr = new JNewArrayOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.type,
			yyvsp[0].tokenInfo.expressionsList->toVector(), 0);
		break;
	case 3:
		cout << "NEW TypeName Dims" << endl;
		yyval.tokenInfo.expr = new JNewArrayOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-1].tokenInfo.type, 0,
			yyvsp[0].tokenInfo.emptyDimsCount);
		break;
	}
}


void yaccActions::complexPrimary(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "'(' Expression ')'" << endl;
		yyval.tokenInfo.expr = yyvsp[-1].tokenInfo.expr;
		break;
	case 2:
		cout << "ComplexPrimaryNoParenthesis" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	}
}

void yaccActions::complexPrimaryNoParenthesis(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "Literals" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "ArrayAccess" << endl;
		break;
	case 3:
		cout << "FieldAccess" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 4:
		cout << "MethodCall" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	}
}


void yaccActions::arrayAccess(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JExpression *expr;
	switch (grammar){
	case 1:
		cout << "QualifiedName '[' Expression ']'" << endl;
		if (yyvsp[-3].tokenInfo.typeName->numberOfParts() == 0) expr = new JVariable(yyvsp[-3].tokenInfo.typeName, 0);
		else expr = new JFieldSelection(yyvsp[-3].tokenInfo.typeName->getLine(), yyvsp[-3].tokenInfo.typeName->getCol(), 0,
			yyvsp[-3].tokenInfo.typeName->nameAfterLastPeriod(), yyvsp[-3].tokenInfo.typeName->nameBeforeLastPeriod());

		yyval.tokenInfo.expr = new JArrayExpression(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol,
			expr, yyvsp[-1].tokenInfo.expr);
		break; 
	case 2:
		cout << "ComplexPrimary '[' Expression ']'" << endl;
		yyval.tokenInfo.expr = new JArrayExpression(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol,
			yyvsp[-3].tokenInfo.expr, yyvsp[-1].tokenInfo.expr);
		break;
	}
}

void yaccActions::fieldAccess(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "NotJustName '.' IDENTIFIER" << endl;
		yyval.tokenInfo.expr = new JFieldSelection(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr,
			yyvsp[0].tokenInfo.tokenImage, 0);
		break;
	case 2:
		cout << "RealPostfixExpression '.' IDENTIFIER" << endl;
		break;
	case 3:
		cout << "QualifiedName '.' THIS" << endl;
		break;
	case 4:
		cout << "QualifiedName '.' CLASS" << endl;
		break;
	case 5:
		cout << "PrimitiveType '.' CLASS" << endl;
		break;
	}
}
 
void yaccActions::methodCall(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JMethodSelection* methodSelection = 0;
	switch (grammar){
	case 1:
		cout << "MethodAccess '(' ArgumentList ')'" << endl;
		methodSelection = (JMethodSelection*)yyvsp[-3].tokenInfo.expr;
		methodSelection->args = yyvsp[-1].tokenInfo.expressionsList->toVector();
		break;
	case 2:
		cout << "MethodAccess '(' ')'" << endl;
		methodSelection = (JMethodSelection*)yyvsp[-2].tokenInfo.expr;
		break;
	}
	yyval.tokenInfo.expr = methodSelection;
}

void yaccActions::methodAccess(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JExpression * expression;
	switch (grammar){
	case 1:
		cout << "ComplexPrimaryNoParenthesis" << endl;
		expression = yyvsp[0].tokenInfo.expr;
		if (dynamic_cast<JFieldSelection *>(expression)){
			JFieldSelection *fieldSelection = (JFieldSelection *)expression;
			yyval.tokenInfo.expr =
				new JMethodSelection(yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenCol, 0,
				fieldSelection->target, fieldSelection->fieldName, 0);
		}
		break;
	case 2:
		cout << "SpecialName" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;

		break;
	case 3:
		cout << "QualifiedName" << endl;
		if (yyvsp[0].tokenInfo.typeName->numberOfParts() == 0){
			yyval.tokenInfo.expr =
				new JMethodSelection(yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenCol, 0, 0,
				yyvsp[0].tokenInfo.typeName->nameAfterLastPeriod(), 0);
		}
		else{
			yyval.tokenInfo.expr =
				new JMethodSelection(yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenCol, 0, 0,
				yyvsp[0].tokenInfo.typeName->nameAfterLastPeriod(), yyvsp[0].tokenInfo.typeName->nameBeforeLastPeriod());
		}
		
		break;
	}
}

void yaccActions::argumentList(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "Expression" << endl;
		yyval.tokenInfo.expressionsList = new ExpressionsList();
		yyval.tokenInfo.expressionsList->insert(yyvsp[0].tokenInfo.expr);
		break;
	case 2:
		cout << "ArgumentList ',' Expression" << endl;
		yyval.tokenInfo.expressionsList->insert(yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::dimExprs(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "DimExpr" << endl;
		yyval.tokenInfo.expressionsList = new ExpressionsList();
		yyval.tokenInfo.expressionsList->insert(yyvsp[0].tokenInfo.expr);
		break;
	case 2:
		cout << "DimExprs DimExpr" << endl;
		yyval.tokenInfo.expressionsList->insert(yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::dimExpr(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "'[' Expression ']'" << endl;
	yyval.tokenInfo.expr = yyvsp[-1].tokenInfo.expr;
}

void yaccActions::dims(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "OP_DIM" << endl;
		yyval.tokenInfo.emptyDimsCount = 1;
		break;
	case 2:
		cout << "Dims OP_DIM" << endl;
		yyval.tokenInfo.emptyDimsCount++;
		break;
	}
}

void yaccActions::primitiveTypeExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "PrimitiveType" << endl;
		yyval.tokenInfo.type = yyvsp[0].tokenInfo.type;
		break;
	case 2:
		cout << "PrimitiveType Dims" << endl;
		yyval.tokenInfo.type = new ArrayType(yyvsp[-1].tokenInfo.type,yyvsp[0].tokenInfo.emptyDimsCount);
		break;
	case 3: 
		cout << "QualifiedName Dims" << endl;
		yyval.tokenInfo.type = new ArrayType(new ReferenceType(yyvsp[-1].tokenInfo.typeName), yyvsp[0].tokenInfo.emptyDimsCount);
		break;
	}

}

void yaccActions::castExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "'(' PrimitiveTypeExpression ')' CastExpression" << endl;
		yyval.tokenInfo.expr = new CastExpression(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.type,
			yyvsp[0].tokenInfo.expr);
		break;
	case 2:
		cout << "'(' ClassTypeExpression ')' CastExpression" << endl;
		yyval.tokenInfo.expr = new CastExpression(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.type,
			yyvsp[0].tokenInfo.expr);

		break;
	case 3:
		cout << "'(' Expression ')' LogicalUnaryExpression" << endl;
		Type *type = 0;
		JExpression * expr = yyvsp[-2].tokenInfo.expr;
		if (dynamic_cast<JVariable *>(expr)){
			type = new ReferenceType(((JVariable *)expr)->typeName);
		}
		else if (dynamic_cast<JFieldSelection *>(expr)){
			char * fullName = strcat(strcat(((JFieldSelection *)(expr))->routedName->name, "."), ((JFieldSelection *)(expr))->fieldName);
			type = new ReferenceType(new TypeName(expr->getLine(),expr->getCol(),fullName));
		}
		yyval.tokenInfo.expr = new CastExpression(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, type,
			yyvsp[0].tokenInfo.expr);
	}
}

void yaccActions::NewInner(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	JNewOp *newOp;
	ReferenceType *referenceType;
	TypeName *typeName;
	switch (grammar){
	case 1:
		cout << " NotJustName '.' NEW IDENTIFIER '(' ')'" << endl;
		typeName = new TypeName(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage);
		referenceType = new ReferenceType(typeName);
		newOp = new JNewOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, referenceType, 0, 0);
		newOp->routedName = 0;
		newOp->target = yyvsp[-5].tokenInfo.expr;
		break;
	case 2:
		cout << "NotJustName '.' NEW IDENTIFIER '(' ArgumentList ')'" << endl;
		typeName = new TypeName(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-3].tokenInfo.tokenImage);
		referenceType = new ReferenceType(typeName);
		newOp = new JNewOp(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol,
			referenceType, yyvsp[-1].tokenInfo.expressionsList->toVector(), 0);
		newOp->routedName = 0;
		newOp->target = yyvsp[-6].tokenInfo.expr;
		break;
	case 3:
		cout << "QualifiedName '.' NEW IDENTIFIER '(' ')'" << endl;
		typeName = new TypeName(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.tokenImage);
		referenceType = new ReferenceType(typeName);
		newOp = new JNewOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, referenceType, 0, 0);
		newOp->routedName = yyvsp[-5].tokenInfo.typeName;
		newOp->target = 0;
		break;
	case 4:
		cout << " QualifiedName '.' NEW IDENTIFIER '(' ArgumentList ')'" << endl;
		typeName = new TypeName(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol, yyvsp[-3].tokenInfo.tokenImage);
		referenceType = new ReferenceType(typeName);
		newOp = new JNewOp(yyvsp[-3].tokenInfo.tokenLine, yyvsp[-3].tokenInfo.tokenCol,
			referenceType, yyvsp[-1].tokenInfo.expressionsList->toVector(), 0);
		newOp->routedName = yyvsp[-6].tokenInfo.typeName;
		newOp->target = 0;
		break;
	}
	yyval.tokenInfo.expr = newOp;
}
//switch (grammar){
//case 1:
//	break;
//case 2:
//	break;
//case 3:
//	break;
//case 4:
//	break;
//case 5:
//	break;
//case 6:
//	break;
//case 7:
//	break;
//case 8:
//	break;
//case 9:
//	break;
//case 10:
//	break;
//}