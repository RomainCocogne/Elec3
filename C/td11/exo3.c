/*
    str functions with pointer
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*
	Arguments   : s as const string
	Consequents	: lenght of s
*/
int strlen_new (const char *s){
	const char *addr=s;
	while(*s)s++;
	return s-addr;
}


/*
	Arguments   : s1 as char[], s2 as char[]
	Consequents	: 
*/
int compare (const char *s1, const char *s2){
	while(*s1==*s2){
		if(*s1=='\0') return 0;
		s1++;s2++;
	}
	return (*s1-*s2);
}

/*
	Arguments   : char as const s[], c as char
	Consequents	: address of c in s
*/

char *strchr_new (char *s, const char c){
	while(*s){
		if(*s==c) return s;
		s++;
	}
	return NULL;
}

/*
	Arguments   : s as char[], s as char[]
	Consequents	: add s at the end of new_s
*/

char *strcat_new (char *new_s, const char *s){
	char *addr=new_s;
	while(*new_s)new_s++;
	while((*new_s++=*s++));
	return addr;
}

/*
	Arguments   : char *s
	Consequents	: 
*/
char *majuscule (char *s){
	char *addr=s;
	while(*s){
		if(*s>='a' && *s<='z') *s-= ('a'-'A');
		s++;
	}
	return addr;
}


int main(void){

	printf("%d\n", compare("bca","bba"));

	char str1[100]="cot";
	char str2[100] = "abricotier";

	printf("(%d)\n", strlen_new(str1));
	printf("(%s)\n", strcat_new(str2 ,str1 ));
	printf("%ld\n", strchr_new(str2,'a')-str2);
	printf("%s\n", majuscule(str2));
	return EXIT_SUCCESS;
}