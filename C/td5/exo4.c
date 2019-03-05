/*
    construit un triangle isocele sur stdout
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
	Arguments   : i as int
	Consequents	: ecrit sur la sortie standard i etoiles
*/
void ecrireEtoile (int i){
	char star='*';
	for (int j = 0; j < i; ++j)
		{
			printf("%c", star);
		}printf("\n");
}

int main(void){
	int d;
	scanf("%d",&d);
	for (int i = 1; i <= d; ++i)
	{	
		ecrireEtoile(i);
	}
	return EXIT_SUCCESS;
}