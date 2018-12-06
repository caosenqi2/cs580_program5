#include <stdio.h>
#include "vector.h"
#include "Data.h"
#include <stdlib.h>
#include <string.h>

Vector * newVector(){
  Vector * v = malloc(sizeof(Vector));
  v->data = NULL;
  //v->data->initial=0;
  v->current_size = 0;
  v->max_size = 0;
  v->insert = insertVector;
  v->read = readVector;
  v->remove = removeVector;
  v->delete = deleteVector;
  return v;
}

void insertVector(Vector * v, int index, Data value){
  if (index >= v->max_size){
    int orisize=v->max_size;
    v->max_size = index * 2 + 1;
    Data * new_array = malloc(sizeof(Data) * v->max_size);
    //new_array->value = 333;
    memcpy(new_array, v->data, sizeof(Data) * v->current_size);
    for(int i=orisize;i<v->max_size;i++){
      //new_array[i].initial=0;
      new_array[i].value=-1;
    }
    free(v->data);
    v->data = NULL;
    v->data = new_array;
  }
  if (index >= v->current_size){
    v->current_size = index + 1;
  }
  v->data[index] = value;
  //v->data[index].initial = 1; // notice
}

Data * readVector(Vector * v, int index){
  /*if(v->data[index].initial != 1){  //question??
  v->data[index].value = -1;
}*/
  if (index < v->current_size){
    return &(v->data[index]);
  }
  return NULL;
  /*if (index < v->current_size){
  return &(v->data[index]);
  }
  else{
  return NULL;
  }*/
  
  }

void removeVector(Vector * v, int index){
  if (index < v->current_size){
    //printf("current_size%d\n",v->current_size);
    if(v->current_size==1){
      //v->data=NULL;
      free(v->data);
      v->data=NULL;
      v->current_size -= 1;
      v->max_size = v->current_size;
    }
    else{
      Data * new_array = malloc(sizeof(Data) * v->current_size-1);
      for (int i = 0, j = 0; i < v->current_size; i++, j++){
        if (i != index){
          new_array[j] = v->data[i];
        }
        else{
          //i++;           //question??
          j--;
        }
      }
      free(v->data);
      v->data = NULL;
      v->data = new_array;
      v->current_size -= 1;
      v->max_size = v->current_size;
    }
  }
}

void * deleteVector(Vector * v){
  //free(v->data);
  v->data = NULL;
  free(v);
  v = NULL;
}
