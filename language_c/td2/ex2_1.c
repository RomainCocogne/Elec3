#include <stdlib.h>
#include <stdio.h>

int main(void){
	enum boolean {FAUX=10, VRAI=5} a,b;
	a=VRAI;
	b=FAUX;

	printf("a=%d\n",a);
	printf("b=%d\n",b);
	return EXIT_SUCCESS;
}