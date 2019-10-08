#pragma once
#include"Context.h"
class JPackage;

class PackageContext : public Context{

public:

	JPackage *definigPackage;

	PackageContext(Context *, JPackage*);

};