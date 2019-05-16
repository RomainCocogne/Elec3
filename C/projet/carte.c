#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

int getCardForme(Card c){
	return c.f;
}

int getCardMode(Card c){
	return c.mode;
}

void setCardMode(Card *cardPointer, int newMode){
	cardPointer->mode = newMode;
}
void setCardForme(Card *cardPointer, int newforme){
	cardPointer->f=newforme;
}

void initCard(Card *carte, int f, int mode){
	carte->f = f;
	carte->mode = mode;
}
