/*
	Pris sur stackoverflow
	melange les elements d'un array
*/

#pragma once
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* arrange the N elements of ARRAY in random order.
 * Only effective if N is much smaller than RAND_MAX;
 * if this may not be the case, use a better random
 * number generator. */
extern void shuffle(void *, size_t , size_t);
