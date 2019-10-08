#include"AccessProperty.h"

/**/
#include<string>
#include"Utils.h"
#include"ErrorRecovery.h"

AccessProperty::AccessProperty(){
	this->abstractFrequency = 0;
	this->finalFrequency = 0;
	this->nativeFrequency = 0;
	this->privateFrequency = 0;
	this->protectedFrequency = 0;
	this->publicFrequency = 0;
	this->staticFrequency = 0;
	this->synchronizedFrequency = 0;
	this->transientFrequency = 0;
	this->volatileFrequency = 0;

}

void AccessProperty::setAccessProperty(int property){
	switch (property){
	case 1:
		this->abstractFrequency += 1;
		break;
	case 2:
		this->finalFrequency += 1;
		break;
	case 3:
		this->publicFrequency += 1;
		break;
	case 4:
		this->protectedFrequency += 1;
		break;
	case 5:
		this->privateFrequency += 1;
		break;
	case 6:
		this->staticFrequency += 1;
		break;
	case 7:
		this->transientFrequency += 1;
		break;
	case 8:
		this->volatileFrequency += 1;
		break;
	case 9:
		this->nativeFrequency += 1;
		break;
	case 10:
		this->synchronizedFrequency += 1;
		break;
	}
}

bool AccessProperty::isAbstract(){
	return this->abstractFrequency > 0;
}
bool AccessProperty::isFinal(){
	return this->finalFrequency > 0;
}
bool AccessProperty::isNative(){
	return this->nativeFrequency > 0;
}
bool AccessProperty::isPrivate(){
	return this->privateFrequency > 0;
}
bool AccessProperty::isProtected(){
	return this->protectedFrequency > 0;
}
bool AccessProperty::isPublic(){
	return this->publicFrequency > 0;
}
bool AccessProperty::isStatic(){
	return this->staticFrequency > 0;
}
bool AccessProperty::isSynchronized(){
	return this->synchronizedFrequency > 0;
}
bool AccessProperty::isTransient(){
	return this->transientFrequency > 0;
}
bool AccessProperty::isVolatile(){
	return this->volatileFrequency > 0;
}

void AccessProperty::checkRepeatedModifiers(int line, int col, char *name){
	if (this->abstractFrequency > 1 || this->finalFrequency > 1 || this->nativeFrequency > 1 ||
		this->privateFrequency > 1 || this->protectedFrequency > 1 || this->publicFrequency > 1 ||
		this->staticFrequency > 1 || this->synchronizedFrequency > 1 || this->transientFrequency > 1 ||
		this->volatileFrequency > 1){
		string errMsg = "Duplicate modifier for the " + Utils::toString(name) + ".";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
	}
}

void AccessProperty::checkConflictedModifiers(int line, int col, char *name){
	if ((this->publicFrequency > 0 && this->privateFrequency > 0) ||
		(this->publicFrequency > 0 && this->protectedFrequency > 0) ||
		(this->privateFrequency > 0 && this->protectedFrequency > 0)){

		string errMsg = "The " + Utils::toString(name) + " can only set one of public / protected / private";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
	}
}

void AccessProperty::validAsClassAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "class ");
	strcat(fullName, name);
	bool checker = false;

	if (this->nativeFrequency > 1 || this->privateFrequency > 1 || this->protectedFrequency > 1 ||
		this->staticFrequency > 1 || this->synchronizedFrequency > 1 || this->transientFrequency > 1 ||
		this->volatileFrequency > 1){
		errMsg = "Illegal modifier for the class " + Utils::toString(name) + "; only public, abstract & final are permitted";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
		this->checkConflictedModifiers(line, col, fullName);
	}
}

void AccessProperty::validAsInnerClassAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "inner class ");
	strcat(fullName, name);
	bool checker = false;
	

	if (this->nativeFrequency > 1 || this->synchronizedFrequency > 1 ||
		this->transientFrequency > 1 || this->volatileFrequency > 1){
		errMsg = "Illegal modifier for the inner class " + Utils::toString(name) + "; only public, protected, private, abstract, static & final are permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
		this->checkConflictedModifiers(line, col, fullName);
	}
}


