#include"Utils.h"
#include"Context.h"
#include"ClassContext.h"
#include"JClassDeclaration.h"
#include"ReferenceType.h"
#include"Type.h"
#include"ConversionTable.h"
#include"JExpression.h"
#include"JFormalParameter.h"
#include"JVariableDeclarator.h"
#include "JBinaryExpression.h"
#include "PrimitiveType.h"
#include "ReferenceType.h"
#include "ArrayType.h"
#include<vector>
#include"typeName.h"
#include"Type.h"
#include"JMethodDeclaration.h"
#include"JFormalParameter.h"
#include"MethodContext.h"
#include"LocalContext.h"
#include"JBlock.h"
string Utils::VARIABLE_HASH_CODE = "#12AWE78FT";
string Utils::FUNCTION_HASH_CODE = "#98CDDESC76";
string Utils::CLASS_HASH_CODE = "#FF9436CD21";
string Utils::INTERFACE_HASH_CODE = "#ABC44DE99";
ofstream Utils::out("assembly.asm");

string Utils::getHashedName(char *name){
	string tmp = "";

	for (int i = 0; i < strlen(name) && name[i] != '#'; i++){
		tmp += name[i];
	}

	return tmp;
}

char* Utils::give_Me_Token_Image(const char * image){
	char *temp = new char[255];
	strcpy(temp, image);
	return temp;

}

string Utils::toString(const char* image){
	string temp = "";
	for(int i=0; i<strlen(image); i++) temp += image[i];
	return temp;
}

char* Utils::toCharArray(string s){
	char *ret = new char[s.length() + 1];
	strcpy(ret, s.c_str());
	return ret;
}


