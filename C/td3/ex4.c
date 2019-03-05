/*
    demande à l’utilisateur de saisir un entier relatif
    et qui indique, d’une part, si ce nombre est négatif, nul ou positif et d’autre part, si ce
	nombre est pair ou impair.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
	int a;
	printf("un entier relatif: ");
	scanf("%d",&a);
	if(a==0){
		printf("a est nul\n");
	}
	else{
		if(a<0){
	    	printf("a est negatif\n");
		}
		else{
	    	printf("a est positif\n");
		}

		if(a&2==0){
	    	printf("a est pair\n");
		}
		else{
			printf("a est impair\n");
		}
	}

	return EXIT_SUCCESS;
}