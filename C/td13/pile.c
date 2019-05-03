/*
	module de la pile d'entiers suivant 
	le principe de la structure chainee

	pour une description des elements, se referer  au .h
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "pile.h"
#include "liste.h"

/****************************/
//		  variables			//
/****************************/
const Pile PileVide=NULL;

/****************************/
//		  fonctions			//
/****************************/
int estVide(Pile pile){
	return (pile==PileVide);
}

void empiler(Pile *pile, void *val){
	inserer(pile,1,val);
}
void depiler(Pile *pile){
	supprimer(pile,1);
}
void* sommet(Pile pile){
	return ieme(pile,1);
}

//decommenter ce code pour debuger la pile
// int main(int argc, char const *argv[])
// {
// 	Pile p=PileVide;
// 	empiler(&p,1);
// 	empiler(&p,3);
// 	depiler(&p);
// 	depiler(&p);
// 	if(estVide(p)) printf("vide\n");
// 	else printf("%d\n", sommet(p));

	
// 	return 0;
// }