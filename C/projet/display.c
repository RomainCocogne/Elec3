/*
  Module contenant tous les outils pour gerer l'affichage de menus et d'une partie de memory.
*/

#include "display.h"

/*
  Variable globale d'affichage contenant les données necessaires pour representer la partie
*/
display *screen;


/*
  chaines de caracteres constantes
*/
const char * rules_str= "The cards are layed in rows, face down.\nTurn over any two cards.If the two cards match,they are kept shown.\nIf they don't match,they are turned back over.\nRemember what was on each card and where it was.\n\nThe game is over when all the cards have been matched and revealed.\nTo register your score, click again anywhere on the screen.";
const char * start_str= " The game starts now !\n\n\n\n";


/*****************************
    initialisation
*****************************/


/*
  Initialise la variable globale d'affichage screen 
*/
void initGlobalDisplay(){
  screen=malloc(sizeof(display));
  screen->game=malloc(sizeof(Jeu));
  screen->grilleWidth=DEFAULT_GRILLEWIDTH;
  screen->grilleHeight=DEFAULT_GRILLEHEIGHT;
  screen->hide_next_move = NO;
}

/*
  Fonction d'initialisation des couleurs utilisées pour la partie. 
*/
void initCouleurs(){

// On distingue les couleurs du background des couleurs utilisees dans les cartes
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

/*
  Initialisation des bouttons de navigation présent sur toute les fenetres
*/
void initButtonBox(){
  Widget return_button, quit_button;
  return_button=MakeButton("\n          Menu          \n\n", menu,NULL);
  quit_button=MakeButton("\n          Quit          \n\n",quit,NULL);

  SetWidgetPos(quit_button,PLACE_UNDER,return_button,NO_CARE,NULL);
}

/*
  Initialisation du panel informatif adjacent à l'espace de jeu.
  Est utilisé pour communiquer au joueur toute sortes d'informations sur la partie en cours
*/
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

  updateInfoBox(start_str);   //on initialise le message de la box avec la constante initialisee au debut
}
/*
  Initialisation du message informatif communiquant au joueur la difficulté courante du jeu.
  @args:
    - pos1: position par rapport au widget suivant. positions valides: meme que libsx (PLACE_UNDER, PLACE_RIGHT,NO_CARE)
    - w1: widget de reference a la premiere position
    - pos2: position par rapport au second widget
    - w2: widget de reference a la seconde position
*/
void initDiffBox(int pos1, Widget w1, int pos2, Widget w2){
  screen->infoDiffLabel=MakeLabel(NULL);
  SetWidgetPos(screen->infoDiffLabel,pos1,w1,pos2,w2);
  updateDiffBox();
}

/*
  cree une nouvelle fenetre apres avoir fermee la fenetre courante.
  @args: 
    - c: nom de la nouvelle fenetre
*/
void newWindow(char *c){
  Widget w;
  CloseWindow();   //on ferme la fenetre precedante
  w=MakeWindow(c,NULL,NONEXCLUSIVE_WINDOW);   
  SetCurrentWindow(w);
}

/*****************************
    rafraichissement
*****************************/

/*
  Rafraichissent les elements initialisés dans initInfoBox et initDiffBox respectivement.
  updateInfoBox vous permet de choisir le message a afficher.
  updateDiffBox n'est pas parametrable
*/
void updateInfoBox(const char *infoBoxMsg){
  char strPairesRestantes[26];    //on prend 25 car le message fait 25 caracteres (plus 1 si on a un nombre a 2 chiffres de paires)
  sprintf(strPairesRestantes,"%d pair(s) left to match",screen->game->nbCartesRestantes/2);
  SetLabel(screen->pairesRestantesLabel,strPairesRestantes);
  SetLabel(screen->infoBoxLabel,(char *)infoBoxMsg); 
}
void updateDiffBox(){
	char diff[27]; //27 caracteres car le message en fait 27 (la difficultee n'est qu'a 1x1 chiffre)
	sprintf(diff,"(Current Difficulty: %dx%d)",screen->grilleWidth,screen->grilleHeight);
	SetLabel(screen->infoDiffLabel,diff);
}


/*****************************
      fenetres
*****************************/

/*
  Demarre une partie et affiche le plateau de jeu.
  Genere un widget DrawArea pour chaque carte (soit grilleWidth x grilleHeight widgets).
  Associe à chaque widget la carte correspondante, la fonction d'affichage, et la fonction d'action 
  lorsque l'on clique sur la carte.
*/
void startGame(){
  newWindow("game");  

  Widget form_game, form_right_panel, form_infobox;
  form_game=MakeForm(TOP_LEVEL_FORM); //on utilise les form (de libsx) pour compartimenter le jeu et la navigation

  initJeu(screen->game,screen->grilleWidth*screen->grilleHeight);               //initialisation du jeu                                                              

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


  //Initialise les boites d'affichage a droite du plateau
  form_right_panel=MakeForm(TOP_LEVEL_FORM);
  initButtonBox();
  form_infobox=MakeForm(TOP_LEVEL_FORM);
  initInfoBox();

  SetWidgetPos(form_right_panel,PLACE_RIGHT,form_game,NO_CARE,NULL);
  SetWidgetPos(form_infobox,PLACE_RIGHT,form_game,PLACE_UNDER,form_right_panel);

  ShowDisplay();
}

