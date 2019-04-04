/*
	module de la pile d'entiers suivant 
	le principe de la structure chainee

	pour une description des elements, se referer  au .h
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/****************************/
//			types 			//
/****************************/
typedef struct noeud
{
	struct noeud *suivant;
	int val;
} * Pile;

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

void empiler(Pile *pile, int val){
	struct noeud *op =malloc(sizeof(struct noeud));
	op->suivant=*pile;
	op->val=val;
	*pile=op;
}
void depiler(Pile *pile){
	assert(estVide(*pile)==0);
	struct noeud *temp= (**pile).suivant;
	free(*pile);
	*pile=temp;
}
int sommet(Pile pile){
	assert(estVide(pile)==0);
	return pile->val;
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