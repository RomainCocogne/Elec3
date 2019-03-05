#include <stdlib.h>
#include <stdio.h>

enum car_speciaux {AUDIBLEBELL='\a', BACKSPACE='\b', NEWLINE='\n', HORIZONTALTAB='\t', FORMFEED='\f', CARRIAGERETURN='\r', VERTICALTAB='\v'};

int main(void){
	enum car_speciaux i=NEWLINE;
	printf("%d\n",i);

	return EXIT_SUCCESS;
}