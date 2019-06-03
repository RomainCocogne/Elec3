#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "image.h"
#include "forme.h"
#include "player.h"
#include <libsx.h>
#include <string.h>
#include "menu.h"

#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180
#define NB_FORMES 4

typedef struct{
	int color[6];
	int grilleWidth, grilleHeight;
	int fact;
	int state;
	Jeu *board;
} display;

extern display *screen;


extern void quit(Widget w, void *d);
extern void saveScore(Widget w, void *d);
extern void replay(Widget w, void *d);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void initAffichage(Jeu *jeu, int grilleWidth, int grilleHeight);
extern void genereGame();
extern void fenetreDeFin();
extern void retournerCarte(Widget w, int which_button, int x, int y, void *data);