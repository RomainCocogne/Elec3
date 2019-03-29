/*
    structure de formes. essais avec malloc
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

typedef enum { carre , rond , triangle } forme;

void afficherForme(forme f) {
	switch(f) {
		case carre    : printf("carre\n")   ; 		break; 
		case rond     : printf("rond\n")    ; 		break;
		case triangle : printf("triangle\n"); 		break;
		default       : printf("forme  inconnue\n");
	}
}


int main(int argc, char const *argv[]){
	forme *p, *q, *r;
	p=malloc(sizeof(forme)); *p=carre;
	q=malloc(sizeof(forme)); *q=rond ;
	r=malloc(sizeof(forme));

	afficherForme(*p); //affiche carre
	afficherForme(*q); //affiche rond

	r=p;
	afficherForme(*r); //affiche carre

	*p=triangle;	
	afficherForme(*r);	//affiche triangle
	free(p);
	afficherForme(*r); //affiche carre car free detruit l'espace memoire: r pointe sur 0, or carre est l'element 0 de l'enum
	return EXIT_SUCCESS;
}