#include "shuffle.h"

/* arrange the N elements of ARRAY in random order.
 * Only effective if N is much smaller than RAND_MAX;
 * if this may not be the case, use a better random
 * number generator. */
void shuffle(void *array, size_t n, size_t size) {
    srand(time(NULL));                                          //initialise le random
    char tmp[size];                                             //variable temporaire pour les permutations
    char *arr = array;                                          
    size_t stride = size * sizeof(char);                        //pour se decaler de la bonne valeur

    if (n > 1) {
        size_t i;
        for (i = 0; i < (n - 1); ++i) {                         //pas besoin de melanger plusieurs fois puisqu'on utilise le random
            size_t rnd = (size_t) rand();                       //genere le nombre aleatoire
            size_t j = i + rnd / (RAND_MAX / (n - i) + 1);      //pondere l'indice random

            memcpy(tmp, arr + j * stride, size);                //permutation
            memcpy(arr + j * stride, arr + i * stride, size);   //
            memcpy(arr + i * stride, tmp, size);                //
        }
    }
}

