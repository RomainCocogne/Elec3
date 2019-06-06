#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "forme.h"
#include "score.h"
#include <libsx.h>
#include <string.h>
#include "callbacks.h"


#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180
extern int GRILLEWIDTH;
extern int GRILLEHEIGHT;


typedef struct{
	int color[6];
	int grilleWidth, grilleHeight;
	int fact;
	Jeu *board;
} display;

extern display *screen;
extern Widget card1;
extern Widget card2;

extern Widget strEntry;

extern void initDisplay();
extern void hide (int width, int height);
extern void show(Widget w, int width, int height, void *d);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void genereGame();
extern void fenetreDeFin();
extern void menu();
extern void initAffichage(int grilleWidth, int grilleHeight);

