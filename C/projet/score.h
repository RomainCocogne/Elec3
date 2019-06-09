#pragma once
#include <errno.h>
#include <stdio.h>
#include "player.h"

/****************************/
//		  variables			//
/****************************/
#define FILE_NAME "./.score"
#define MAX_SCORE 10
/****************************/
//		  fonctions			//
/****************************/

extern void addScore(Player joueur);
extern void insertAndSort(Player *joueur, Liste *tabjoueurs);
extern void getScore(Liste *joueurs);
extern int getLastScore();
extern int nbScores();
extern int genereScore (int, int);