/*
    lecture/ecriture simple de fichier
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/*
	Arguments   : char *f, n as int
	Consequents	:
*/
void creerFichEntiers (const char *fpath, int n){
	FILE *file;
	if((file=fopen(fpath,"w"))==NULL) {
		perror(fpath); exit(errno);
	}
	srand(time(0));
	int random;
	while(n--)
	{
		random=rand();
		fwrite(&random,sizeof(int),1,file);
	}
	fclose(file);
}

void afficherFichEntiers(const char *fpath){
	FILE *file;
	if((file=fopen(fpath,"r"))==NULL) {
		perror(fpath); exit(errno);
	}
	int i;
	while(fread(&i,sizeof(int),1,file)>0){
		printf("%d\n", i);
	}
	fclose(file);
}

void pairsImpairs(const char *fpath, const char *fpairs, const char *fimpairs){
	FILE *file;
	if((file=fopen(fpath,"r"))==NULL) {
		perror(fpath); exit(errno);
	}
	FILE *filep;
	if((filep=fopen(fpairs,"w"))==NULL) {
		perror(fpairs); exit(errno);
	}
	FILE *filei;
	if((filei=fopen(fimpairs,"w"))==NULL) {
		perror(fimpairs); exit(errno);
	}
	int i;
	while(fread(&i,sizeof(int),1,file)>0){
		if(i&1) fwrite(&i,sizeof(int),1,filei);
		else fwrite(&i,sizeof(int),1,filep);
	}
	fclose(file); fclose(filep); fclose(filei);
}

int main(int argc, char const *argv[]){
	const char *fpath ="fichier.txt";
	const char *fpairs ="pairs.txt";
	const char *fimpairs ="impairs.txt";
	creerFichEntiers(fpath,atoi(argv[1]));
	printf("total\n");
	afficherFichEntiers(fpath);
	pairsImpairs(fpath,fpairs,fimpairs);
	printf("\nimpaires\n");
	afficherFichEntiers(fimpairs);
	printf("\npaires\n");
	afficherFichEntiers(fpairs);
	return EXIT_SUCCESS;
}