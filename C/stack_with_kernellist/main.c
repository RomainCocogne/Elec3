
#include "stack.h"
// #define STACKELT int
#define MAXSTACK 4
Stack *stck; 

int main(void){
	stck =initStack(MAXSTACK);
	int a=3;
	int b=4;

	stack(stck,&a);
	stack(stck,&b);
	stack(stck,&a);
	stack(stck,&b);
	stack(stck,&a);
	stack(stck,&b);
	printf("%d\n", *(int*)pop(stck));
	printf("%d\n", *(int*)pop(stck));
	printf("%d\n", *(int*)pop(stck));
	rmStack(stck);

	return 0;
}