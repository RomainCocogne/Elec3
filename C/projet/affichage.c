#include "affichage.h"

// Pour la couleur des cartes
int gris;
int blanc;
Jeu *board;
Widget widget1;
Widget widget2;

char *forme[] = { "Carre", "Rond", "Triangle", "Etoile", "Losange", "Ellipse" ,NULL };


void displayDrawArea(Widget w, int width, int height, void *data){
    SetColor(gris);
    DrawFilledBox(0,0,width,height);
}

void initAffichage(Jeu *jeu, int grilleWidth, int grilleHeight){
    board = jeu; //Enregistre l'addresse du jeu pour pouvoir la modifier plus tard 
    Widget tabWidget[grilleWidth*grilleHeight];

    for (int k=0; k<grilleHeight*grilleWidth;k++){
        tabWidget[k] = MakeDrawArea(DEFAULT_CARD_WIDTH,DEFAULT_CARD_HEIGHT,displayDrawArea,jeu->TabCartes+k);
        SetButtonDownCB(tabWidget[k],retournerCarte);
    }

    Widget yposWidget = NULL;
    Widget xposWidget = NULL;

    int i,j, right=NO_CARE, under=NO_CARE;
    for (i = 0; i < grilleHeight; ++i)
    {
        for (j = 0; j < grilleWidth; ++j)
        {
            SetWidgetPos(tabWidget[i*grilleWidth + j], right, xposWidget, under, yposWidget);
            xposWidget = tabWidget[i*grilleWidth + j];
            right = PLACE_RIGHT;
        }
        if (i*grilleWidth+j < grilleHeight*grilleWidth) yposWidget = tabWidget[i*grilleWidth];
        right = NO_CARE;
        under = PLACE_UNDER; 
    }
}

void retournerCarte(Widget w, int which_button, int x, int y, void *data){
    if (((Card *)data)->mode == DECOUVERTE ){
    	printf("Carte déja révélée\n");
    	return;
    }
    int areaWidth, areaHeight;
    GetDrawAreaSize(&areaWidth,&areaHeight);
    if (board->etape == VERIFICATION){
    	printf("Verification\n");
    	if (!verifierCoup(board)){;
	    	SetDrawArea(widget1);
	        SetColor(gris); 
	        DrawFilledBox(0,0,areaWidth,areaHeight);
	    	SetDrawArea(widget2);
	        SetColor(gris); 
	        DrawFilledBox(0,0,areaWidth,areaHeight);
	    }
    }
    else{
    	SetDrawArea(w);
        SetColor(blanc);
        DrawFilledBox(0,0,areaWidth,areaHeight);
        SetColor(gris);
        SetBgColor(w,blanc);
        DrawText(forme[getCardForme(*(Card *)data)],areaWidth/2,areaHeight/2);
        if (board->etape == CARTE1) widget1=w;
        else widget2=w;
        jouerCoup(board,data);
    }
}

	