#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include <assert.h>
#include "display.h"
#include "score.h"
#include "couleur.h"

#define YES 1
#define NO 0
/****************************/
//		  variables			//
/****************************/

/*
	widget1, widget2 : buffers contenant les widgets des cartes cliquées par le joueur. 
					   Permet d'enregistrer les zones des deux cartes qui ont été cliquées.  
*/
extern Widget card1Widget;
extern Widget card2Widget;
extern int hide_next_move;

/****************************/
// 		  fonctions			//
/****************************/

/*
  Callback pour quitter le programme
*/
extern void quit(Widget , void *d);
extern void saveScore(Widget , void *);
extern void setSize(Widget , void *);
extern void retournerCarte(Widget , int , int , int , void *);
