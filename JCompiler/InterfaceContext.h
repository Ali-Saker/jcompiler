#pragma once
#include"Context.h"
class JInterfaceDeclaration;

class InterfaceContext : public Context{
public:

	JInterfaceDeclaration * definingInterface;

	InterfaceContext(Context *, JInterfaceDeclaration *);
};