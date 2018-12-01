#include "stack.h"
#include "stack.h"
#include "queue.h"
#include "queue.h"
#include "vector.h"
#include "vector.h"
#include "list.h"
#include "list.h"
//#include "profile.h"
//#include "profile.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define PRINTD(f,v) { if(DEBUG) fprintf(stderr, "%s:%d|\t("#v") "f"\n", __FILE__, __LINE__, v); }
#define PRINTT { if(DEBUG) fprintf(stderr, "%s:%d|\n", __FILE__, __LINE__); }
/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE 	                    */
/********************************************************************/

int main(){
  int i = 0;
  srand(time(NULL));
  printf("\t-----------------------------------\n");
  printf("\t-          Part A: Vectors        -\n");
  printf("\t-----------------------------------\n");
  
  printf("\n\t=========Test #1: Creating your Vector===========\n\n");
  
  Vector *vect = newVector();
  assert(vect->current_size == 0);
  assert(vect->max_size == 0);
  assert(vect->data == NULL);
  printf("\n\t=========Test #1 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #2: Inserting 20 random values into your Vector===========\n\n");
  //Insert Vector
  Data data_array[20];
  for(i = 0 ; i < 20 ; i++){
    data_array[i].value = (rand() % 20) + 1;
    vect->insert(vect, i, data_array[i]);
  }
  
  assert(vect->max_size == 31);
  assert(vect->current_size == 20);
  printf("\n\t=========Test #2 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #3: Inserting values into out of bounds index===========\n\n");
  vect->insert(vect, 49, (Data){49});
  assert(vect->max_size == 99);
  assert(vect->current_size == 50);
  
  printf("\n\t=========Test #3 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #4: Inserting values into out of bounds index===========\n\n");
  //tests outof bounds insert with expansion
  vect->insert(vect, 40, (Data){40});
  assert(vect->max_size == 99);
  assert(vect->current_size == 50);
  
  printf("\n\t=========Test #4 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #5: Reading from your vector===========\n\n");
  
  for(i = 0 ; i < 20 ; i++){
    Data * d = vect->read(vect, i);
    fprintf(stderr, "%d %d\n",data_array[i].value, d->value );
    assert(data_array[i].value == d->value);
  }
  Data * d = vect->read(vect, 49);
  assert(49 == d->value);
  printf("\n\t=========Test #5 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #6: Reading from unititialized vector index (should return -1)===========\n\n");
  
  d = vect->read(vect, 45);
  fprintf(stderr, "%d\n", d->value);
  assert(d->value == -1);
  
  printf("\n\t=========Test #6 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #7: Attempting to read from out of bounds===========\n\n");
  
  d = vect->read(vect, 100);
  assert(d == NULL);
  
  printf("\n\t=========Test #7 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #8: Remove elements from the vector ===========\n\n");
  
  //RemoveVector
  vect->remove(vect, 49);
  vect->remove(vect, 40);
  
  printf("\n\t=========Test #8 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #9: Remove elements from the vector randomly ===========\n\n");
  
  while(vect->current_size){
    vect->remove(vect, (rand()%5));
  }
  vect->remove(vect, 50);
  printf("\n\t=========Test #9 Passed...            ===========\n\n");
  
  printf("\n\t=========Test #10: Delete the vector from memory ===========\n\n");
  
  vect->delete(vect);
  vect = NULL;
  
  printf("\n\t=========Test #10 Passed...            ===========\n\n");
}