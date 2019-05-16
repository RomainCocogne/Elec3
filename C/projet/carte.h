#pragma once 

enum FORME {CARRE, ROND, TRIANGLE};

typedef struct
{
	int mode;
	enum FORME f;

} Card;

extern int getCardForme(Card c);

extern int getCardMode(Card c);


extern void setCardMode(Card *cardPointer, int newMode);
void setCardForme(Card *cardPointer, int newforme);

extern void initCard(Card *carte,int f, int mode);

