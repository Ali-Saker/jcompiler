#include"JExpression.h"
#include"JStatement.h"
#include"Context.h"
#include"JVariableDeclaration.h"
#include"JForeachStatement.h"
#include"ArrayType.h"
#include"ReferenceType.h"
#include"ClassContext.h"
#include"JVariableDeclarator.h"
#include"ConversionTable.h"
#include"typeName.h"
#include"ErrorRecovery.h"
#include"Utils.h"
#include"JBlock.h"
#include"JEmptyStatement.h"
JForeachStatement::JForeachStatement(int line, int col, JStatement *statement,
	JVariableDeclaration *variableDeclarator, JExpression *arrayExpr)
	:JIterationStatement(line, col, "JForeachStatement", statement){
	this->foreachVariableDeclaration = variableDeclarator;
	this->arrayExpr = arrayExpr;
}

void JForeachStatement::preAnalyze(Context *surrounding){
	if (this->preAnalyzed) return;
	this->preAnalyzed = true;

	int loop_num = Utils::LoopCount++;
	if (dynamic_cast<JBlock *>(this->statement)){
		JBlock *block = (JBlock *)this->statement;
		block->id = loop_num;
		block->kind = 1;
	}
	this->id = loop_num;

	if (this->foreachVariableDeclaration != 0){
		this->foreachVariableDeclaration->preAnalyze(surrounding);
	}

	if (this->arrayExpr != 0){
		this->arrayExpr->preAnalyze(surrounding);
	}
	this->statement->preAnalyze(surrounding);
	this->setContext(surrounding);
}

void JForeachStatement::analyze(){
	if (this->analyzed) return;
	this->analyzed = true;
	string errMsg;
	int errLine, errCol;
	Context *surrounding = this->getContext();
	if (this->foreachVariableDeclaration != 0){
		this->foreachVariableDeclaration->analyze();
	}

	if (this->arrayExpr != 0){
		this->arrayExpr->analyze();
	}
	Type *lhs = 0, *rhs = 0;
	if (this->arrayExpr != 0 && this->arrayExpr->expressionType != 0){
		if (!dynamic_cast<ArrayType *>(this->arrayExpr->expressionType)){
			errLine = this->arrayExpr->getLine();
			errCol = this->arrayExpr->getCol();
			errMsg = "foreach statement can only iterate over an array";
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
		else{
			ArrayType *type = (ArrayType *)this->arrayExpr->expressionType;
			if (dynamic_cast<ReferenceType *>(type->type)){
				bool resolved = ((ReferenceType *)this->arrayExpr->expressionType)->resolve(surrounding->getClassContext());
				if (!resolved){
					errLine = this->arrayExpr->getLine();
					errCol = this->arrayExpr->getCol();
					errMsg = Utils::toString(type->type->typeName->name) + " cann't be resolved to a type";
					ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				}
				else{
					rhs = (ReferenceType *)type->type;
				}
			}
			else{
				rhs = type->type;
			}
		}
	}

	if (this->foreachVariableDeclaration != 0){
		lhs = foreachVariableDeclaration->type;
	}
	if (lhs != 0 && rhs != 0){
		int status = ConversionTable::getCurrentInstance()->checkConversion(lhs->getName().first, rhs->getName().first, "=");
		if (status != 1){
			errLine = this->arrayExpr->getLine();
			errCol = this->arrayExpr->getCol();
			errMsg = "Type mismatch: cannot convert from element type "
				+ Utils::toString(rhs->typeName->name) + " to " + Utils::toString(lhs->typeName->name);
			ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
		}
	}

	this->statement->analyze();
}

void JForeachStatement::codegen(){
	int loop_num = this->id;

	this->foreachVariableDeclaration->codegen();
	this->arrayExpr->codegen();
	int offset = this->foreachVariableDeclaration->decls->at(0)->id * -4;
	Utils::out << "li $t5,-1" << endl;
	Utils::out << "lw $t1,4($sp)" << endl; //$t1 is array ref
	Utils::out << "addiu $sp,$sp,4" << endl;
	Utils::out << "lw $t2, 0($t1)" << endl; //$t2 is size
	Utils::out << "move $t6,$t1" << endl;
	

	Utils::out << "loop" << loop_num << ":" << endl;
	Utils::out << "addi $t5,$t5,1" << endl;
	Utils::out << "addi $t6,$t6,4" << endl;
	//Utils::out << "lw $t1,4($sp)" << endl; //$t1 is array ref
	//Utils::out << "lw $t2,0($t1)" << endl; //$t2 is array size
	Utils::out << "beq $t5,$t2," << "endloop" << loop_num << endl;
	Utils::out << "lw $t3,0($t6)" << endl;
	Utils::out << "sw $t3," << offset << "($fp)" << endl;

	/////save counters
	if (!dynamic_cast<JEmptyStatement *>(this->statement)){
		Utils::out << "addi $sp,$sp,-12" << endl;
		Utils::out << "sw $t5,4($sp)" << endl;
		Utils::out << "sw $t6,8($sp)" << endl;
		Utils::out << "sw $t2,12($sp)" << endl;
		this->statement->codegen();
		/////load counters
		Utils::out << "loopinc"<< loop_num << ":" <<  endl;
		Utils::out << "lw $t5,4($sp)" << endl;
		Utils::out << "lw $t6,8($sp)" << endl;
		Utils::out << "lw $t2,12($sp)" << endl;
		Utils::out << "addi $sp,$sp,12" << endl;
	}
	Utils::out << " j loop" << loop_num << endl;
	Utils::out << "endloop" << loop_num << ":" << endl;

}