/*
	a nice string hash function called 'Jenkins One' At A Time Hash.
*/
ll Utils::hashKey(char *key, size_t len) {
	ll hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

char* Utils::hashCodeCat(char *name, short code){
	switch (code)
	{
	case 0:
		return strcat(strcpy(new char[256], name), toCharArray(CLASS_HASH_CODE));
		break;
	case 1:
		return strcat(strcpy(new char[256], name), toCharArray(VARIABLE_HASH_CODE));
		break;
	case 2:
		return strcat(strcpy(new char[256], name), toCharArray(FUNCTION_HASH_CODE));
		break;
	case 3:
		return strcat(strcpy(new char[256], name), toCharArray(INTERFACE_HASH_CODE));
		break;
	}
}


bool Utils::find(vector<char*>::iterator begin, vector<char*>::iterator end, char* value){
	for (vector<char*>::iterator t = begin; t != end; t++){
		if (strcmp(value, *t) == 0)
			return 1;
	}
	return 0;
}

bool Utils::find(set<char*>::iterator begin, set<char*>::iterator end, char* value){
	for (set<char*>::iterator t = begin; t != end; t++){
		if (strcmp(value, *t) == 0)
			return 1;
	}
	return 0;
}

vector<string> Utils::tokenize(char *name){
	vector<string> result;
	int n = strlen(name);
	string tempName;
	for (int i = 0; i < n; i++){
		if (name[i] == '.'){
			result.push_back(tempName);
			tempName = "";
		}
		else{
			tempName += name[i];
		}
	}
	result.push_back(tempName);
	return result;
}


vector<char*>* Utils::toVector(stack<char*> st){
	vector<char*> *res = new vector<char*>;
	while (!st.empty()){
		res->push_back(st.top());
		st.pop();
	}
	return res;
}

string Utils::toString(int number){
	string temp = "";
	if (number == 0) return "0";
	while (number != 0){
		temp += number % 10;
		number /= 10;
	}

	reverse(temp.begin(), temp.end());
	return temp;
}

bool Utils::canBePrivate(Context *surrounding, char* className){

	while (true){
		if (surrounding == 0) return 0;
		if (dynamic_cast<ClassContext *>(surrounding)){
			JClassDeclaration *classDecl = ((ClassContext *)surrounding)->definingClass;
			if (strcmp(classDecl->fullName, className) != 0) return 0;
			else return 1;
		}
		surrounding = surrounding->surroundingContext;
	}
}

bool Utils::canBeProtected(Context *surrounding, char* className){
	JClassDeclaration *classDecl;
	while (true){
		if (surrounding == 0) return 0;
		if (dynamic_cast<ClassContext *>(surrounding)){
			classDecl = ((ClassContext *)surrounding)->definingClass;
			break;
		}
		surrounding = surrounding->surroundingContext;
	}

	while (true){
		if (strcmp(classDecl->fullName, className) == 0) return 1;
		
		if (classDecl->superType == 0) return 0;
		else{
			ReferenceType * referenceType = (ReferenceType*)classDecl->superType;
			classDecl = (JClassDeclaration *)referenceType->referenceTypeDecl;
			if (!classDecl->analyzed) classDecl->analyze();
		}
	}
}

bool Utils::compareParameters(vector<JExpression *> &args, vector<JFormalParameter *> &params){
	int n = params.size();
	int m = args.size();
	if (m > n) return 0;
	for (int i = 0; i < m; i++) args[i]->analyze();
	for (int i = 0; i < n; i++) params[i]->analyze();

	for (int i = m; i < n; i++){
		if (params[i]->variableDeclarator->initializer == 0) return 0;
	}

	for (int i = 0; i < m; i++){
		if (params[i]->type == 0 || args[i]->expressionType == 0) return 0;
		pair<char *, int> lhs = params[i]->variableDeclarator->type->getName();
		pair<char *, int> rhs = args[i]->expressionType->getName();
		int status = ConversionTable::getCurrentInstance()->checkConversion(Utils::toString(lhs.first),
			Utils::toString(rhs.first), "=");

		if (status != 1 || lhs.second != rhs.second){
			return 0;
		}
	}
	return 1;
}


bool Utils::compareParams(vector<JFormalParameter *> &params1, vector<JFormalParameter *> &params2){
	int n = params1.size();
	int m = params2.size();
	if (m != n) return 0;
	for (int i = 0; i < m; i++) params1[i]->analyze();
	for (int i = 0; i < n; i++) params2[i]->analyze();


	for (int i = 0; i < m; i++){
		if (params1[i]->type == 0 || params2[i]->type == 0) return 0;
	
		if (dynamic_cast<PrimitiveType *>(params1[i]->type)){
			if (!dynamic_cast<PrimitiveType *>(params2[i]->type)) return 0;

			if (strcmp(params1[i]->type->typeName->name, params2[i]->type->typeName->name) != 0) return 0;
		}
		else if (dynamic_cast<ReferenceType *>(params1[i]->type)){
			if (!dynamic_cast<ReferenceType *>(params2[i]->type)) return 0;

			if (strcmp(params1[i]->type->typeName->name, params2[i]->type->typeName->name) != 0) return 0;
		}
		else{
			if (!dynamic_cast<ArrayType *>(params2[i]->type)) return 0;

			if (strcmp(params1[i]->type->typeName->name, params2[i]->type->typeName->name) != 0) return 0;
			int t1 = ((ArrayType *)params1[i]->type)->dimensions;
			int t2 = ((ArrayType *)params2[i]->type)->dimensions;
			if (t1 != t2) return 0;
		}
	}

	return 1;
}

Type * Utils::getNewType(Type *oldType){
	if (dynamic_cast<PrimitiveType*>(oldType)){
		if (Utils::returnedType == "int") return PrimitiveType::JINTEGER;
		if (Utils::returnedType == "double") return PrimitiveType::JDOUBLE;
		if (Utils::returnedType == "float") return PrimitiveType::JFLOAT;
		if (Utils::returnedType == "String") return PrimitiveType::JSTRING;
		if (Utils::returnedType == "char") return PrimitiveType::JCHAR;
		if (Utils::returnedType == "long") return PrimitiveType::JLONG;
		if (Utils::returnedType == "boolean") return PrimitiveType::JBOOLEAN;
		if (Utils::returnedType == "void") return PrimitiveType::JVOID;
		if (Utils::returnedType == "null") return PrimitiveType::JNUL;
	}
	else{
		return oldType;
	}
}

bool Utils::itsMain(JMethodDeclaration *method){
	if (strcmp(method->name, "main") != 0) return 0;
	if (method->params == 0 || method->params->size() > 1) return 0;
	if (!dynamic_cast<ArrayType*>(method->params->at(0)->type)) return 0;
	ArrayType *arrayType = (ArrayType*)method->params->at(0)->type;
	if (arrayType->dimensions != 1) return 0;
	if (strcmp(arrayType->type->typeName->name, "String") != 0) return 0;
	return 1;
}

pair<int, int> Utils::getLoop(Context *surrounding){
	while (!dynamic_cast<MethodContext *>(surrounding)){
		LocalContext *local = (LocalContext *)(surrounding);
		JBlock *block = local->definingBlock;
		if (block->id != -1){
			return make_pair(block->id, block->kind);
		}
		surrounding = surrounding->surroundingContext;
	}
	return make_pair(-1, -1);
}

int Utils::getJustLoop(Context *surrounding){
	
	while (!dynamic_cast<MethodContext *>(surrounding)){
		LocalContext *local = (LocalContext *)(surrounding);
		JBlock *block = local->definingBlock;
		if (block->kind == 1){
			return block->id;
		}
		surrounding = surrounding->surroundingContext;
	}
	return -1;
}
void Utils::adeptTypes(JExpression* expr){
	JExpression * lhs = ( (JBinaryExpression*)expr )->lhs;
	JExpression * rhs = ((JBinaryExpression*)expr)->rhs;
	if (expr->isString()){
		/*if (!lhs->isString()){
			if (lhs->isFP()){
				Utils::out << "lwc1 $f12, 4($sp)" << endl;
				Utils::out << "addi $sp, $sp, -4" << endl;
				Utils::out << "sw $ra, 4($sp)" << endl;
				Utils::out << "jal float_to_str" << endl;
				Utils::out << "lw $ra, 4($sp)" << endl;
				Utils::out << "addi $sp, $sp, 4" << endl;
			    Utils::out << "sw $v0, 4($sp)" << endl;
			}
			else{
				Utils::out << "lw $a0, 4($sp)" << endl;
				Utils::out << "addi $sp, $sp, -4" << endl;
				Utils::out << "sw $ra, 4($sp)" << endl;
				Utils::out << "jal int_to_str" << endl;
				Utils::out << "lw $ra, 4($sp)" << endl;
				Utils::out << "addi $sp, $sp, 4" << endl;
				Utils::out << "sw $v0, 4($sp)" << endl;
			}
		}*/
		/*
		if (!rhs->isString()){
			if (rhs->isFP()){
				Utils::out << "lwc1 $f12, 8($sp)" << endl;
				Utils::out << "addi $sp, $sp, -4" << endl;
				Utils::out << "sw $ra, 4($sp)" << endl;
				Utils::out << "jal float_to_str" << endl;
				Utils::out << "lw $ra, 4($sp)" << endl;
				Utils::out << "addi $sp, $sp, 4" << endl;
				Utils::out << "sw $v0, 8($sp)" << endl;
			}
			else{
				Utils::out << "lw $a0, 8($sp)" << endl;
				Utils::out << "addi $sp, $sp, -4" << endl;
				Utils::out << "sw $ra, 4($sp)" << endl;
				Utils::out << "jal int_to_str" << endl;
				Utils::out << "lw $ra, 4($sp)" << endl;
				Utils::out << "addi $sp, $sp, 4" << endl;
				Utils::out << "sw $v0, 8($sp)" << endl;
			}
		}*/

	}
	else if (expr->isFP()){
		if (lhs->isIntegral()){
		    //convert to fp
			Utils::out << "lwc1 $f1, 4($sp)" << endl;
			Utils::out << "cvt.s.w $f1, $f1" << endl;
			Utils::out << "swc1 $f1, 4($sp)" << endl;
		
		}
		if (rhs->isIntegral()){
			//convert to fp
			Utils::out << "lwc1 $f1, 8($sp)" << endl;
			Utils::out << "cvt.s.w $f1, $f1" << endl;
			Utils::out << "swc1 $f1, 8($sp)" << endl;
		}

	}
	else if (expr->isIntegral()){
		if (lhs->isFP()){
			//convert to fp
			Utils::out << "lwc1 $f1, 4($sp)" << endl;
			Utils::out << "cvt.w.s $f1, $f1" << endl;
			Utils::out << "mfc1 $t1, $f1" << endl;
			Utils::out << "sw $t1, 4($sp)" << endl;

		}
		if (rhs->isFP()){
			//convert to fp
			Utils::out << "lwc1 $f1, 8($sp)" << endl;
			Utils::out << "cvt.w.s $f1, $f1" << endl;
			Utils::out << "mfc1 $t1, $f1" << endl;
			Utils::out << "sw $t1, 8($sp)" << endl;
		}

	}

}

int Utils::LoopCount = 0;
int Utils::staticCount = 1;
string Utils::returnedType = "";
int Utils::SwitchCount = 0;
int Utils::ElseCount = 0;
int Utils::GlobalOffset = 0;

void  Utils::codegen(){
	Utils::out << "int_to_str:" << endl;
	Utils::out << "move $t2, $a0" << endl;
	Utils::out << "li $t3, 1" << endl;
	Utils::out << "li $t4, 10" << endl;
	Utils::out << "loop_int_to_str :" << endl;
	Utils::out << "rem $t2, $t1, $t4 # $t2 %= 10" << endl;
	Utils::out << "addi $t2, $t2, 48 # $t2 += '0'" << endl;
	Utils::out << "div $t1, $t1, $t4 #$t1 /= 10" << endl;
	Utils::out << "addi $sp, $sp, -4" << endl;
	Utils::out << "sw $t2, 4($sp)" << endl;
	Utils::out << "addi $t3, $t3, 1" << endl;
	Utils::out << "beq $t1, $zero, end_loop_int_to_str" << endl;
	Utils::out << "j loop_int_to_str" << endl;
	Utils::out << "end_loop_int_to_str :" << endl;

	Utils::out << "addi $t0, $t3, 1" << endl;
	Utils::out << "sll $t0, $t0, 2" << endl;
	Utils::out << "move $a0, $t0" << endl;
	Utils::out << "li $v0, 9" << endl;
	Utils::out << "syscall" << endl;
	Utils::out << "move $t0, $v0" << endl;
	Utils::out << "move $v1, $t3" << endl;
	Utils::out << "addi $t1, $t3, 1" << endl;
	Utils::out << "sw $t1, 0($t0)" << endl;

	Utils::out << "loop_int_to_str_empty_stack:" << endl;
	Utils::out << "lw  $t1, 4($sp)" << endl;
	Utils::out << "add $sp, $sp, 4" << endl;
	Utils::out << "addi $t0, $t0, 4" << endl;
	Utils::out << "sw  $t1, 0($t0)" << endl;
	Utils::out << "addi $t3, $t3, -1" << endl;
	Utils::out << "beq $t3, $zero, end_int_to_str_empty_stack" << endl;
	Utils::out << "j loop_int_to_str_empty_stack" << endl;
	Utils::out << "end_int_to_str_empty_stack :" << endl;

	Utils::out << "jal $ra" << endl;





	Utils::out << "#float in $f12" << endl;
	Utils::out << "#ref in $v0" << endl;
	Utils::out << "float_to_str :" << endl;
	Utils::out << "#integer part" << endl;
	Utils::out << "mov.s $f0, $f12" << endl;
	Utils::out << "cvt.w.s $f1, $f0" << endl;
	Utils::out << "mfc1 $a0, $f1" << endl;

	Utils::out << "addi $sp, $sp, -4" << endl;
	Utils::out << "sw $ra, 4($sp)" << endl;
	Utils::out << "jal int_to_str" << endl;
	Utils::out << "lw $ra, 4($sp)" << endl;
	Utils::out << "addi $sp, $sp, 4" << endl;
	
	Utils::out << "move $t0, $v0" << endl;
	Utils::out << "move $t1, $v1" << endl;

	Utils::out << "#save registers" << endl;

	Utils::out << "addiu $sp, $sp, -8" << endl;
	Utils::out << "sw $t0, 4($sp)" << endl;
	Utils::out << "sw $t1, 8($sp)" << endl;



	Utils::out << "#fraction part 5 decimal digitsW" << endl;
	Utils::out << "li.s $f3, 10000.0" << endl;
	Utils::out << "	cvt.s.w $f1, $f1 # back to float" << endl;
	Utils::out << "sub.s $f1, $f0, $f1" << endl;
	Utils::out << "	mul.s $f1, $f1, $f3" << endl;
	Utils::out << "cvt.w.s $f1, $f1" << endl;
	Utils::out << "mfc1 $a0, $f1" << endl;

	Utils::out << "addi $sp, $sp, -4" << endl;
	Utils::out << "sw $ra, 4($sp)" << endl;
	Utils::out << "jal int_to_str" << endl;
	Utils::out << "lw $ra, 4($sp)" << endl;
	Utils::out << "addi $sp, $sp, 4" << endl;


	Utils::out << "move $t2, $v0" << endl;
	Utils::out << "move $t3, $v1" << endl;
	

	Utils::out << "sw $t0, 4($sp)" << endl;
	Utils::out << "sw $t1, 8($sp)" << endl;
	Utils::out << "addiu $sp, $sp, 8" << endl;

	Utils::out << "add $a0, $t1, $t3" << endl;
	Utils::out << "addi $a0, $a0, 2" << endl;
	Utils::out << "addi $a0, $a0, 2" << endl;
	Utils::out << "sll $a0, $a0, 2" << endl;
	Utils::out << "li $v0, 9" << endl;
	Utils::out << "syscall" << endl;
	Utils::out << "move $t7, $v0" << endl;
	Utils::out << "addi $t1, $t1, -1" << endl;
	Utils::out << "li $t5, 0" << endl;
	Utils::out << "add $a0, $t1, $t3" << endl;
	Utils::out << "addi $a0, $a0, 1" << endl;
	Utils::out << "sw $a0, 0($t7)" << endl;
	
	Utils::out << "# $t0 + $t2" << endl;
	Utils::out << "loop_fp_to_str :" << endl;
	Utils::out << "beq $t5, $t1, end_loop_fp_to_str" << endl;
	Utils::out << "addi $t5, $t5, 1" << endl;
	Utils::out << "addi $t0, $t0, 4" << endl;
	Utils::out << "addi $t7, $t7, 4" << endl;
	Utils::out << "lw  $t6, 0($t0)" << endl;
	Utils::out << "sw  $t6, 0($t7)" << endl;

	Utils::out << "j loop_fp_to_str" << endl;
	Utils::out << "end_loop_fp_to_str :" << endl;
	Utils::out << "li $t6, 46" << endl;
	Utils::out << "addi $t7, $t7, 4" << endl;
	Utils::out << "sw  $t6, 0($t7)" << endl;
	Utils::out << "li $t5, 0" << endl;
	Utils::out << "loop_fp_to_str1 :" << endl;
	Utils::out << "beq $t5, $t3, end_loop_fp_to_str1" << endl;
		Utils::out << "addi $t5, $t5, 1" << endl;
	Utils::out << "addi $t2, $t2, 4" << endl;
	Utils::out << "addi $t7, $t7, 4" << endl;
	Utils::out << "lw  $t6, 0($t2)" << endl;
	Utils::out << "sw  $t6, 0($t7)" << endl;
	
	Utils::out << "j loop_fp_to_str1" << endl;
	Utils::out << "end_loop_fp_to_str1 :" << endl;


	Utils::out << "j $ra" << endl;

}