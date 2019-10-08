#ifndef _Utils_h
#define _Utils_h
#include<string>
#include<vector>
#include"ErrorRecovery.h"
#include<stack>
#include<vector>
#include<set>
#include<fstream>
using namespace std;
typedef long long ll;
class Context;
class JFormalParameter;
class JExpression;
class Type;
class JMethodDeclaration;
class Utils{

public:
	static ofstream out;
	///counters
	static int LoopCount;
	///
	static int staticCount;

	static int SwitchCount;

	static int ElseCount;
	static int GlobalOffset;

	//after calling check conversions the returned type stored in this string below
	static string returnedType;

	static string VARIABLE_HASH_CODE;
	static string FUNCTION_HASH_CODE;
	static string CLASS_HASH_CODE;
	static string INTERFACE_HASH_CODE;

	static char* give_Me_Token_Image(const char *);

	static string toString(const char*);
	static string toString(int);

	static ll hashKey(char *key, size_t len);
	
	static char* toCharArray(string);

	static char* hashCodeCat(char*, short);

	static bool validInterfaceModifiers(bool &isInError, vector<char*>*, int, int);

	static bool validClassModifiers(bool &isInError, vector<char*>*, int, int);

	static bool validConstructorModifiers(vector<char*>*, int, int);

	static bool compare(pair<char*, char*>, pair<char*, char*>);

	static string getHashedName(char *);

	static bool canBePrivate(Context *, char *);

	static bool canBeProtected(Context *, char *);

	static vector<char*>* toVector(stack<char*> st);
	static bool find(vector<char*>::iterator, vector<char*>::iterator, char*);
	static bool find(set<char*>::iterator, set<char*>::iterator, char*);

	static vector<string> tokenize(char *);
	static bool compareParameters(vector<JExpression *> &, vector<JFormalParameter *> &);
	static bool compareParams(vector<JFormalParameter *> &, vector<JFormalParameter *> &);
	static void adeptTypes( JExpression*);
	static Type *getNewType(Type *);
	static bool itsMain(JMethodDeclaration *);
	static pair<int, int> getLoop(Context *);
	static int getJustLoop(Context *);

	static void  codegen(); 
};


#endif