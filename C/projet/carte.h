#pragma once 

#define CACHEE		0
#define RETOURNEE	1
#define DECOUVERTE	2


// enum FORME {CARRE, ROND, TRIANGLE,ETOILE};
typedef struct
{
	int id,mode;
	int f;

} Card;

extern int getCardForme(Card c);

extern int getCardMode(Card c);

extern int getCardId(Card c);


extern void initCard(Card *carte, int id , int mode, int f);

