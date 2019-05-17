#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <libsx.h>
#include <string.h>

#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180

extern Jeu *board;


extern char *forme[];

//Pour la couleur des cartes
extern int gris;
extern int blanc;

extern void initAffichage(Jeu *jeu, int grilleWidth, int grilleHeight);

extern void initDrawArea(Widget w, int width, int height, void *data);
extern void retournerCarte(Widget w, int which_button, int x, int y, void *data);
