/*

*/
#include "player.h"

void initPlayer(Player *j){
	j->name=malloc(MAX_NAME*sizeof(char));
	j->score=INT_MAX;
}

void setPlayerName(Player *j, char *name){
	strcpy(j->name,name);
}

void setPlayerScore(Player *j, int score){
	j->score=score;
}

void playercpy(Player *j1, Player *j2){
	initPlayer(j1);
	strcpy(j1->name,j2->name);
	j1->score=j2->score;
}

void addScore(Player joueur){
	FILE *fscore;
	if((fscore=fopen(FILE_NAME,"r+"))==NULL) {
		perror(FILE_NAME); exit(errno);
	}
	FILE *ftemp;
	if((ftemp=fopen("file_temp","w"))==NULL) {
		perror("file_temp"); exit(errno);
	}
	
	size_t sizebuff=0;
	char* buffer=0;
	ssize_t lenbuff=0;
	
	Liste all_players;
	initListe(&all_players);

	while ((lenbuff=getdelim(&buffer, &sizebuff, ':',fscore)>0)) {
		Player *jtemp=malloc(sizeof(Player));
		initPlayer(jtemp);
		buffer[strlen(buffer)-1]='\0';
		strcpy(jtemp->name,buffer);
		lenbuff=getline(&buffer, &sizebuff,fscore);
		jtemp->score=atoi(buffer);
		inserer(&all_players,1,jtemp);
		
		free(buffer); 
		buffer=NULL;
		
	}
	rewind(fscore);
	insertAndSort(&joueur,&all_players);

	for(int j=longueur(all_players)-1; j>1; j--){
		Player *jp;
		jp=((Player*)ieme(all_players,j));
	    fprintf(ftemp,"%s:%d\n",jp->name,jp->score);
	}
	fprintf(ftemp,"%s:%d",((Player*)ieme(all_players,1))->name,((Player*)ieme(all_players,1))->score);
	fclose(fscore);fclose(ftemp);
	remove(FILE_NAME);
	rename("file_temp",FILE_NAME);
}

void insertAndSort(Player *joueur, Liste *listejoueurs){
	int i=1;
	while(i<=10 && i<longueur(*listejoueurs) && ((Player *)ieme(*listejoueurs,i))->score>=joueur->score)i++;
	inserer(listejoueurs,i,joueur);
	while(longueur(*listejoueurs)>11) supprimer(listejoueurs,1);
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
		buffer=NULL;
		
	}
}