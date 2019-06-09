/*
	module facilitant la gestion des couleurs
*/
#pragma once

/****************************/
//		 inclusions 		//
/****************************/
#include <assert.h>
#include <stdlib.h>

/****************************/
//			 types	 		//
/****************************/
/*
	Structure de tableau contenant le tableau et sa taille
	Elle est definit ici car elle n'est utile que dans ce cas particulier et 
	ne necessite pas un module a ele tout seul
*/
typedef struct
{
	size_t len;
	int *tab;
} Tab;

/****************************/
//		  Variables			//
/****************************/
extern Tab *couleurBg; 		//tableau contenant les couleurs utiles au decors du jeu
extern Tab *couleurCard;	//tableau contenant les couleurs utiles au cartes 

/****************************/
//		  fonctions			//
/****************************/
/*

*/
extern void initBgColor(int *c, size_t size);

/*

*/
extern void initCardColor(int *c, size_t size);

/*

*/
extern int getBgColor(int i);

/*

*/
extern int getLoopedCardColor(int i);
