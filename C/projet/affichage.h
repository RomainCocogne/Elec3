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
#include "display.h"

#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180
#define NB_FORMES 4



typedef struct{
	int color[6];
	int grilleWidth, grilleHeight;
	int fact;
	Jeu *board;
} display;

extern display *screen;


extern void saveScore(Widget w, void *d);
extern void initAffichage(Jeu *jeu, int grilleWidth, int grilleHeight);
extern void retournerCarte(Widget w, int which_button, int x, int y, void *data);