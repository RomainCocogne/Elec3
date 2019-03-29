/*
    swap
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*
	Arguments   : pointers to a and b integers
	Consequents	: swap values of a and b
*/
void swap (int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(void){
	int a=4,b=6;
	swap(&a,&b);
	printf("a=%d,b=%d\n", a,b);

	return EXIT_SUCCESS;
}