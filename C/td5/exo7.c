/*
    approximation de pi
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>

/*
	Antecedants : n as int nombre total de points
	Consequents	: valeur approximative de pi
*/
double pi (int n){
	srand48(time(NULL));
	int m=0;
	double pi; double x,y;
	for (int i = 0; i < n; ++i)
	{
		x=drand48();
		y=drand48();
		if(x*x+y*y<=1) ++m;
	}
	pi=4*((double)(m)/((double)(n)));
	return pi;
}

int main(void){
	int n;
	scanf("%d",&n);
	printf("%f\n", pi(n));

	return EXIT_SUCCESS;
}