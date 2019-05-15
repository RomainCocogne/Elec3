/*
    fonctions de base d'une liste
    utilise dans la fichier de pile
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "liste.h" //importe le module liste

/****************************/
//		  variables			//
/****************************/
const Liste ListeVide=NULL;

/****************************/
//		  fonctions			//
/****************************/


void initListe (Liste *l,void *f){
	*l=malloc(sizeof(struct noeud)); //allocation espace memoire
	(*l)->suivant=NULL;	//pointe vers 'la terre'
	(*l)->val=f;
}

int longueur (Liste l){
	int i=0;				//compteur 
	struct noeud *s= l;	    //noeud qui pointe vers la premiere forme
	while(s){				//tant qu'il y a des elements (a la fin ca vaudra NULL)
		i++;				//on incremente le compteur 
		s=s->suivant;		//on passe a l element suivant
	}
	return i;
}

void *ieme (Liste l, int r){
	assert(r>0 && r<=longueur(l));		//on verifie que r est valide
	struct noeud *s= l;			
	while(--r) s=s->suivant;			//on se positionne a la r'ieme position
	return (s->val);
}

void inserer (Liste *l, int r, void *f){
	assert(r>0 && r<=longueur(*l)+1);		//verfification (longueur+1 pour pouvoir ajouter un element a la fin)
	Liste newl;
	initListe(&newl,f);						//creation d'un nouveau element
	while(--r) l=&(**l).suivant;			//on pointe sur la r'ieme position avec le pointeur l
	newl->suivant=*l;						//on insere le nouveau element
	*l=newl;								
}

void supprimer (Liste *l, int r){
	assert(r>0 && r<=longueur(*l));	
	while(--r) l=&(**l).suivant;		
	struct noeud *suivant=(**l).suivant; //on sauvegarde la forme suivante pour ne pas la perdre
	free(*l);				//on supprime la forme
	*l=suivant;			   //on racorde les deux bouts
	//free((**lf).suivant);
}
