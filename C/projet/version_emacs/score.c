/*
  Implementation des fonctions du module score.h
*/

#include "score.h"


/*
  Cree le fichier score si il n'existe pas deja.
  Permet de faire fonctionner le jeu si le fichier est supprime par erreur
*/
void createFile(){
  FILE *fscore;
  if((fscore=fopen(FILE_NAME,"r"))==NULL) { 	   //si on ne peut pas l'ouvir en lecture, il n'existe pas
    fscore=fopen(FILE_NAME,"w");	           //on le cree
  }
  fclose(fscore);
	
}

/*
  ajoute un score (nom+score) dans le fichier.
  le score est insere de facon a ce que le fichier soit trie dans l'ordre decroissant des scores
  Cette procedure cree un fichier temporaire qui va etre renomme pour ecraser le fichier score
  @args:
  - Pointeur sur char le nom du joueur
  - int son score
*/
void saveScore(char *name, int sc){	

  Player joueur;					//initialise la variable Player
  initPlayer(&joueur);
  setPlayerScore(&joueur,sc);
  setPlayerName(&joueur,name);								
	
  Liste all_players;				        //liste de tout les joueurs dans le fichier
  initListe(&all_players);

  getScore(&all_players);
  insertAndSort(&joueur,&all_players);			//insertion du joueur dans la liste

  FILE *ftemp;					        //ouverture du fichier temporaire
  if((ftemp=fopen(".file_temp","w"))==NULL) {
    perror(".file_temp"); exit(errno);
  }

  for(int j=1; j<=longueur(all_players); j++){	//ecriture dans le fichier temporaire de tout les joueurs
    fwrite(((Player*)ieme(all_players,j))->name,sizeof(char)*MAX_NAME,1,ftemp);	//d'abord le nom
    fwrite(&(((Player*)ieme(all_players,j))->score),sizeof(int),1,ftemp);	//puis le score
  }
	
  fclose(ftemp);							//on ferme le fichier temp
  remove(FILE_NAME);						        //supprime le fichier de scores
  rename(".file_temp",FILE_NAME);			                //renome le fichier temp 
}

/*
  Ajoute un joueur dans la liste de tout les joueurs contenus dans le fichier,
  puis trie les joueurs dans l'ordre decroissant des scores
  @args:
  - Pointeur sur Player le joueur a ajouter a la liste
  - Pointeur sur Liste la liste contenant tout les joueurs du fichier score
*/
void insertAndSort(Player *joueur, Liste *listejoueurs){
  int i=1;
  // on se place de facon a respecter l'ordre decroissant des scores
  while(i<=longueur(*listejoueurs) && ((Player *)ieme(*listejoueurs,i))->score>=joueur->score)i++;
  //si le score n'existe pas deja pour ce nom, on peut l'ajouter
  if(i==1 || compare(*joueur,*(Player *)ieme(*listejoueurs,i-1))) inserer(listejoueurs,i,joueur);
  //on supprime les scores si on depasse le nombre max de scores
  while(longueur(*listejoueurs)>MAX_SCORE) supprimer(listejoueurs,longueur(*listejoueurs));
}

/*
  Recupere la liste de tout les joueurs dans le fichier score
  @args:
  - Pointeur sur Liste qui va contenir tout les joueurs
*/
void getScore(Liste *joueurs){
  FILE *fscore;							//ouverture du fichier score
  if((fscore=fopen(FILE_NAME,"r"))==NULL) {
    perror(FILE_NAME); exit(errno);
  }
	
	
  char *bufferchar=malloc(sizeof(char)*MAX_NAME);	
  int bufferint;

  while(fread(bufferchar,sizeof(char)*MAX_NAME,1,fscore)>0){	//on lit le nom dans le fichier
    fread(&bufferint,sizeof(int),1,fscore);		        //puis le score

    Player *jtemp=malloc(sizeof(Player));			//on cree un joueur temporaire
    initPlayer(jtemp);
    strcpy(jtemp->name,bufferchar);
    jtemp->score=bufferint;
    inserer(joueurs,longueur(*joueurs)+1,jtemp);		//on l'ajoute a la fin de la liste
		
    free(bufferchar);
    bufferchar=malloc(sizeof(char)*MAX_NAME);
    bufferint=0;
  }
  fclose(fscore);
}

/*
  Donne le dernier score enregistre dans le fichier.
  Si le fichier est vide, NULL est retourne
  @return:
  - int le dernier score du fichier
*/
int getLastScore(){
  FILE *fscore;								//ouverture du fichier score
  if((fscore=fopen(FILE_NAME,"r"))==NULL) {
    perror(FILE_NAME); exit(errno);
  }
  char *bufferchar=malloc(sizeof(char)*MAX_NAME);
  int bufferint;
  //on parcourt tout le fichier en lisant d'abord le nom puis le score de chaque joueur
  while(fread(bufferchar,sizeof(char)*MAX_NAME,1,fscore)>0) fread(&bufferint,sizeof(int),1,fscore);
	
  free(bufferchar);
  fclose(fscore); 
  return bufferint;
}

/*
  Donne le nombre de scores dans le fichier
  @return:
  - int le nombre de scores dans le fichier (0 si aucun score)
*/
int nbScores(){
  FILE *fscore;								//ouverture du fichier score
  if((fscore=fopen(FILE_NAME,"r"))==NULL) {
    perror(FILE_NAME); exit(errno);
  }
	
  int lines=0;
  char *bufferchar=malloc(sizeof(char)*MAX_NAME);
  int bufferint;
  //on parcourt tout le fichier en comptant le nombre de lignes
  while(fread(bufferchar,sizeof(char)*MAX_NAME,1,fscore)>0){
    fread(&bufferint,sizeof(int),1,fscore);
    lines++;
  }
  free(bufferchar);
  fclose(fscore);
	
  return lines;
}

/*
  Genere le score du joueur selon cette formule:
  (1/10+1/nbCoups)*nbCartes*100
  avec nbCoups le nombre de coups joues dans la partie et nbCartes le nombre de cartes dans la partie
*/
int genereScore(int nbCoups, int nbCartes){
  return (int)((0.1+1.0/(double)(nbCoups))*(nbCartes)*100);
}
