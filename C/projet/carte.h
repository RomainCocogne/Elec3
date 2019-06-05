#pragma once 

#define CACHEE		0
#define RETOURNEE	1
#define DECOUVERTE	2


typedef struct
{
	int id;
	int mode;

} Card;

extern int getCardForme(Card c);

extern int getCardMode(Card c);

extern int getCardId(Card c);


extern void initCard(Card *carte, int id , int mode, int f);

