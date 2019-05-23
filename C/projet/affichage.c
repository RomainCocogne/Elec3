/*
	Module de gestion de l'affichage du jeu. 
	Gere les clics de l'utilisateur et gére les actions de jeu associées
	à ces clics
*/
#include "affichage.h"
#include "forme.h"
#include "player.h"

/* 
	Variables pour accés rapide aux couleurs prédéfinies 
*/
int gris;
int blanc;
int bleu;
int rouge;
int vert;
int orange;

/*
	Variables pour l'accés à l'etat actuel du jeu
	- board : contient tous les paramètres necessaires la logique du jeu, 
			  est passé au fonctions du module "jeu"
	- wigdets : contient les widgets des cartes qui doivent êtres retournées 
	 			à la prochaine verification 
*/
Jeu *board;
Widget widget1;
Widget widget2;


/* Formes à afficher pour identifier graphiquement les cartes */
//Trouver comment comment en faire un const sans faire de warning
#define NB_FORMES 4
char *forme[] = { "Carre", "Rond", "Triangle", "Etoile", "Losange", "Ellipse" ,NULL };

void quit(Widget w, void *d)
{
    exit(EXIT_SUCCESS);
}

/*
	Fonction de callback des zones de dessin qui représentent les cartes. 
	Appelée une premiére fois par chaque zone lors du premier affichage, puis rappelée à 
	chaque fois que l'utilisateur change la taille de la fenêtre
*/
void displayDrawArea(Widget w, int width, int height, void *data){
    if (((Card *)data)->mode >= RETOURNEE) {
        SetColor(blanc);
        DrawFilledBox(0,0,width,height);
        SetColor(gris);
        SetBgColor(w,blanc);
        // DrawText(forme[((Card *)data)->f],width/2,height/2);
        Forme forme;
        genereforme(&forme,((Card *)data)->f%NB_FORMES,width,height);
        int couleur[]={bleu,rouge,vert,orange,rouge,vert,orange,bleu,vert,orange,bleu,rouge,orange,bleu,rouge,vert};
        SetFgColor(w,couleur[((Card *)data)->f]);
        DrawFilledPolygon(forme.ptarray,forme.size);
    }
    else{
        SetColor(gris);
        DrawFilledBox(0,0,width,height);
    }
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
    //Initialisation de la variable globale
    board = jeu; 
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
        if (i*grilleWidth+j < grilleHeight*grilleWidth) 
        	yposWidget = tabWidget[i*grilleWidth];
        right = NO_CARE;
        under = PLACE_UNDER; 
    }
}


void fenetreDeFin(){
    MakeWindow(NULL,SAME_DISPLAY,EXCLUSIVE_WINDOW);
    Widget congrats = MakeLabel("Felicitations, vous avez gagne !\nVotre score est :");
    char str[4];
    sprintf(str,"%d",board->nbCoups);
    Widget score = MakeLabel(str);
    Widget boutonRejouer = MakeButton("\n     Rejouer      \n\n",NULL,NULL);
    Widget boutonQuitter = MakeButton("\n     Quitter      \n\n",quit,NULL); 
    SetWidgetPos(score,PLACE_UNDER,congrats,NO_CARE,NULL);
    SetWidgetPos(boutonRejouer,PLACE_UNDER,score,NO_CARE,NULL);
    SetWidgetPos(boutonQuitter,PLACE_UNDER,score,PLACE_RIGHT,boutonRejouer);
    if(board->nbCoups<=getLastScore() || nbScores()<10){
        Widget nomJoueur = MakeStringEntry("Votre Nom",400,NULL,NULL);
        Widget boutonEnregistrer = MakeButton("Enregister le score",NULL,NULL);
        SetWidgetPos(nomJoueur,PLACE_UNDER,boutonRejouer,NO_CARE,NULL);
        SetWidgetPos(boutonEnregistrer,PLACE_UNDER,nomJoueur,NO_CARE,NULL);
    }
    ShowDisplay();
    MainLoop();
}

/*
	Fonction de callback, appelée lorsque l'utilisateur clique sur une carte.
	Appelle les fonctions du module jeu pour jouer les coups. Affiche graphiquement 
	le resultat de chaque coup.
	Quand deux cartes sont révélées, l'utilisateur peut observer leur valeur, 
	et doit cliquer à nouveau pour les remettre face cachée ou pour valider la paire. 

	*data : pointeur sur type Carte, contient la carte du Widget qui à été cliqué.
*/
void retournerCarte(Widget w, int which_button, int x, int y, void *data){
    //Si la partie est terminée : pas d'action
    if (board->etape == TERMINE){
    	fenetreDeFin();
        return;
        // exit(EXIT_SUCCESS);
    }

    //Si la carte est déjà révélée : pas d'action
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
    	if (((Card *)data)->mode == RETOURNEE){
    		printf("Carte déjà retournée, choisissez une autre carte\n");
    		return;
    	}
    	SetDrawArea(w);
        SetColor(blanc);
        DrawFilledBox(0,0,areaWidth,areaHeight);
        SetColor(gris);
        SetBgColor(w,blanc);
        // DrawText(forme[((Card *)data)->f],areaWidth/2,areaHeight/2);
        Forme forme;
        genereforme(&forme,((Card *)data)->f%NB_FORMES,areaWidth,areaHeight);
        int couleur[]={bleu,rouge,vert,orange,rouge,vert,orange,bleu,vert,orange,bleu,rouge,orange,bleu,rouge,vert};
        SetFgColor(w,couleur[((Card *)data)->f]);
        DrawFilledPolygon(forme.ptarray,forme.size);
        if (board->etape == CARTE1) widget1=w;
        else widget2=w;
        jouerCoup(board,data);
    }
}

