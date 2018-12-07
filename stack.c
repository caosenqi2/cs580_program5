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
  stack->delete = deleteStacklist;
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
  //stack->data->delete(stack->data);
  while(stack->data->size >0){                    //remember this hard debug
    stack->data->remove(stack->data, stack->data->size-1);
  }
};

void * deleteStacklist(Stacklist * stack){
  if(stack != NULL){
    stack->data->delete(stack->data);
    free(stack);
    stack = NULL;
  }
};

Stackvector * newStackvector(){
  Stackvector * stack = malloc(sizeof(Stackvector));
  stack->data = newVector();
  stack->stackCount = 0;
  stack->push = pushStackvector;
  stack->pop=popStackvector;
  stack->peek=peekStackvector;
  stack->clear=clearStackvector;
  stack->delete=deleteStackvector;
  return stack;
}

void pushStackvector(Stackvector * stack, Data value){
  stack->data->insert(stack->data, stack->stackCount, value);
  stack->stackCount += 1;
}

Data popStackvector(Stackvector * stack){
  Data d;
  if(stack->stackCount==0){
    d.value=-1;
  }
  //Data *num=malloc(sizeof(Data));
  //printf("abc\n");
  else{
    Data *num=stack->data->read(stack->data,stack->stackCount-1);
    //printf("ac\n");
    d=*num;
    stack->data->remove(stack->data,stack->stackCount-1);
    stack->stackCount-=1;
    //printf("abc\n");
  }
  return d;
}
Data peekStackvector(Stackvector * stack){
  //printf("abc\n");
  Data *num=stack->data->read(stack->data,(stack->stackCount)-1);
  Data d=*num;
  //printf("c\n");
  return d;
}
void clearStackvector(Stackvector * stack){
  //printf("c\n");
  for(int i=stack->stackCount;i>0;i--){
    //printf("c\n");
    stack->data->remove(stack->data,stack->stackCount-1);
    stack->stackCount-=1;
  }
}
void * deleteStackvector(Stackvector * stack){
  free(stack->data);
  stack->data=NULL;
  free(stack);
  stack=NULL;
}