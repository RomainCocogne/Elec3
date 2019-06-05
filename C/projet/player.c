/*

*/
#include "player.h"

int compare (Player j1, Player j2){
	if (!strcmp(j1.name,j2.name) && j1.score==j2.score)
		return 0;
	return j1.score>j2.score? -1:1;
}
void initPlayer(Player *j){
	j->name=malloc(MAX_NAME*sizeof(char));
	j->score=INT_MAX;
}
void rmPlayer(Player *j){
	free(j);
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
