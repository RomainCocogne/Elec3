/*
	met en evidence le fait qu'une instruction inscrite
	dans un enonce compose est independante du reste du code
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
	
	int a=10;

	{
		int a=100;
		//affiche a=100
		printf("a= %d\n",a);
	}
	//affiche a=10
	printf("a=%d\n",a);

	return EXIT_SUCCESS;
}