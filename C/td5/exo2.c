/*
    division par soustraction successives
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


/*
   Antecedant: a,b deux entiers
   Consequent: un entier resultat de la division entiere entre a et b
*/
int division (int a,int b){
	int q=0;
	int i=a;
	while(i>=b){
	    i=i-b;
	    q++;
	}
	return q;
}

int main(void){
	int a,b;
	scanf("%d/%d",&a,&b);
	printf("%d\n",division(a,b));

	return EXIT_SUCCESS;
}