/*
    exercice 1 du ds du 06/05
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
	Arguments   : entier i 
	Consequents	: taille de i (nombre de chiffres dans i)
*/
int len_int(int i){
	int len=0;
	while(i){
		i=i/10;
		len++;
	}
	return len;
}

/*
	Arguments   : entier i
	Consequents	: chaine de caractere c contenant i
*/
char *itos (int i){
	assert(i>=0);							//on verifie que i est positif
	char *c, *c_first;						//on cree la chaine de caracteres(avec un pointeur sur le premier element)
	c=malloc(len_int(i)*sizeof(char)+1);	//on fait +1 pour le caractere de fin de chaine
	c_first=c;
    int j = i;								//sauvegarde temporaire de l'entier
    do{										//on se place a la fin de la chaine
        c++;								//on fait un do/while pour traiter le cas i=0;
        j = j/10;
    }while(j);
    *c = '\0';								//on est a la fin: on ajoute le caractere de fin de chaine
    do{ 									//on parcourt la chaine dans l'autre sens
        *--c = '0'+i%10;					//on ajoute le chiffre compris entre 0 et 9
        i = i/10;
	}while(i);
	return c_first;
}

int main(int argc, char const *argv[]){
	char *c;
	int i=0;
	c=itos(i);
	printf(" i=0, c=%s\n", c);
	i=100240100;
	c=itos(i);
	printf(" i=100240100, c=%s\n", c);
	return EXIT_SUCCESS;
}