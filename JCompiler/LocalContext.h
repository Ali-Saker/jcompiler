#pragma once
#include"Context.h"
class JBlock;
class LocalContext :
	public Context
{
public:
	JBlock *definingBlock;
	LocalContext(Context *, JBlock *);
};