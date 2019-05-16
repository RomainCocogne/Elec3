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

struct cmplex {
    int foo;
    double bar;
};

const char *forme[] = { "carre", "rond", "triangle", "etoile", NULL };

int main(int argc, char const *argv[]){

   	int nbCards=8;
   	Card grille[nbCards];
   	initGrid(nbCards,grille);
   	//shuffle(grille,nbCards,sizeof(Card));
   	print_type(NELEMS(grille),printf("%s  ",forme[grille[i].f]));

   	Liste joueurs;
   	initListe(&joueurs);
   	getScore(&joueurs);
   	print_type(longueur(joueurs),printf("%s:%d\n",((Player *)ieme(joueurs,i+1))->name,((Player *)ieme(joueurs,i+1))->score));

	return EXIT_SUCCESS;
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