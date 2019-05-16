#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include "carte.h"

#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 200

//Pour la couleur des cartes
int gris;
int blanc;
int card_width;
int card_height; 

// void redisplay(Widget w, int width, int height, void *data){
//     DrawImage((char*)data,0,0,iWidth,iHeight);
// }

void retournerCarte(Widget w, int which_button, int x, int y, void *data){
    SetDrawArea(w);
    int mode = getCardMode(data);
    if (mode == CACHEE){
        char str[3];
        sprintf(str,"%d",getCardId(data));
        printf("%s\n",str );
        SetColor(blanc);
        DrawFilledBox(0,0,card_width,card_height);
        SetColor(gris);
        SetBgColor(w,blanc);
        DrawText(str,card_width/2,card_height/2);
        setCardMode(data,RETOURNEE);
    }
    else{
        SetColor(gris); 
        DrawFilledBox(0,0,card_width,card_height);
        setCardMode(data,CACHEE);
    }

}

void initJeuCartes(Card *TabCartes,int nbCartes){
    for (int k=0; k<nbCartes; k++){
        initCard(TabCartes+k,k,CACHEE);
    }
}

void initDrawArea(Widget w, int width, int height, void *data){
    SetColor(gris);
    // SetWidgetFont(w,GetFont("comicSansMS"));
    DrawFilledBox(0,0,width,height);
    card_width = width;
    card_height = height;
}

void initAffichage(Card *tabCartes, int grilleWidth, int grilleHeight){
    Widget tabWidget[grilleHeight*grilleWidth];

    for (int k=0; k<grilleHeight*grilleWidth;k++){
        tabWidget[k] = MakeDrawArea(card_width,card_height,initDrawArea,tabCartes+k);
        SetButtonDownCB(tabWidget[k],retournerCarte);
        // initDrawArea(tabWidget[k]);
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

int main(int argc, char *argv[])
{
    card_height = DEFAULT_CARD_HEIGHT;
    card_width = DEFAULT_CARD_WIDTH;

	if (OpenDisplay(argc, argv)==0){
		fprintf(stderr, "Can't open display\n");
		return EXIT_FAILURE;
	}
    
    int grilleWidth = 7;
    int grilleHeight = 4;
    int size = grilleWidth*grilleHeight;

    Card tabCartes[size];
    initJeuCartes(tabCartes,size);

	GetStandardColors();
    gris = GetRGBColor(20,20,20);
    blanc = GetRGBColor(250,250,250);
    initAffichage(tabCartes, grilleWidth, grilleHeight);
    
	ShowDisplay();
	MainLoop();

	return 0;
}




