//#ifndef _ASTgrphics_H
//#define _ASTgrphics_H
//#include"ASTfiles.h"
//#include<iostream>
//using namespace std;
//
//void VisualizeSymbolTable(JCompilationUnit* compilationUnit){
//
//}
//
//void VisualizeAST(JCompilationUnit* compilationUnit){
//	vector<JTypeDecl*>* typeDeclarations = compilationUnit->typeDeclarations;
//
//	for(int i=0; i<typeDeclarations->size(); i++){
//		JTypeDecl * jast = (*typeDeclarations)[i];
//
//		cout<<"Package name: "<<(compilationUnit->getPackageName()==0?"":compilationUnit->getPackageName())<<endl;
//		vector<TypeName*>* imports = compilationUnit->imports;
//
//		for(int i=0; imports!=0&&i<imports->size(); i++){
//			cout<< "Import: #"<< i+1 << " " <<(*imports)[i]->toString()<<endl;
//		}
//
//		
//		if (JClassDeclaration* classDeclaration = dynamic_cast<JClassDeclaration*>(jast)){
//			cout << "class Name: " << classDeclaration->getName() << endl;
//			if (classDeclaration->mods != 0){
//				vector<char*>* it = classDeclaration->mods;
//				int sz = it->size();
//				for (int i = 0; i<sz; i++)
//					cout << "MOD : " << (*it)[i] << endl;
//			}
//
//			if (classDeclaration->interfaces != 0){
//				vector<TypeName*>* it = classDeclaration->interfaces;
//				int sz = it->size();
//				for (int i = 0; i<sz; i++)
//					cout << "Interfaces : " << (*it)[i]->name << endl;
//			}
//
//			if(classDeclaration->classBlock != 0){
//				vector<JMember*>* classBlock = classDeclaration->classBlock;
//				for(int i=0; i<classBlock->size(); i++){
//					JMember* member = (*classBlock)[i];
//
//					if(JFieldDeclaration* field = dynamic_cast<JFieldDeclaration*>(member)){
//						vector<JVariableDeclarator*>* decls = field->decls;
//						for(int j=0; j<decls->size(); j++)
//							
//							cout<<"var name: "<<(*decls)[j]->getName()<<endl;
//					}
//
//					if (JConstructorDeclaration* field = dynamic_cast<JConstructorDeclaration*>(member)){
//						cout << "JConstructor Name: " << field->name << endl;
//						vector<JStatement*>* stmts = field->body->statements;
//						for (int j = 0; j < stmts->size(); j++){
//							if (JIfStatement* ifStmt = dynamic_cast<JIfStatement*>( (*stmts)[j] ) ){
//								cout << "expr name: " << ifStmt->condition->expressionName<< endl;
//								if (ifStmt->condition->expressionName == "BinaryExpression"){
//									JBinaryExpression* binExpr = (JBinaryExpression*) ifStmt->condition;
//									cout << "lhs: " << binExpr->lhs->expressionName 
//										<< "  rhs:" << binExpr->rhs->expressionName << endl;
//								}
//							}
//						}
//					}
//				}
//			}
//
//		}
//		else{
//			JInterfaceDeclaration* InterfaceDeclaration = dynamic_cast<JInterfaceDeclaration*>(jast);
//			cout << "interface Name: " << InterfaceDeclaration->getName() << endl;
//		}
//
//		
//
//		
//	}
//
//}
//
//
//#endif