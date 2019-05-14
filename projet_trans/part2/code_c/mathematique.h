/*
	ensemble de fonctions et macro
	realisant des operations mathematiques
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

/****************************/
//		  variables			//
/****************************/
#define ARRAY_LEN(x) ((int) (sizeof(x)/sizeof(x[0])))
#define MAX(x,y) ((x)>(y) ? (x) : (y))
#define MIN(x,y) ((x)<(y) ? (x) : (y))

/****************************/
//		  fonctions			//
/****************************/
/*
	retourne les valeurs de n en db
*/
void db(double *n, unsigned int size);

/*
	transforme un tableau de reels en tableau de complex
*/
void toComplex (double complex *resultat, double *data, unsigned int size);

/*
	transforme un tableau de complex en tableau de reels
*/
void toReal (double *resultat, double complex *data, unsigned int size);

/*
	effectue une forme de decimation en faisant la moyenne sur un 
	interval
*/	
void moyenne(double *data, double *result, int sizeinit, int sizefin);
