/*
    lit N notes (des réels doubles) sur l’entrée standard et les
mémorise dans un tableau. Puis calcule la moyenne des notes
contenues dans le tableau. Le tableau est passé en paramètre à chaque fois
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
	Arguments   : t as double tab,n as int
	Consequents	: 
*/
void initTab (double t[],int n){
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&t[i]);
	}

}

/*
	Arguments   : t as double tab,n as int
	Consequents	: m as double
*/
double moyenne (double t[],int n){
	double m;
	for (int i = 0; i < n; ++i)
	{
		m+=t[i];
	}
	return m/n;
}

int main(void){
	int n;
	scanf("%d",&n);
	double notetab[n];
	initTab(notetab,n);
	printf("%lf\n", moyenne(notetab,n));
	return EXIT_SUCCESS;
}