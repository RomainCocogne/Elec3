#pragma once

#include "list.h"

#include<stdio.h>
#include<stdlib.h>

#ifndef STACKELT
#define STACKELT void*
#endif

typedef struct{
    int capacity;
    int size;
    STACKELT e;
    struct list_head list;
} Stack;

Stack * initStack(int max);
void rmStack(Stack *Q);
STACKELT front(Stack *Q);	
STACKELT tail(Stack* Q);
STACKELT pop(Stack *Q);
void stack(Stack *Q, STACKELT element);
