/*
    somme des N premiers termes de la serie 
    1+1/2+1/3+...+1/N
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

double somme (int i){
	double res=1.0;
	for (int j = 2; j <= i+1; ++j)
	{
		res+=1/(double)j;
	}
	return res;
}

double sommetotale (double t[],int n){
	double res=0;
	for (int i = 0; i < n; ++i)
	{
		res+=t[i];
	}
	return res;
}

void initTab (double t[], int n){
	for(int i; i<n; i++) {
		t[i]=somme(i);
		//printf("%f\n", t[i]);
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	double tab[n];
	initTab(tab,n);
	printf("%f\n",tab[0]);
	printf("%f\n",sommetotale(tab,n));
	return EXIT_SUCCESS;
}