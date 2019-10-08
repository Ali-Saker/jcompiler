#pragma once

#include <iostream>
#include <istream>
#include<fstream>
#include <ostream>		
#include <flexlexer.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string.h>
#include<stack>
#include<list>
#include"yacc.hpp"
#include"ASTfiles.h"
#include"Defn.h"
const int N = 400;
using namespace std;

/*
* Class TypeNode & TypeList
* Used in Yacc file to get List of [type : *Type]
* From a deeper level of parsing process.
*/
class TypeNode{
public:
	TypeNode(Type* type){
		this->type = type;
		next = 0;
	}
	TypeNode* next;
	Type* type;
};

class TypeList{
public:
	TypeNode* head;

	TypeList(){
		this->head = 0;
	}

	TypeList(TypeNode* head){
		this->head = head;
	}

	void insert(Type* type){
		TypeNode* temp = new TypeNode(type);
		temp->next = head;
		head = temp;
	}

	vector<Type*> *toVector(){
		vector<Type*> *result = new vector<Type*>;
		while (head != 0){
			result->insert(result->begin(), head->type);
			head = head->next;
		}
		return result;
	}
};


/*
 * Class Member & MemberList 
 * Used in Yacc file to get List of [member : *JAST]
 * From a deeper level of parsing process.
*/
class Member{
public:
	Member(JAST* member){
		this->member = member;
		next = 0;
	}
	Member* next;
	JAST* member;

};

class MemberList{
public:
	Member* head;

	MemberList(){
		this->head = 0;
	}

	MemberList(Member* head){
		this->head = head;
	}

	void insert(JAST* member){
		Member* temp = new Member(member);
		temp->next = head;
		head = temp;
	}

	vector<JAST*>* toVector(){
		vector<JAST*>* result = new vector<JAST*>;
		while (head != 0){
			result->insert(result->begin(), head->member);
			head = head->next;
		}
		return result;
	}
};

/*
* Class Declarator & DeclaratorsList
* Used in Yacc file to get List of [declarator : *JVariableDeclarator]
* From a deeper level of parsing process.
*/
class Declarator{
public:
	Declarator(JVariableDeclarator* variableDeclarator){
		this->variableDeclarator = variableDeclarator;
		next = 0;
	}
	Declarator* next;
	JVariableDeclarator* variableDeclarator;

};

class DeclaratorList{
public:
	Declarator* head;

	DeclaratorList(){
		this->head = 0;
	}

	DeclaratorList(Declarator* head){
		this->head = head;
	}

	void insert(JVariableDeclarator* variableDeclarator){
		Declarator* temp = new Declarator(variableDeclarator);
		temp->next = head;
		head = temp;
	}

	vector<JVariableDeclarator*>* toVector(){

		vector<JVariableDeclarator*>* result = new vector<JVariableDeclarator*>;
		while (head != 0){
			result->insert(result->begin(), head->variableDeclarator);
			head = head->next;
		}
		return result;
	}
};

class Statement{
public:
	Statement(JStatement* image){
		statement = image;
		next = 0;
	}
	Statement* next;
	JStatement* statement;
};

class StatementsList{
public:
	Statement* head;

	StatementsList(){
		this->head = 0;
	}

	StatementsList(Statement* head){
		this->head = head;
	}

	void insert(JStatement* elem){
		Statement* temp = new Statement(elem);
		temp->next = head;
		head = temp;
	}

	vector<JStatement*>* toVector(){
		vector<JStatement*>* result = new vector<JStatement*>;
		while (head != 0){
			result->insert(result->begin(), head->statement);
			head = head->next;
		}
		return result;
	}
};

/*
* Class Parameter & ParameterList
* Used in Yacc file to get List of [parameter : *JFormalParameter]
* From a deeper level of parsing process.
*/
class Parameter{
public:
	Parameter(JFormalParameter *parameter){
		this->parameter = parameter;
		next = 0;
	}
	Parameter* next;
	JFormalParameter* parameter;

};

class ParameterList{

public:
	Parameter* head;

	ParameterList(){
		this->head = 0;
	}

	ParameterList(Parameter* head){
		this->head = head;
	}

	void insert(JFormalParameter* parameter){
		Parameter* temp = new Parameter(parameter);
		temp->next = head;
		head = temp;
	}

	vector<JFormalParameter*> *toVector(){
		vector<JFormalParameter*> *result = new vector<JFormalParameter*>;
		while (head != 0){
			result->insert(result->begin(), head->parameter);
			head = head->next;
		}
		return result;
	}
};

class ExprStmt{
public:
	ExprStmt(JExpressionStatement* image){
		expressionStatement = image;
		next = 0;
	}
	ExprStmt* next;
	JExpressionStatement* expressionStatement;
};


class ExprStmtsList{

public:
	ExprStmt* head;

	ExprStmtsList(){
		this->head = 0;
	}

	ExprStmtsList(ExprStmt* head){
		this->head = head;
	}

	void insert(JExpressionStatement* elem){
		ExprStmt* temp = new ExprStmt(elem);
		temp->next = head;
		head = temp;
	}

	vector<JExpressionStatement*>* toVector(){
		vector<JExpressionStatement*>* result = new vector<JExpressionStatement*>;
		while (head != 0){
			result->insert(result->begin(), head->expressionStatement);
			head = head->next;
		}
		return result;
	}
};



class CatchNode{
public:
	CatchNode(JCatch* image){
		jCatch = image;
		next = 0;
	}
	CatchNode* next;
	JCatch* jCatch;

};

class CatchesList{

public:
	CatchNode* head;

	CatchesList(){
		this->head = 0;
	}

	CatchesList(CatchNode* head){
		this->head = head;
	}

	void insert(JCatch* elem){
		CatchNode* temp = new CatchNode(elem);
		temp->next = head;
		head = temp;
	}

	vector<JCatch*>* toVector(){
		vector<JCatch*>* result = new vector<JCatch*>;
		while (head != 0){
			result->insert(result->begin(), head->jCatch);
			head = head->next;
		}
		return result;
	}
};

class ExpressionNode{
public:
	ExpressionNode(JExpression* image){
		expr = image;
		next = 0;
	}
	ExpressionNode* next;
	JExpression* expr;

};

class ExpressionsList{

public:
	ExpressionNode* head;

	ExpressionsList(){
		this->head = 0;
	}

	ExpressionsList(ExpressionNode* head){
		this->head = head;
	}

	void insert(JExpression* elem){
		ExpressionNode* temp = new ExpressionNode(elem);
		temp->next = head;
		head = temp;
	}

	vector<JExpression*>* toVector(){
		vector<JExpression*>* result = new vector<JExpression*>;
		while (head != 0){
			result->insert(result->begin(), head->expr);
			head = head->next;
		}
		return result;
	}
};