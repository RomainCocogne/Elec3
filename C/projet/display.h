/*
	Module contenant tous les outils pour gerer l'affichage de menus et d'une partie de memory.
	utilise la librairie libsx
*/

#pragma once
#include <libsx.h>
#include "forme.h"
#include "score.h"
#include "couleur.h"
#include "callbacks.h"
#include "jeu.h"

/****************************/
// 		  Macros			//
/****************************/

/*
	Dimensions graphiques des cartes par defaut. 
	Il s'agit de la taille des cartes lors de l'affichage du debut d'une partie.
	L'utilisateur peut ensuite redimensionner la fenêtre et changer la taille des cartes.
 */
#define DEFAULT_CARD_WIDTH 90
#define DEFAULT_CARD_HEIGHT 170


/*
	Taille de la grille de cartes par default.
	Il s'agit de la taille de grille appliquée si l'utilisateur n'a pas précisé la difficulté.
*/
#define DEFAULT_GRILLEWIDTH 3
#define DEFAULT_GRILLEHEIGHT 2

/*
	Valeurs possibles de hide_next_move (utilité expliquée plus bas)
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
	Variable globale d'affichage contenant les données necessaires pour representer la partie
*/
extern display *screen;


/****************************/
// 		  fonctions			//
/****************************/

/*
  Initialise la variable globale d'affichage screen 
*/
extern void initGlobalDisplay();

/*****************************
		initialisation
*****************************/

/*
  Initialisation des couleurs utilisées pour la partie. 
*/
extern void initCouleurs();

/*
	Initialisation des bouttons de navigation présent sur toute les fenetres
*/
extern void initButtonBox();
/*
	Initialisation du panel informatif adjacent à l'espace de jeu.
	Est utilisé pour communiquer au joueur toute sortes d'informations sur la partie en cours
*/
extern void initInfoBox();
/*
	Initialisation du message informatif communiquant au joueur la difficulté courante du jeu.
	@args:
		- position par rapport au widget suivant. positions valides: meme que libsx (PLACE_UNDER, PLACE_RIGHT,NO_CARE)
		- widget de reference a la premiere position
		- position par rapport au second widget
		- widget de reference a la seconde position
*/
extern void initDiffBox(int, Widget, int, Widget);
/*
	cree une nouvelle fenetre apres avoir fermee la fenetre courante.
	@args: 
		-nom de la nouvelle fenetre
*/
extern void newWindow(char *);


/*****************************
		rafraichissement
*****************************/

/*
	Rafraichissent les elements initialisés dans initInfoBox et initDiffBox respectivement.
	updateInfoBox vous permet de choisir le message a afficher.
	updateDiffBox n'est pas parametrable
*/
extern void updateInfoBox(const char *);
extern void updateDiffBox();


/*****************************
			fenetres
*****************************/

/*
	Demarre une partie et affiche le plateau de jeu.
	Genere un widget DrawArea pour chaque carte (soit grilleWidth x grilleHeight widgets).
	Associe à chaque widget la carte correspondante, la fonction d'affichage, et la fonction d'action 
	lorsque l'on clique sur la carte.
*/
extern void startGame();
/*
	Cree et affiche la fenetre contenant le menu du jeu.
	Ferme la fenetre precedante.
	Donne acces via callbacks aux fenetres de jeu, des scores et des regles.
*/
extern void menu();
/*
	Cree et affiche le fenetre de fin.
	Si le score du joueur est suffisant, on lui propose de le sauvegarder.
	Ferme la fenetre precedante.
*/
extern void fenetreDeFin();
/*
	Cree et affiche la fenetre des regles.
	Ferme la fenetre precedante.
*/
extern void rules();
/*
	Cree et affiche la fenetre des scores.
	Les scores sont tries du plus meilleur au pire.
	Ferme la fenetre precedante.
	@args:
		- widget transmis si la fonction est utilisee en callback
		- donnees transmises si la fonction est utilisee en callback
*/
extern void printScores(Widget, void*);