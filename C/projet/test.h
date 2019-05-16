#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include "carte.h"

#define CARD_WIDTH 50
#define CARD_HEIGHT 100

//Pour la couleur des cartes
int gris;
int blanc; 
void retournerCarte(Widget w, int which_button, int x, int y, void *data);
void initJeuCartes(Card *TabCartes,int nbCartes);
void initDrawArea(Widget w, int width, int height, void *data);
void initAffichage(Card *tabCartes, int grilleWidth, int grilleHeight);
