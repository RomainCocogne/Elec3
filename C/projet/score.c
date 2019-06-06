#include "score.h"


void addScore(Player joueur){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	FILE *ftemp;
	if((ftemp=fopen("file_temp","w"))==NULL) {
		perror("file_temp"); exit(errno);
	}
	
	Liste all_players;
	initListe(&all_players);

	getScore(&all_players);
	rewind(fscore);
	insertAndSort(&joueur,&all_players);

	for(int j=1; j<=longueur(all_players)-1; j++){
		Player *jp;
		jp=((Player*)ieme(all_players,j));
	    fprintf(ftemp,"%s:%d\n",jp->name,jp->score);
	    // rmPlayer(jp);
	}
	fprintf(ftemp,"%s:%d",((Player*)ieme(all_players,longueur(all_players)))->name,((Player*)ieme(all_players,longueur(all_players)))->score);
	fclose(fscore);fclose(ftemp);
	remove(FILE_NAME);
	rename("file_temp",FILE_NAME);
	// rmListe(&all_players);
}

void insertAndSort(Player *joueur, Liste *listejoueurs){
	int i=1;
	while(i<=longueur(*listejoueurs) && ((Player *)ieme(*listejoueurs,i))->score>=joueur->score)i++;
	printf("%d\n",longueur(*listejoueurs));
	if(i==1 || compare(*joueur,*(Player *)ieme(*listejoueurs,i-1))) inserer(listejoueurs,i,joueur);
	while(longueur(*listejoueurs)>10) supprimer(listejoueurs,longueur(*listejoueurs));
}

void getScore(Liste *joueurs){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	size_t sizebuff=0;
	char* buffer=0;
	ssize_t lenbuff=0;
	while ((lenbuff=getdelim(&buffer, &sizebuff, ':',fscore)>0)) {
		Player *jtemp=malloc(sizeof(Player));
		initPlayer(jtemp);
		buffer[strlen(buffer)-1]='\0';
		strcpy(jtemp->name,buffer);
		lenbuff=getline(&buffer, &sizebuff,fscore);
		jtemp->score=atoi(buffer);
		inserer(joueurs,longueur(*joueurs)+1,jtemp);
		free(buffer); 
		// rmPlayer(jtemp);
		buffer=NULL;
		
	}
	fclose(fscore);
}

int getLastScore(){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	size_t sizebuff=0;
	char* buffer=0;
	ssize_t lenbuff=0;
	
	Player joueur;
	while ((lenbuff=getdelim(&buffer, &sizebuff, ':',fscore)>0)) {
		initPlayer(&joueur);
		buffer[strlen(buffer)-1]='\0';
		strcpy(joueur.name,buffer);
		lenbuff=getline(&buffer, &sizebuff,fscore);
		joueur.score=atoi(buffer);
		free(buffer);
		buffer=NULL;
		
	}
	int sc=joueur.score;
	// rmPlayer(joueur);
	fclose(fscore);
	return sc;
}

int nbScores(){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	int lines=0;
	size_t sizebuff=0;
	char* buffer=0;
	ssize_t lenbuff=0;
	while ((lenbuff=getline(&buffer, &sizebuff,fscore)>0))lines++;
	fclose(fscore);free(buffer);
	return lines;
}