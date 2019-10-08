#include<vector>
#include<fstream>
#include<iostream>
#include<stdio.h>
#include"JPackage.h"
using namespace std;

class WorkingWithFiles{
public:

	static FILE *fin;

	static vector<char*> files;

	static vector<char*> dirs;

	static void changeDirAndGetFiles(char* path);

	static void fillFilesList();

	static void changeDirAndGetDirs(char* path);

	static void fillDirsList();

};

//int main(){
//	//WorkingWithFiles::initJavaWorkSpacePath("D:/JavaWorkSpace");
//	//system("dir");
//	//WorkingWithFiles::chooseThisProject("FirstJavaProject");
//	//WorkingWithFiles::getFiles();
//	//system("cd /d D:\JavaWorkSpace\\\"FirstJavaProject\" && dir");
//	WorkingWithFiles::changeDirAndGetFiles("D:/JavaWorkSpace/\"FirstJavaProject\"");
//
//}