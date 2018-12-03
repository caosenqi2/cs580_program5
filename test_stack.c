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
  printf("hello2\n");
  fprintf(stderr, "\n\t=========Test #15: Stack Create ===========\n\n");
  printf("hello1\n");
  Stacklist * sl = newStacklist();
  printf("stack->data->head %d\n", sl->data->head );
  assert(sl->data->head == NULL);
  
  //Stackvector * sv = newStackvector();
  printf("hello\n");
  //assert(sv->data->current_size == 0);
  fprintf(stderr, "\n\t\tTest #15 Passed...\n\n");
}