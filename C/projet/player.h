/*
	header du module de la gestion de joueurs
*/
#pragma once
#include <string.h>
#include <limits.h>
#include <stdlib.h>  
#include "liste.h"

typedef struct{
	char *name;
	int score;
} Player;


#define MAX_NAME 100

extern int compare(Player j1, Player j2);
extern void initPlayer(Player *j);
extern void rmPlayer(Player *j);
extern void setPlayerName(Player *j, char *name);
extern void setPlayerScore(Player *j, int score);
extern void playercpy(Player *j1, Player *j2);