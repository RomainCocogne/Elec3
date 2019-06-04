#include "callbacks.h"

int GRILLEWIDTH=3;
int GRILLEHEIGHT=2;

void quiter (Widget w,void *d){
  exit(EXIT_SUCCESS);
}

void ruler (Widget w,void *d){
  Widget window,label_rules;
  window=MakeWindow("Rules",NULL,NONEXCLUSIVE_WINDOW);
  SetCurrentWindow(window);
  label_rules=MakeLabel(" The cards are layed in rows, face down.\n Turn over any two cards.If the two cards match,they are kept shown.\n If they don't match,they are turned back over if you click anywhere on the screen.\n Remember what was on each card and where it was.\n The game is over when all the cards have been matched and revealed");
  SetWidgetPos(label_rules,NO_CARE,NULL,NO_CARE,NULL);

  ShowDisplay();
  
}

void setSize(Widget w, void *d){
	char *str=(char*)d;
	GRILLEWIDTH=str[0]-'0';
	GRILLEHEIGHT=str[1]-'0';
	printf("%d,%d\n",GRILLEHEIGHT,GRILLEWIDTH);
}

void printScores(Widget w, void *d){
	Liste joueurs;
	initListe(&joueurs);
	getScore(&joueurs);
	// printf("%s\n",((Player *)ieme(joueurs,1))->name);

	char strJoueurs[(longueur(joueurs)+1)*sizeof(char)*MAX_NAME*2];
	if(longueur(joueurs)>0){
		sprintf(strJoueurs,"%s : %d\n",((Player *)ieme(joueurs,1))->name,((Player *)ieme(joueurs,1))->score);
		for(int i=2; i<=longueur(joueurs); i++){
			char temp[sizeof(char)*MAX_NAME*2];
		    sprintf(temp,"%s : %d\n",((Player *)ieme(joueurs,i))->name,((Player *)ieme(joueurs,i))->score);

			strcat(strJoueurs,temp);
		}
	}
	else{
		strcpy(strJoueurs,"No hight score yet.");
	}
	Widget window,label_scores;
  	window=MakeWindow("HightScore",NULL,NONEXCLUSIVE_WINDOW);
  	SetCurrentWindow(window);
  	label_scores=MakeLabel(strJoueurs);
  	SetWidgetPos(label_scores,NO_CARE,NULL,NO_CARE,NULL);
  	// rmListe(&joueurs);
  	// free(strJoueurs);
  	ShowDisplay();
}