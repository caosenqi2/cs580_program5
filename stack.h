#ifndef STACK_H
#define STACK_H
#include "Data.h"
#include "list.h"
#include "vector.h"

typedef struct Stacklist{
  List * data;
  Data (*peek)(struct Stacklist * stack);
  Data (*pop)(struct Stacklist * stack);
  void (*push)(struct Stacklist * stack, Data value);
  void (*clear)(struct Stacklist * stack);
  void (*delete)(struct Stacklist * stack);
} Stacklist;

Stacklist * newStacklist();
void pushStacklist(Stacklist * stack, Data value);
Data popStacklist(Stacklist * stack);
Data peekStacklist(Stacklist * stack);
void clearStacklist(Stacklist * stack);
void * deleteStacklist(Stacklist * stack);

typedef struct Stackvector{
  Vector * data;
  int stackCount;
  Data (*peek)(struct Stackvector * stack);
  Data (*pop)(struct Stackvector * stack);
  void (*push)(struct Stackvector * stack, Data value);
  void (*clear)(struct Stackvector * stack);
  void (*delete)(struct Stackvector * stack);
} Stackvector;

Stackvector * newStackvector();
void pushStackvector(Stackvector * stack, Data value);
Data popStackvector(Stackvector * stack);
Data peekStackvector(Stackvector * stack);
void clearStackvector(Stackvector * stack);
void * deleteStackvector(Stackvector * stack);

#endif