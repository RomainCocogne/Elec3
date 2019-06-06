#pragma once
#include <libsx.h>
#include <assert.h>
#include <stdlib.h>

typedef struct
{
	size_t len;
	int *tab;
} Tab;

extern Tab *couleurBg;
extern Tab *couleurCard;

extern void initBgColor(int *c, size_t size);
extern void initCardColor(int *c, size_t size);
extern int getBgColor(int i);
extern int getLoopedCardColor(int i);