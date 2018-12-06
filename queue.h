#ifndef QUEUE_H
#define QUEUE_H
#include "Data.h"
#include "list.h"
#include "vector.h"

typedef struct Queuelist{
  List * data;
  void (*enqueue)(struct Queuelist * queue, Data value);
  Data (*dequeue)(struct Queuelist * queue);
  Data (*peek)(struct Queuelist * queue);
  void (*clear)(struct Queuelist * queue);
  void (*delete)(struct Queuelist * queue);
} Queuelist;

Queuelist * newQueuelist();
void enqueueQueuelist(Queuelist * queue, Data value);
Data dequeueQueuelist(Queuelist * queue);
Data peekQueuelist(Queuelist * queue);
void clearQueuelist(Queuelist * queue);
void * deleteQueuelist(Queuelist * queue);

typedef struct Queuevector{
	Vector * data;
	int queueCount;
	Data (*peek)(struct Queuevector *);
  Data (*dequeue)(struct Queuevector *);
  void (*enqueue)(struct Queuevector *, Data);
  void (*clear)(struct Queuevector *);
  void (*delete)(struct Queuevector *);
} Queuevector;

Queuevector * newQueuevector();
void pushQueuevector(Queuevector * queue, Data value);
Data popQueuevector(Queuevector * queue);
Data peekQueuevector(Queuevector * queue);
void clearQueuevector(Queuevector * queue);
void deleteQueuevector(Queuevector * queue);

#endif