/*
	Module contenant tous les outils permettant de representer 
	une carte de memory.
*/


#pragma once 


/****************************/
// 		  Macros			//
/****************************/

/*
	Modes : Etats possibles d'une carte.
		-CACHEE : La carte est face cachée et peut être retournée
		-RETOURNEE : La carte est retournée est attend l'etape de verification
		-DECOUVERTE : La carte et sa paire ont été decouvertes par le joueur, 
					  on ne peut plus interagir avec la carte
*/
#define CACHEE		0
#define RETOURNEE	1
#define DECOUVERTE	2


/****************************/
// 		   types			//
/****************************/

/*
	Structure permettant de representer une carte. 
	Membres : 
		- id : numero d'identification de la carte. Chaque paire de 
			   carte est representée par un id
		- mode : etat de la carte dans le jeu, parmi les etats definis plus haut 
*/
typedef struct
{
	int id;
	int mode;

} Card;