#include <stdio.h>
#include <stdlib.h>
#include "carte.h"


<<<<<<< Updated upstream
int getCardMode(Card c){
	return c.mode;
}

int getCardId(Card c){
	return c.id;
}


=======
>>>>>>> Stashed changes
void initCard(Card *carte, int id , int mode, int f){
	carte->mode = mode;
	carte->id = id;
}
