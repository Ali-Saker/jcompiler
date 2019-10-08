#include"Type.h"
#include"JExpression.h"
#include"Context.h"
#include"typeName.h"
/**/
#include<string>
#include<vector>
using namespace std;
#include"Utils.h"
#include"JVariable.h"
#include"ReferenceType.h"
#include"packageContext.h"
#include"JPackage.h"
#include"JClassDeclaration.h"
#include"JInterfaceDeclaration.h"
#include"ProjectContext.h"
#include"PackageNameDefn.h"
#include"JVariableDeclarator.h"
#include"PrimitiveType.h"
#include"JFieldSelection.h"
#include"JClass.h"
#include"JPackageSelector.h"
TypeName::TypeName(int line, int col, char *name){
	this->line = line;
	this->col = col;
	this->name = name;
}

int TypeName::getLine(){
	return this->line;
}

int TypeName::getCol(){
	return this->col;
}

char *TypeName::nameAfterLastPeriod(){
	string s = string(this->name);
	return strcpy(new char[300] , s.substr(s.find_last_of('.') + 1).c_str());
}

TypeName *TypeName::nameBeforeLastPeriod(){
	string s = string(this->name);
	if (Utils::tokenize(this->name).size() == 1){
		return 0;
	}
	return new TypeName(this->getLine(), this->getCol(),
		strcpy(new char[300], s.substr(0, s.find_last_of('.')).c_str()));
}

int TypeName::numberOfParts(){
	int count = 0;
	for (int i = 0; i < strlen(this->name); i++){
		if (this->name[i] == '.'){
			++count;
		}
	}
	return count;
}

JExpression *TypeName::reclassifyNameBeforeLastPeriod(Context *surrounding){
	string errMsg;
	int errLine, errCol;
	int line = this->getLine();
	int col = this->getCol();
	vector<string> name = Utils::tokenize(this->name);
	int n = name.size(), i = 0;
	JVariable *variable = new JVariable(new TypeName(line, col, Utils::toCharArray(name[i])), 0);
	variable->preAnalyze(surrounding);
	variable->analyze();
	JClass *jclass = new JClass(new TypeName(line, col, Utils::toCharArray(name[i])), 0);
	jclass->preAnalyze(surrounding);
	jclass->analyze();
	JPackageSelector * jpackage = new JPackageSelector(new TypeName(line, col,this->name),0);
	jpackage->preAnalyze(surrounding);
	jpackage->analyze();
	JExpression *res = 0;
	if (variable->variableDeclarator != 0){
		res = variable;
		i += 1;
	}
	else if (jclass->classDeclaration != 0){
		res = jclass;
		i += 1;
	}
	else if(jpackage->package != 0){
		res = jpackage;
		i = Utils::tokenize(jpackage->package->name).size();
	}
	else{
		errLine = this->getLine();
		errCol = this->getCol();
		errMsg = Utils::toString(this->name) + " bad expression prefix.";
		ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		return 0;
	}
	///add interface later

	JExpression *tempRes;
	while (i < n && res != 0){
		tempRes = res;
		res = new JFieldSelection(this->getLine(), this->getCol(), tempRes, Utils::toCharArray(name[i]), 0);
		++i;
	}

	return res;

	
}

//bool TypeName::matchesExpected(TypeName* type, char* op){
//
//	if (this->equals(TypeName::ANYTYPE) || type->equals(TypeName::ANYTYPE)){
//		return true;
//	}
//
//	int conversionType = -1;
//	try{
//		conversionType = ConversionTable::getCurrentInstance()->checkConversion(this->name, type->name, op);
//	}
//	catch (exception){
//
//	}
//	// no conversion found
//	if (conversionType == -1) return false;
//
//	// assignment needs check on cast type
//	if (op == "="){
//		if (conversionType == 3){
//			return false; // report semantic down cast
//		}
//		return true;
//	}
//
//	// conversion is valid
//	return true;
//}