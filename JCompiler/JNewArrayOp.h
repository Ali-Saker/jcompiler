#pragma once
#include "JExpression.h"
#include<vector>
#include"Type.h"
#include"ErrorRecovery.h"
#include"Utils.h"
#include"Context.h"
class JNewArrayOp :
	public JExpression
{
public:
	Type* typeSpec;
	vector<JExpression*>* dims;
	int emptyDims;

	JNewArrayOp(int line, int col, Type* typeSpec, vector<JExpression*> * dims, int emptyDims)
			: JExpression(line, col, "JNewArrayOp", 0)
	{
		this->typeSpec = typeSpec;
		this->dims = dims;
		this->emptyDims = emptyDims;
	}

	virtual void preAnalyze(Context *surrounding){
		if (this->preAnalyzed) return;
		this->preAnalyzed = true;
		for (int i = 0; this->dims != 0 && i < this->dims->size(); i++){
			this->dims->at(i)->preAnalyze(surrounding);
		}
		this->setContext(surrounding);
	}

	virtual void analyze(){
		if (this->analyzed) return;
		this->analyzed = true;
		string errMsg;
		int errLine, errCol;
		Context *surrounding = this->getContext();
		for (int i = 0; this->dims != 0 && i < this->dims->size(); i++){
			this->dims->at(i)->analyze();
			if (this->dims->at(i)->expressionType == 0 || !dynamic_cast<PrimitiveType *>(this->dims->at(i)->expressionType)
				|| strcmp(((PrimitiveType *)this->dims->at(i)->expressionType)->getName().first, "int") != 0){
				errLine = this->dims->at(i)->getLine();
				errCol = this->dims->at(i)->getCol();
				errMsg = "dims expressions must have an integer type";
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
			}
		}

		if (dynamic_cast<ReferenceType *>(typeSpec)){
			((ReferenceType *)typeSpec)->resolve((Context *)surrounding->getClassContext());
			if (((ReferenceType *)typeSpec)->referenceTypeDecl == 0){
				errMsg = "'" + Utils::toString(this->typeSpec->typeName->name) + "' cann't be resolved to a type.";
				errLine = this->typeSpec->typeName->getLine();
				errCol = this->typeSpec->typeName->getCol();
				ErrorRecovery::reportSemanticError(errLine, errCol, Utils::toCharArray(errMsg));
				this->expressionType = 0;
			}
			else{
				this->expressionType = new ArrayType(this->typeSpec, this->emptyDims + (this->dims == 0? 0 : this->dims->size()));
			}
		}
		else{
			this->expressionType = new ArrayType(this->typeSpec, this->emptyDims + (this->dims == 0 ? 0 : this->dims->size()));
		}
	}

	virtual void  codegen(){
		int amount = this->dims->size() * 4;
		for (int i = 0; i < this->dims->size(); i++){
			this->dims->at(i)->codegen();
		}
		
		//Utils::out << "addi $sp,$sp,-" << amount << endl;
		Utils::out << "lw $t3," << amount << "($sp)" << endl;
		Utils::out << "move $a0,$t3" << endl;
		Utils::out << "addiu $a0,$a0,1" << endl;
		Utils::out << "sll $a0,$a0,2" << endl;
		Utils::out << "li $v0 ,9" << endl;
		Utils::out << "syscall" << endl;
		Utils::out << "move $s1 ,$v0" << endl;
		Utils::out << "sw $t3,0($s1)" << endl;
		Utils::out << "move $s2 ,$sp" << endl;
		Utils::out << "sw $s1 ,0($sp)" << endl;
		Utils::out << "addi $sp ,$sp, -4" << endl;
		this->alloc(1);
		Utils::out << "addi $sp,$sp," << amount -4<< endl;
		Utils::out << "sw $s1,4($sp)" << endl;
		Utils::out << "move $v0,$s1" << endl;
	}
	void alloc(int index){
		int amount = this->dims->size() * 4;
		if (index < this->dims->size()){
			int loop_num = Utils::LoopCount; Utils::LoopCount++;
			Utils::out << "lw $t1 ,4($sp)" << endl; //array ref  // counter
			Utils::out << "addiu $sp ,$sp, 4" << endl;

			Utils::out << "lw $t2 ," << amount - (index * 4) << "($s2)" << endl; // sizes
			Utils::out << "li $t5 ,-1" << endl;
			Utils::out << "loop" << loop_num << ":" << endl;
			//change counter
			Utils::out << "addi $t1,$t1,4" << endl;
			Utils::out << "addi $t5,$t5,1" << endl;
			Utils::out << "beq  $t5,$t2,end" << loop_num << endl;
			//alloc
			Utils::out << "move $a0,$t2" << endl; // size
			Utils::out << "sll $a0, $a0, 2" << endl;
			Utils::out << "addi $a0,$a0,4" << endl;
			Utils::out << "li $v0 ,9" << endl;
			Utils::out << "syscall" << endl;
			Utils::out << "move $t3,$v0" << endl;
			Utils::out << "sw $t2 ,0($t3)" << endl; // size
			Utils::out << "sw $t3 ,0($t1)" << endl;
			///sp + 8 = $t1
			//sp + 4 = ref
			Utils::out << "addi $sp,$sp,-12" << endl;
			Utils::out << "sw $t3,4($sp)" << endl; // size
			Utils::out << "sw $t1,8($sp)" << endl;
			Utils::out << "sw $t5,12($sp)" << endl;


			this->alloc(index + 1);
			//sp + 4
			//$t1 = sp + 4
			Utils::out << "sw $t5,12($sp)" << endl;
			Utils::out << "sw $t1,8($sp)" << endl;
			Utils::out << "addi $sp,$sp,12" << endl;
			Utils::out << "lw $t2 ," << amount - (index * 4) << "($s2)" << endl;
			Utils::out << "j loop" << loop_num << endl;
			Utils::out << "end" << loop_num << ":" << endl;
		}
		
	}
};
