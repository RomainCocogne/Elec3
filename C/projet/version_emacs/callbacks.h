/*
  Module contenant les fonctions de callback non graphiques.
*/

#pragma once

/****************************/
//	  inclusions 	    //
/****************************/
#include <libsx.h>
#include "display.h"
#include "score.h"
#include "couleur.h"


/****************************/
// 	  fonctions	    //
/****************************/

/*
  Callback pour quitter le programme
*/
extern void quit();

/*
  Callback pour enregistrer le score
  @args:
  - Widget du callback
  - Pointeur sur void correspondant au score (int)
*/
extern void saveScoreCallback(Widget , void *);

/*
  Fonction appellée par les boutons de changement de difficulté
  Assigne la difficulté selectionnée à la partie.
  @args:
  - Widget du callback
  - Pointeur sur void correspondant aux donnees transmises par le callback
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
  @args:
  - Widget du callback qi correspond a la drawArea de la carte
  - int donne si il s'agit d'un click gauche (1) ou pas
  - int donne la position en x de la drawArea
  - int donne la position en y de la drawArea
  - Pointeur sur void correspond a la carte associée au Widget qui à été cliqué.
*/
extern void retournerCarte(Widget , int , int , int , void *);

/*
  Cette fonction remet une carte face cachee
  /!\ Apres l'execution de cette fonction, Widget sera le widget courant
  @args:
  - Widget la carte 
  - int la largeur d'une carte
  - int la hauteur d'une carte
*/
extern void hideCard(Widget, int, int);

/*
  Cette fonction decouvre une carte en generant une forme et une couleur d'apres son id
  @args:
  - Widget la carte 
  - int la largeur d'une carte
  - int la hauteur d'une carte
  - Pointeur sur void représentant la carte
*/
extern void showCard(Widget, int, int, void *);

/*
  Fonction de callback des zones de dessin qui représentent les cartes. 
  Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
  chaque fois que l'utilisateur change la taille de la fenêtre
  @args:
  - Widget correspondant a la carte
  - int la largeur de la carte
  - int le hauteur de la carte
  - Pointeur sur void, pointeur vers la structure carte associée au widget ayant appelé cette fonction
*/
extern void displayDrawArea(Widget, int, int, void *);
