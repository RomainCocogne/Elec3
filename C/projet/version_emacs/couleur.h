/*
  module facilitant la gestion des couleurs.
*/
#pragma once

/****************************/
//	 inclusions 	    //
/****************************/
#include <assert.h>
#include <stdlib.h>

/****************************/
//	   types	    //
/****************************/
/*
  Structure de tableau contenant le tableau et sa taille
  Elle est definit ici car elle n'est utile que dans ce cas particulier et 
  ne necessite pas un module a elle tout seul
*/
typedef struct
{
  size_t len;
  int *tab;
} Tab;

/****************************/
//	  Variables	    //
/****************************/
extern Tab *couleurBg; 		//tableau contenant les couleurs utiles au decors du jeu
extern Tab *couleurCard;	//tableau contenant les couleurs utiles au cartes 

/****************************/
//	 fonctions	    //
/****************************/
/*
  initialise la variable globale couleurBg
  @args:
  - Pointeur sur int tableau qui va remplir couleurBg
  - size_t la taille de ce tableau
*/
extern void initBgColor(int *, size_t);

/*
  initialise la variable globale couleurCard
  @args:
  - Pointeur sur int tableau qui va remplir couleurCard
  - size_t la taille de ce tableau
*/
extern void initCardColor(int *, size_t);

/*
  renvoie la couleur stockee dans couleurBg a l'indice donnee
  @args:
  - indice de la couleur
*/
extern int getBgColor(int);

/*
  renvoie la valeur stockee dans couleurCard a l'indice donnee.
  L'indice peut depasser la taille du tableau de couleur.
  Si c'est la cas, le nouvel indice est calcule avec la formule suivante:
  (i%size+i/size)%size avec i l'indice et size la taille du tableau
  Cette formule assure une permutation circulaire des couleurs
  @args:
  - int indice de la couleur
*/
extern int getLoopedCardColor(int);
