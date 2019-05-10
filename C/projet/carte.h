#pragma once 


typedef struct
{
	int id,mode,posX,posY;

} Card;

extern int getCardId(Card c);

extern int getCardMode(Card c);

extern int getCardX(Card c);

extern int getCardY(Card c);

extern void setCardMode(Card *cardPointer, int newMode);

extern void setCardX(Card *cardPointer, int newX);

extern void setCardY(Card *cardPointer, int newY);

extern Card initCard(int id, int mode, int posX, int posY);

