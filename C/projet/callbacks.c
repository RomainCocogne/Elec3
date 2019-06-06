#include "callbacks.h"

char * rules_str= " The cards are layed in rows, face down.\n Turn over any two cards.If the two cards match,they are kept shown.\n If they don't match,they are turned back over if you click anywhere on the screen.\n Remember what was on each card and where it was.\n The game is over when all the cards have been matched and revealed";

void quit(Widget w, void *d)
{
    exit(EXIT_SUCCESS);
}


void replay(Widget w, void *d){
    // SetCurrentWindow(GetTopWidget(w));
    // board->etape=MENU;
    // free(screen->board->TabCartes);
    // initJeu(screen->board,screen->fact);
    // initAffichage(screen->board, screen->grilleWidth, screen->grilleHeight);
    menu();
}

void saveScore(Widget w, void *d){
    Player *j=(Player *)d;
    setPlayerName(j,GetStringEntry(strEntry));
    addScore(*j);
}

void ruler (Widget w,void *d){
	newWindow("rules");
	Widget label_rules, form_rules, form_under_panel;
	form_rules=MakeForm(TOP_LEVEL_FORM);
	label_rules=MakeLabel(rules_str);
	SetWidgetPos(label_rules,NO_CARE,NULL,NO_CARE,NULL);

	form_under_panel=MakeForm(TOP_LEVEL_FORM);
    
    sidePanel();

    SetWidgetPos(form_under_panel,PLACE_RIGHT,form_rules,NO_CARE,NULL);
	ShowDisplay();
  
}

void setSize(Widget w, void *d){
	char *str=(char*)d;
	screen->grilleWidth=str[0]-'0';
	screen->grilleHeight=str[1]-'0';
}

void printScores(Widget w, void *d){
	newWindow("hight scores");
	Widget label_scores, form_hight_score, form_under_panel;
  	form_hight_score=MakeForm(TOP_LEVEL_FORM);
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
  	label_scores=MakeLabel(strJoueurs);
  	SetWidgetPos(label_scores,NO_CARE,NULL,NO_CARE,NULL);

  	form_under_panel=MakeForm(TOP_LEVEL_FORM);
    
    sidePanel();

    SetWidgetPos(form_under_panel,PLACE_RIGHT,form_hight_score,NO_CARE,NULL);
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
	    	SetDrawArea(card1);
	        hide(areaWidth,areaHeight);
	    	SetDrawArea(card2);
	        hide(areaWidth,areaHeight);
	    }
    }
    else{
    	if (((Card *)data)->mode == RETOURNEE){
    		printf("Carte déjà retournée, choisissez une autre carte\n");
    		return;
    	}
    	show(w,areaWidth,areaHeight, data);
        if (screen->board->etape == CARTE1) card1=w;
        else card2=w;
        jouerCoup(screen->board,data);
    }
}
