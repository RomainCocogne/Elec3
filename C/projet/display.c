#include "display.h"

void quit(Widget w, void *d)
{
    exit(EXIT_SUCCESS);
}


void replay(Widget w, void *d){
    // SetCurrentWindow(GetTopWidget(w));
    CloseWindow();
    CloseWindow();
    // board->etape=MENU;
    free(screen->board->TabCartes);
    // initJeu(screen->board,screen->fact);
    // initAffichage(screen->board, screen->grilleWidth, screen->grilleHeight);
    init_display(0, 0, NULL);
}

/**************/

void hide (int width, int height){
	SetColor(screen->color[0]);
    DrawFilledBox(0,0,width,height);
}

void show(Widget w, int width, int height, void *data){
	SetColor(screen->color[1]);
    DrawFilledBox(0,0,width,height);
    SetColor(screen->color[0]);
    SetBgColor(w,screen->color[1]);
    Forme forme;
    genereforme(&forme,((Card *)data)->f%NB_FORMES,width,height);
    int couleur[]={screen->color[2],screen->color[3],screen->color[4],screen->color[5],screen->color[3],screen->color[4],screen->color[5],screen->color[2],screen->color[4],screen->color[5],screen->color[2],screen->color[3],screen->color[5],screen->color[2],screen->color[3],screen->color[4]};
    SetFgColor(w,couleur[((Card *)data)->f]);
    DrawFilledPolygon(forme.ptarray,forme.size);
    free(forme.ptarray);
}

/*
	Fonction de callback des zones de dessin qui représentent les cartes. 
	Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
	chaque fois que l'utilisateur change la taille de la fenêtre
*/
void displayDrawArea(Widget w, int width, int height, void *data){
    if (((Card *)data)->mode >= RETOURNEE)
        show(w,width, height, data);
    else
        hide(width,height);
}


/***********/


void genereGame(){
    initJeu(screen->board,GRILLEWIDTH*GRILLEHEIGHT);               //initialisation du jeu
    initAffichage(screen->board, GRILLEWIDTH, GRILLEHEIGHT);       //initialisation de l'affichage
    CloseWindow();
    Widget window;
    window=MakeWindow("game",NULL,NONEXCLUSIVE_WINDOW);
    SetCurrentWindow(window);
    Widget tabWidget[screen->fact];

    for (int k=0; k<screen->grilleHeight*screen->grilleWidth;k++){
        tabWidget[k] = MakeDrawArea(DEFAULT_CARD_WIDTH,DEFAULT_CARD_HEIGHT,displayDrawArea,screen->board->TabCartes+k);
        SetButtonDownCB(tabWidget[k],retournerCarte);
    }

    Widget yposWidget = NULL;
    Widget xposWidget = NULL;

    int i,j, right=NO_CARE, under=NO_CARE;
    for (i = 0; i < screen->grilleHeight; ++i)
    {
        for (j = 0; j < screen->grilleWidth; ++j)
        {
            SetWidgetPos(tabWidget[i*screen->grilleWidth + j], right, xposWidget, under, yposWidget);
            xposWidget = tabWidget[i*screen->grilleWidth + j];
            right = PLACE_RIGHT;
        }
        if (i*screen->grilleWidth+j < screen->grilleHeight*screen->grilleWidth) 
            yposWidget = tabWidget[i*screen->grilleWidth];
        right = NO_CARE;
        under = PLACE_UNDER; 
    }
    ShowDisplay();
}


void fenetreDeFin(){
    int sc=(int)((double)(screen->board->nbCoups)/screen->fact*1000);
    MakeWindow(NULL,SAME_DISPLAY,EXCLUSIVE_WINDOW);
    Widget congrats = MakeLabel("Felicitations, vous avez gagne !\nVotre score est :");
    char str[4];
    sprintf(str,"%d",sc);
    Widget score = MakeLabel(str);
    Widget boutonRejouer = MakeButton("\n     Rejouer      \n\n",replay,NULL);
    Widget boutonQuitter = MakeButton("\n     Quitter      \n\n",quit,NULL); 
    SetWidgetPos(score,PLACE_UNDER,congrats,NO_CARE,NULL);
    SetWidgetPos(boutonRejouer,PLACE_UNDER,score,NO_CARE,NULL);
    SetWidgetPos(boutonQuitter,PLACE_UNDER,score,PLACE_RIGHT,boutonRejouer);
    if(sc<=getLastScore() || nbScores()<10){
        Widget nomJoueur = MakeStringEntry("Votre Nom",MAX_NAME,NULL,NULL);
        strEntry=nomJoueur;
        Player *joueur=malloc(sizeof(Player));
        initPlayer(joueur);
        setPlayerScore(joueur,sc);
        Widget boutonEnregistrer = MakeButton("Enregister le score",saveScore,joueur);
        SetWidgetPos(nomJoueur,PLACE_UNDER,boutonRejouer,NO_CARE,NULL);
        SetWidgetPos(boutonEnregistrer,PLACE_UNDER,nomJoueur,NO_CARE,NULL);
    }
    // free(screen);
    ShowDisplay();
    MainLoop();
}