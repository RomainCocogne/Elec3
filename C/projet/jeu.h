/*
	Module contenant tous les outils pour representer une partie de memory.
	Chaque partie est représentée par un type Jeu defini par le module
*/

#pragma once
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "carte.h"
#include "player.h"
#include "score.h"

/****************************/
// 		  Macros			//
/****************************/

/*
	Etape : etats possibles du jeu
		CARTE1 : le joueur doit retourner une premiere carte
		CARTE2 : le joueur doit retourner une deuxiéme carte
		VERIFICATION : le joueur à retourné deux cartes, le programme verifie les cartes retournées
		TERMINE : la partie est finie
*/
#define CARTE1	1
#define CARTE2	2
#define VERIFICATION 3
#define TERMINE 4

/****************************/
//			types 			//
/****************************/

/*
	Struture permettant de representer une partie de memory
		nbCartes : nombre de cartes dans la partie
		nbCartesRestantes : nombre de cartes non découvertes par le joueur
		nbCoups : nombre de coups joués 
		etape : représente l'etat actuel du jeu, parmi les valeurs définies plus haut
		carte1/carte2 : pointeurs vers les cartes selectionnées par le joueur
		TabCartes : pointeur vers un tableau contenant les cartes du jeu
*/
typedef struct
{
	int nbCartes,nbCartesRestantes,nbCoups;
	int etape;
	Card *carte1,*carte2;
	Card *TabCartes;
} Jeu;



/****************************/
// 		  fonctions			//
/****************************/

/*
	Melange les N éléments du tableau array de maniére aléatoire. 
	Utilisé pour melanger les cartes du tableau TabCartes
	Fonction trouvée sur stack overflow : https://stackoverflow.com/questions/6127503/shuffle-array-in-c
	@args:
		- Pointeur sur void representant le tableau d'elements a melanger
		- size_t le nombre d'elements dans le tableau
		- size_t la taille d'un element du tableau
*/
extern void shuffle(void *, size_t , size_t);

/*
	Initialise une tableau de type Card de taille nbCartes.
	Genere des paires de cartes ayant le même id. Il y a donc nbCartes/2 paires différentes.
	Melange l'ordre des cartes dans le tableau en appelant la fonction du module "shuffle" 
	@args:
		- Pointeur sur Card representant un tableau de cartes
		- Int le nombre de cartes dans le tableau
*/
extern void initTabCartes(Card *,int );

/*
	Initialise une strucutre Jeu déclarée au préalable. 
	Doit être appelée en premeier pour demarrer une partie. 
	@args:
		- Pointeur sur Jeu a initialiser
		- Int nombre de Card a ajouter au jeu
*/
extern void initJeu(Jeu *, int );

/*
	Fonction à apeller pour retourner une carte.
	Si le jeu est à l'étape CARTE1 ou CARTE2, enregistre l'addresse de la 
	carte retournée dans les variables carte1/carte2 de la structure jeu 
	passée en paramètre. Si l'étape est CARTE1, avance le jeu à l'étape CARTE2.
	Si le jeu est à l'étape VERIFICATION ou TERMINE, la fonction ne fait rien.
	Il faut appeler verifierCoup() avant de pouvoir jouer un autre coup
	@args:
		- Pointeur sur le jeu actuel
		- Pointeur sur la carte a jouer
*/
extern void jouerCoup(Jeu *, Card *);


/*
	Fonction à apeller pour verifier un coup.
	Compare les deux cartes retournées par l'utilisateur, qui sont enregistrées dnas
	les variables carte1 et carte2 de la structure jeu.
	Si la partie est terminée, fait avancer le jeu à l'étape TERMINE. 
	Sinon, fait revenir à l'étape CARTE1 pour jouer le prochain coup.
	@args:
		- Pointeur sur le jeu actuel
	@return:
		- Int donnant le resultat de la comparaison des deux cartes retournees (1 si identiques, 0 sinon)
*/
extern int verifierCoup(Jeu *);
