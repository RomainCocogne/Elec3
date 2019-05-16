#include "grille.h"


void initGrid(int nbCartes, Card tab[nbCartes]){
	enum FORME f=CARRE;
	 for(int i=0; i<nbCartes; i+=2,f++){
	     initCard(tab+i,f,0);
	     initCard(tab+i+1,f,0);
	 }
	 shuffle(tab,nbCartes,sizeof(Card));
}
