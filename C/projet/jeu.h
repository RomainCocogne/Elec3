/*
	Module contenant tous les outils pour representer une partie de memory.
	Chaque partie est représentée par un type Jeu defini par le module
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "carte.h"

/****************************/
// 		  Macros			//
/****************************/

/*
	Etape : etats possibles du jeu
		OFF : 
		CARTE1 : le joueur doit retourner une premiere carte
		CARTE2 : le joueur doit retourner une deuxiéme carte
		VERIFICATION : le joueur à retourné deux cartes, le programme verifie les cartes retournées
		TERMINE : la partie est finie
*/
#define OFF 0
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
		TabCartes : 
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
*/
extern void shuffle(void *, size_t , size_t);


/*
	Initialise une tableau de type Card de taille nbCartes.
	Genere des paires de cartes ayant le même id. Il y a donc nbCartes/2 paires différentes.
	Mélange l'ordre des cartes dans le tableau en appelant la fonction du module "shuffle" 
*/
extern void initTabCartes(Card *TabCartes,int nbCartes);



/*
	Initialise une strucutre Jeu déclarée au préalable. 
	Doit être appelée en prmeier pour demarrer une partie. 
*/
extern void initJeu(Jeu *jeu, int nbCartes);


/*
	Fonction à apeller pour retourner une carte.
	Si le jeu est à l'étape CARTE1 ou CARTE2, enregistre l'addresse de la 
	carte retournée dans les variables carte1/carte2 de la structure jeu 
	passée en paramètre. Si l'étape est CARTE1, avance le jeu à l'étape CARTE2.
	Si le jeu est à l'étape VERIFICATION ou TERMINE, la fonction ne fait rien.
	Il faut appeler verifierCoup() avant de pouvoir jouer un autre coup
*/
extern void jouerCoup(Jeu *jeu, Card *carteRetournee);


/*
	Fonction à apeller pour verifier un coup.
	Compare les deux cartes retournées par l'utilisateur, qui sont enregistrées dnas
	les variables carte1 et carte2 de la structure jeu.
	Si la partie est terminée, fait avancer le jeu à l'étape TERMINE. 
	Sinon, fait revenir à l'étape CARTE1 pour jouer le prochain coup.

	Resultat : 
		1 si les deux cartes sont identiques
		0 sinon 
*/
extern int verifierCoup(Jeu *jeu);