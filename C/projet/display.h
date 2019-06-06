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



/****************************/
// 		   types			//
/****************************/

/*
	Structure contenant toutes les données necessaires à l'affichage de la partie.
		-grilleWidth, grilleHeight : Taille de la grille de jeu. grilleWidth x grilleHeight doit être égal au nombre de cartes dans le jeu. 
		-game : pointeur vers une structure jeu contenant toutes les infos de jeu. Ce pointeur permet à l'affichage de recupérer les données 
				 de la partie pour pouvoir les afficher.
*/
typedef struct{
	int grilleWidth, grilleHeight;
	Jeu *game;
} display;


/****************************/
//		  variables			//
/****************************/

/*
	-screen: variable globale d'affichage contenant les données necessaires pour representer la partie
	-strEntry : widget de l'entrée texte permettant d'entrer un nom de joueur.
*/
extern display *screen;
extern Widget strEntry;

/****************************/
// 		  fonctions			//
/****************************/

extern void initGlobalDisplay();
extern void hide (int width, int height);
extern void show(Widget w, int width, int height, void *d);
extern void sidePanel();
extern void initInfoBox();
extern void updateInfoBox(const char *);
extern void newWindow(char *c);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void genereGame();
extern void fenetreDeFin();
extern void menu();
extern void initAffichage(int grilleWidth, int grilleHeight);
extern void ruler (Widget w,void *d);
extern void printScores(Widget w, void *d);