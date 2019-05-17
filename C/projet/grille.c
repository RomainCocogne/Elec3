#include "grille.h"


void initGrid(int nbCartes, Card tab[nbCartes]){
	enum FORME f=CARRE;
	 for(int i=0; i<nbCartes/2; i+=1){
	     initCard(tab+i,i,0,f);
	     initCard(tab+i+1,i,0,f);
	 }
	 shuffle(tab,nbCartes,sizeof(Card));
}
