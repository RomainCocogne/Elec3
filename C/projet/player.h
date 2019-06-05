/*
	header du module de la gestion de joueurs
*/
#pragma once
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>  
#include "liste.h"

/****************************/
//			types 			//
/****************************/

typedef struct{
	char *name;
	int score;
} Player;

/****************************/
//		  variables			//
/****************************/
#define MAX_NAME 100
#define FILE_NAME "./score.txt"

/****************************/
//		  fonctions			//
/****************************/

extern int compare(Player j1, Player j2);
extern void initPlayer(Player *j);
extern void rmPlayer(Player *j);
extern void setPlayerName(Player *j, char *name);
extern void setPlayerScore(Player *j, int score);
extern void playercpy(Player *j1, Player *j2);
extern void addScore(Player joueur);
extern void insertAndSort(Player *joueur, Liste *tabjoueurs);
extern void getScore(Liste *joueurs);
extern int getLastScore();
extern int nbScores();