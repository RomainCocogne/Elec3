#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

// #define CACHEE		0
// #define RETOURNEE	1

int getCardId(Card *cardPointer){
	return cardPointer->id;
}

int getCardMode(Card *cardPointer){
	return cardPointer->mode;
}

void setCardMode(Card *cardPointer, int newMode){
	cardPointer->mode = newMode;
}


void initCard(Card *cartep, int id, int mode){
	cartep->id = id;
	cartep->mode = mode;
}
