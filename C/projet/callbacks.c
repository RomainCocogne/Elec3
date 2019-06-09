/*
	Module contenant les fonctions de callback non graphiques.
*/

#include "callbacks.h"

/*
  Callback pour quitter le programme
*/
void quit()
{
	free(screen->game);
	free(screen);
    exit(EXIT_SUCCESS);
}

/*
	Fonction appellée par le bouton SaveScore. 
	Enregistre le score sous le nom contenu dans strEntry
*/
void saveScoreCallback(Widget w, void *d){
	saveScore(GetStringEntry(screen->strEntry),*((int*)d));
    printScores();
}

/*
	Fonction appellée par les boutons de changement de difficulté
	Assigne la difficulté selectionnée à la partie.
*/
void setSize(Widget w, void *d){
	char *str=(char*)d;
	assert(!(((str[0]-'0')*(str[1]-'0'))&1));
	screen->grilleWidth=str[0]-'0';
	screen->grilleHeight=str[1]-'0';
	updateDiffBox();
}



/*
	Fonction appelée lorsque l'utilisateur clique sur une carte.
	Appelle les fonctions du module jeu pour jouer les coups. Affiche graphiquement 
	le resultat de chaque coup.
	Quand deux cartes sont révélées, le coup est verifié est l'infobox est mise à jour.
	Si la paire est juste, les cartes restent face visible. Sinon, elles seront retournées face cachée au prochain coup
	sinon la paire est remise face cachée. 
	Si la derniére paire à été retournée, l'ecran de fin s'affiche au prochain clic.

	*data : pointeur sur type Carte, contient la carte associée au Widget qui à été cliqué.
*/
void retournerCarte(Widget w, int which_button, int x, int y, void *data){

	//Si le clic n'est pas un clic gauche, aucune action.
	if (which_button != 1)
		return;

	//Si la partie est terminée et que l'utilisateur a cliqué a nouveau, afiche la fenêtre de fin.
    if (screen->game->etape == TERMINE){
    	fenetreDeFin();
        return;
    }

	//Recupere les dimensions de la carte
    int areaWidth, areaHeight;
    GetDrawAreaSize(&areaWidth,&areaHeight);

    //Si deu cartes ont été retournées et doivent être remises face cachée
    if(screen->hide_next_move){
		SetDrawArea(screen->card1Widget);
		hideCard(areaWidth,areaHeight);
		SetDrawArea(screen->card2Widget);
		hideCard(areaWidth,areaHeight);
		SetDrawArea(w);   
		screen->hide_next_move=NO; 	
    }

    /*La partie est toujours en cours*/

    //Si la carte est déjà decouverte: pas d'action
    if (((Card *)data)->mode == DECOUVERTE){
    	updateInfoBox("Card already matched !");
    	return;
    }

    /*La carte cliquée n'a pas encore été découverte*/ 

    //Si la carte est déjà retournée : pas d'action
	if (((Card *)data)->mode == RETOURNEE){
		updateInfoBox("Card already picked !");
		return;
	}
    
    /*
    	La partie est toujours en cours, la carte n'a pas encore été découverte 
    	et n'est pas déjà retournée.
		L'utilisateur a donc cliqué une carte valide : on joue le coup
    */

    //Affichage de la carte correspondante
	showCard(w,areaWidth,areaHeight, data);

	//Enregistrement du widget cliqué
    if (screen->game->etape == CARTE1)
    	//La carte cliquée est la premiére des deux cartes 
    	screen->card1Widget=w;
    else 
    	//Lacarte cliquée est la deuxiéme carte
    	screen->card2Widget=w;

    jouerCoup(screen->game,data);
    

    //Si deux cartes ont été révélées, effectue la verification.
    if (screen->game->etape == VERIFICATION){
    	//Verification de la paire selectionnée
    	if (verifierCoup(screen->game)){
    		updateInfoBox("You found a pair !");
    	}
    	else{
	    	screen->hide_next_move=YES;
	    	updateInfoBox("Wrong pair !");
	    }
    
	    //Aprés verification du coup, si la partie est terminée, indique à l'utilisateur qu'il faut cliquer à nouveau pour finir la partie
	    if (screen->game->etape == TERMINE){
	    	updateInfoBox("Game is finished! \nClick again to see\nyour score");
	    }
	}
}


void hideCard(int width, int height){
    SetColor(getBgColor(0));
    DrawFilledBox(0,0,width,height);
}

void showCard(Widget w, int width, int height, void *data){
    SetColor(getBgColor(1));
    DrawFilledBox(0,0,width,height);
    SetColor(getBgColor(0));
    SetBgColor(w,getBgColor(1));
    Forme forme;
    genereforme(&forme,((Card *)data)->id%NB_FORMES,width,height);
    SetFgColor(w,getLoopedCardColor(((Card *)data)->id));
    DrawFilledPolygon(forme.ptarray,forme.size);
    free(forme.ptarray);
}

/*
	Fonction de callback des zones de dessin qui représentent les cartes. 
	Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
	chaque fois que l'utilisateur change la taille de la fenêtre

  data : pointeur vers la structure carte associée au widget ayant appelé cette fonction
*/
void displayDrawArea(Widget w, int width, int height, void *data){
    if (((Card *)data)->mode >= RETOURNEE)
        showCard(w,width, height, data);
    else
        hideCard(width,height);
}

