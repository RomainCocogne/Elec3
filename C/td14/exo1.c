/*
    lecture/ecriture simple de fichier
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*
	Arguments   : char *f, n as int
	Consequents	:
*/
void creerFichEntiers (const char *fpath, int n){
	FILE *file;
	file=fopen(fpath,"w");
	while (n--) fprintf(file, "%d\n", rand());
}

int main(int argc, char const *argv[]){
	const char *fpath ="fichier.txt";
	creerFichEntiers(fpath,atoi(argv[1]));

	return EXIT_SUCCESS;
}