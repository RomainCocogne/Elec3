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


void initCard(Card *carte, int id , int mode, int f){
	carte->f = f;
	carte->mode = mode;
	carte->id = id;
}
