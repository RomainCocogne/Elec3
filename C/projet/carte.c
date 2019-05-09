#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

int getCardId(Card c){
	return c.id;
}

int getCardMode(Card c){
	return c.mode;
}
int getCardX(Card c){
	return c.posX;
}
int getCardY(Card c){
	return c.posY;
}

extern void setCardMode(Card *cardPointer, int newMode){
	cardPointer->mode = newMode;
}

extern void setCardX(Card *cardPointer, int newX){
	cardPointer->posX = newX;
}

extern void setCardY(Card *cardPointer, int newY){
	cardPointer->posY = newY;
}

extern Card initCard(int id, int mode, int posX, int posY){
	Card carte;
	carte.id = id;
	carte.mode = mode;
	carte.posX = posX;
	carte.posY = posY;
	return carte;
}
