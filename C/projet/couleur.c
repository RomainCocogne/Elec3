#include "couleur.h"

Tab *couleurBg;
Tab *couleurCard;
void initBgColor(int *c, size_t size){
	couleurBg=malloc(sizeof(Tab));
	couleurBg->len=size;
	couleurBg->tab=malloc(sizeof(int)*size);
	for (int i = 0; i < size; ++i)
		couleurBg->tab[i]=c[i];
}

void initCardColor(int *c, size_t size){
	couleurCard=malloc(sizeof(Tab));
	couleurCard->len=size;
	couleurCard->tab=malloc(sizeof(int)*size);
	for (int i = 0; i < size; ++i)
		couleurCard->tab[i]=c[i];
}

int getBgColor(int i){
	assert(i<couleurBg->len);
	return couleurBg->tab[i];
}

int getLoopedCardColor(int i){
	return couleurCard->tab[(i%couleurCard->len+i/couleurCard->len)%couleurCard->len];
}