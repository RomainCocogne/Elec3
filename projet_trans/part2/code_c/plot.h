/*
	module d'affichage graphique
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/****************************/
//		  variables			//
/****************************/
#define SIZE 1024/8

/****************************/
//		  fonctions			//
/****************************/

/*
	affiche sous formes de barrettes data sur stdout
*/
void plot(double *data, int width, int scale);