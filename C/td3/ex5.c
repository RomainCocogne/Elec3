/*
    demande à l’utilisateur de saisir 3 nombres réels
	(double) au clavier et les affiche par ordre décroissant.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
	double a,b,c;
	printf("3 nombres reels: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a>=b){ 
		//possibilites: abc, acb, cab
	    if(b>=c){
	        printf("%lf %lf %lf\n",a,b,c);
	    }
	    else{
	    	//possibilites: acb, cab
	    	if(c>=a){
	    	    printf("%lf %lf %lf\n",c,a,b);
	    	}
	    	else{
	    		printf("%lf %lf %lf\n",a,c,b);
	    	}
	    }
	}
	else{
		//possibilites: bac, bca, cba
		if(c>=b){
	        printf("%lf %lf %lf\n",c,b,a);
	    }
	    else{
	    	//possibilites: bac, bca
	    	if(c>=a){
	    	    printf("%lf %lf %lf\n",b,c,a);
	    	}
	    	else{
	    		printf("%lf %lf %lf\n",b,a,c);
	    	}
	    }
	}

	return EXIT_SUCCESS;
}