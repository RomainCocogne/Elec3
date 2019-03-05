/*
    affiche les valeurs de la fonction
    f(x)=x*x*x/2 sur un intervalle d'entiers
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

double f(int x){
	return (double)(x*x*x)/2;
}

/*
	Arguments   : 
	Consequents	: 
*/
void initTab (int t[],int a, int b){
	for (int i = 0; i <= b-a+1; ++i)
	{
		t[i]=a+i;
	}
}

int main(void){
	int a,b;
	scanf("[%d,%d]",&a,&b);
	int intervalle[b-a+1];
	initTab(intervalle,a,b);
	for (int i = 0; i < b-a+1; ++i)
	{
		printf("f(%d)=%f\n",intervalle[i],f(intervalle[i]));
	}
	return EXIT_SUCCESS;
}