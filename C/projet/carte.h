#pragma once 

#define CACHEE		0
#define RETOURNEE	1
#define DECOUVERTE	2


typedef struct
{
	int id;
	int mode;

} Card;

<<<<<<< Updated upstream
extern int getCardMode(Card c);

extern int getCardId(Card c);
=======
>>>>>>> Stashed changes


extern void initCard(Card *carte, int id , int mode, int f);

