#pragma once 
#include <vector>
using namespace std;
class Access{
public:
	int sp_offset;
	void * value;
};

class Frame {
public:
	int sp, fp;
	string label;
	int size;
	vector<Access> formals;
	Frame(string label, int size){
		this->label = label;
	}
};