#include "test.h"
#include "shuffle.h"

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
        if (mode == RETOURNEE){
            SetColor(gris); 
            DrawFilledBox(0,0,card_width,card_height);
            setCardMode(data,CACHEE);
        }
    }

}

void initJeuCartes(Card *TabCartes,int nbCartes){
    for(int i=0; i<nbCartes/2; i+=1){
         initCard(TabCartes+2*i,i,0,0);
         initCard(TabCartes+2*i+1,i,0,0);
    }
    shuffle(TabCartes,nbCartes,sizeof(Card));
}

void initDrawArea(Widget w, int width, int height, void *data){
    SetColor(gris);
    DrawFilledBox(0,0,width,height);
    card_width = width;
    card_height = height;
}

void initAffichage(Card *tabCartes, int grilleWidth, int grilleHeight){
    Widget tabWidget[grilleHeight*grilleWidth];

    for (int k=0; k<grilleHeight*grilleWidth;k++){
        tabWidget[k] = MakeDrawArea(card_width,card_height,initDrawArea,tabCartes+k);
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






