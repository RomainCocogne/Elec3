/*
	header du module du type liste
	pour la pile
*/

#pragma once



/****************************/
//			types 			//
/****************************/
typedef struct noeud					//structure suivant le principe de la structure chainee
{
	struct noeud *suivant;
	void *val;
} * Liste;

/****************************/
//		  variables			//
/****************************/
extern const Liste ListeVide;				//liste vide elementaire

/****************************/
//		  fonctions			//
/****************************/
void initListe (Liste *l,void *f);					//cree un nouvel element qui pointe vers une liste
int longueur (Liste l);						//renvoie le nombre de formes dans la liste
void *ieme (Liste l, int r);					//renvoie l element a la ieme position
void inserer (Liste *l, int r, void *f);		//insere element f au rang r
void supprimer (Liste *l, int r);			//supprime l element f an rang r


