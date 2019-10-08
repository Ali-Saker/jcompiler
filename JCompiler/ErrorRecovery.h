#pragma once
#include<queue>
#include<iostream>
using namespace std;
class ErrorRecovery
{
public:

	static queue<pair<pair<int, int>, char*> > *ErrorList;

	static void printErrorList(){
		while (!ErrorList->empty()){
			pair<pair<int, int>, char*> thisError = ErrorList->front();
			ErrorList->pop();
			cout << "line " << thisError.first.first << " col " << thisError.first.second << " " << thisError.second << endl;
		}

	}

	static void reportSemanticError(int line, int col, char* msg){
		char* errMsg = new char[256];
		strcpy(errMsg, "semantic error, ");
		strcat(errMsg, msg);
		ErrorList->push(make_pair(make_pair(line, col), errMsg));
	}

	static void reportParserError(int line, int col, char* msg){
		char* errMsg = new char[256];
		strcpy(errMsg, "Parser error, ");
		strcat(errMsg, msg);
		ErrorList->push(make_pair(make_pair(line, col), errMsg));
	}


	ErrorRecovery()
	{
	}

	~ErrorRecovery()
	{
	}
};

