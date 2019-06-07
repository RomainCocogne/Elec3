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

	for(int j=1; j<=longueur(all_players); j++){
		Player *jp=malloc(sizeof(Player));
		jp=((Player*)ieme(all_players,j));

	//     fprintf(ftemp,"%s:%d\n",jp->name,jp->score);
		fwrite(jp->name,sizeof(char)*MAX_NAME,1,ftemp);
		fwrite(&(jp->score),sizeof(int),1,ftemp);
	}
	// char test[20]="test";
	// fwrite(test,sizeof(char)*20,1,ftemp);
	// fprintf(ftemp,"%s:%d",((Player*)ieme(all_players,longueur(all_players)))->name,((Player*)ieme(all_players,longueur(all_players)))->score);
	fclose(fscore);fclose(ftemp);
	remove(FILE_NAME);
	rename("file_temp",FILE_NAME);
	// rmListe(&all_players);
}

void insertAndSort(Player *joueur, Liste *listejoueurs){
	int i=1;
	while(i<=longueur(*listejoueurs) && ((Player *)ieme(*listejoueurs,i))->score>=joueur->score)i++;
	//printf("%d\n",longueur(*listejoueurs));
	if(i==1 || compare(*joueur,*(Player *)ieme(*listejoueurs,i-1))) inserer(listejoueurs,i,joueur);
	while(longueur(*listejoueurs)>10) supprimer(listejoueurs,longueur(*listejoueurs));
}

void getScore(Liste *joueurs){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	// size_t sizebuff=0;
	// char* buffer=0;
	// ssize_t lenbuff=0;
	// while ((lenbuff=getdelim(&buffer, &sizebuff, ':',fscore)>0)) {
	// 	buffer[strlen(buffer)-1]='\0';
	// 	strcpy(jtemp->name,buffer);
	// 	lenbuff=getline(&buffer, &sizebuff,fscore);
	// 	jtemp->score=atoi(buffer);
	// 	free(buffer); 
	// 	buffer=NULL;
		
	// }
	// char test [20];
	char *bufferchar=malloc(sizeof(char)*MAX_NAME);
	int bufferint;
	while(fread(bufferchar,sizeof(char)*MAX_NAME,1,fscore)>0){
		fread(&bufferint,sizeof(int),1,fscore);

		Player *jtemp=malloc(sizeof(Player));
		initPlayer(jtemp);
		strcpy(jtemp->name,bufferchar);
		jtemp->score=bufferint;
		inserer(joueurs,longueur(*joueurs)+1,jtemp);
		free(bufferchar);

		bufferint=0;
		bufferchar=NULL;
		bufferchar=malloc(sizeof(char)*MAX_NAME);
	}
	fclose(fscore);
}

int getLastScore(){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	char *bufferchar=malloc(sizeof(char)*MAX_NAME);
	int bufferint;
	while(fread(bufferchar,sizeof(char)*MAX_NAME,1,fscore)>0) fread(&bufferint,sizeof(int),1,fscore);
	int sc=bufferint;
	fclose(fscore); free(bufferchar);
	return sc;
}

int nbScores(){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	int lines=0;
	char *bufferchar=malloc(sizeof(char)*MAX_NAME);
	int bufferint;
	while(fread(bufferchar,sizeof(char)*MAX_NAME,1,fscore)>0){
		fread(&bufferint,sizeof(int),1,fscore);
		lines++;
	}
	// printf("%d\n",lines);
	fclose(fscore);free(bufferchar);
	return lines;
}

int genereScore(Jeu jeu){
	return (int)((0.1+1.0/(double)(jeu.nbCoups))*(jeu.nbCartes)*100);
}