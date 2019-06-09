/*
	Module contenant les fonctions de callback non graphiques.
*/

#pragma once
#include <libsx.h>
#include "display.h"
#include "score.h"
#include "couleur.h"


/****************************/
// 		  fonctions			//
/****************************/

/*
  Callback pour quitter le programme
*/
extern void quit();


extern void saveScoreCallback(Widget , void *);

/*
	Fonction appellée par les boutons de changement de difficulté
	Assigne la difficulté selectionnée à la partie.
*/
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

extern void hideCard(int width, int height);
extern void showCard(Widget w, int width, int height, void *d);

/*
	Fonction de callback des zones de dessin qui représentent les cartes. 
	Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
	chaque fois que l'utilisateur change la taille de la fenêtre

  data : pointeur vers la structure carte associée au widget ayant appelé cette fonction
*/
extern void displayDrawArea(Widget w, int width, int height, void *data);
