/*
    lit entier puis l'ecrit sur stdout
    prend en compte le signe 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
	Arguments   : 
	Consequents	: i l'entier lu sur stdin
*/
int lireInt (){
	int c;
	int neg=0;
	int i=0;
	while ((c=getchar()) !='\n')
	{
		if (c=='-') neg=1;
		if (c <= '9' && c >= '0'){
		    i *= 10;
		    i += c - '0';
		}
	}
	if (neg) i*=-1;
	//i=i*i;	
	return i;
}

int main(void){
	
	int i=lireInt();
	printf("%d\n", i);

	return EXIT_SUCCESS;
}