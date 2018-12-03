#include <stdio.h>
#include "list.h"

Node * newNode(Data data, Node * next, Node * prev){
  Node * n = malloc(sizeof(Node));
  n->data = data;
  n->next = next;
  n->prev = prev;
  return n;
};

List * newList(){
  List * l = malloc(sizeof(List));
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  l->insert = insertList;
  l->read = readData;
  l->remove = removeData;
  l->delete = deleteList;
  return l;
};

void insertList(List * list, int index, Data value){
  if (list->head == NULL){
    Node * p = newNode(value, NULL, NULL);
    list->head = p;
    list->tail = p;
    list->size = list->size + 1;
    printf("first size %d\n",list->size);
  }
  else if (index > list->size-1){         ///notice "else"
    Node * p = list->tail;
    Node * tmp = newNode(value, NULL, p);
    p->next = tmp;                       // notice update
    list->tail = tmp;
    list->size = list->size + 1;
    printf("size %d\n",list->size);
  }
  else {
    Node * tmp = list->head;
    for (int i = 0; i < index; i++){
      tmp = tmp->next;
    }
    Node * p = newNode(value, tmp, tmp->prev);
    tmp->prev->next = p;
    tmp->prev = p;
    list->size = list->size + 1;
    if (index == 0) 
      list->head = p;
  }
};

Data * readData(List * list, int index){
  if (index > list->size - 1) {
    printf("null");
    return NULL;
  }
    
  else {
    Node * tmp = list->head;
    for (int i = 0; i < index; i++){
      tmp = tmp->next;
    }
    return &(tmp->data); //question??
  }
};

void removeData(List * list, int index){
  if (index == 0){
    printf("index is 0 size %d\n",list->size);
    
    if (list->head->next == NULL){
      printf("last node to remove");
      free(list->head);
      list->head = NULL;
    }
    printf("list head exist");
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    list->size -= 1;
  }
  if (index > 0 && index < list->size - 1){
    printf("normal index size %d\n",list->size);
    Node * tmp = list->head;
    for (int i = 0; i < index; i++){
      tmp = tmp->next;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    tmp = NULL;
    list->size -= 1;
  }
  if (index == list->size-1){
    printf("last index size %d\n",list->size);
    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    list->size -= 1;
  }
  if (index != 0 && index>list->size-1) {
    printf("index %d, size %d\n",index, list->size);
    printf("out of bound\n");
  }
};

void *deleteList(List * list){
  Node * tmp = list->head;
  while(tmp != NULL && tmp->next != NULL){
    tmp = tmp->next;
    free(tmp->prev);
    tmp->prev = NULL;
  }
  free(tmp);
  tmp = NULL;
  free(list);
  list = NULL;
};

