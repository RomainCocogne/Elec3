/*
  Jeu de memory utilisant la librairie graphique libsx

  @distribution: Linux (ubuntu)    
  @authors: Zayd El Hachimi, Quentin Combal, Romain Cocogne
  @arguments: none

  Pour compiler faire make dans le dossier courant

  Le programme supporte le changement de taille standard de la fenetre,
  mais pas des changements brusques ou des tailles improbables. 

*/
#include "header.h"

int main(int argc, char *argv[])
{
  if (OpenDisplay(argc, argv)==0){                      //cree la fenetre libsx
    fprintf(stderr, "Can't open display\n");
    return EXIT_FAILURE;
  }
  
  createFile();                //si le fichier de stockage des scores n'existe pas, on le cree
  initGlobalDisplay();         //initalise la variable globale d'ecran
  initCouleurs();              //initalise les couleurs du jeu
  menu();                      //affiche le menu. tout le reste va s'afficher avec des callbacks
  MainLoop();                  //loop

  return EXIT_SUCCESS;
}
