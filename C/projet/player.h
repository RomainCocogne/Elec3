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

int compare(Player j1, Player j2);
void initPlayer(Player *j);
void rmPlayer(Player *j);
void setPlayerName(Player *j, char *name);
void setPlayerScore(Player *j, int score);
void playercpy(Player *j1, Player *j2);
void addScore(Player joueur);
void insertAndSort(Player *joueur, Liste *tabjoueurs);
void getScore(Liste *joueurs);
int getLastScore();
int nbScores();