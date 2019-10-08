#pragma once
#include"Defn.h"
class JPackage;

class PackageNameDefn : public Defn
{
public:

	JPackage *definingPackage;
	PackageNameDefn(JPackage *);

};

