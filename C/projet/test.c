#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <string.h>
#include "carte.h"

<<<<<<< Updated upstream
#define DEFAULT_CARD_WIDTH 100
#define DEFAULT_CARD_HEIGHT 200

//Pour la couleur des cartes
int gris;
int blanc;
int card_width;
int card_height; 
=======
// #define CARD_WIDTH 50
// #define CARD_HEIGHT 100

// //Pour la couleur des cartes
// int gris;
// int blanc; 

// // void redisplay(Widget w, int width, int height, void *data){
// //     DrawImage((char*)data,0,0,iWidth,iHeight);
// // }

// void retournerCarte(Widget w, int which_button, int x, int y, void *data){
//     SetDrawArea(w);
//     int mode = getCardMode(data);
//     if (mode == CACHEE){
//         char str[3];
//         sprintf(str,"%d",getCardId(data));
//         printf("%s\n",str );
//         SetColor(blanc);
//         SetBgColor(w,gris);
//         DrawText(str,CARD_WIDTH/2,CARD_HEIGHT/2);
//         setCardMode(data,RETOURNEE);
//     }
//     else{
//         SetColor(gris); 
//         DrawFilledBox(0,0,CARD_WIDTH,CARD_HEIGHT);
//         setCardMode(data,CACHEE);
//     }

// }

// void initJeuCartes(Card *TabCartes,int nbCartes){
//     for (int k=0; k<nbCartes; k++){
//         initCard(TabCartes+k,k,CACHEE);
//     }
// }
>>>>>>> Stashed changes

// void initDrawArea(Widget w, int width, int height, void *data){
//     SetColor(gris);
//     // SetWidgetFont(w,GetFont("comicSansMS"));
//     DrawFilledBox(0,0,CARD_WIDTH,CARD_HEIGHT);
<<<<<<< Updated upstream
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
=======
// }

// void initAffichage(Card *tabCartes, int grilleWidth, int grilleHeight){
//     Widget tabWidget[grilleHeight*grilleWidth];

//     for (int k=0; k<grilleHeight*grilleWidth;k++){
//         tabWidget[k] = MakeDrawArea(CARD_WIDTH,CARD_HEIGHT,initDrawArea,tabCartes+k);
//         SetButtonDownCB(tabWidget[k],retournerCarte);
//         // initDrawArea(tabWidget[k]);
//     }

//     Widget yposWidget = NULL;
//     Widget xposWidget = NULL;

//     int i,j, right=NO_CARE, under=NO_CARE;
//     for (i = 0; i < grilleHeight; ++i)
//     {

//         for (j = 0; j < grilleWidth; ++j)
//         {
//             SetWidgetPos(tabWidget[i*grilleWidth + j], right, xposWidget, under, yposWidget);
//             xposWidget = tabWidget[i*grilleWidth + j];
//             right = PLACE_RIGHT;
//         }
//         if (i*grilleWidth+j < grilleHeight*grilleWidth) yposWidget = tabWidget[i*grilleWidth];
//         right = NO_CARE;
//         under = PLACE_UNDER; 
//     }
// }

// int main(int argc, char *argv[])
// {

// 	if (OpenDisplay(argc, argv)==0){
// 		fprintf(stderr, "Can't open display\n");
// 		return EXIT_FAILURE;
// 	}
>>>>>>> Stashed changes
    
//     int grilleWidth = 7;
//     int grilleHeight = 4;
//     int size = grilleWidth*grilleHeight;

//     Card tabCartes[size];
//     initJeuCartes(tabCartes,size);

<<<<<<< Updated upstream
	GetStandardColors();
    gris = GetRGBColor(20,20,20);
    blanc = GetRGBColor(250,250,250);
    initAffichage(tabCartes, grilleWidth, grilleHeight);
=======
// 	GetStandardColors();
//     gris = GetRGBColor(20,20,20);
//     blanc = GetRGBColor(230,230,230);
//     initAffichage(tabCartes, grilleWidth, grilleHeight);
>>>>>>> Stashed changes
    
// 	ShowDisplay();
// 	MainLoop();

// 	return 0;
// }




