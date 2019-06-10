/*
  Implementation des fonctions de player.h
*/
#include "player.h"

/*
  Compare les noms et scores de 2 joueurs.
  @args:
  - j1: Player premier joueur a comparer
  - j2: Player second joueur a comparer
  @return:
  - int resultat de la comparaison. 0 si les noms sont differents et scores egaux,
  sinon, -1 si score du premier joueur et plus grand, 1 sinon
*/
int compare (Player j1, Player j2){
  if (!strcmp(j1.name,j2.name) && j1.score==j2.score)
    return 0;
  return j1.score>j2.score? -1:1;
}

/*
  Initialise la structure Player
  @args:
  - j: Pointeur sur le Player a Initialiser
*/
void initPlayer(Player *j){
  j->name=calloc(MAX_NAME,sizeof(char));
  j->score=0;
}

/*
  Supprime un joueur
  @args:
  - j: Pointeur sur le Player a supprimer
*/
void rmPlayer(Player *j){
  free(j->name);
  free(j);
}

/*
  Permet de donner un nom au joueur.
  Si un nom est deja donne, il sera ecrase
  @args:
  - j: Pointeur sur le Player dont on veut modifier le nom
  - name: Pointeur sur char (chaine de caracteres) representant le nom
*/
void setPlayerName(Player *j, char *name){
  strcpy(j->name,name);
}

/*
  Permet de donner un score a un joueur.
  @args:
  - j: Pointeur sur le Player dont on veut modifier le score
  - score: int le score
*/
void setPlayerScore(Player *j, int score){
  j->score=score;
}

/*
  Copie le nom et le score d'un joueur dans un autre joueur
  @args:
  - j1: Pointeur sur le joueur recepteur
  - j2: Pointeur sur le joueur donneur
*/
void playercpy(Player *j1, Player *j2){
  strcpy(j1->name,j2->name);
  j1->score=j2->score;
}