void AccessProperty::validAsInterfaceAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "interface ");
	strcat(fullName, name);
	bool checker = false;

	if (this->nativeFrequency > 1 || this->privateFrequency > 1 || this->protectedFrequency > 1 ||
		this->staticFrequency > 1 || this->synchronizedFrequency > 1 || this->transientFrequency > 1 ||
		this->volatileFrequency > 1 || this->finalFrequency > 1){
		errMsg = "Illegal modifier for the interface " + Utils::toString(name) + "; only public, abstract are permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
		this->checkConflictedModifiers(line, col, fullName);
	}
}

void AccessProperty::validAsInterfaceFieldAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "interface field ");
	strcat(fullName, name);
	bool checker = false;

	if (this->nativeFrequency > 1 || this->privateFrequency > 1 || this->protectedFrequency > 1 ||
		this->synchronizedFrequency > 1 || this->transientFrequency > 1 || this->volatileFrequency > 1 ||
		this->abstractFrequency > 1){
		errMsg = "Illegal modifier for the interface field " + Utils::toString(name) + "; only public, static & final are permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
	}
}

void AccessProperty::validAsInterfaceMethodAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "interface method ");
	strcat(fullName, name);
	bool checker = false;

	if (this->nativeFrequency > 1 || this->privateFrequency > 1 || this->protectedFrequency > 1 ||
		this->synchronizedFrequency > 1 || this->transientFrequency > 1 || this->volatileFrequency > 1 ||
		this->finalFrequency > 1){
		errMsg = "Illegal modifier for the interface method " + Utils::toString(name) + "; only public, abstract, static are permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
		if (this->isAbstract() && this->isStatic()){
			errMsg = "Illegal combination of modifiers for the interface method " + Utils::toString(name) +
				"; only one of abstract, static permitted.";
			ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		}
	}
}

void AccessProperty::validAsMethodAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "method ");
	strcat(fullName, name);
	bool checker = false;

	if (this->transientFrequency > 1 || this->volatileFrequency > 1){
		errMsg = "Illegal modifier for the method " + Utils::toString(name) + "; only public, protected, private, abstract, static, final, synchronized, native & strictfp are permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
		this->checkConflictedModifiers(line, col, fullName);
		if (this->isAbstract() && this->isStatic()){
			errMsg = "Illegal combination of modifiers for the method " + Utils::toString(name) +
				"; only one of abstract, static permitted.";
			ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		}
	}
}
//Illegal modifier for the field a; only public, protected, private, static, final, transient & volatile are permitted
void AccessProperty::validAsFieldAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "field ");
	strcat(fullName, name);
	bool checker = false;

	if (this->abstractFrequency > 1 || this->nativeFrequency > 1 || this->synchronizedFrequency > 1){
		errMsg = "Illegal modifier for the field " + Utils::toString(name) +
			"; only public, protected, private, static, final, transient & volatile are permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
		this->checkConflictedModifiers(line, col, fullName);
	}
}
void AccessProperty::validAsLocalVariableAccessProperty(int line, int col, char *name){
	string errMsg;
	char *fullName = new char[300];
	strcpy(fullName, "local variable ");
	strcat(fullName, name);
	bool checker = false;

	if (this->publicFrequency > 1 || this->privateFrequency > 1 || this->protectedFrequency > 1 ||
		this->abstractFrequency > 1 || this->nativeFrequency > 1 || this->synchronizedFrequency > 1 |
		this->staticFrequency > 1 || this->volatileFrequency > 1 || this->transientFrequency > 1){
		errMsg = "Illegal modifier for the local variable " + Utils::toString(name) +
			"; only final is permitted.";
		ErrorRecovery::reportSemanticError(line, col, Utils::toCharArray(errMsg));
		checker = true;
	}

	if (!checker){
		this->checkRepeatedModifiers(line, col, fullName);
	}
}