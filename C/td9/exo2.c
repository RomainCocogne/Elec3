/*
    tests avec la library string.h
    et reecriture des fonctions strlen, strchr, strcpy, strcat
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
	Arguments   : s as const string
	Consequents	: lenght of s
*/
int strlen_new (const char s[]){
	int i=0;
	while (s[i]!='\0') i++;
	return i;
}

/*
	Arguments   : char as const s[], c as char
	Consequents	: indice of c in s
*/
int strchr_new (const char s[], char c){
	for (int i = 0; i <= strlen_new(s); ++i)
	{
		if (s[i] == c) return i;
	}
	return -1;
}

/*
	Arguments   : s as char[], s as char[]
	Consequents	: copy s in new_s
*/
void strcpy_new (char new_s[], char s[]){
	int i=0;
	while(i<=strlen_new(s)) {
		new_s[i]=s[i];
		i++;
	}
}

/*
	Arguments   : s as char[], s as char[]
	Consequents	: add s at the end of new_s
*/
void strcat_new (char new_s[], char s[]){
	int i=0;
	while(new_s[i]!='\0')i++;
	int j=0;
	while(s[j]!='\0')new_s[i++]=s[j++];
}
int main(void) {
/*   test avec string.h     */

	char str1[10]={'c','o','t','\0'};
	char str2[10] = "abri";
	printf("(%s) : (%s)\n", str1 , str2);
	printf("(%c) : (%c)\n", str1[1], str2 [2]);
	printf("(%lu) : (%lu)\n",sizeof str1 ,sizeof "abc");
	printf("(%d) : (%zd)\n", strlen_new(str1), strlen(str2 ));
	strcat_new(str2 ,str1 );
	printf("(%s)\n", str2);
	printf("%d\n", strchr_new(str2,'b'));
	strcpy_new(str2,str1);
	strcat_new(str2,"azertyuioplkjhgerstdyjtfhthhggg");
	printf("%s\n", str2);
	return EXIT_SUCCESS;
}