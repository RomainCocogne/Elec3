/*
    produit de x par y suivant l'algo chelou du prof
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
   Antecedant: x,y entiers
   Consequent: produit de x par y
*/
int produit(int x, int y){
	int a=x; int b=y;
	int p=0;	
	while(b!=0){
	    while((b&1)==0){
	        b=b>>1;
	        printf("%d\n",b);
	        a+=x;
	    }
	    b=b-1;
	    p+=a;
	}
	return p;
}
int main(void){
	int x,y;                                                                                                                                                                                                                            
	scanf("%dx%d",&x,&y);                                                                                        
	printf("%d\n",produit(x,y));

	return EXIT_SUCCESS;
}