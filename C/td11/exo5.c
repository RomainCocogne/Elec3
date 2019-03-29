/*
    calculatrice
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int calcul (int od, int og, char *op){
	switch(*op){
		case '+': return og+od;
		case '-': return og-od;
		case 'x': return og*od;
		case '/': return og/od;
		default: return 0;
	}
}

int isnumber(char const *str){
	while(*str){
	    if(!isdigit(*str))
	    	return 0;
	    str++;
	}
	return 1;
}

int main(int argc, char *argv[]){
	argv++;
	printf("%d\n",isnumber("51"));
	char *op=*(argv+1);
	int od=atoi(*argv);
	int og=atoi(*(argv+2));
	int res=calcul(od,og,op);
	printf("%s %s %s = %d\n", *argv,*(argv+1),*(argv+2),res);

	return EXIT_SUCCESS;
}