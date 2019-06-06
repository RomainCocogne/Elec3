#include "callbacks.h"

Widget card1Widget;
Widget card2Widget;

void quit(Widget w, void *d)
{
    exit(EXIT_SUCCESS);
}

/*
	A quoi elle sert du coup ?	
*/
void replay(Widget w, void *d){
    // SetCurrentWindow(GetTopWidget(w));
    // game->etape=MENU;
    // free(screen->game->TabCartes);
    // initJeu(screen->game,screen->fact);
    // initAffichage(screen->game, screen->grilleWidth, screen->grilleHeight);
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
	Quand deux cartes sont révélées, l'utilisateur peut observer leur valeur.
	Au prochain clic, le coup est verifié. Si la paire est juste, les cartes restent retournées, 
	sinon la paire est remise face cachée. 

	*data : pointeur sur type Carte, contient la carte du Widget qui à été cliqué.
*/
void retournerCarte(Widget w, int which_button, int x, int y, void *data){

	//Recupere les dimensions de la carte
    int areaWidth, areaHeight;
    GetDrawAreaSize(&areaWidth,&areaHeight);

    //Si deux cartes ont déjà été révélées, effectue la verification avant tout autre action
    if (screen->game->etape == VERIFICATION){
    	printf("Verification\n");
    	if (!verifierCoup(screen->game)){
	    	SetDrawArea(card1Widget);
	        hide(areaWidth,areaHeight);
	    	SetDrawArea(card2Widget);
	        hide(areaWidth,areaHeight);
	    }
    }

    //Si la partie est terminée, afiche la fenêtre de fin
    if (screen->game->etape == TERMINE){
    	fenetreDeFin();
        return;
    }

    /*La partie est toujours*/

    //Si la carte est déjà decouverte: pas d'action
    if (((Card *)data)->mode == DECOUVERTE){
    	printf("Carte déja découverte\n");
    	return;
    }

    /*La carte cliquée n'a pas encore été découverte*/ 

    //Si la carte est déjà retournée : pas d'action
	if (((Card *)data)->mode == RETOURNEE){
		printf("Carte déjà retournée, choisissez une autre carte\n");
		return;
	}
    
    /*
    	La partie est toujours en cours, la carte n'a pas encore été découverte 
    	et n'est pas déjà retournée.
		L'utilisateur a donc cliqué une carte valide : on joue le coup
    */
	SetDrawArea(w);
	show(w,areaWidth,areaHeight, data);
	//Enregistrement du widget cliqué
    if (screen->game->etape == CARTE1) 
    	card1Widget=w;
    else 
    	card2Widget=w;
    jouerCoup(screen->game,data);
}
