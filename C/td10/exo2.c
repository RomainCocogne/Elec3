/*
    jeu avec les strings (sans pointeurs)
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define MAXCAR 100

typedef struct {
	char s[MAXCAR];
	int lg;
}String;

/*
	Antecedant: char[]
	Consequent: String
*/
String string (const char s[]){
	String str;
	strcpy(str.s,s);
	int i=0;
	while (s[i]!='\0')i++;
	assert(i<MAXCAR);
	str.lg=i;
	return str;
}

/*
	Arguments   : String s
	Consequents	: s on stdout
*/
void ecrireString (const String s){
	printf("%s", s.s);
}

/*
	Arguments   : String s
	Consequents	: s\n on stdout
*/
void ecrireLnString (const String s){
	printf("%s\n", s.s);
}

/*
	Arguments   : s as String
	Consequents	: copy of s
*/
String stringcpy (String s){
	String s_cpy = s;
	return s_cpy;
}

/*
	Arguments   : s as String1, s as String2
	Consequents	: concatene s1 et s2
*/
String stringcat (const String s1, const String s2){
	int lg=s1.lg+s2.lg;
	assert(lg<MAXCAR);
	String new_s;
	strcat(strcpy(new_s.s,s1.s),s2.s); new_s.lg=lg;
	return new_s;
}

int main(void){
	String s1=string ("test");
	String s2=string ("chocolat");
	ecrireLnString(stringcat(s1,s2));
	ecrireLnString(stringcpy(s1));
	return EXIT_SUCCESS;
}
