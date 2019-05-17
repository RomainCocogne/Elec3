#include "jeu.h"


void initJeuCartes(Card *TabCartes,int nbCartes){
    int i, f;
    for(i=0, f=0; i<nbCartes/2; i++, f++){
         initCard(TabCartes+2*i,i,0,f);
         initCard(TabCartes+2*i+1,i,0,f);
    }
    shuffle(TabCartes,nbCartes,sizeof(Card));
}