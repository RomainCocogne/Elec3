#include "display.h"
#include "player.h"

Widget strEntry;
display *screen;


const char * rules_str= "The cards are layed in rows, face down.\nTurn over any two cards.If the two cards match,they are kept shown.\nIf they don't match,they are turned back over.\nRemember what was on each card and where it was.\n\nThe game is over when all the cards have been matched and revealed.\nTo register your score, click again anywhere on the screen.";



void initGlobalDisplay(){
    screen=malloc(sizeof(display));
    screen->game=malloc(sizeof(Jeu));
    screen->grilleWidth=DEFUALT_GRILLEWIDTH;
    screen->grilleHeight=DEFUALT_GRILLEHEIGHT;
}

void hide (int width, int height){
    SetColor(getBgColor(0));
    DrawFilledBox(0,0,width,height);
}

void show(Widget w, int width, int height, void *data){
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

void sidePanel(){
    Widget return_button, quit_button;
    return_button=MakeButton("menu", menu,NULL);
    quit_button=MakeButton("quit",quit,NULL);
    SetWidgetPos(quit_button,PLACE_UNDER,return_button,NO_CARE,NULL);
}

void newWindow(char *c){
    Widget w;
    CloseWindow();
    w=MakeWindow(c,NULL,NONEXCLUSIVE_WINDOW);
    SetCurrentWindow(w);
}

/*
	Fonction de callback des zones de dessin qui représentent les cartes. 
	Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
	chaque fois que l'utilisateur change la taille de la fenêtre

  data : pointeur vers la structure carte associée au widget ayant appelé cette fonction
*/
void displayDrawArea(Widget w, int width, int height, void *data){
    if (((Card *)data)->mode >= RETOURNEE)
        show(w,width, height, data);
    else
        hide(width,height);
}


/***********/

/*
  Genere un widget DrawArea pour chaque carte (soit grilleWidth x grilleHeight widgets).
  Associe à chaque widget la carte correspondante, la fonction d'affichage, et la fonction d'action 
  lorsque l'on clique sur la carte.
*/
void startGame(){
    newWindow("game");

    Widget form_game, form_right_panel;
    form_game=MakeForm(TOP_LEVEL_FORM);

    initJeu(screen->game,screen->grilleWidth*screen->grilleHeight);               //initialisation du jeu
    initAffichage(screen->grilleWidth, screen->grilleHeight);       //initialisation de l'affichage

    Widget tabWidget[screen->grilleWidth*screen->grilleHeight];

    //Genere le tableau de widgets en associant chaque widget à une carte
    //Le widget d'indice k dans tabWidget est associé à la carte d'incie k dans TabCartes 
    for (int k=0; k<screen->grilleHeight*screen->grilleWidth;k++){
        tabWidget[k] = MakeDrawArea(DEFAULT_CARD_WIDTH,DEFAULT_CARD_HEIGHT,displayDrawArea,screen->game->TabCartes+k);
        SetButtonDownCB(tabWidget[k],retournerCarte);
    }

    //Place les widgets de tabWidget dans la zone de jeu
    //Les widgets sont placés dans l'ordre croissant des indices du tableau, 
    //de gauche à droite puis de haut en bas
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

    form_right_panel=MakeForm(TOP_LEVEL_FORM);
    sidePanel();
    SetWidgetPos(form_right_panel,PLACE_RIGHT,form_game,NO_CARE,NULL);
    ShowDisplay();


}


void fenetreDeFin(){
	newWindow("congratulation !");

    size_t sc=(int)((0.5+1.0/(double)(screen->game->nbCoups))*(screen->grilleWidth*screen->grilleHeight)*100);
    Widget congrats = MakeLabel("Congratulation ! you won ! \nyour score is :");
    char str[4];
    sprintf(str,"%ld",sc);
    Widget score = MakeLabel(str);
    Widget boutonRejouer = MakeButton("\n     menu      \n\n",menu,NULL);
    Widget boutonQuitter = MakeButton("\n     quit      \n\n",quit,NULL); 
    SetWidgetPos(score,PLACE_UNDER,congrats,NO_CARE,NULL);
   
    if(sc>=getLastScore() || nbScores()<10){
        Widget nomJoueur = MakeStringEntry("name",MAX_NAME,NULL,NULL);
        strEntry=nomJoueur;
        Player *joueur=malloc(sizeof(Player));
        initPlayer(joueur);
        setPlayerScore(joueur,sc);
        Widget boutonEnregistrer = MakeButton("Save score",saveScore,joueur);
        SetWidgetPos(nomJoueur,PLACE_UNDER,score,NO_CARE,NULL);
        SetWidgetPos(boutonEnregistrer,PLACE_UNDER,nomJoueur,NO_CARE,NULL);
        SetWidgetPos(boutonRejouer,PLACE_UNDER,boutonEnregistrer,NO_CARE,NULL);
        SetWidgetPos(boutonQuitter,PLACE_UNDER,boutonEnregistrer,PLACE_RIGHT,boutonRejouer);
    }

    else{
    	Widget too_bad;
    	too_bad=MakeLabel("Too bad ! your score isn't good enough to be registered :(");
    	SetWidgetPos(too_bad,PLACE_UNDER,score,NO_CARE,NULL);
    	SetWidgetPos(boutonRejouer,PLACE_UNDER,too_bad,NO_CARE,NULL);
    	SetWidgetPos(boutonQuitter,PLACE_UNDER,too_bad,PLACE_RIGHT,boutonRejouer);
    }
    ShowDisplay();
}



void menu(){
  newWindow("menu");
  Widget welcome,highest_scores,rules,difficulty,
  		 diff_3x2,diff_4x3,diff_4x4,diff_5x4,diff_6x5,diff_8x4,
  		 start,quit_button,
  		 space1,space2,space3,space4 ;

  //labels.
  welcome=MakeLabel("Welcome to MEMORY");
  difficulty=MakeLabel("Difficulty:");
  space1=MakeLabel("");
  space2=MakeLabel("");
  space3=MakeLabel("                  ");
  space4=MakeLabel("        ");

  //pop_up d'affichage des régles
  rules=MakeButton("Rules",ruler,NULL);

  //création des boutons.
  highest_scores=MakeButton("Highest_scores",printScores,NULL);
  start=MakeButton("Start",startGame,NULL);
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
	Fonction d'initialisation des paramétres graphiques de la partie. 
	   -grilleWidth, grilleHeight : largeur et hauteur de la grille en nombre de cartes
*/
void initAffichage(int grilleWidth, int grilleHeight){
    //Initialisation des variables globales de dimension
    screen->grilleWidth = grilleWidth;
    screen->grilleHeight = grilleHeight;

    int bgColor[2], cardColor[4];
    bgColor[0]   = GetRGBColor(40,40,40);
    bgColor[1]   = GetRGBColor(230,230,230);
    cardColor[0] = GetRGBColor(20,20,180);
    cardColor[1] = GetRGBColor(180,20,20) ;
    cardColor[2] = GetRGBColor(20,180,20);
    cardColor[3] = GetRGBColor(220,130,20);

    initBgColor(bgColor, 2);
    initCardColor(cardColor,4);
}

void ruler (Widget w,void *d){
	newWindow("rules");
	Widget label_rules, form_rules, form_under_panel;
	form_rules=MakeForm(TOP_LEVEL_FORM);
	label_rules=MakeLabel((char *)rules_str);
	SetWidgetPos(label_rules,NO_CARE,NULL,NO_CARE,NULL);

	form_under_panel=MakeForm(TOP_LEVEL_FORM);
    
    sidePanel();

    SetWidgetPos(form_under_panel,PLACE_RIGHT,form_rules,NO_CARE,NULL);
	ShowDisplay();
  
}

void printScores(Widget w, void *d){
	newWindow("hight scores");
	Widget label_scores, form_hight_score, form_under_panel;
  	form_hight_score=MakeForm(TOP_LEVEL_FORM);
	Liste joueurs;
	initListe(&joueurs);
	getScore(&joueurs);
	// printf("%s\n",((Player *)ieme(joueurs,1))->name);

	char strJoueurs[(longueur(joueurs)+1)*sizeof(char)*MAX_NAME*2];
	if(longueur(joueurs)>0){
		sprintf(strJoueurs,"%s : %d\n",((Player *)ieme(joueurs,1))->name,((Player *)ieme(joueurs,1))->score);
		for(int i=2; i<=longueur(joueurs); i++){
			char temp[sizeof(char)*MAX_NAME*2];
		    sprintf(temp,"%s : %d\n",((Player *)ieme(joueurs,i))->name,((Player *)ieme(joueurs,i))->score);

			strcat(strJoueurs,temp);
		}
	}
	else{
		strcpy(strJoueurs,"No hight score yet.");
	}
  	label_scores=MakeLabel(strJoueurs);
  	SetWidgetPos(label_scores,NO_CARE,NULL,NO_CARE,NULL);

  	form_under_panel=MakeForm(TOP_LEVEL_FORM);
    
    sidePanel();

    SetWidgetPos(form_under_panel,PLACE_RIGHT,form_hight_score,NO_CARE,NULL);
  	ShowDisplay();
}
