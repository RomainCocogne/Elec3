/*
    factorielle en ordre croissant et decroissant
    valeur max de n : 12 sinon calcul faux
    (valeur peut etre verifiee avec limits.h et le programme n<= max(INTEGER)/fact(n-1))
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
   Antecedant: entier n
   Consequent: entier resutlat de la factorielle de n
*/
int factCroissant(int n){
	int fact=1;
	for (int i = 1; i <= n; ++i)
	{
		fact=fact*i;
	}
	return fact;
}

/*
   Antecedant: entier n
   Consequent: entier resutlat de la factorielle de n
*/
int factDecroissant(int n){
	int fact=1;
	for (int i = n; i > 0; --i)
	{
		fact=fact*i;
	}
	return fact;
}

int main(void){
	int n;
	scanf("%d",&n);
	printf("%d\n", factCroissant(n));
	printf("%d\n", factDecroissant(n));
	return EXIT_SUCCESS;
}