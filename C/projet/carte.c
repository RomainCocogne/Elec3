#include <stdio.h>
#include <stdlib.h>
#include "carte.h"



int getCardForme(Card c){
	return c.f;
}

int getCardMode(Card c){
	return c.mode;
}

int getCardId(Card c){
	return c.id;
}

void setCardMode(Card *cardPointer, int newMode){
	cardPointer->mode = newMode;
}
void setCardForme(Card *cardPointer, int newforme){
	cardPointer->f=newforme;
}

void initCard(Card *carte, int id , int mode, int f){
	carte->f = f;
	carte->mode = mode;
	carte->id = id;
}

int compareCard(Card carteA, Card carteB){
	return carteA.id == carteB.id;
}
