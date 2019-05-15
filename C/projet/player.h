/*
	header du module de la gestion de joueurs
*/
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>  
#include "liste.h"
#pragma once

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

void initPlayer(Player *j);
void addScore(Player joueur);
void insertAndSort(Player *joueur, Liste *tabjoueurs);