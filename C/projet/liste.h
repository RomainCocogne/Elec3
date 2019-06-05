/*
	header du module du type liste
	pour la pile
*/

#pragma once

/****************************/
//		 inclusions 		//
/****************************/
#include <stdlib.h>
#include <assert.h>


/****************************/
//			types 			//
/****************************/
typedef struct noeud					//structure suivant le principe de la structure chainee
{
	struct noeud *suivant;
	void *val;
} * Liste;

/****************************/
//		  variables			//
/****************************/
extern const Liste ListeVide;				//liste vide elementaire

/****************************/
// 		  fonctions			//
/****************************/
extern void initListe (Liste *);					//cree un nouvel element qui pointe vers une liste
extern void rmListe   (Liste *);					//supprimer une liste
extern int  longueur  (Liste );						//renvoie le nombre de formes dans la liste
extern void *ieme     (Liste , int );				//renvoie l element a la ieme position
extern void inserer   (Liste *, int , void *);		//insere element f au rang r
extern void supprimer (Liste *, int );				//supprime l element f an rang r


