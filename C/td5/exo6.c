/*
    triangle isocele encore plus dure
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
	Arguments   : i as int
	Consequents	: ecrit sur la sortie standard i characteres
*/
void ecrirechar (int i,char c){
	for (int j = 0; j <= i; ++j)
		{
			printf("%c", c);
		}
}

/*
	Arguments   : d as int
	Consequents	: dessine un trianle isocele
*/
void triangleiso (int d){
	char star='*'; char space=' ';
	for (int i = 0; i < d; ++i)
	{	
		ecrirechar(d-i,space);		
		ecrirechar(2*i,star);
		printf("\n");
	}
	
}

int main(void){
	int d;
	scanf("%d",&d);
	triangleiso(d);

	return EXIT_SUCCESS;
}