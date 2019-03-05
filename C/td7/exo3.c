/*
    initialise un tableau de N entiers 
    en random et affiche le max du tableau
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>

/*
	Arguments   : t as int tab,n as int
	Consequents	: 
*/
void initTab (int t[],int n){
	srand48(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		t[i]=rand();
	}

}

/*
	Arguments   : t as int tab,n as int
	Consequents	: 
*/
int max (int t[],int n){
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		if (t[i]>max)
		{
			max=t[i];
		}
	}
	return max;
}

int main(void){
	int n;
	scanf("%d",&n);
	int randtab[n];
	initTab(randtab,n);
	printf("%d\n",max(randtab,n));
	return EXIT_SUCCESS;
}