
#include "forme.h"
#include <math.h>


void arrayXPointcpy(XPoint *f1, XPoint *f2,int size){
	for (int i = 0; i < size; ++i)
	{
		f1[i].x=f2[i].x; f1[i].y=f2[i].y;
	}
}



void genereforme(Forme *forme, int f, int w, int h){
	forme->w=w/2; forme->h=h/2;
	forme->f=f;
	createXPointArray(forme);
}

void createXPointArray(Forme *forme){
	switch(forme->f){
		case CARRE:;
		int len= (forme->w < forme->h ? forme->w: forme->h)/2;
		forme->size=4;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint carre[4]={{forme->w-len,forme->h-len},{forme->w-len,forme->h+len},{forme->w+len,forme->h+len},{forme->w+len,forme->h-len}};
		arrayXPointcpy(forme->ptarray,carre,forme->size);
		break;

		case ROND:
		forme->size=360;
		int rad= (forme->w < forme->h ? forme->w: forme->h)/2;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint rond[360];
		for (int i = 0; i < 360; ++i) {
			rond[i].x=rad*cos((double)(i)*M_PI/180)+forme->w;
			rond[i].y=rad*sin((double)(i)*M_PI/180)+forme->h;
			// printf("%d:%d\n", rond[i].x,rond[i].y);
		}
		arrayXPointcpy(forme->ptarray,rond,forme->size);
		break;

		case TRIANGLE:
		forme->size=3; 
		int cote= (forme->w < forme->h ? forme->w: forme->h)/2;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint triangle[3]={{forme->w,forme->h-cote},{forme->w+cote,forme->h+cote},{forme->w-cote,forme->h+cote}};
		arrayXPointcpy(forme->ptarray,triangle,forme->size);
		break;

		case ETOILE:
		forme->size=8;
		int pointe= (forme->w < forme->h ? forme->w: forme->h)/2;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint etoile[8]={{forme->w,forme->h-pointe*3/2},{forme->w+pointe,forme->h+pointe/2},{forme->w-pointe,forme->h+pointe/2},{forme->w,forme->h-pointe*3/2},
						  {forme->w,forme->h+pointe},{forme->w+pointe,forme->h-pointe},{forme->w-pointe,forme->h-pointe},{forme->w,forme->h+pointe}};
		arrayXPointcpy(forme->ptarray,etoile,forme->size);
		break;

		default:
		forme->size=1;
		forme->ptarray=calloc(forme->size,sizeof(XPoint));
		XPoint null[1]={{0,0}};
		arrayXPointcpy(forme->ptarray,null,forme->size);
	}
}
















