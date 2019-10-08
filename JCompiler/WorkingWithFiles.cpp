#include"WorkingWithFiles.h"

FILE *WorkingWithFiles::fin = fopen("F:/in.txt", "r");
vector<char*> WorkingWithFiles::files;
vector<char*> WorkingWithFiles::dirs;

void WorkingWithFiles::changeDirAndGetFiles(char* path){
	char *command = new char[300];
	strcpy(command, "cd /d ");
	strcat(command, path);
	strcat(command, " && ");
	strcat(command, "dir /b /a-d > F:/in.txt");
	system(command);
	fillFilesList();
}

void WorkingWithFiles::fillFilesList(){
	files.clear();
	fin = fopen("F:/in.txt", "r");
	char *name = new char[300];
	while (fscanf(fin, "%s\n", name) != EOF){
		files.push_back(name);
		name = new char[300];
	}

	fclose(fin);
}

void WorkingWithFiles::changeDirAndGetDirs(char* path){
	char *command = new char[300];
	strcpy(command, "cd /d ");
	strcat(command, path);
	strcat(command, " && ");
	strcat(command, "dir /b /ad > F:/in.txt");
	system(command);

	fillDirsList();
}

void WorkingWithFiles::fillDirsList(){
	dirs.clear();
	fin = fopen("F:/in.txt", "r");
	char *name = new char[300];
	while (fscanf(fin, "%s\n", name) != EOF){
		dirs.push_back(name);
		name = new char[300];
	}

	fclose(fin);

}