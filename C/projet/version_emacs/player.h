/*
  header du module de la gestion de joueurs
*/
#pragma once

/****************************/
//	inclusions 	    //
/****************************/
#include <string.h> 
#include "liste.h"

/****************************/
//	    macros 	    //
/****************************/
#define MAX_NAME 100

/****************************/
//      types	            //
/****************************/
/*
  structure de joueur contenant le nom et le score du joueur
*/
typedef struct{
  char *name;
  int score;
} Player;



/****************************/
//	   fonctions 	    //
/****************************/

/*
  Compare les noms et scores de 2 joueurs.
  @args:
  - Player premier joueur a comparer
  - Player second joueur a comparer
  @return:
  - int resultat de la comparaison. 0 si les noms sont differents et scores egaux,
  sinon, -1 si score du premier joueur et plus grand, 1 sinon
*/
extern int compare(Player, Player);

/*
  Initialise la structure Player
  @args:
  - Pointeur sur le Player a Initialiser
*/
extern void initPlayer(Player *);

/*
  Supprime un joueur
  @args:
  - Pointeur sur le Player a supprimer
*/
extern void rmPlayer(Player *);

/*
  Permet de donner un nom au joueur.
  Si un nom est deja donne, il sera ecrase
  @args:
  - Pointeur sur le Player dont on veut modifier le nom
  - Pointeur sur char (chaine de caracteres) representant le nom
*/
extern void setPlayerName(Player *, char *);

/*
  Permet de donner un score a un joueur.
  @args:
  - Pointeur sur le Player dont on veut modifier le score
  - int le score
*/
extern void setPlayerScore(Player *, int);

/*
  Copie le nom et le score d'un joueur dans un autre joueur
  @args:
  - Pointeur sur le joueur recepteur
  - Pointeur sur le joueur donneur
*/
extern void playercpy(Player *, Player *);
