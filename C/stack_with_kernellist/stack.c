#include "stack.h"

/* Create a Stack */
Stack * initStack(int max)
{
    Stack *Q;
    Q = (Stack *)malloc(sizeof(Stack));
    Q->size = 0;
    Q->capacity = max;
    /* initialize the list head. Kernel list method */
    INIT_LIST_HEAD(&Q->list);
    return Q;
}

void rmStack(Stack *Q){
	while(Q->size!=0)
		pop(Q);
	free(Q);
}


/* pop out the Stack front, and free the element space */
STACKELT pop(Stack *Q)
{
    Stack* tmp;
    if(Q->size==0){
	printf("Stack is Empty.\n");
	return NULL;
    }
    STACKELT s=front(Q);
	Q->size--;
	tmp = list_entry(Q->list.next, Stack, list);
	list_del(Q->list.next);
	free(tmp);
	return s;
}

STACKELT front(Stack *Q)
{
    Stack* first_element;
    struct list_head * first;
    if(Q->size==0){
	printf("Stack is Empty\n");
	exit(0);
    }
    /* find the first element first */
    first = Q->list.next;
    /* reconstruct the first structure */
    first_element = list_entry(first, Stack, list);
    return first_element->e; 
}

STACKELT tail(Stack *Q)
{
    Stack* last_element;
    struct list_head * last;
    if(Q->size==0){
	printf("Stack is Empty.\n");
	exit(0);
    }
    /* find the last element first */
    last = Q->list.prev;
    /* reconstruct the last structure */
    last_element = list_entry(last, Stack, list);
    return last_element->e; 
}

void stack(Stack *Q, STACKELT element)
{
    Stack* newQ;
    if(Q->size == Q->capacity){
	printf("Stack is Full. No element added.\n");
    }
    else{
	Q->size++;
	newQ = (Stack*) malloc(sizeof(Stack));
	newQ->e = element;
	/* add to the list tail */
	list_add_tail(&(newQ->list), &(Q->list));
    }
}

