#include"JExpression.h"
#include"JEmptyStatement.h"

JEmptyStatement::JEmptyStatement(int line, int col) : JStatement(line, col, "JEmptyStatement")
{
}

void JEmptyStatement::preAnalyze(Context *)
{
}
void JEmptyStatement::analyze()
{
}

void JEmptyStatement::codegen()
{
}