/*
	Module de gestion de l'affichage du jeu. 
	Gere les clics de l'utilisateur et gére les actions de jeu associées
	à ces clics
*/
#include "affichage.h"

/*
	Variables pour l'accés à l'etat actuel du jeu
	- wigdets : contient les widgets des cartes qui doivent êtres retournées 
	 			à la prochaine verification 
    - board : contient tous les paramètres necessaires la logique du jeu
*/

display *screen;
Widget widget1;
Widget widget2;
Widget strEntry;



void saveScore(Widget w, void *d){
    Player *j=(Player *)d;
    setPlayerName(j,GetStringEntry(strEntry));
    addScore(*j);
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
    if (screen->board->etape == TERMINE){
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

    if (screen->board->etape == VERIFICATION){
    	printf("Verification\n");
    	if (!verifierCoup(screen->board)){;
	    	SetDrawArea(widget1);
	        SetColor(screen->color[0]); 
	        DrawFilledBox(0,0,areaWidth,areaHeight);
	    	SetDrawArea(widget2);
	        SetColor(screen->color[0]); 
	        DrawFilledBox(0,0,areaWidth,areaHeight);
	    }
    }
    else{
    	if (((Card *)data)->mode == RETOURNEE){
    		printf("Carte déjà retournée, choisissez une autre carte\n");
    		return;
    	}
    	SetDrawArea(w);
        SetColor(screen->color[1]);
        DrawFilledBox(0,0,areaWidth,areaHeight);
        SetColor(screen->color[0]);
        SetBgColor(w,screen->color[1]);
        // DrawText(forme[((Card *)data)->f],areaWidth/2,areaHeight/2);
        Forme forme;
        genereforme(&forme,((Card *)data)->f%NB_FORMES,areaWidth,areaHeight);
        int couleur[]={screen->color[2],screen->color[3],screen->color[4],screen->color[5],screen->color[3],screen->color[4],screen->color[5],screen->color[2],screen->color[4],screen->color[5],screen->color[2],screen->color[3],screen->color[5],screen->color[2],screen->color[3],screen->color[4]};
        SetFgColor(w,couleur[((Card *)data)->f]);
        DrawFilledPolygon(forme.ptarray,forme.size);
        if (screen->board->etape == CARTE1) widget1=w;
        else widget2=w;
        jouerCoup(screen->board,data);
        free(forme.ptarray);
    }
}
