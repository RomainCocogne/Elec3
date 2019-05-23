#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "image.h"
#include "forme.h"
#include "player.h"
#include <libsx.h>
#include <string.h>

#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180



extern char *forme[];

//Pour la couleur des cartes
extern int gris;
extern int blanc;
extern int bleu;
extern int rouge;
extern int vert;
extern int orange;

void quit(Widget w, void *d);
extern void saveScore(Widget w, void *d);
void displayDrawArea(Widget w, int width, int height, void *data);
extern void initAffichage(Jeu *jeu, int grilleWidth, int grilleHeight);
void fenetreDeFin();
extern void retournerCarte(Widget w, int which_button, int x, int y, void *data);