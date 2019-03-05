/*
     un entier sur l’entrée standard représentant le numéro
     d’un mois et qui affiche le mois en toutes lettres
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
	int n;
	char mois[12][10]= {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
	
	printf("numero de mois: ");
	scanf("%d",&n);
	if(n<13 && n>0){
		printf("%s\n",mois[n-1]);
	}
	else{
		printf("entree non valide\n");
	}
	return EXIT_SUCCESS;
}