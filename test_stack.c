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
  
  Stackvector * sv = newStackvector();
  assert(sv->data->current_size == 0);
  fprintf(stderr, "\n\t\tTest #15 Passed...\n\n");
  
  fprintf(stderr, "\n\t=========Test #16: Stack Push ===========\n\n");
  for(int i = 0; i < 10; i++){
    sl->push(sl, (Data){.value=i});
  }
  for(int i = 0, j = 9; i < 10; i++, j--){
    assert(sl->data->read(sl->data, i)->value == i || sl->data->read(sl->data, i)->value == j);
  }
  

  for(int i = 0; i < 10; i++){
    sv->push(sv, (Data){.value=i});
  }
 
  for(int i = 0, j = 9; i < 10; i++, j--){
    assert(sv->data->read(sv->data, i)->value == i || sv->data->read(sv->data, i)->value == j);
  }
  fprintf(stderr, "\n\t\tTest #16 Passed...\n\n");
}

