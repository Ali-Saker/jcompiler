#include"JExpression.h"
#include"Context.h"
#include"JJumpStatement.h"

#include"MethodContext.h"
#include"ErrorRecovery.h"
#include"Utils.h"
#include"JMethodDeclaration.h"
#include"Type.h"
#include"ConversionTable.h"
JJumpStatement::JJumpStatement(int line, int col, char *jumpName, JExpression *returnExpression)
: JStatement(line, col, "JJumpStatement")
{
	this->jumpName = jumpName;
	this->returnExpression = returnExpression;
}

void JJumpStatement::preAnalyze(Context *context){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;
	if (this->returnExpression != 0){
		this->returnExpression->preAnalyze(context);
	}
	this->setContext(context);
}
void JJumpStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	Context *context = this->getContext();

	if (strcmp(this->jumpName, "break") == 0){
		int kind = Utils::getLoop(context).second;
		if (kind == -1){
			errMsg = "break must be inside switch/loop block.";
			errLine = this->getLine();
			errCol = this->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
	}

	if (strcmp(this->jumpName, "continue") == 0){
		int kind = Utils::getJustLoop(context);
		if (kind == -1){
			errMsg = "continue must be inside loop block.";
			errLine = this->getLine();
			errCol = this->getCol();
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
	}

	if (this->returnExpression != 0){
		this->returnExpression->analyze();
		MethodContext * methodContext = context->getMethodContext();
		
		if (methodContext == 0){
			errMsg = "return statement outside method or constructor.";
			ErrorRecovery::reportSemanticError(this->getLine(), this->getCol(), Utils::toCharArray(errMsg));
		}
		else{
			int errLine, errCol;
			methodContext->definingMethod->hasReturnStatement = true;
			pair<char *, int> lhs = methodContext->definingMethod->returnType->getName();
			pair<char *, int> rhs = this->returnExpression->expressionType->getName();
			int status = ConversionTable::getCurrentInstance()->checkConversion(lhs.first, rhs.first, "=");
			if (status != 1 || lhs.second != rhs.second){
				string type1 = Utils::toString(lhs.first);
				string type2 = Utils::toString(rhs.first);
				while (lhs.second--)type1 += "[]";
				while (rhs.second--)type2 += "[]";
				errLine = this->getLine();
				errCol = this->getCol();
				errMsg = "Type mismatch: cannot convert " + type2
					+ " to " + type1;

				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}
	}
}

void JJumpStatement::codegen(){
	Context *surrounding = this->getContext();
	

	if (!strcmp(this->jumpName, "break")){
		// get loop or switch id
		pair<int, int> p = Utils::getLoop(surrounding);
		int id = p.first;
		//	if loop
		if (p.second == 1){
			Utils::out << "j endloop" << id << endl;
		}
		
		// if switch 
		if (p.second == 2){
			Utils::out << "j endswitch" << id << endl;
		}
	}
	else if (!strcmp(this->jumpName, "continue")){
		//	if loop
		int id = Utils::getJustLoop(surrounding);
		Utils::out << "j loopinc" << id << endl;
	}
	else if (!strcmp(this->jumpName, "return")){
		if (this->returnExpression != 0){
			this->returnExpression->codegen();
		}
		Utils::out << "j end" << this->getContext()->getMethodContext()->definingMethod->label << endl;
	}
	else if (!strcmp(this->jumpName, "throw")){

	}

}