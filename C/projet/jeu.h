#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carte.h"
#include <string.h> 

#define OFF 0
#define CARTE1	1
#define CARTE2	2
#define VERIFICATION 3
#define TERMINE 4

typedef struct
{
	int nbCartes,nbCartesRestantes,nbCoups;
	int etape;
	Card *carte1,*carte2;
	Card *TabCartes;
} Jeu;




extern void shuffle(void *, size_t , size_t);

extern void initTabCartes(Card *TabCartes,int nbCartes);

extern void initJeu(Jeu *jeu, int nbCartes);

extern void jouerCoup(Jeu *jeu, Card *carteRetournee);

extern int verifierCoup(Jeu *jeu);