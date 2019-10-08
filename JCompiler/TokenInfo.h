#ifndef _TokenIfo_h
#define _TokenInfo_h
#include "global.h"

class TokenInfo{
private:
	TokenKind kind;
	std::string image;
	int line;

public:
	TokenInfo(TokenKind kind, std::string image, int line){
		this->kind = kind;
		this->image = image;
		this->line = line;
	}

	TokenInfo(TokenKind kind, int line){
		this->kind = kind;
		this->line = line;
	}
	
	std::string image(){
		return image;
	}

	TokenKind kind(){
		return kind;
	}

	int line(){
		return line;
	}
};
#endif
