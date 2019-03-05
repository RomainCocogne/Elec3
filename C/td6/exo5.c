/*
    reprise simplifiee (sans les options)
    de la commande wc
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

int main(void){
	int nb_nl=0, nb_w=0, nb_c=0;
	int is_mot=0;
	int c;
	while ((c=getchar ()) != EOF){
		if (isspace(c)!=0) {
			if (is_mot) ++nb_w;
			is_mot=0;
		}
		if (c=='\n') ++nb_nl;
		else is_mot=1;
		++nb_c;
	}
	printf("%d %d %d\n",nb_nl,nb_w,nb_c);
	return EXIT_SUCCESS;
}