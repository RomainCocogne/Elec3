/*
	implementation des fonctions du module forme
*/
#include "forme.h"
#include <math.h>

/*
	copie un ensemble de points dont le nombre est specifie
	dans une autre chaine de points
	la chaine receptrice doit etre plus grande
	et elle doit etre vide
*/
void arrayXPointcpy(XPoint *f1, XPoint *f2,int size){
	for (int i = 0; i < size; ++i)
	{
		f1[i].x=f2[i].x; f1[i].y=f2[i].y; 			//copie des coordonnees une par une
	}
}

/*
	cree une chaine de points dessinant la forme choisie
	et la stock dans la Forme
	l'objet Forme doit avoir f,h et w initialises
*/
void createXPointArray(Forme *forme){

	int len= (forme->w < forme->h ? forme->w: forme->h)/2;			//pour eviter de deformer les formes

	switch(forme->f){												//on choisit une forme differente en fonction de f

		case CARRE:;
		forme->size=4;												//un carre a 4 angles 

		forme->ptarray=calloc(forme->size,sizeof(XPoint));			/**/
		XPoint carre[4]={{forme->w-len,forme->h-len},				//
						 {forme->w-len,forme->h+len},				// on dessine un carre par rapport a l'origine
						 {forme->w+len,forme->h+len},				//
						 {forme->w+len,forme->h-len}};				/**/

		arrayXPointcpy(forme->ptarray,carre,forme->size);			//on copie le carre dans la chaine de points de 'forme'
		break;

		case ROND:;
		forme->size=360;											//on fait un point par degres du cercle
		
		forme->ptarray=calloc(forme->size,sizeof(XPoint));			/**/
		XPoint rond[360];											//
		for (int i = 0; i < 360; ++i) {								// on dessine un rond par rapport a l'origine
			rond[i].x=len*cos((double)(i)*M_PI/180)+forme->w;		// on a un point par degres
			rond[i].y=len*sin((double)(i)*M_PI/180)+forme->h;		//
		}															/**/

		arrayXPointcpy(forme->ptarray,rond,forme->size);			//on copie le rond dans la chaine de points de 'forme'
		break;

		case TRIANGLE:;
		forme->size=3; 												//un triangle a 3 angles

		forme->ptarray=calloc(forme->size,sizeof(XPoint));			/**/
		XPoint triangle[3]={{forme->w,forme->h-len},				// on dessine les 3 sommets par rapport a l'origine
							{forme->w+len,forme->h+len},			//
							{forme->w-len,forme->h+len}};			/**/

		arrayXPointcpy(forme->ptarray,triangle,forme->size);		//on copie le triangle dans la chaine de points de 'forme'

		break;

		case ETOILE:;
		forme->size=8;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint etoile[8]={{forme->w,forme->h-len},
						  {forme->w+len,forme->h+len/2},
						  {forme->w-len,forme->h+len/2},
						  {forme->w,forme->h-len},
						  {forme->w,forme->h+len},
						  {forme->w+len,forme->h-len/2},
						  {forme->w-len,forme->h-len/2},
						  {forme->w,forme->h+len}};
		arrayXPointcpy(forme->ptarray,etoile,forme->size);
		break;

		default:;
		forme->size=1;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint null[1]={{0,0}};
		arrayXPointcpy(forme->ptarray,null,forme->size);
	}
}

/*
	initialise un objet de type Forme
	en lui assignant un tableau de points 
	correspondant au nom de la forme fournie
	la hauteur et la largeur doivent etre renseignes
*/
void genereforme(Forme *forme, int f, int w, int h){
	forme->w=w/2; forme->h=h/2;
	forme->f=f;
	createXPointArray(forme);
}













