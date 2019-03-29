/*
    structure de formes. jouer avec les pointeurs
    simuler des tableaux dynamiques
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

typedef enum { carre , rond , triangle } forme;

typedef struct noeud {
	forme f;
	struct noeud *suivant;
} * ListeDeFormes;

void afficherForme(forme f) {
	switch(f) {
		case carre    : printf("carre\n")   ; 		break; 
		case rond     : printf("rond\n")    ; 		break;
		case triangle : printf("triangle\n"); 		break;
		default       : printf("forme  inconnue\n");
	}
}

void *	initForme (forme f){
	ListeDeFormes lf=malloc(sizeof(struct noeud));
	lf->f=f;
	lf->suivant=NULL;
	return lf;
}

void afficherListedeForme (ListeDeFormes lf){
	struct noeud *s= lf;
	while(s!=NULL){
		afficherForme(s->f);
		s=s->suivant;
	}
}

int main(int argc, char const *argv[]){
	ListeDeFormes lf;
	lf=malloc(sizeof(struct noeud));
	lf->f=rond;
	lf->suivant=initForme(triangle);
	lf->suivant->suivant=initForme(carre);

	//afficherListedeForme(lf);

//ajouter un carre en premiere position
	ListeDeFormes newlf = initForme(carre);
	newlf->suivant=lf;
	lf=newlf;
	//afficherListedeForme(lf);

//supprimer le triangle
	lf->suivant->suivant=lf->suivant->suivant->suivant;
	free(lf->suivant->suivant->suivant);
	afficherListedeForme(lf);
	return EXIT_SUCCESS;
}