/*
	Module de la gestion des scores
	Chaque fonction qui doit acceder au fichier ouvre puis ferme ce dernier.
	Cela assure que l'utilisation du fichier est transparente pour le reste du programme.
*/

#pragma once

/****************************/
//		 inclusions 		//
/****************************/
#include <errno.h>
#include <stdio.h>
#include "player.h"

/****************************/
//		  macros			//
/****************************/
#define FILE_NAME "./.score" //nom du fichier score
#define MAX_SCORE 10		 //nombre de scores total dans le fichier


/****************************/
//		  fonctions			//
/****************************/
/*
	Cree le fichier score si il n'existe pas deja.
	Permet de faire fonctionner le jeu si le fichier est supprime par erreur
*/
extern void createFile();

/*
	ajoute un score (nom+score) dans le fichier.
	le score est insere de facon a ce que le fichier soit trie dans l'ordre decroissant des scores
	Cette procedure cree un fichier temporaire qui va etre renomme pour ecraser le fichier score
	@args:
		- Pointeur sur char le nom du joueur
		- int son score
*/
extern void saveScore(char*, int);

/*
	Ajoute un joueur dans la liste de tout les joueurs contenus dans le fichier,
	puis trie les joueurs dans l'ordre decroissant des scores
	@args:
		- Pointeur sur Player le joueur a ajouter a la liste
		- Pointeur sur Liste la liste contenant tout les joueurs du fichier score
*/
extern void insertAndSort(Player *, Liste *);

/*
	Recupere la liste de tout les joueurs dans le fichier score
	@args:
		- Pointeur sur Liste qui va contenir tout les joueurs
*/
extern void getScore(Liste *);

/*
	Donne le dernier score enregistre dans le fichier.
	Si le fichier est vide, NULL est retourne
	@return:
		- int le dernier score du fichier
*/
extern int getLastScore();

/*
	Donne le nombre de scores dans le fichier
	@return:
		- int le nombre de scores dans le fichier (0 si aucun score)
*/
extern int nbScores();

/*
	Genere le score du joueur selon cette formule:
		(1/10+1/nbCoups)*nbCartes*100
		avec nbCoups le nombre de coups joues dans la partie et nbCartes le nombre de cartes dans la partie
*/
extern int genereScore (int, int);