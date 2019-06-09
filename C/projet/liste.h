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

/*
	cree un nouvel element qui pointe vers une liste
	@args:
		- Pointeur sur la liste a initialiser
*/
extern void initListe (Liste *);	

/*
	supprimer une liste
	@args:
		- Pointeur sur la liste a supprimer
*/
extern void rmListe   (Liste *);					

/*
	renvoie le nombre d'elements dans la liste
	@args:
		- Liste dont on veut connaitre la longueur
	@return:
		- Int la taille de la liste
*/
extern int  longueur  (Liste );						

/*
	renvoie l'element a la ieme position
	@args:
		- Liste dont on veut chercher l'element
		- Int representant la position de l'element, 1 etant le premier de la liste
	@return:
		- element de la liste
*/
extern void *ieme     (Liste , int );				

/*
	insere element f au rang r
	@args:
		- Pointeur sur la liste que l'on veut modifier
		- Int representant le rang d'insertion. 1 etant le debut de la liste
		- Pointeur sur void sera l'element a ajouter a la liste
*/
extern void inserer   (Liste *, int , void *);		

/*
	supprime l element f an rang r
	@args:
		- Pointeur sur la liste que l'on veut modifier
		- Int representant le rang de suppression. 1 etant le debut de la liste
*/
extern void supprimer (Liste *, int );
