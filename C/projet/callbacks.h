#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "affichage.h"
#include "player.h"

extern int GRILLEWIDTH;
extern int GRILLEHEIGHT;

extern void quiter (Widget w, void *d);

extern void ruler (Widget w,void *d);
extern void setSize(Widget w, void *d);
extern void printScores(Widget w, void *d);