#include "display.h"
#include "player.h"


Widget strEntry;
display *screen;
Widget widget1;
Widget widget2;

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
    genereforme(&forme,((Card *)data)->id%NB_FORMES,width,height);
    int couleur[]={screen->color[2],screen->color[3],screen->color[4],screen->color[5],screen->color[3],screen->color[4],screen->color[5],screen->color[2],screen->color[4],screen->color[5],screen->color[2],screen->color[3],screen->color[5],screen->color[2],screen->color[3],screen->color[4]};
    SetFgColor(w,couleur[((Card *)data)->id]);
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



void init_display(int argc, char *argv[], void *d){
  // CloseWindow();
  Widget window;
  window=MakeWindow("menu",NULL,NONEXCLUSIVE_WINDOW);
  SetCurrentWindow(window);
  Widget welcome,highest_scores,rules,difficulty,diff_3x2,diff_4x3,diff_4x4,diff_5x4,diff_6x5,diff_8x4,start,quit_button,space1,space2,space3,space4 ;

  //labels.
  welcome=MakeLabel("Welcome to MEMORY");
  difficulty=MakeLabel("Difficulty:");
  space1=MakeLabel("");
  space2=MakeLabel("");
  space3=MakeLabel("                  ");
  space4=MakeLabel("        ");

  //création de pop_up.
  rules=MakeButton("Rules",ruler,NULL);

  //création des boutons.
  highest_scores=MakeButton("Highest_scores",printScores,NULL);
  start=MakeButton("Start",genereGame,NULL);
  quit_button=MakeButton("Quit", quit,NULL);

  //menu difficulté.
  diff_3x2=MakeButton("3x2",setSize,"32");
  diff_4x3=MakeButton("4x3",setSize,"43");
  diff_4x4=MakeButton("4x4",setSize,"44");
  diff_5x4=MakeButton("5x4",setSize,"54");
  diff_6x5=MakeButton("6x5",setSize,"65");
  diff_8x4=MakeButton("8x4",setSize,"84");

  //position des widgets.
  SetWidgetPos(highest_scores,PLACE_UNDER,welcome,NO_CARE,NULL);
  SetWidgetPos(space4,PLACE_UNDER,welcome,PLACE_RIGHT,highest_scores);
  SetWidgetPos(rules,PLACE_RIGHT,space4,PLACE_UNDER,welcome);
  SetWidgetPos(space1,PLACE_UNDER,highest_scores,NO_CARE,NULL);
  SetWidgetPos(difficulty,PLACE_UNDER,space1,NO_CARE,NULL);
  SetWidgetPos(diff_3x2,PLACE_UNDER,difficulty,NO_CARE,NULL);
  SetWidgetPos(diff_4x3,PLACE_RIGHT,diff_3x2,PLACE_UNDER,difficulty);
  SetWidgetPos(diff_4x4,PLACE_RIGHT,diff_4x3,PLACE_UNDER,difficulty);
  SetWidgetPos(diff_5x4,PLACE_UNDER,diff_3x2,NO_CARE,NULL);
  SetWidgetPos(diff_6x5,PLACE_RIGHT,diff_5x4,PLACE_UNDER,diff_4x3);
  SetWidgetPos(diff_8x4,PLACE_RIGHT,diff_6x5,PLACE_UNDER,diff_4x4);
  SetWidgetPos(space2,PLACE_UNDER,diff_5x4,NO_CARE,NULL);
  SetWidgetPos(start,PLACE_UNDER,space2,NO_CARE,NULL);
  SetWidgetPos(space3,PLACE_RIGHT,start,PLACE_UNDER,space2);
  SetWidgetPos(quit_button,PLACE_RIGHT,space3,PLACE_UNDER,space2);

  ShowDisplay(); 
}

/*
	Fonction d'initialisation graphique de la partie. 
	Genere un widget DrawArea pour chaque carte (soit grilleWidth x grilleHeight widgets).
	Associe à chaque widget la carte correspondante, la fonction d'affichage, et la fonction d'action 
	lorsque l'on clique sur la carte. 

	-jeu : un type Jeu initialisé au préalable
	-grilleWidth, grilleHeight : largeur et hauteur de la grille en nombre de cartes
*/
void initAffichage(Jeu *jeu, int grilleWidth, int grilleHeight){
    screen=malloc(sizeof(display));
    //Initialisation des variables globales
    screen->fact=grilleWidth*grilleHeight;
    screen->grilleWidth = grilleWidth;
    screen->grilleHeight = grilleHeight;
    screen->board = jeu; 

    GetStandardColors();
    screen->color[0] = GetRGBColor(40,40,40);
    screen->color[1] = GetRGBColor(230,230,230);
    screen->color[2] = GetRGBColor(20,20,180);
    screen->color[3] = GetRGBColor(180,20,20) ;
    screen->color[4] = GetRGBColor(20,180,20);
    screen->color[5] = GetRGBColor(220,130,20);
}
