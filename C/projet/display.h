/*
	Module contenant tous les outils pour gerer l'affichage de menus et d'une partie de memory.
*/

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
		-hide_next_move : lors d'une verification de coup, enregistre si les deux cartes doivent être retournées faces cachée
						  au prochain coup.		
		-widget1, widget2 : buffers contenant les widgets des cartes cliquées par le joueur. 
					   		Permet d'enregistrer les zones des deux cartes qui ont été cliquées
		-widgets labels : widgets permettant un affichage d'informations en temps réel. Ces widgets sont enregistrés pour pouvoir 
						  être actualisés depuis une fonction de callback
		-strEntry : widget de l'entrée texte permettant d'entrer un nom de joueur.
*/
typedef struct{
	Jeu *game;
	int grilleWidth, grilleHeight;
	int hide_next_move;
	Widget card1Widget, card2Widget;
	Widget infoBoxLabel, pairesRestantesLabel, infoDiffLabel;
	Widget strEntry;
} display;


/****************************/
//		  Variables			//
/****************************/

/*
	-screen: variable globale d'affichage contenant les données necessaires pour representer la partie
	-strEntry : widget de l'entrée texte permettant d'entrer un nom de joueur.
*/
extern display *screen;


/****************************/
// 		  fonctions			//
/****************************/

/*
  Initialise la variable globale d'affichage screen 
*/
extern void initGlobalDisplay();

/*
  Fonction d'initialisation des couleurs utilisées pour la partie. 
*/
extern void initCouleurs();


extern void initButtonBox();
extern void initInfoBox();
extern void updateInfoBox(const char *);
extern void initDiffBox(int pos1, Widget w1, int pos2, Widget w2);
extern void updateDiffBox();
extern void newWindow(char *c);
extern void hideCard(int width, int height);
extern void showCard(Widget w, int width, int height, void *d);

/*
	Fonction de callback des zones de dessin qui représentent les cartes. 
	Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
	chaque fois que l'utilisateur change la taille de la fenêtre

  data : pointeur vers la structure carte associée au widget ayant appelé cette fonction
*/
extern void displayDrawArea(Widget w, int width, int height, void *data);

/*
  Demarre une partie et affiche le plateau de jeu.
  Genere un widget DrawArea pour chaque carte (soit grilleWidth x grilleHeight widgets).
  Associe à chaque widget la carte correspondante, la fonction d'affichage, et la fonction d'action 
  lorsque l'on clique sur la carte.
*/
extern void startGame();
extern void fenetreDeFin();
extern void menu();
extern void rules();
extern void printScores(Widget w, void *d);