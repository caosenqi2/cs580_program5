#include "Data.h"

#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector{
  Data * data;
  int current_size;
  int max_size;
  void (*insert)(struct Vector * v, int index, Data value);
  Data * (*read)(struct Vector * v, int index);
  void (*remove)(struct Vector * v, int index);
  void (*delete)(struct Vector * v);
} Vector;

void insertVector(Vector * v, int index, Data value);
Data * readVector(Vector * v, int index);
void removeVector(Vector * v, int index);
void * deleteVector();
Vector * newVector();


#endif