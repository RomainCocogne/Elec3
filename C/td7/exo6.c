/*
    écrit les lignes de texte lues sur l’entrée standard en inversant
l’ordre des caractères de chaque ligne sur la sortie standard.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define N 50


/*
	Arguments   : t as int[], i as int
	Consequents	: 
*/
void print_reverse (int t[],int a){
	for (int i = 0; i < a; ++i)
	{
		putchar(t[a-1-i]);
	}
	printf("\n");
	
}

int main(void){
	int c,i=0;
	int tab[N];
	while ((c=getchar()) !=EOF){
		if(c=='\n'){
			print_reverse(tab,i);
			i=0;
		}
		else{
			if(i<N)
				tab[i++]=c;
		}
	}
	if(i!=0){
		print_reverse(tab,i);
	}
	return EXIT_SUCCESS;
}