#include <stdlib.h>
#include <stdio.h>

int main(void){
	int i;
	unsigned int j,k;

	printf ("trois entiers :\n");
	printf("en decimal : ");
	scanf("%d",&i);
	printf("en octal : ");
	scanf("%o",&j);
	printf("en hexa : ");
	scanf("%x",&k);

	printf("Premier nombre en decimal : %d.\n",i);
	printf("Second nombre en decimal : %d.\n",j);
	printf("Dernier nombre en decimal : %d.\n",k);

	return EXIT_SUCCESS;
}