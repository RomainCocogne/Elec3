/*
    tests avec argc et argv
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*
	Arguments   : argc as int, argv as char pointer
	Consequents	: 
*/
void echo (int argc, char const *argv[]){
	int option=0;
	if (argc==1) printf("\n");
	else{
		if(!strcmp(*++argv,"-n")){
			option=1; argv++; argc--;
		}
		if(argc !=1){
		while(--argc>1)
			printf("%s ", *argv++);
		printf("%s",*argv);
	}
		if(!option) printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	echo(argc, argv);
			
	return EXIT_SUCCESS;
}
