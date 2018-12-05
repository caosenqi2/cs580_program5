#include "stack.h"
#include "stack.h"
#include "vector.h"
#include "vector.h"
#include "list.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define PRINTD(f,v) { if(DEBUG) fprintf(stderr, "%s:%d|\t("#v") "f"\n", __FILE__, __LINE__, v); }
#define PRINTT { if(DEBUG) fprintf(stderr, "%s:%d|\n", __FILE__, __LINE__); }

int main(){
  fprintf(stderr, "\n\t=========Test #15: Stack Create ===========\n\n");
  Stacklist * sl = newStacklist();
  assert(sl->data->head == NULL);
  
  /*Stackvector * sv = newStackvector();
  assert(sv->data->current_size == 0);*/
  fprintf(stderr, "\n\t\tTest #15 Passed...\n\n");
  
  fprintf(stderr, "\n\t=========Test #16: Stack Push ===========\n\n");
  for(int i = 0; i < 10; i++){
    sl->push(sl, (Data){.value=i});
  }
  for(int i = 0, j = 9; i < 10; i++, j--){
    assert(sl->data->read(sl->data, i)->value == i || sl->data->read(sl->data, i)->value == j);
  }
  

  /*for(int i = 0; i < 10; i++){
    sv->push(sv, (Data){.value=i});
  }
 
  for(int i = 0, j = 9; i < 10; i++, j--){
    assert(sv->data->read(sv->data, i)->value == i || sv->data->read(sv->data, i)->value == j);
  }*/
  fprintf(stderr, "\n\t\tTest #16 Passed...\n\n");
  
  fprintf(stderr, "\n\t=========Test #17: Stack Pop ===========\n\n");
  for(int i = 9; i >= 0; i--){
    Data d = sl->pop(sl);
    printf("i:%d  pop value:%d  size: %d\n",i,d.value, sl->data->size);
    assert(d.value == i);
  }
  /*for(int i = 9; i >= 0; i--){
    Data d = sv->pop(sv);
    assert(d.value == i);
  }*/
  fprintf(stderr, "\n\t\tTest #17 Passed...\n\n");
  
  fprintf(stderr, "\n\t=========Test #18: Stack Peek ===========\n\n");
  //TODO check to make sure I can pop empty
  for(int i = 0; i < 10; i++){
    sl->push(sl, (Data){.value=i});
    printf("i:%d  pushin value:%d  size: %d\n",i,sl->data->tail->data.value, sl->data->size);
  }
  for(int i = 9; i >= 0; i--){
    
    Data d = sl->peek(sl);
    printf("i:%d  value:%d\n",i,d.value);
    assert(d.value == i);
    d = sl->peek(sl);
    assert(d.value == i);
    sl->pop(sl);
  }
  
  /*for(int i = 0; i < 10; i++){
    sv->push(sv, (Data){.value=i});
  }
  for(int i = 9; i >= 0; i--){
    Data d = sv->peek(sv);
    assert(d.value == i);
    d = sv->peek(sv);
    assert(d.value == i);
    sv->pop(sv);
  }*/
  fprintf(stderr, "\n\t\tTest #18 Passed...\n\n");
  
  fprintf(stderr, "\n\t=========Test #19: Stack Clear ===========\n\n");
  for(int i = 0; i < 10; i++){
    sl->push(sl, (Data){.value=i});
    printf("i:%d  pushin value:%d  size: %d\n",i,sl->data->tail->data.value, sl->data->size);
  }
  sl->clear(sl);
  //assert(sl->pop(sl).value == -1);
  /*for(int i = 0; i < 10; i++){
    sv->push(sv, (Data){.value=i});
  }
  sv->clear(sv);
  assert(sv->pop(sv).value == -1);*/
  fprintf(stderr, "\n\t\tTest #19 Passed...\n\n");
  
  fprintf(stderr, "\n\t=========Test #20: Stack Delete ===========\n\n");
  sl->delete(sl);
  //sv->delete(sv);
  fprintf(stderr, "\n\t\tTest #20 Passed (but check valgrind to be sure)...\n\n");
}

