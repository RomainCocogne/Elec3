/*
    Jeu de memory utilisant la librairie graphique libsx

    @distribution: Linux (ubuntu)    
    @authors: Zayd El Hachimi, Quentin Combal, Romain Cocogne
    @arguments: none

    Pour compiler faire make dans le dossier courant
    Pour executer faire compile/main

*/
#include "header.h"

int main(int argc, char *argv[])
{
  if (OpenDisplay(argc, argv)==0){                      //cree la fenetre libsx
      fprintf(stderr, "Can't open display\n");
      return EXIT_FAILURE;
  }
  
  initGlobalDisplay();         //initalise la variable globale d'ecran
  menu();                      //affiche le menu. tout le reste va s'afficher avec des callbacks
  MainLoop();                  //loop

  return EXIT_SUCCESS;
}