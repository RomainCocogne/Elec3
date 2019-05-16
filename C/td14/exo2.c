/*
    copie de fichiers
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

void copier(const char *fpath, const char *newfpath){
	FILE *file;
	if((file=fopen(fpath,"r"))==NULL) {
		perror(fpath); exit(errno);
	}
	FILE *newfile;
	if((newfile=fopen(newfpath,"w"))==NULL) {
		perror(newfpath); exit(errno);
	}

	void* i;
	i=malloc(sizeof(void*));
	int element;
	while((element=fread(i,sizeof(void*),BUFSIZ,file))>0){
		fwrite(i,sizeof(void*),element,newfile);
	}
}

int main(int argc, char const *argv[]){
	copier(argv[1],argv[2]);
	return EXIT_SUCCESS;
}