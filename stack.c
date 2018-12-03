#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "vector.h"
#include "list.h"
#include "stack.h"

Stacklist * newStacklist(){
  Stacklist * stack = malloc(sizeof(Stacklist));
  stack->data = newList();
  stack->push = pushStacklist;
  return stack; // remember this line
};

void pushStacklist(Stacklist * stack, Data value){
  stack->data->insert(stack->data, stack->data->size, value);
  stack->data->size += 1;
};

Data popStacklist(Stacklist * stack);
Data peekStacklist(Stacklist * stack);
void clearStacklist(Stacklist * stack);
void * deleteStacklist(Stacklist * stack);

Stackvector * newStackvector(){
  Stackvector * stack = malloc(sizeof(Stackvector));
  stack->data = newVector();
  stack->stackCount = 0;
  stack->push = pushStackvector;
  return stack;
}

void pushStackvector(Stackvector * stack, Data value){
	stack->data->insert(stack->data, stack->stackCount, value);
	stack->stackCount += 1;
}

Data popStackvector(Stackvector * stack);
Data peekStackvector(Stackvector * stack);
void clearStackvector(Stackvector * stack);
void * deleteStackvector(Stackvector * stack);
