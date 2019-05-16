#pragma once 

#define CACHEE		0
#define RETOURNEE	1

typedef struct
{
	int id,mode;

} Card;

extern int getCardId(Card *cardPointer);

extern int getCardMode(Card *cardPointer);

// extern int getCardX(Card c);

// extern int getCardY(Card c);

extern void setCardMode(Card *cardPointer, int newMode);

// extern void setCardX(Card *cardPointer, int newX);

// extern void setCardY(Card *cardPointer, int newY);

extern void initCard(Card *cartep, int id, int mode);

 
