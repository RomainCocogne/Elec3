/*
    experiences avec pointeurs
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

int main(void){
	int *p;
	int i;
	int k;
	i=42;
	k=i;
	p=&i;
	*p=75;
	printf("%d\n", i);

	return EXIT_SUCCESS;
}