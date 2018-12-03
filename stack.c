#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "vector.h"
#include "list.h"
#include "stack.h"

Stacklist * newStacklist(){
  Stacklist * stack = malloc(sizeof(Stacklist));
  stack->data = newList();
  printf("stack->data->head %d\n", stack->data->head );
  /*stack->data->head = NULL;
  stack->data->tail = NULL;
  stack->data->size = 0;
  stack->data->insert = insertList;
  stack->data->read = readData;
  stack->data->remove = removeData;
  stack->data->delete = deleteList;
  stack->push = pushStacklist;*/
};

void pushStacklist(Stacklist * stack, Data value){
  printf("begin to push into list");
  stack->data->insert(stack->data, stack->data->size, value);
  stack->data->size += 1;
};

Data popStacklist(Stacklist * stack);
Data peekStacklist(Stacklist * stack);
void clearStacklist(Stacklist * stack);
void * deleteStacklist(Stacklist * stack);

Stackvector * newStackvector(){
  Stackvector * stack = malloc(sizeof(Stackvector));
  stack->data->data = NULL;
  stack->data->current_size = 0;
  stack->data->max_size = 0;
  stack->data->insert = insertVector;
  stack->data->read = readVector;
  stack->data->remove = removeVector;
  stack->data->delete = deleteVector;
  
  stack->stackCount = 0;
  stack->push = pushStackvector;
  return stack;
}

void pushStackvector(Stackvector * stack, Data value){
  printf("begin to push into vector");
	stack->data->insert(stack->data, stack->stackCount, value);
	stack->stackCount += 1;
}

Data popStackvector(Stackvector * stack);
Data peekStackvector(Stackvector * stack);
void clearStackvector(Stackvector * stack);
void * deleteStackvector(Stackvector * stack);
