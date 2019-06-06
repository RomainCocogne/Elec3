#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "forme.h"
#include "score.h"
#include "couleur.h"
#include <libsx.h>
#include <string.h>
#include "callbacks.h"

/****************************/
// 		  Macros			//
/****************************/

/*
	Dimensions graphiques des cartes par defaut. 
	Il s'agit de la taille des crtaes lors de l'affichage du debut d'une partie.
	L'utilisateur peut ensuite redimensionner la fenêtre et changer la tailel des cartes.
 */
#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 180

/*
	Taille de la grille de cartes par default.
	Il s'agit de la taille de grille appliquée si l'utilisateur n'a pas précisé la difficulté.
*/
#define DEFUALT_GRILLEWIDTH 3
#define DEFUALT_GRILLEHEIGHT 2



extern int GRILLEWIDTH;
extern int GRILLEHEIGHT;


/****************************/
// 		   types			//
/****************************/


/*
	Structure contenant toutes les données necessaires à l'affichage de la partie.
		-Color : Tableau contenant toutes les couleurs utilisées dans l'affichage.
				 Couleur 0 : couleur de fond (blanc par defaut)
				 Couleur 1 : couleur de la face cahcée des cartes (noir par defaut)
				 Couleurs 2 à 5 : couleurs utilisées pour les formes (bleu, vert, orange et rouge par defaut)
		-grilleWidth, grilleHeight : Taille de la grille de jeu. grilleWidth x grilleHeight doit être égal au nombre de cartes dans le jeu. 
		-board : pointeur vers une structure jeu contenant toutes les infos de jeu. Ce pointeur permet à l'affichage de recupérer les données 
				 de la partie pour pouvoir les afficher.
*/
typedef struct{
	int grilleWidth, grilleHeight;
	Jeu *board;
} display;


/****************************/
//		  variables			//
/****************************/

/*
	-display : variable global d'affichage contenant les données necessaires pour representer la partie
	-widget1, widget2 : buffers contenant les widgets des cartes cliquées par le joueur. 
						Permet d'enregistrer les zones des deux cartes qui ont été cliquées.  
	-strEntry : widget de l'entrée texte permettant d'entrer un nom de joueur.
*/
extern display *screen;
extern Widget widget1;
extern Widget widget2;
extern Widget strEntry;

extern Widget strEntry;

extern void initGlobalDisplay();

/****************************/
// 		  fonctions			//
/****************************/



extern void hide (int width, int height);
extern void show(Widget w, int width, int height, void *d);
extern void sidePanel();
extern void newWindow(char *c);
extern void displayDrawArea(Widget w, int width, int height, void *data);
extern void genereGame();
extern void fenetreDeFin();
extern void menu();
extern void initAffichage(int grilleWidth, int grilleHeight);
extern void ruler (Widget w,void *d);
extern void printScores(Widget w, void *d);