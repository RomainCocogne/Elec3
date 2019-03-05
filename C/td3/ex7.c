/*
    résout l’équation ax*x+bx+c= 0 en envisageant tous les cas particuliers.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1E-300

int main(void){
	double a,b,c;
	double r1,r2,i1,i2;
	printf ("a,b et c: ");
	scanf("%lf %lf %lf",&a,&b, &c);

	assert(fabs(a)>=EPSILON);

	double d= b*b-4*a*c;
	if(a !=0){
	    if(d>=0){
	    	r1=(b>0 ? (-b-sqrt(d)):(-b+sqrt(d)))/(2*a);
	    	r2=(fabs(r1)<EPSILON ? 0 : c/(a*r1));
	    	i1=i2=0;
			//printf ("les solutions sont: %lf et %lf\n",r1,r2);
		}
		else{
			r1=-b/a;
			r2=r1;
			i1=sqrt(-d)/(2*a);
			i2=-i1;
			//printf("les solutions sont: %lf+i%lf et %lf-i%lf\n",r1,i1,r2,i2);
		}
		if(fabs(r1)<EPSILON) r1=0.0;
		printf("la/les solution(s) est/sont: %lf+ix%lf et %lf+ix%lf\n",r1,i1,r2,i2);
	}
	else{
		if(b==0){
	    	if(c==0){
	        	printf("tout x est solution\n");
	    	}
	    	else{
	    		printf("pas de solution\n");
	    	}
		}
		else{
			printf("la solution est %lf\n",(-c)/b);
		}
	}

	return EXIT_SUCCESS;
}