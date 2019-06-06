#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "display.h"
#include "score.h"


extern Widget card1Widget;
extern Widget card2Widget;


/*
  Callback pour quitter le programme
*/
extern void quit(Widget w, void *d);

/*
  Callback pour relancer une partie
  Ferme les feêntres ouvertes, libére l'espace aloué aux cartes de lapattie précdente,
  et reinitialise les paramétres de la partie et de l'affichage.
*/
extern void replay(Widget w, void *d);
extern void saveScore(Widget w, void *d);
extern void setSize(Widget w, void *d);
extern void retournerCarte(Widget w, int which_button, int x, int y, void *data);
