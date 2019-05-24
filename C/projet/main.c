/*
    
*/
#include "header.h"

#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))


#define print_type(count, stmt) \
    do { \
    printf("["); \
    for (size_t i = 0; i < (count); ++i) { \
        stmt; \
    } \
    printf("]\n"); \
    } while (0)


// const char *forme[] = { "carre", "rond", "triangle", "etoile", NULL };

int main(int argc, char *argv[])
{
  if (OpenDisplay(argc, argv)==0){
      fprintf(stderr, "Can't open display\n");
      return EXIT_FAILURE;
  }
  
  int grilleWidth = 6;
  int grilleHeight = 3;
  int size = grilleWidth*grilleHeight;

  Jeu jeu;
  initJeu(&jeu,size);

  GetStandardColors();
  gris = GetRGBColor(40,40,40); //Pas sur que ce soit propre de init les couleurs comme ça
  blanc = GetRGBColor(230,230,230);
  bleu = GetRGBColor(20,20,180);
  rouge = GetRGBColor(180,20,20) ;
  vert = GetRGBColor(20,180,20);
  orange = GetRGBColor(220,130,20);


  initAffichage(&jeu, grilleWidth, grilleHeight);
  // printf("Gris = %d\nBlanc = %d\n",gris,blanc );
  ShowDisplay();
  MainLoop();

  return 0;
}

//test du shuffle
    // print_type(NELEMS(intarr), printf("%d,", intarr[i]));
    // shuffle(intarr, NELEMS(intarr), sizeof(intarr[0]));
    // print_type(NELEMS(intarr), printf("%d,", intarr[i]));

    // struct cmplex cmparr[] = {
    //     { 1, 3.14 },
    //     { 5, 7.12 },
    //     { 9, 8.94 },
    //     { 20, 1.84 }
    // };

    // print_type(NELEMS(intarr), printf("{%d %f},", cmparr[i].foo, cmparr[i].bar));
    // shuffle(cmparr, NELEMS(cmparr), sizeof(cmparr[0]));
    // print_type(NELEMS(intarr), printf("{%d %f},", cmparr[i].foo, cmparr[i].bar));

//tests
 //   	int nbCards=8;
 //   	Card grille[nbCards];
 //   	initGrid(nbCards,grille);
 //   	//shuffle(grille,nbCards,sizeof(Card));
 //   	print_type(NELEMS(grille),printf("%s  ",forme[grille[i].f]));

 //   	Liste joueurs;
 //   	initListe(&joueurs);
 //   	getScore(&joueurs);
 //   	print_type(longueur(joueurs),printf("%s:%d\n",((Player *)ieme(joueurs,i+1))->name,((Player *)ieme(joueurs,i+1))->score));

	// return EXIT_SUCCESS;
