#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "vector.h"
#include "stack.h"

Stacklist * newStacklist(){
  Stacklist * stack = malloc(sizeof(Stacklist));
  stack->data->head = NULL;
  stack->data->tail = NULL;
  stack->data->size = 0;
  stack->data->insert = insertList;
  stack->data->read = readData;
  stack->data->remove = removeData;
  stack->data->delete = deleteList;
  stack->push = pushStacklist;
};

void pushStacklist(Stacklist * stack, Data value){
  printf("begin to push");
  stack->data->insert(stack->data, stack->data->size, value);
  stack->data->size += 1;
};

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
  printf("begin to insert");
	stack->data->insert(stack->data, stack->stackCount, value);
	stack->stackCount += 1;
}
