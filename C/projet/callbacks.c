#include "callbacks.h"


void saveScore(Widget w, void *d){
    Player *j=(Player *)d;
    setPlayerName(j,GetStringEntry(strEntry));
    addScore(*j);
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


/*
	Fonction de callback, appelée lorsque l'utilisateur clique sur une carte.
	Appelle les fonctions du module jeu pour jouer les coups. Affiche graphiquement 
	le resultat de chaque coup.
	Quand deux cartes sont révélées, l'utilisateur peut observer leur valeur, 
	et doit cliquer à nouveau pour les remettre face cachée ou pour valider la paire. 

	*data : pointeur sur type Carte, contient la carte du Widget qui à été cliqué.
*/
void retournerCarte(Widget w, int which_button, int x, int y, void *data){

    //Si la partie est terminée : pas d'action
    if (screen->board->etape == TERMINE){
    	fenetreDeFin();
        return;
        // exit(EXIT_SUCCESS);
    }

    //Si la carte est déjà révélée : pas d'action
    if (((Card *)data)->mode == DECOUVERTE ){
    	printf("Carte déja révélée\n");
    	return;
    }
    int areaWidth, areaHeight;
    GetDrawAreaSize(&areaWidth,&areaHeight);

    if (screen->board->etape == VERIFICATION){
    	printf("Verification\n");
    	if (!verifierCoup(screen->board)){;
	    	SetDrawArea(widget1);
	        hide(areaWidth,areaHeight);
	    	SetDrawArea(widget2);
	        hide(areaWidth,areaHeight);
	    }
    }
    else{
    	if (((Card *)data)->mode == RETOURNEE){
    		printf("Carte déjà retournée, choisissez une autre carte\n");
    		return;
    	}
    	show(w,areaWidth,areaHeight, data);
        if (screen->board->etape == CARTE1) widget1=w;
        else widget2=w;
        jouerCoup(screen->board,data);
    }
}
