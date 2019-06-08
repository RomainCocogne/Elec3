#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include <assert.h>
#include "display.h"
#include "score.h"
#include "couleur.h"


/****************************/
// 		  fonctions			//
/****************************/

/*
  Callback pour quitter le programme
*/
extern void quit(Widget , void *d);
extern void saveScore(Widget , void *);
extern void setSize(Widget , void *);

/*
	Fonction appelée lorsque l'utilisateur clique sur une carte.
	Appelle les fonctions du module jeu pour jouer les coups. Affiche graphiquement 
	le resultat de chaque coup.
	Quand deux cartes sont révélées, le coup est verifié est l'infobox est mise à jour.
	Si la paire est juste, les cartes restent face visible. Sinon, elles seront retournées face cachée au prochain coup
	sinon la paire est remise face cachée. 
	Si la derniére paire à été retournée, l'ecran de fin s'affiche au prochain clic.

	*data : pointeur sur type Carte, contient la carte associée au Widget qui à été cliqué.
*/
extern void retournerCarte(Widget , int , int , int , void *);
