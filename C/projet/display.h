#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "forme.h"
#include "score.h"
#include "couleur.h"
#include <libsx.h>
#include <string.h>
#include "callbacks.h"



#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180

typedef struct{
	int grilleWidth, grilleHeight;
	Jeu *board;
} display;

extern display *screen;
extern Widget card1;
extern Widget card2;

extern Widget strEntry;

extern void initGlobalDisplay();
extern void hide (int width, int height);
extern void show(Widget w, int width, int height, void *d);
extern void sidePanel();
extern void newWindow(char *c);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void genereGame();
extern void fenetreDeFin();
extern void menu();
extern void initAffichage(int grilleWidth, int grilleHeight);
extern void ruler (Widget w,void *d);
extern void printScores(Widget w, void *d);