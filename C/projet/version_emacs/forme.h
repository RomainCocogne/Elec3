/*
	ressence toute les formes pour dessiner sur les cartes
	une forme utilise les points definits dans 
	la librairie libsx
*/

#pragma once

/****************************/
//	   inclusions  	    //
/****************************/
#include <stdlib.h>
#include <libsx.h>

/****************************/
//       macros 	    //
/****************************/
#define NB_FORMES 4

/****************************/
//	    enums	    //
/****************************/
/*
	enumeration des formes possibles que 
	l'on peut dessiner
*/
enum FORME {CARRE, ROND, TRIANGLE, ETOILE};

/****************************/
//	    types 	    //
/****************************/
/*
	structure Forme qui contient:
		- la hauteur et la largeur de la forme
		- le nombre de points pour dessiner la forme
		- le nom de la forme
		- une chaine de points correspondant a la forme
*/
typedef struct 
{
	int w,h;
	int size;
	enum FORME f;
	XPoint *ptarray;
}Forme;

/****************************/
//	  fonctions 	    //
/****************************/
/*
	copie un ensemble de points dont le nombre est specifie
	dans une autre chaine de points
	la chaine receptrice doit etre plus grande
	et elle doit etre vide
	@args: 
		- Pointeur sur XPoint correspond au tableau de points recepteur
		- Pointeur sur XPoint correspond au tableau a copier
		- int correspond au nombre de points dans le tableau a copier
*/
extern void arrayXPointcpy(XPoint *, XPoint *, int);

/*
	cree une chaine de points dessinant la forme choisie
	et la stock dans la Forme
	l'objet Forme doit avoir f,h et w initialises
	@args: 
		- Pointeur sur Forme dans laquelle on va initialiser le tableau de points et la taille
*/
extern void createXPointArray(Forme *);

/*
	initialise un objet de type Forme
	en lui assignant un tableau de points 
	correspondant au nom de la forme fournie
	la hauteur et la largeur doivent etre renseignes
	@args: 
		- Pointeur sur Forme que l'on va initialiser avec les parametres suivants
		- int correspondant au nom de la forme comme decrit dans enum FORME
		- int correspondant a la longueur de la forme
		- int correspondant a la hauteur de la forme
*/
extern void genereforme(Forme *, int, int, int);
