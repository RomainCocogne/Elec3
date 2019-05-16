#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include "carte.h"

#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 200

//Pour la couleur des cartes
int gris;
int blanc; 
int card_width;
int card_height; 

void retournerCarte(Widget w, int which_button, int x, int y, void *data);
void initJeuCartes(Card *TabCartes,int nbCartes);
void initDrawArea(Widget w, int width, int height, void *data);
void initAffichage(Card *tabCartes, int grilleWidth, int grilleHeight);
