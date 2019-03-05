#include <stdlib.h>
#include <stdio.h>

int main(void){
	double c;
	//int f;
	printf("temperature en celsius: ");
	scanf("%lf",&c);
	//f=(9/5)*c+32;
	printf("conversion en fahrenheit: %d\n",(int) ((9/5)*c+32));

	return EXIT_SUCCESS;
}
