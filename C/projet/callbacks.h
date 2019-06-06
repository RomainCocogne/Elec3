#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "display.h"
#include "score.h"


/****************************/
//		  variables			//
/****************************/

/*
	widget1, widget2 : buffers contenant les widgets des cartes cliquées par le joueur. 
					   Permet d'enregistrer les zones des deux cartes qui ont été cliquées.  
*/
extern Widget card1Widget;
extern Widget card2Widget;


/****************************/
// 		  fonctions			//
/****************************/

/*
  Callback pour quitter le programme
*/
extern void quit(Widget , void *d);

/*
  Callback pour relancer une partie
  Ferme les feêntres ouvertes, libére l'espace aloué aux cartes de lapattie précdente,
  et reinitialise les paramétres de la partie et de l'affichage.
*/
extern void replay(Widget , void *);

extern void saveScore(Widget , void *);
extern void setSize(Widget , void *);
extern void retournerCarte(Widget , int , int , int , void *);
