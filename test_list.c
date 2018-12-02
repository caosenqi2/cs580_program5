#include "list.h"
#include "list.h"
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
  printf("\t-          Part B: Lists        -\n");
  printf("\t-----------------------------------\n");
  
  printf("\n\t=========Test #11: Creating your Linked List===========\n\n");
  List * list = newList();
  assert(list->head == NULL && list->tail == NULL);
  printf("\n\t\tTest #11: Passed ...\n\n");
  
  printf("\n\t=========Test #12: Linked List Insertion===========\n\n");
  int index = 0;
  //add elements to the list
  for(index = 0 ; index < 10 ; index++ ){
    list->insert(list , index, (Data){index+1});
  }
  assert(list->head != NULL && list->tail != NULL);
  assert(list->head->next != NULL && list->head->prev == NULL);
  assert(list->tail->next == NULL && list->tail->prev != NULL);
  Node * test = list->head;
  for(index = 0 ; index < 10 ; index++, test = test->next){
    assert(test->data.value == index +1);
  }
  //***** Test that out of bounds indexes are appended to the list ****/
  list->insert(list , 20, (Data){11});
  assert(list->tail->data.value == 11);
  
  fprintf(stderr, "\n\t\tTest #12: Passed ...\n\n");
  
  printf("\n\t=========Test #13: Linked List Read===========\n\n");
  for(index = 0 ; index < 10 ; index++){
    Data * d = list->read(list, index);
    assert(d->value == index +1);
  }
  Data * d = list->read(list, 20);
  assert(d == NULL);
  printf("\n\t\tTest #13: Passed ...\n\n");
  
  fprintf(stderr, "\n\t=========Test #14: Linked List Remove===========\n\n");
  
  for(index = 0; list->head != NULL; index++){
    index = index % 4;
    list->remove(list , index);
  }
  assert(list->head == NULL && list->tail == NULL);
  list->delete(list);
  list = NULL;
  fprintf(stderr, "\n\t\tTest #14 Passed...\n\n");
}