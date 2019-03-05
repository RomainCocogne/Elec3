/*
    afficher les lignes ecrites sur stdin 
    avec les numeros de ligne
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
	Arguments   : lit un fichier sur entree standard
	Consequents	: ecrit ligne par ligne avec le numero sur sortie standard
*/
void traiteFichier (){
	int c,c_prec='\n';
	int ligne=1;
	//printf("%d ",ligne);
	while ((c=getchar ()) != EOF){
		if (c_prec=='\n'){
			printf("%d ",ligne++);
		}
		putchar(c);
		c_prec=c;
	}
}

int main(void){
	
	traiteFichier();

	return EXIT_SUCCESS;
}