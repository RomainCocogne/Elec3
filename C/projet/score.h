#pragma once
#include <errno.h>
#include <stdio.h>
#include <errno.h>
#include "player.h"
#include "jeu.h"

/****************************/
//		  variables			//
/****************************/
#define FILE_NAME "./score.txt"

/****************************/
//		  fonctions			//
/****************************/

extern void addScore(Player joueur);
extern void insertAndSort(Player *joueur, Liste *tabjoueurs);
extern void getScore(Liste *joueurs);
extern int getLastScore();
extern int nbScores();
extern int genereScore (Jeu);