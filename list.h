#include "Data.h"

#ifndef LIST_H
#define LIST_H

typedef struct Node{
  Data data;
  struct Node * next;
  struct Node * prev;
} Node;

typedef struct List{
  Node * head;
  Node * tail;
  int size;
  void (*insert)(struct List * list, int index, Data value);
  Data * (*read)(struct List * list, int index);
  void (*remove)(struct List * list, int index);
  void (*delete)(struct List * list);
} List;

Node * newNode(Data data, Node * next, Node * prev);
List * newList();
void insertList(List * list, int index, Data value);
Data * readData(List * list, int index);
void removeData(List * list, int index);
void deleteList(List * list);

#endif