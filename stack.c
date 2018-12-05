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
  stack->pop = popStacklist;
  stack->peek = peekStacklist;
  stack->clear = clearStacklist;
  stack->delete = deleteList;
  return stack; // remember this line
};

void pushStacklist(Stacklist * stack, Data value){
  stack->data->insert(stack->data, stack->data->size, value);
};

Data popStacklist(Stacklist * stack){
  if (stack->data->size == 0){
    Data data = {data.value = -1};
    return data;
  }
  else {
    Data to_push = *stack->data->read(stack->data, stack->data->size-1);
    stack->data->remove(stack->data, stack->data->size-1);
    return to_push;
  }
};

Data peekStacklist(Stacklist * stack){
  if (stack->data->size == 0){
    Data data = {data.value = -1};
    return data;
  }else{
    Data to_push = *stack->data->read(stack->data, stack->data->size-1);
    return to_push;
  }
}
 

void clearStacklist(Stacklist * stack){
  stack->data->delete(stack->data);
};

void * deleteStacklist(Stacklist * stack){
  free(stack);
  stack = NULL;
};



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
void * deleteStackvector(Stackvector * stack){
};
