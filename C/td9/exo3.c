/*
    fonction compare qui renvoie: 
    une valeur négative, si s1 est inférieure à s2 ; 0, si s1 est égale à s2 ; une valeur positive, si s1 est supérieure à s2.

    fonction trim qui supprime les espaces devant et derriere la chaine
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
	Arguments   : s1 as char[], s2 as char[]
	Consequents	: 
*/
int compare (const char s1[], const char s2[]){
	int i=0;
	while(s1[i]==s2[i]){
		if(s1[i]=='\0') return 0;
		i++;
	}
	return s1[i]-s2[i];
}

void trim (const char s1[], char s2[]){
	int a=0,b=0;
	int i=0;
	while(s1[a]==' ')a++;
	b=a;
	while(s1[b]!='\0')b++;
	while (s1[--b]==' ');
	while(a<=b){
		s2[i]=s1[a];
		i++;a++;
	}
	s2[i]='\0';
}

int main(void){
	char str2[100] = "  a   ";
	char str3[10] = "";
	printf("%d\n", compare("ba","bc"));
	trim(str2,str3);
	printf("-%s-\n", str3);
	return EXIT_SUCCESS;
}