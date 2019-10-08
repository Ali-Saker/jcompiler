#include"JBlock.h"
#include"LocalContext.h"

LocalContext::LocalContext(Context *surrounding, JBlock *definigBlock) :
Context("LocalContext", surrounding->projectContext, surrounding->packageContext, surrounding->compilationContext,
surrounding){
	this->definingBlock = definigBlock;
}