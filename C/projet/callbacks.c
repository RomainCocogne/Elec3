#include "callbacks.h"

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


void setSize(Widget w, void *d){
	char *str=(char*)d;
	screen->grilleWidth=str[0]-'0';
	screen->grilleHeight=str[1]-'0';
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


    //Si la carte est déjà révélée : pas d'action
    if (((Card *)data)->mode == DECOUVERTE ){
    	printf("Carte déja révélée\n");
    	return;
    }
    int areaWidth, areaHeight;
    GetDrawAreaSize(&areaWidth,&areaHeight);

    if (screen->board->etape == VERIFICATION){
    	printf("Verification\n");
    	if (!verifierCoup(screen->board)){
	    	SetDrawArea(card1);
	        hide(areaWidth,areaHeight);
	    	SetDrawArea(card2);
	        hide(areaWidth,areaHeight);
	    }
    }
    if(screen->board->etape == CARTE1 || screen->board->etape == CARTE2){
    	SetDrawArea(w);
    	if (((Card *)data)->mode == RETOURNEE){
    		printf("Carte déjà retournée, choisissez une autre carte\n");
    		return;
    	}
    	show(w,areaWidth,areaHeight, data);
        if (screen->board->etape == CARTE1) card1=w;
        else card2=w;
        jouerCoup(screen->board,data);
    }
    //Si la partie est terminée 
    if (screen->board->etape == TERMINE){
    	fenetreDeFin();
        return;
        // exit(EXIT_SUCCESS);
    }
}
