#include"JPackage.h"
#include"packageContext.h"

PackageContext::PackageContext(Context *surrounding, JPackage* definingPackage) :
Context("PackageContext", surrounding->projectContext, 0, 0, surrounding)
{

	this->packageContext = this;
	this->definigPackage = definingPackage;
}