/*
	implementation des fonctions du module couleur.h
*/
#include "couleur.h"

Tab *couleurBg;
Tab *couleurCard;

/*
	initialise la variable globale couleurBg
	@args:
		- c: Pointeur sur int tableau qui va remplir couleurBg
		- size: size_t la taille de ce tableau
*/
void initBgColor(int *c, size_t size){
	couleurBg=malloc(sizeof(Tab));
	couleurBg->len=size;
	couleurBg->tab=malloc(sizeof(int)*size);
	for (int i = 0; i < size; ++i)
		couleurBg->tab[i]=c[i];
}

/*
	initialise la variable globale couleurCard
	@args:
		- c: Pointeur sur int tableau qui va remplir couleurCard
		- size: size_t la taille de ce tableau
*/
void initCardColor(int *c, size_t size){
	couleurCard=malloc(sizeof(Tab));
	couleurCard->len=size;
	couleurCard->tab=malloc(sizeof(int)*size);
	for (int i = 0; i < size; ++i)
		couleurCard->tab[i]=c[i];
}

/*
	renvoie la couleur stockee dans couleurBg a l'indice donnee
	@args:
		- i: indice de la couleur
*/
int getBgColor(int i){
	assert(i<couleurBg->len);
	return couleurBg->tab[i];
}

/*
	renvoie la valeur stockee dans couleurCard a l'indice donnee.
	L'indice peut depasser la taille du tableau de couleur.
	Si c'est la cas, le nouvel indice est calcule avec la formule suivante:
		(i%size+i/size)%size avec i l'indice et size la taille du tableau
	Cette formule assure une permutation circulaire des couleurs
	@args:
		- i: int indice de la couleur
*/
int getLoopedCardColor(int i){
	return couleurCard->tab[(i%couleurCard->len+i/couleurCard->len)%couleurCard->len];
}