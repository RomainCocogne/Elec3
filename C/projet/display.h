#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include "jeu.h"
#include "forme.h"
#include "score.h"
#include "couleur.h"
#include "callbacks.h"
#include "player.h"

/****************************/
// 		  Macros			//
/****************************/

/*
	Dimensions graphiques des cartes par defaut. 
	Il s'agit de la taille des crtaes lors de l'affichage du debut d'une partie.
	L'utilisateur peut ensuite redimensionner la fenêtre et changer la tailel des cartes.
 */
#define DEFAULT_CARD_WIDTH 90
#define DEFAULT_CARD_HEIGHT 170


/*
	Taille de la grille de cartes par default.
	Il s'agit de la taille de grille appliquée si l'utilisateur n'a pas précisé la difficulté.
*/
#define DEFUALT_GRILLEWIDTH 3
#define DEFUALT_GRILLEHEIGHT 2

/*
	Valeurs possibles de hide_next_move
*/
#define YES 1
#define NO 0

/****************************/
// 		   Types			//
/****************************/

/*
	Structure contenant toutes les données necessaires à l'affichage de la partie.
		-grilleWidth, grilleHeight : Taille de la grille de jeu. grilleWidth x grilleHeight doit être égal au nombre de cartes dans le jeu. 
		-game : pointeur vers une structure jeu contenant toutes les infos de jeu. Ce pointeur permet à l'affichage de recupérer les données 
				de la partie pour pouvoir les afficher.
		-widget1, widget2 : buffers contenant les widgets des cartes cliquées par le joueur. 
					   		Permet d'enregistrer les zones des deux cartes qui ont été cliquées
		-infoBoxLabel, pairesRestantesLabel : widgets de l'infobox et du compteur de paires restantes. Ces widgets sont enregistrés pour pouvoir 
											  être actualisés depuis une fonction de callback
		-hide_next_move : lors d'une verification de coup, enregistre si les deux cartes doivent être retournées faces cachée
						  au rochain coup.
*/
typedef struct{
	Jeu *game;
	int grilleWidth, grilleHeight;
	Widget card1Widget, card2Widget;
	Widget infoBoxLabel, pairesRestantesLabel;
	int hide_next_move;
} display;


/****************************/
//		  Variables			//
/****************************/

/*
	-screen: variable globale d'affichage contenant les données necessaires pour representer la partie
	-strEntry : widget de l'entrée texte permettant d'entrer un nom de joueur.
*/
extern Widget strEntry;
extern Widget infoDiffLabel;
extern display *screen;


/****************************/
// 		  fonctions			//
/****************************/

extern void initGlobalDisplay();
extern void initCouleurs();
extern void initButtonBox();
extern void initInfoBox();
extern void updateInfoBox(const char *);
extern void initDiffBox(int pos1, Widget w1, int pos2, Widget w2);
extern void updateDiffBox();
extern void newWindow(char *c);
extern void hideCard(int width, int height);
extern void showCard(Widget w, int width, int height, void *d);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void startGame();
extern void fenetreDeFin();
extern void menu();
extern void rules();
extern void printScores(Widget w, void *d);