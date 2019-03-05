/*
    résout l’équation ax+b= 0.
    Bien évidemment, on n’oubliera pas tous les cas particuliers (notamment les cas
    "tout x est solution" et "pas de solution").
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
	double a,b;
	printf ("a et b: ");
	scanf("%lf %lf",&a,&b);
	if(a==0){
	    if(b==0){
	        printf("tout x est solution\n");
	    }
	    else{
	    	printf("pas de solution\n");
	    }
	}
	else{
		printf("x= %lf\n",(-b)/a);
	}

	return EXIT_SUCCESS;
}