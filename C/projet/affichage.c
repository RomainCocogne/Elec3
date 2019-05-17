#include "affichage.h"

//Pour la couleur des cartes
int gris;
int blanc;


char *forme[] = { "Carre", "Rond", "Triangle", "Etoile", "Losange", "Ellipse" ,NULL };


void displayDrawArea(Widget w, int width, int height, void *data){
    SetColor(gris);
    DrawFilledBox(0,0,width,height);
}

void initAffichage(Card *tabCartes, int grilleWidth, int grilleHeight){
    Widget tabWidget[grilleHeight*grilleWidth];

    for (int k=0; k<grilleHeight*grilleWidth;k++){
        tabWidget[k] = MakeDrawArea(DEFAULT_CARD_WIDTH,DEFAULT_CARD_HEIGHT,displayDrawArea,tabCartes+k);
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
    SetDrawArea(w);
    int areaWidth, areaHeight;
    GetDrawAreaSize(&areaWidth,&areaHeight);
    int mode = getCardMode(data);
    if (mode == CACHEE){
        SetColor(blanc);
        DrawFilledBox(0,0,areaWidth,areaHeight);
        SetColor(gris);
        SetBgColor(w,blanc);
        DrawText(forme[getCardForme(data)],areaWidth/2,areaHeight/2);
        setCardMode(data,RETOURNEE);
    }
    else{
        if (mode == RETOURNEE){
            SetColor(gris); 
            DrawFilledBox(0,0,areaWidth,areaHeight);
            setCardMode(data,CACHEE);
        }
    }
}

