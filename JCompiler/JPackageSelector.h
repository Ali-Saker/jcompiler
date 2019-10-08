#pragma once
#include "JExpression.h"
class TypeName; class Context; class JPackage;
class JPackageSelector :
	public JExpression
{
public:
	TypeName * typeName;
	JPackage * package;
	virtual void preAnalyze(Context *);
	virtual void analyze();
	JPackageSelector(TypeName *, JPackage *);
	~JPackageSelector();


};

