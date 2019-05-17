#include "jeu.h"



void initTabCartes(Card *TabCartes,int nbCartes){
    int i, f;
    for(i=0, f=0; i<nbCartes/2; i++, f++){
         initCard(TabCartes+2*i,i,0,f);
         initCard(TabCartes+2*i+1,i,0,f);
    }
    shuffle(TabCartes,nbCartes,sizeof(Card));
}

void initJeu(Jeu *jeu, int nbCartes){
	jeu->nbCartes = nbCartes;
	jeu->nbCartesRestantes = nbCartes;
	jeu->nbCoups = 0;
	jeu->etape = CARTE1;
	jeu->TabCartes = malloc(nbCartes*sizeof(Card));
	initTabCartes(jeu->TabCartes,nbCartes);
}

void jouerCoup(Jeu *jeu, Card *carteRetournee){
	int etape = jeu->etape;
	if (etape < VERIFICATION) {
		if (etape == CARTE1){
			jeu->carte1 = carteRetournee;
			printf("Carte 1 retournée!\n");
			jeu->etape = CARTE2;
		}
		else{
			jeu->carte2 = carteRetournee;
			printf("Carte 2 retournée!\n");
			jeu-> etape = VERIFICATION;
		}
	}
}

int verifierCoup(Jeu *jeu){
	jeu->nbCoups++;
	jeu->etape = CARTE1;
	if (jeu->carte1->id == jeu->carte2->id){
		jeu->nbCartesRestantes -= 2;
		printf("Cartes identiques\n");
		jeu->carte1->mode = DECOUVERTE;
		jeu->carte2->mode = DECOUVERTE;
		return 1;
	}
	return 0;
}