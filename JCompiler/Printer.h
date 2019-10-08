#include"JStatement.h"
class JExpression;
class Context;
class Printer : public JStatement{
public:
	JExpression *expr;
	Printer(JExpression *);
	virtual void preAnalyze(Context *);
	virtual void analyze();
	virtual void codegen();
};