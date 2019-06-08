#include "display.h"


display *screen;


const char * rules_str= "The cards are layed in rows, face down.\nTurn over any two cards.If the two cards match,they are kept shown.\nIf they don't match,they are turned back over.\nRemember what was on each card and where it was.\n\nThe game is over when all the cards have been matched and revealed.\nTo register your score, click again anywhere on the screen.";
const char * start_str= " The game starts now !\n\n\n\n";


void initGlobalDisplay(){
    screen=malloc(sizeof(display));
    screen->game=malloc(sizeof(Jeu));
    screen->grilleWidth=DEFUALT_GRILLEWIDTH;
    screen->grilleHeight=DEFUALT_GRILLEHEIGHT;
    screen->hide_next_move = NO;
}

/*
  Fonction d'initialisation des couleurs utilisées pour la partie. 
*/
void initCouleurs(){

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

void initButtonBox(){
    Widget return_button, quit_button;
    return_button=MakeButton("\n          Menu          \n\n", menu,NULL);
    quit_button=MakeButton("\n          Quit          \n\n",quit,NULL);

    SetWidgetPos(quit_button,PLACE_UNDER,return_button,NO_CARE,NULL);
}

void initInfoBox(){
    Widget verticalSpace1, verticalSpace2;

    verticalSpace1=MakeLabel("\n");
    screen->pairesRestantesLabel = MakeLabel(NULL);
    verticalSpace2=MakeLabel("\n");
    screen->infoBoxLabel=MakeLabel(NULL);

    SetWidgetPos(verticalSpace1, NO_CARE, NULL, NO_CARE, NULL);
    SetWidgetPos(screen->pairesRestantesLabel, PLACE_UNDER, verticalSpace1, NO_CARE, NULL);
    SetWidgetPos(verticalSpace2, PLACE_UNDER, screen->pairesRestantesLabel, NO_CARE, NULL);
    SetWidgetPos(screen->infoBoxLabel,PLACE_UNDER,verticalSpace2,NO_CARE,NULL);

    updateInfoBox(start_str);
}


void updateInfoBox(const char *infoBoxMsg){
    char strPairesRestantes[25];
    sprintf(strPairesRestantes,"%d pair(s) left to match",screen->game->nbCartesRestantes/2);
    SetLabel(screen->pairesRestantesLabel,strPairesRestantes);
    SetLabel(screen->infoBoxLabel,(char *)infoBoxMsg); 
}

void initDiffBox(int pos1, Widget w1, int pos2, Widget w2){
	screen->infoDiffLabel=MakeLabel(NULL);
	SetWidgetPos(screen->infoDiffLabel,pos1,w1,pos2,w2);
  updateDiffBox();
}

void updateDiffBox(){
	char diff[27];
	sprintf(diff,"(Current Difficulty: %dx%d)",screen->grilleWidth,screen->grilleHeight);
	SetLabel(screen->infoDiffLabel,diff);
}

void newWindow(char *c){
    Widget w;
    CloseWindow();
    w=MakeWindow(c,NULL,NONEXCLUSIVE_WINDOW);
    SetCurrentWindow(w);
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



/*
  Genere un widget DrawArea pour chaque carte (soit grilleWidth x grilleHeight widgets).
  Associe à chaque widget la carte correspondante, la fonction d'affichage, et la fonction d'action 
  lorsque l'on clique sur la carte.
*/
void startGame(){
    newWindow("game");

    Widget form_game, form_right_panel, form_infobox;
    form_game=MakeForm(TOP_LEVEL_FORM);

    initJeu(screen->game,screen->grilleWidth*screen->grilleHeight);               //initialisation du jeu
    initCouleurs();       //initialisation de l'affichage

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
    Widget yposWidget = NULL; //Widget de reference pour le placement vertical
    Widget xposWidget = NULL; //Widget de reference pour le placement horizontal

    int i,j, right=NO_CARE, under=NO_CARE;
    for (i = 0; i < screen->grilleHeight; ++i)
    {
        //Les widgets des i premiéres lignes sont placés
        for (j = 0; j < screen->grilleWidth; ++j)
        {
            //pour la ligne courante, les j premiers widgets sont placés
            SetWidgetPos(tabWidget[i*screen->grilleWidth + j], right, xposWidget, under, yposWidget);
            xposWidget = tabWidget[i*screen->grilleWidth + j];
            right = PLACE_RIGHT;
        }
        //Les widgets de la ligne courante sont tous placés. 
        //Le widget de reference verticale devient le dernier widget de la ligne courante

        if (i*screen->grilleWidth+j < screen->grilleHeight*screen->grilleWidth) 
            yposWidget = tabWidget[i*screen->grilleWidth];
        right = NO_CARE;
        under = PLACE_UNDER; 
    }


    //Initialise 
    form_right_panel=MakeForm(TOP_LEVEL_FORM);
    initButtonBox();
    form_infobox=MakeForm(TOP_LEVEL_FORM);
    initInfoBox();
    
    SetWidgetPos(form_right_panel,PLACE_RIGHT,form_game,NO_CARE,NULL);
    SetWidgetPos(form_infobox,PLACE_RIGHT,form_game,PLACE_UNDER,form_right_panel);

    ShowDisplay();
}


void fenetreDeFin(){
    newWindow("Congratulations !");
    Widget form_end_game, form_right_panel;
    size_t sc=genereScore(*(screen->game));
    char str[4];
    sprintf(str,"%ld",sc);

   	form_end_game=MakeForm(TOP_LEVEL_FORM);
    Widget congrats = MakeLabel("Your score is :");
    Widget score = MakeLabel(str);

    SetWidgetPos(score,PLACE_UNDER,congrats,NO_CARE,NULL);

    if(sc>=getLastScore() || nbScores()<10){
        Widget nomJoueur = MakeStringEntry("name",MAX_NAME,NULL,NULL);
        screen->strEntry=nomJoueur;
        Player *joueur=malloc(sizeof(Player));
        initPlayer(joueur);
        setPlayerScore(joueur,sc);
        Widget boutonEnregistrer = MakeButton("Save score",saveScore,joueur);
        SetWidgetPos(nomJoueur,PLACE_UNDER,score,NO_CARE,NULL);
        SetWidgetPos(boutonEnregistrer,PLACE_UNDER,nomJoueur,NO_CARE,NULL);
    }

    else{
    	Widget too_bad;
    	too_bad=MakeLabel("(Not enough to be registered)");
    	SetWidgetPos(too_bad,PLACE_UNDER,score,NO_CARE,NULL);}
    form_right_panel=MakeForm(TOP_LEVEL_FORM);
    initButtonBox();
    SetWidgetPos(form_right_panel,PLACE_RIGHT,form_end_game,NO_CARE,NULL);
    ShowDisplay();
}



void menu(){
  newWindow("menu");
  Widget welcome,highest_scores,rulesButton,difficulty,
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
  rulesButton=MakeButton("Rules",rules,NULL);

  //création des boutons.
  highest_scores=MakeButton("Highest_scores",printScores,NULL);
  start=MakeButton("Start",startGame,NULL);
  quit_button=MakeButton("Quit", quit,NULL);

  //menu difficulté.
  diff_3x2=MakeToggle("3x2",FALSE, NULL, setSize,"32");
  diff_4x3=MakeToggle("4x3",FALSE, diff_3x2, setSize,"43");
  diff_4x4=MakeToggle("4x4",FALSE, diff_3x2, setSize,"44");
  diff_5x4=MakeToggle("5x4",FALSE, diff_3x2, setSize,"54");
  diff_6x5=MakeToggle("7x4",FALSE, diff_3x2, setSize,"74");
  diff_8x4=MakeToggle("8x4",FALSE, diff_3x2, setSize,"84");

  //position des widgets.
  SetWidgetPos(highest_scores,PLACE_UNDER,welcome,NO_CARE,NULL);
  SetWidgetPos(space4,PLACE_UNDER,welcome,PLACE_RIGHT,highest_scores);
  SetWidgetPos(rulesButton,PLACE_RIGHT,space4,PLACE_UNDER,welcome);
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
  initDiffBox(PLACE_UNDER, difficulty,PLACE_RIGHT,diff_4x4);

  ShowDisplay(); 
}



void rules (Widget w,void *d){
	newWindow("rules");
	Widget label_rules, form_rules, form_right_panel;
	form_rules=MakeForm(TOP_LEVEL_FORM);
	label_rules=MakeLabel((char *)rules_str);
	SetWidgetPos(label_rules,NO_CARE,NULL,NO_CARE,NULL);

	form_right_panel=MakeForm(TOP_LEVEL_FORM);
    
    initButtonBox();

    SetWidgetPos(form_right_panel,PLACE_RIGHT,form_rules,NO_CARE,NULL);
	ShowDisplay();
  
}

void printScores(Widget w, void *d){
	newWindow("hight scores");
	Widget label_scores, form_hight_score, form_right_panel;
  	form_hight_score=MakeForm(TOP_LEVEL_FORM);
	Liste joueurs;
	initListe(&joueurs);
	getScore(&joueurs);
	
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

  	form_right_panel=MakeForm(TOP_LEVEL_FORM);
    
    initButtonBox();

    SetWidgetPos(form_right_panel,PLACE_RIGHT,form_hight_score,NO_CARE,NULL);
  	ShowDisplay();
}
