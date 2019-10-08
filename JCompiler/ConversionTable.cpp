#include"ConversionTable.h"
#include"typeName.h"
#include"Utils.h"

ConversionTable* ConversionTable::conversionTableInstance = 0;

void ConversionTable::init(){
	/*(char, "=")*/
	_ConversionTable["="]["char"].push_back(make_pair("char", new ConversionInfo("char")));
	_ConversionTable["="]["char"].push_back(make_pair("int", new ConversionInfo("char")));
	/*(int, "=")*/
	_ConversionTable["="]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["="]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	/*(long, "=")*/
	_ConversionTable["="]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["="]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["="]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	/*(float, "=")*/
	_ConversionTable["="]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["="]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["="]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["="]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	/*(double, "=")*/
	_ConversionTable["="]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["="]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["="]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["="]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["="]["double"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["="]["boolean"].push_back(make_pair("boolean", new ConversionInfo("boolean")));
	_ConversionTable["="]["String"].push_back(make_pair("String", new ConversionInfo("String")));
	_ConversionTable["="]["String"].push_back(make_pair("null", new ConversionInfo("null")));
	_ConversionTable["="]["void"].push_back(make_pair("void", new ConversionInfo("void")));

	_ConversionTable["+"]["char"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["+"]["char"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["+"]["char"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["+"]["char"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["+"]["char"].push_back(make_pair("double", new ConversionInfo("double")));
	_ConversionTable["+"]["char"].push_back(make_pair("String", new ConversionInfo("String")));

	_ConversionTable["+"]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["+"]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["+"]["int"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["+"]["int"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["+"]["int"].push_back(make_pair("double", new ConversionInfo("double")));
	_ConversionTable["+"]["int"].push_back(make_pair("String", new ConversionInfo("String")));

	_ConversionTable["+"]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["+"]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["+"]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["+"]["long"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["+"]["long"].push_back(make_pair("double", new ConversionInfo("double")));
	_ConversionTable["+"]["long"].push_back(make_pair("String", new ConversionInfo("String")));

	_ConversionTable["+"]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["+"]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["+"]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["+"]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["+"]["float"].push_back(make_pair("double", new ConversionInfo("double")));
	_ConversionTable["+"]["float"].push_back(make_pair("String", new ConversionInfo("String")));

	_ConversionTable["+"]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["+"]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["+"]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["+"]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["+"]["double"].push_back(make_pair("double", new ConversionInfo("double")));
	_ConversionTable["+"]["double"].push_back(make_pair("String", new ConversionInfo("String")));

	_ConversionTable["+"]["String"].push_back(make_pair("char", new ConversionInfo("String")));
	_ConversionTable["+"]["String"].push_back(make_pair("int", new ConversionInfo("String")));
	_ConversionTable["+"]["String"].push_back(make_pair("long", new ConversionInfo("String")));
	_ConversionTable["+"]["String"].push_back(make_pair("float", new ConversionInfo("String")));
	_ConversionTable["+"]["String"].push_back(make_pair("double", new ConversionInfo("String")));
	_ConversionTable["+"]["String"].push_back(make_pair("String", new ConversionInfo("String")));




	_ConversionTable["-"]["char"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["-"]["char"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["-"]["char"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["-"]["char"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["-"]["char"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["-"]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["-"]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["-"]["int"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["-"]["int"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["-"]["int"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["-"]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["-"]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["-"]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["-"]["long"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["-"]["long"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["-"]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["-"]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["-"]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["-"]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["-"]["float"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["-"]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["-"]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["-"]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["-"]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["-"]["double"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["*"]["char"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["*"]["char"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["*"]["char"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["*"]["char"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["*"]["char"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["*"]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["*"]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["*"]["int"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["*"]["int"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["*"]["int"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["*"]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["*"]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["*"]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["*"]["long"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["*"]["long"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["*"]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["*"]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["*"]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["*"]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["*"]["float"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["*"]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["*"]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["*"]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["*"]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["*"]["double"].push_back(make_pair("double", new ConversionInfo("double")));



	_ConversionTable["/"]["char"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["/"]["char"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["/"]["char"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["/"]["char"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["/"]["char"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["/"]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["/"]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["/"]["int"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["/"]["int"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["/"]["int"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["/"]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["/"]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["/"]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["/"]["long"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["/"]["long"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["/"]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["/"]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["/"]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["/"]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["/"]["float"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["/"]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["/"]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["/"]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["/"]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["/"]["double"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["%"]["char"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["%"]["char"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["%"]["char"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["%"]["char"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["%"]["char"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["%"]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["%"]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["%"]["int"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["%"]["int"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["%"]["int"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["%"]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["%"]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["%"]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["%"]["long"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["%"]["long"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["%"]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["%"]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["%"]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["%"]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["%"]["float"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["%"]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["%"]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["%"]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["%"]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["%"]["double"].push_back(make_pair("double", new ConversionInfo("double")));


	_ConversionTable[">"]["char"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable[">"]["char"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable[">"]["char"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable[">"]["char"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable[">"]["char"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable[">"]["int"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable[">"]["int"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable[">"]["int"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable[">"]["int"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable[">"]["int"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable[">"]["long"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable[">"]["long"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable[">"]["long"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable[">"]["long"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable[">"]["long"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable[">"]["float"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable[">"]["float"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable[">"]["float"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable[">"]["float"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable[">"]["float"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable[">"]["double"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable[">"]["double"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable[">"]["double"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable[">"]["double"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable[">"]["double"].push_back(make_pair("double", new ConversionInfo("boolean")));


	_ConversionTable["=="]["char"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable["=="]["char"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable["=="]["char"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable["=="]["char"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable["=="]["char"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable["=="]["int"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable["=="]["int"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable["=="]["int"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable["=="]["int"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable["=="]["int"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable["=="]["long"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable["=="]["long"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable["=="]["long"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable["=="]["long"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable["=="]["long"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable["=="]["float"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable["=="]["float"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable["=="]["float"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable["=="]["float"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable["=="]["float"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable["=="]["double"].push_back(make_pair("char", new ConversionInfo("boolean")));
	_ConversionTable["=="]["double"].push_back(make_pair("int", new ConversionInfo("boolean")));
	_ConversionTable["=="]["double"].push_back(make_pair("long", new ConversionInfo("boolean")));
	_ConversionTable["=="]["double"].push_back(make_pair("float", new ConversionInfo("boolean")));
	_ConversionTable["=="]["double"].push_back(make_pair("double", new ConversionInfo("boolean")));

	_ConversionTable["=="]["String"].push_back(make_pair("String", new ConversionInfo("boolean")));
	_ConversionTable["=="]["boolean"].push_back(make_pair("boolean", new ConversionInfo("boolean")));

	/*(char, "cast")*/
	_ConversionTable["cast"]["char"].push_back(make_pair("char", new ConversionInfo("char")));
	_ConversionTable["cast"]["char"].push_back(make_pair("int", new ConversionInfo("char")));
	_ConversionTable["cast"]["char"].push_back(make_pair("long", new ConversionInfo("char")));
	_ConversionTable["cast"]["char"].push_back(make_pair("float", new ConversionInfo("char")));
	_ConversionTable["cast"]["char"].push_back(make_pair("double", new ConversionInfo("char")));
	/*(int, "cast")*/
	_ConversionTable["cast"]["int"].push_back(make_pair("char", new ConversionInfo("int")));
	_ConversionTable["cast"]["int"].push_back(make_pair("int", new ConversionInfo("int")));
	_ConversionTable["cast"]["int"].push_back(make_pair("long", new ConversionInfo("int")));
	_ConversionTable["cast"]["int"].push_back(make_pair("float", new ConversionInfo("int")));
	_ConversionTable["cast"]["int"].push_back(make_pair("double", new ConversionInfo("int")));
	/*(long, "cast")*/
	_ConversionTable["cast"]["long"].push_back(make_pair("char", new ConversionInfo("long")));
	_ConversionTable["cast"]["long"].push_back(make_pair("int", new ConversionInfo("long")));
	_ConversionTable["cast"]["long"].push_back(make_pair("long", new ConversionInfo("long")));
	_ConversionTable["cast"]["long"].push_back(make_pair("float", new ConversionInfo("long")));
	_ConversionTable["cast"]["long"].push_back(make_pair("double", new ConversionInfo("long")));
	/*(float, "cast")*/
	_ConversionTable["cast"]["float"].push_back(make_pair("char", new ConversionInfo("float")));
	_ConversionTable["cast"]["float"].push_back(make_pair("int", new ConversionInfo("float")));
	_ConversionTable["cast"]["float"].push_back(make_pair("long", new ConversionInfo("float")));
	_ConversionTable["cast"]["float"].push_back(make_pair("float", new ConversionInfo("float")));
	_ConversionTable["cast"]["float"].push_back(make_pair("double", new ConversionInfo("float")));
	/*(double, "cast")*/
	_ConversionTable["cast"]["double"].push_back(make_pair("char", new ConversionInfo("double")));
	_ConversionTable["cast"]["double"].push_back(make_pair("int", new ConversionInfo("double")));
	_ConversionTable["cast"]["double"].push_back(make_pair("long", new ConversionInfo("double")));
	_ConversionTable["cast"]["double"].push_back(make_pair("float", new ConversionInfo("double")));
	_ConversionTable["cast"]["double"].push_back(make_pair("double", new ConversionInfo("double")));

	_ConversionTable["&&"]["boolean"].push_back(make_pair("boolean", new ConversionInfo("boolean")));
	_ConversionTable["||"]["boolean"].push_back(make_pair("boolean", new ConversionInfo("boolean")));
	//_ConversionTable["=="]["Object"].push_back(make_pair("Object", new ConversionInfo("Object")));
	//_ConversionTable["=="]["Object"].push_back(make_pair("Object", new ConversionInfo("Object")));
}

/*
 * return 0 : if operation not defined on type lhs.
 * return 1 : if operation on types lhs, rhs valid.
 * return 2 : if operation not defined on types lhs, rhs.
 */

int ConversionTable::checkConversion(string lhs, string rhs, string op ){
	vector< pair< string, ConversionInfo*> >  types = _ConversionTable[op][lhs];
	if (types.size() == 0) return 0;
	for each (pair< string, ConversionInfo*> type in types){
		if (type.first.compare(rhs) == 0){
			Utils::returnedType = type.second->returnType;
			return 1;
		}
	}
	return 2;
}

/* add new type to the conversion table */
void ConversionTable::addType(string childType, string parentType){

	//add this type to himself
	_ConversionTable["="][childType].push_back(make_pair(childType, new ConversionInfo(childType)));
	_ConversionTable["=="][childType].push_back(make_pair(childType, new ConversionInfo(childType)));
	_ConversionTable["cast"][childType].push_back(make_pair(childType, new ConversionInfo(childType)));

	if (parentType.compare("") != 0){
		// add super type to this type "Down Cast"
		_ConversionTable["cast"][childType].push_back(make_pair(parentType, new ConversionInfo(childType)));

		// add this type to super types
		_ConversionTable["cast"][parentType].push_back(make_pair(childType, new ConversionInfo(parentType)));
		_ConversionTable["="][parentType].push_back(make_pair(childType, new ConversionInfo(parentType)));
	}
}

/* get current instance of this table */
ConversionTable* ConversionTable::getCurrentInstance(){
	if (conversionTableInstance == 0){
		conversionTableInstance = new ConversionTable();
		conversionTableInstance->init();
	}
	return conversionTableInstance;
}