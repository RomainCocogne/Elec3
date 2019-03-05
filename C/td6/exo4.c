/*
    affiche le nombre de lettres, nombres, espaces, 
    caracteres donnes par l'entree standard
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>



int main(void){
	int nb_l=0, nb_n=0, nb_s=0, nb_c=0;
	int c;
	while ((c=getchar ()) != EOF){
		if (isalpha(c)!=0) ++nb_l;
		else if (isdigit(c)!=0) ++nb_n;
		else if (isspace(c)!=0) ++nb_s;
		else ++nb_c;
	}
	printf("lettres: %d, nombres: %d, espaces: %d, caracteres: %d\n",nb_l,nb_n,nb_s,nb_c);
	return EXIT_SUCCESS;
}