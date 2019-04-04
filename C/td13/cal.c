/*
    calculatrice avec expressions postfixee
    on utilise les piles def dans pile.h et pile.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "pile.h" //importe le module pile

/*
	verifie si la chaine de caracteres envoyee
	est un nombre
*/
int isnumber(char const *str){
	while(*str){
	    if(!isdigit(*str))
	    	return 0;
	    str++;
	}
	return 1;
}

/*
	recupere les operandes dans la pile
	et les enleves de celle ci
*/
void extract_operandes (Pile *p, int *x, int *y){
	assert(estVide(*p)==0);
	*y= sommet(*p);
	depiler(p);
	assert(estVide(*p)==0);
	*x= sommet(*p);
	depiler(p);
}

/*
	effectue le calcul puis stock le 
	resultat dans la pile
*/
void calcul (Pile *p, int x, int y, const char *op){
	switch(*op){
		case '+': empiler(p,x+y);	break;
		case '-': empiler(p,x-y);	break;
		case 'x': empiler(p,x*y);	break;
		case '/': empiler(p,x/y);	break;
		default: printf("error in operator\n");
	}
}


int main(int argc, char const *argv[]){
	argv++;
	Pile pile=NULL;
	int x,y;
	while(--argc){
		if (isnumber(*argv)) empiler(&pile,atoi(*argv++));
		else{
			extract_operandes(&pile,&x,&y);
			//printf("(%d%s%d)",x,*argv,y );
			calcul(&pile,x,y,*argv++);
		}
	}
	printf("%d\n", sommet(pile));
	return EXIT_SUCCESS;
}