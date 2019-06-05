#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "display.h"
#include "score.h"



extern void saveScore(Widget w, void *d);
extern void ruler (Widget w,void *d);
extern void setSize(Widget w, void *d);
extern void printScores(Widget w, void *d);
extern void retournerCarte(Widget w, int which_button, int x, int y, void *data);
