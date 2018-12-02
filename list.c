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
  int size = 0;
  l->head = l->tail = NULL;
  l->insert = insertList;
  l->read = readData;
  l->remove = removeData;
  l->delete = deleteList;
  return l;
};

void insertList(List * list, int index, Data value){
  if (list->head == NULL){
    list->head = list->tail = newNode(value, NULL, NULL);
    list->size += 1;
  }
  if (index > list->size-1){
    Node * p = list->tail;
    list->tail = p->next = newNode(value, NULL, p);
    list->size += 1;
  }
  else {
    Node * tmp = list->head;
    for (int i = 0; i < index; i++){
      tmp = tmp->next;
    }
    Node * p = newNode(value, tmp, tmp->prev);
    tmp->prev->next = p;
    tmp->prev = p;
    list->size += 1;
    if (index == 0) 
      list->head = p;
  }
};

Data * readData(List * list, int index){
  if (index > list->size-1)
    return NULL;
  Node * tmp = list->head;
  for (int i = 0; i < index; i++){
    tmp = tmp->next;
  }
  return &(tmp->data); //question??
};

void removeData(List * list, int index){
  if (index == 0){
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    list->size -= 1;
  }
  if (index > 0 && index < list->size-1){
    Node * tmp = list->head;
    for (int i = 0; i < index; i++){
      tmp = tmp->next;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    tmp = NULL;
    list->size -= 1;
  if (index == list->size-1){
    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    list->size -= 1;
  }
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
  free(list);
};


