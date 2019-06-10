/*
  Module contenant tous les outils pour representer une partie de memory.
  Chaque partie est représentée par un type Jeu defini par le module
*/

#include "jeu.h"

/*
  Melange les N éléments du tableau array de maniére aléatoire. 
  Utilisé pour melanger les cartes du tableau TabCartes
  Fonction trouvée sur stack overflow : https://stackoverflow.com/questions/6127503/shuffle-array-in-c
  @args:
  - array: Pointeur sur void representant le tableau d'elements a melanger
  - n: size_t le nombre d'elements dans le tableau
  - size: size_t la taille d'un element du tableau
*/
void shuffle(void *array, size_t n, size_t size) {
  srand(time(NULL));                                          //initialise le random
  char tmp[size];                                             //variable temporaire pour les permutations
  char *arr = array;                                          
  size_t stride = size * sizeof(char);                        //pour se decaler de la bonne valeur

  if (n > 1) {
    size_t i;
    for (i = 0; i < (n - 1); ++i) {                           //pas besoin de melanger plusieurs fois puisqu'on utilise le random
      size_t rnd = (size_t) rand();                           //genere le nombre aleatoire
      size_t j = i + rnd / (RAND_MAX / (n - i) + 1);          //pondere l'indice random

      memcpy(tmp, arr + j * stride, size);                    /**/
      memcpy(arr + j * stride, arr + i * stride, size);       // Permutation
      memcpy(arr + i * stride, tmp, size);                    /**/
    }
  }
}

/*
  Initialise une tableau de type Card de taille nbCartes.
  Genere des paires de cartes ayant le même id. Il y a donc nbCartes/2 paires différentes.
  Melange l'ordre des cartes dans le tableau en appelant la fonction du module "shuffle" 
  @args:
  - TabCartes: Pointeur sur Card representant un tableau de cartes
  - nbCartes: int le nombre de cartes dans le tableau
*/
void initTabCartes(Card *TabCartes,int nbCartes){
  int i, f;
  for(i=0, f=0; i<nbCartes/2; i++, f++){
    	
    //Initalisation de la paire de cartes avec le même id.
    (TabCartes+2*i)->id = i;	
    (TabCartes+2*i+1)->id = i;
    (TabCartes+2*i)->mode = CACHEE;
    (TabCartes+2*i+1)->mode = CACHEE;
  }
  //Melange du tableau de carte
  shuffle(TabCartes,nbCartes,sizeof(Card));
}

/*
  Initialise une strucutre Jeu déclarée au préalable. 
  Doit être appelée en premeier pour demarrer une partie. 
  @args:
  - Jeu: Pointeur sur Jeu a initialiser
  - nbCartes: int nombre de Card a ajouter au jeu
*/
void initJeu(Jeu *jeu, int nbCartes){
  jeu->nbCartes = nbCartes;
  jeu->nbCartesRestantes = nbCartes;
  jeu->nbCoups = 0;
  jeu->etape = CARTE1;
  jeu->TabCartes = malloc(nbCartes*sizeof(Card));
  initTabCartes(jeu->TabCartes,nbCartes);
}

/*
  Fonction à apeller pour retourner une carte.
  Si le jeu est à l'étape CARTE1 ou CARTE2, enregistre l'addresse de la 
  carte retournée dans les variables carte1/carte2 de la structure jeu 
  passée en paramètre. Si l'étape est CARTE1, avance le jeu à l'étape CARTE2.
  Si le jeu est à l'étape VERIFICATION ou TERMINE, la fonction ne fait rien.
  Il faut appeler verifierCoup() avant de pouvoir jouer un autre coup
  @args:
  - jeu: Pointeur sur le jeu actuel
  - carteRetournee: Pointeur sur la carte a jouer
*/
void jouerCoup(Jeu *jeu, Card *carteRetournee){
  int etape = jeu->etape;
  //Effectue un action si l'étape est CARTE1 ou CARTE2
  //Si l'étape est VERIFICATION ou TERMINE, ne fait rien.
  if (etape < VERIFICATION) {
    //Au moins une des deux cartes n'est pas encore retournée
    jeu->nbCoups++;
    if (etape == CARTE1){
      //Aucune carte n'est actuellement retournée  : la carte choisie est la premiere carte
      carteRetournee->mode = RETOURNEE; 
      jeu->carte1 = carteRetournee;
      //Une carte est retournée : on passe à l'étape CARTE2
      jeu->etape = CARTE2;
    }
    else{
      //Une carte est retournée : la carte choisie est la deuxiéme
      carteRetournee->mode = RETOURNEE;
      jeu->carte2 = carteRetournee;
      //Les deux cartes sont retournées. Le jeu est avance à l'étape VERIFICATION
      jeu-> etape = VERIFICATION;
    }
  }
}

/*
  Fonction à apeller pour verifier un coup.
  Compare les deux cartes retournées par l'utilisateur, qui sont enregistrées dnas
  les variables carte1 et carte2 de la structure jeu.
  Si la partie est terminée, fait avancer le jeu à l'étape TERMINE. 
  Sinon, fait revenir à l'étape CARTE1 pour jouer le prochain coup.
  @args:
  - jeu: Pointeur sur le jeu actuel
  @return:
  - Int donnant le resultat de la comparaison des deux cartes retournees (1 si identiques, 0 sinon)
*/
int verifierCoup(Jeu *jeu){
  //L'étape suivante du jeu aprés verification est CARTE1 par defaut. 
  jeu->etape = CARTE1;
  if (jeu->carte1->id == jeu->carte2->id){
    //Les deux cartes sont identiques
    jeu->nbCartesRestantes -= 2;
    jeu->carte1->mode = DECOUVERTE;
    jeu->carte2->mode = DECOUVERTE;
    if (jeu->nbCartesRestantes == 0){
      //Toutes les cartes ont été decouvertes. La partie est terminée
      jeu->etape = TERMINE;
    }
    return 1;
  }
  //Les cartes sont différentes, on les retourne
  jeu->carte1->mode = CACHEE;
  jeu->carte2->mode = CACHEE;
  return 0;
}
