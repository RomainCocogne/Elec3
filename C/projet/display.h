#pragma once
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "image.h"
#include "forme.h"
#include "player.h"
#include <libsx.h>
#include <string.h>
#include "menu.h"

extern void quit(Widget w, void *d);
extern void replay(Widget w, void *d);
extern void hide (int width, int height);
extern void show(Widget w, int width, int height, void *d);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void genereGame();
extern void fenetreDeFin();
