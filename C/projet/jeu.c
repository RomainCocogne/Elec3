/*
	Module contenant tous les outils pour representer une partie de memory.
	Chaque partie est représentée par un type Jeu defini par le module
*/

#include "jeu.h"

//  arrange the N elements of ARRAY in random order.
//  * Only effective if N is much smaller than RAND_MAX;
//  * if this may not be the case, use a better random
//  * number generator. 

void shuffle(void *array, size_t n, size_t size) {
    srand(time(NULL));                                          //initialise le random
    char tmp[size];                                             //variable temporaire pour les permutations
    char *arr = array;                                          
    size_t stride = size * sizeof(char);                        //pour se decaler de la bonne valeur

    if (n > 1) {
        size_t i;
        for (i = 0; i < (n - 1); ++i) {                         //pas besoin de melanger plusieurs fois puisqu'on utilise le random
            size_t rnd = (size_t) rand();                       //genere le nombre aleatoire
            size_t j = i + rnd / (RAND_MAX / (n - i) + 1);      //pondere l'indice random

            memcpy(tmp, arr + j * stride, size);                //permutation
            memcpy(arr + j * stride, arr + i * stride, size);   //
            memcpy(arr + i * stride, tmp, size);                //
        }
    }
}

/*
	Initialise une tableau de type Card de taille nbCartes.
	Genere des paires de cartes ayant le même id. Il y a donc nbCartes/2 paires différentes.
	Mélange l'ordre des cartes dans le tableau en appelant la fonction du module "shuffle" 
*/
void initTabCartes(Card *TabCartes,int nbCartes){
    int i, f;
    for(i=0, f=0; i<nbCartes/2; i++, f++){
         initCard(TabCartes+2*i,i,0,f);
         initCard(TabCartes+2*i+1,i,0,f);
    }
    shuffle(TabCartes,nbCartes,sizeof(Card));
}

/*
	Initialise une strucutre Jeu déclarée au préalable. 
	Doit être appelée en prmeier pour demarrer une partie. 
*/
void initJeu(Jeu *jeu, int nbCartes){
	jeu->nbCartes = nbCartes;
	jeu->nbCartesRestantes = nbCartes;
	jeu->nbCoups = 0;
	jeu->etape = CARTE1;
	jeu->TabCartes = malloc(nbCartes*sizeof(Card));
	initTabCartes(jeu->TabCartes,nbCartes);
}

void freeJeu(Jeu *jeu){
	free(jeu->TabCartes);
}

/*
	Retourne une carte et enregistre sa valeur
	Lorsque le jeu est à l'étape VERIFICATION, il faut appeler 
	verifierCoup() avant de pouvoir jouer un autre coup
*/
void jouerCoup(Jeu *jeu, Card *carteRetournee){
	int etape = jeu->etape;
	if (etape < VERIFICATION) {
		jeu->nbCoups++;
		if (etape == CARTE1){
			carteRetournee->mode = RETOURNEE; 
			jeu->carte1 = carteRetournee;
			printf("Carte 1 retournée!\n");
			jeu->etape = CARTE2;
		}
		else{
			carteRetournee->mode = RETOURNEE;
			jeu->carte2 = carteRetournee;
			printf("Carte 2 retournée!\n");
			jeu-> etape = VERIFICATION;
		}
	}
}

int verifierCoup(Jeu *jeu){
	jeu->etape = CARTE1;
	if (jeu->carte1->id == jeu->carte2->id){
		jeu->nbCartesRestantes -= 2;
		printf("Cartes identiques\n");
		jeu->carte1->mode = DECOUVERTE;
		jeu->carte2->mode = DECOUVERTE;
		if (jeu->nbCartesRestantes == 0){
			printf("Felicitations ! Vous avez gagné !\n");
			jeu->etape = TERMINE;
		}
		return 1;
	}
	jeu->carte1->mode = CACHEE;
	jeu->carte2->mode = CACHEE;
	return 0;
}