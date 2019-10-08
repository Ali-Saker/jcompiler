#include"JPackage.h"
#include"PackageNameDefn.h"

PackageNameDefn::PackageNameDefn(JPackage* definingPackage) : Defn("PackageNameDefn")
{
	this->definingPackage = definingPackage;
}