/*
  Cree et affiche la fenetre contenant le menu du jeu.
  Ferme la fenetre precedante.
  Donne acces via callbacks aux fenetres de jeu, des scores et des regles.
*/
void menu(){
  newWindow("menu");

  //widgets
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

  //pop_up d'affichage des regles
  rulesButton=MakeButton("Rules",rules,NULL);

  //creation des boutons.
  highest_scores=MakeButton("Highest_scores",printScores,NULL);
  start=MakeButton("Start",startGame,NULL);
  quit_button=MakeButton("Quit", quit,NULL);

  //menu difficulte.
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
  initDiffBox(PLACE_UNDER, difficulty,PLACE_RIGHT,diff_4x4);  //positionnement du message sur la difficulte courante

  ShowDisplay(); 
}

/*
  Cree et affiche le fenetre de fin.
  Si le score du joueur est suffisant, on lui propose de le sauvegarder.
  Ferme la fenetre precedante.
*/
void fenetreDeFin(){
  newWindow("Congratulations !");

  Widget form_end_game, form_right_panel;

  int *sc=malloc(sizeof(int));  //on utilise un pointeur pour le callback
  *sc=genereScore(screen->game->nbCoups, screen->game->nbCartes); //on recupere le score

  char str[4];
  sprintf(str,"%d",*sc); //passage en char*

  	form_end_game=MakeForm(TOP_LEVEL_FORM);
  Widget congrats = MakeLabel("Your score is :");
  Widget score = MakeLabel(str);

  SetWidgetPos(score,PLACE_UNDER,congrats,NO_CARE,NULL);

  //Si le score est trop mauvais et qu'il n'y a plus de place, on ne propose pas d'enregistrer le score
  if(*sc>=getLastScore() || nbScores()<MAX_SCORE){
      Widget nomJoueur = MakeStringEntry("name",MAX_NAME,NULL,NULL);
      screen->strEntry=nomJoueur;
      Widget boutonEnregistrer = MakeButton("Save score",saveScoreCallback,sc);
      SetWidgetPos(nomJoueur,PLACE_UNDER,score,NO_CARE,NULL);
      SetWidgetPos(boutonEnregistrer,PLACE_UNDER,nomJoueur,NO_CARE,NULL);
  }

  else{
  	Widget too_bad;
  	too_bad=MakeLabel("(Not enough to be registered)");
  	SetWidgetPos(too_bad,PLACE_UNDER,score,NO_CARE,NULL);
  }

  form_right_panel=MakeForm(TOP_LEVEL_FORM);    //boutons de navigation
  initButtonBox();
  SetWidgetPos(form_right_panel,PLACE_RIGHT,form_end_game,NO_CARE,NULL);

  ShowDisplay();
}

/*
  Cree et affiche la fenetre des regles avec les boutons de navigation.
  Ferme la fenetre precedante.
*/
void rules (Widget w,void *d){
  newWindow("rules");

  Widget label_rules, form_rules, form_right_panel;

  form_rules=MakeForm(TOP_LEVEL_FORM);        //regles
  label_rules=MakeLabel((char *)rules_str);
  SetWidgetPos(label_rules,NO_CARE,NULL,NO_CARE,NULL);

  form_right_panel=MakeForm(TOP_LEVEL_FORM);  //boutons de navigation
  initButtonBox();

  SetWidgetPos(form_right_panel,PLACE_RIGHT,form_rules,NO_CARE,NULL);
  ShowDisplay();
  
}

/*
  Cree et affiche la fenetre des scores.
  Les scores sont tries du plus meilleur au pire.
  Ferme la fenetre precedante.
*/
void printScores(){
	newWindow("hight scores");

	Widget label_scores, form_hight_score, form_right_panel;

  form_hight_score=MakeForm(TOP_LEVEL_FORM);

//liste de joueurs pour stocker les scores
	Liste joueurs;
	initListe(&joueurs);
	getScore(&joueurs);  //on recupere tout les scores
	
	char strJoueurs[(longueur(joueurs)+1)*sizeof(char)*MAX_NAME*2]; //on va stocker les scores dans une seule chaine de caracteres
//si il y a bien des scores	
  if(longueur(joueurs)>0){
		sprintf(strJoueurs,"%s : %d\n",((Player *)ieme(joueurs,1))->name,((Player *)ieme(joueurs,1))->score);
		for(int i=2; i<=longueur(joueurs); i++){ //ajout de tout les scores a strJoueurs
			char temp[sizeof(char)*MAX_NAME*2];
		  sprintf(temp,"%s : %d\n",((Player *)ieme(joueurs,i))->name,((Player *)ieme(joueurs,i))->score);
			strcat(strJoueurs,temp);
		}
	}
//sinon, on affiche un message
	else{
		strcpy(strJoueurs,"No hight score yet.");
	}

	label_scores=MakeLabel(strJoueurs);
	SetWidgetPos(label_scores,NO_CARE,NULL,NO_CARE,NULL);

	form_right_panel=MakeForm(TOP_LEVEL_FORM); //boutons de navigation
  initButtonBox();

  SetWidgetPos(form_right_panel,PLACE_RIGHT,form_hight_score,NO_CARE,NULL);

	ShowDisplay();
}
