/*
	header du module de la pile
	pour la calculatrice
*/

#ifndef _PILE_H_ 	//pour ne pas inclure le fichier plusieurs fois
#define _PILE_H_



/****************************/
//			types 			//
/****************************/
typedef struct noeud					//structure suivant le principe de la structure chainee
{
	struct noeud *suivant;
	int val;
} * Pile;

/****************************/
//		  variables			//
/****************************/
extern const Pile PileVide;				//pile vide elementaire

/****************************/
//		  fonctions			//
/****************************/
int estVide(Pile pile);					//verifie si la pile est vide
void empiler(Pile *pile, int val);		//ajouter un entier au sommet de la pile
void depiler(Pile *pile);				//enlever l'element au sommet de la pile
int sommet(Pile pile);					//renvoie la valeur presente au sommet de la pile

#endif