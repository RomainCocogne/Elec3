#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void){
	double t;
	scanf ("%lf",&t);
	assert(t>=0);
	printf("%dh%dmin%ds%dc\n",(int)((t)/3600),((int)t%3600)/60,(int)(t)%60,(int)((t-floor(t))*100));

	return EXIT_SUCCESS;
}