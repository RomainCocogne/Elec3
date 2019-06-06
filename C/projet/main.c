/*
    Programme de memori utilisant la librairie graphique libsx

    @distribution: Linux (ubuntu)    
    @authors: Zayd, Quentin, Romain
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
  
  initDisplay();                                        //initalise la variable globale d'ecran
  menu();                                               //affiche le menu
  MainLoop();                                           //loop

  return EXIT_SUCCESS;
}