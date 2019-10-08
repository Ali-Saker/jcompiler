#pragma once

#include<map>
#include<iostream>
#include<string>
#include <vector>
#include<string.h>
using namespace std;

class TypeName;


struct ConversionInfo{
	string returnType;
	ConversionInfo(string returnType){
		this->returnType = returnType;
	}
	bool operator < (const ConversionInfo*  conversioninfo) const{
		return this->returnType < conversioninfo->returnType;
	}
	/*bool operator==(const ConversionInfo*  conversioninfo) const{
		return this->returnType == conversioninfo->returnType;
	}*/
};


class  ConversionTable{
private:
	map < string, map< string, vector< pair< string, ConversionInfo* > > > > _ConversionTable;
	static ConversionTable* conversionTableInstance;
	ConversionTable(){};

public:
	static ConversionTable* getCurrentInstance();
	void init();
	int checkConversion(string, string, string);
	void addType(string, string);
};
