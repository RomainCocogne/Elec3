#pragma once 

enum FORME {CARRE, ROND, TRIANGLE,ETOILE};
#define CACHEE		0
#define RETOURNEE	1
#define DECOUVERTE	2

typedef struct
{
	int id,mode;
	enum FORME f;

} Card;

extern int getCardForme(Card *c);

extern int getCardMode(Card *c);

extern int getCardId( Card *c);

extern void setCardMode(Card *cardPointer, int newMode);
void setCardForme(Card *cardPointer, int newforme);

extern void initCard(Card *carte, int id , int mode, int f);

