#include "yaccActions.h"

void yaccActions::literals(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "INT_LITERAL" << endl;
		yyval.tokenInfo.expr = new JLiteralInt(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage);
		break;
	case 2:
		cout << "LONG_LITERAL" << endl;
		yyval.tokenInfo.expr = new JLiteralLong(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage);
		break;
	case 3:
		cout << "DOUBLE_LITERAL" << endl;
		yyval.tokenInfo.expr = new JLiteralDouble(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage);
		break;
	case 4:
		cout << "FLOAT_LITERAL" << endl;
		yyval.tokenInfo.expr = new JLiteralFloat(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage);
		break;
	case 5:
		cout << "STRING_LITERAL" << endl;
		yyval.tokenInfo.expr = new JLiteralString(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage);
		break;
	case 6:
		cout << "CHAR_LITERAL" << endl;
		yyval.tokenInfo.expr = new JLiteralChar(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, yyvsp[0].tokenInfo.tokenImage);
		break;
	case 7:
		cout << "BOOLLIT" << endl;
		if (strcmpi(yyvsp[0].tokenInfo.tokenImage , "true")==0)
			yyval.tokenInfo.expr = new JLiteralTrue(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, "true");
		else
			yyval.tokenInfo.expr = new JLiteralFalse(yyvsp[0].tokenInfo.tokenLine, yyvsp[0].tokenInfo.tokenCol, "false");
		break;
	}
}

void yaccActions::multiplicativeExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "CastExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "MultiplicativeExpression '*' CastExpression" << endl;
		yyval.tokenInfo.expr = new JMulOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 3:
		cout << "MultiplicativeExpression '/' CastExpression" << endl;
		yyval.tokenInfo.expr = new JDivOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 4:
		cout << "MultiplicativeExpression '%' CastExpression" << endl;
		yyval.tokenInfo.expr = new JModOp(yyvsp[-1].tokenInfo.tokenLine, yyvsp[-1].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::additiveExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "MultiplicativeExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "AdditiveExpression '+' MultiplicativeExpression" << endl;
		yyval.tokenInfo.expr = new JPlusOP(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 3:
		cout << "AdditiveExpression '-' MultiplicativeExpression" << endl;
		yyval.tokenInfo.expr = new JSubOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::shiftExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){

	switch (grammar){
	case 1:
		cout << "AdditiveExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	}
}

void yaccActions::relationalExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "ShiftExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "RelationalExpression '<' ShiftExpression" << endl;
		yyval.tokenInfo.expr = new JLessThanOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 3:
		cout << "RelationalExpression '>' ShiftExpression" << endl;
		yyval.tokenInfo.expr = new JGreaterThanOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 4:
		cout << "RelationalExpression OP_LE ShiftExpression" << endl;
		yyval.tokenInfo.expr = new JLessOrEqualOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 5:
		cout << "RelationalExpression OP_GE ShiftExpression" << endl;
		yyval.tokenInfo.expr = new JGreaterOrEqualOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 6:
		cout << "RelationalExpression INSTANCEOF TypeSpecifier" << endl;
		break;
	}
}

void yaccActions::equalityExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "RelationalExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "EqualityExpression OP_EQ RelationalExpression" << endl;
		yyval.tokenInfo.expr = new JEqualOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	case 3:
		cout << "EqualityExpression OP_NE RelationalExpression" << endl;
		yyval.tokenInfo.expr = new JNotEqualOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::andExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "EqualityExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "AndExpression '&' EqualityExpression" << endl;
		break;
	}
}


void yaccActions::exclusiveOrExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "AndExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "ExclusiveOrExpression '^' AndExpression" << endl;
		break;
	}
}

void yaccActions::inclusiveOrExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){

	switch (grammar){
	case 1:
		cout << "ExclusiveOrExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "InclusiveOrExpression '|' ExclusiveOrExpression" << endl;
		break;
	}
}

void yaccActions::conditionalAndExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "InclusiveOrExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "ConditionalAndExpression OP_LAND InclusiveOrExpression" << endl;
		yyval.tokenInfo.expr = new JLogicalAndOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::conditionalOrExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "ConditionalAndExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "ConditionalOrExpression OP_LOR ConditionalAndExpression" << endl;
		yyval.tokenInfo.expr = new JLogicalOrOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}

void yaccActions::conditionalExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "ConditionalOrExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "ConditionalOrExpression '?' Expression ':' ConditionalExpression" << endl;
		yyval.tokenInfo.expr = new JConditionalExpression(yyvsp[-4].tokenInfo.tokenLine, yyvsp[-4].tokenInfo.tokenCol, yyvsp[-4].tokenInfo.expr,
			yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}


void yaccActions::assignmentExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	switch (grammar){
	case 1:
		cout << "ConditionalExpression" << endl;
		yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
		break;
	case 2:
		cout << "UnaryExpression AssignmentOperator AssignmentExpression" << endl;
		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage, "=") == 0)
			yyval.tokenInfo.expr = new JAssignOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);

		if ( strcmpi( yyvsp[-1].tokenInfo.tokenImage , "+=" )==0 )
			yyval.tokenInfo.expr = new JPlusAssignOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);

		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage, "*=") == 0)
			yyval.tokenInfo.expr = new JMulAssignOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);

		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage, "/=") == 0)
			yyval.tokenInfo.expr = new JDivAssignOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);

		if (strcmpi(yyvsp[-1].tokenInfo.tokenImage, "-=") == 0)
			yyval.tokenInfo.expr = new JSubAssignOp(yyvsp[-2].tokenInfo.tokenLine, yyvsp[-2].tokenInfo.tokenCol, yyvsp[-2].tokenInfo.expr, yyvsp[0].tokenInfo.expr);
		break;
	}
}


void yaccActions::expression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "Expression" << endl;
	yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
}

void yaccActions::constantExpression(int grammar, YYSTYPE* yyvsp, YYSTYPE& yyval){
	cout << "ConditionalExpression" << endl;
	yyval.tokenInfo.expr = yyvsp[0].tokenInfo.expr;
}