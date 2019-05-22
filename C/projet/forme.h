/*
	ressence toute les formes
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "affichage.h"

enum FORME {CARRE, ROND, TRIANGLE,ETOILE};

typedef struct 
{
	int w,h;
	int size;
	enum FORME f;
	XPoint *ptarray;
}Forme;

void arrayXPointcpy(XPoint *f1, XPoint *f2,int size);
void genereforme(Forme *forme, int f, int w, int h);
void createXPointArray(Forme *forme);