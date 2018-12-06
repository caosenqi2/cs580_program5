#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "vector.h"
#include "list.h"
#include "queue.h"

Queuelist * newQueuelist(){
  Queuelist * queue = malloc(sizeof(Queuelist));
  queue->data = newList();
  queue->enqueue = enqueueQueuelist;
  queue->dequeue = dequeueQueuelist;
  queue->peek = peekQueuelist;
  queue->clear = clearQueuelist;
  queue->delete = deleteQueuelist;
  return queue;
};

void enqueueQueuelist(Queuelist * queue, Data value){
  queue->data->insert(queue->data, queue->data->size, value);
};

Data dequeueQueuelist(Queuelist * queue){
  Data d;
  if(queue->data->size == 0){
    d.value = -1;
  }
  else{
    d = *queue->data->read(queue->data, 0);
    queue->data->remove(queue->data, 0);
  }
  return d;
};

Data peekQueuelist(Queuelist * queue){
  Data d;
  if(queue->data->size == 0){
    d.value = -1;
  }
  else{
    d = *queue->data->read(queue->data, 0);
  }
  return d;
}
void clearQueuelist(Queuelist * queue){
  while(queue->data->size>0){
    queue->data->remove(queue->data,0);
  }
};
void * deleteQueuelist(Queuelist * queue){
  free(queue);
  queue = NULL;
};


Queuevector * newQueuevector(){
  Queuevector * queue = malloc(sizeof(Queuevector));
  queue->data = newVector();
  queue->queueCount = 0;
  queue->enqueue = pushQueuevector;
  queue->dequeue=popQueuevector;
  queue->peek=peekQueuevector;
  queue->clear=clearQueuevector;
  queue->delete=deleteQueuevector;
  return queue;
}

void pushQueuevector(Queuevector * queue, Data value){
	queue->data->insert(queue->data, queue->queueCount, value);
	queue->queueCount += 1;
}

Data popQueuevector(Queuevector * queue){
	Data d;
	if(queue->queueCount==0){
		d.value=-1;
	}
	//Data *num=malloc(sizeof(Data));
	//printf("abc\n");
	else{
	Data *num=queue->data->read(queue->data,0);
	//printf("%d\n",queue->queueCount);
	d=*num;
	queue->data->remove(queue->data,0);
	//printf("%d",queue->data->data->value);
	queue->queueCount-=1;
	//printf("abc\n");
	}
	//printf("%d\n",d.value);
	return d;
}
Data peekQueuevector(Queuevector * queue){
	Data *num=queue->data->read(queue->data,0);
	Data d=*num;
	//printf("c\n");
	return d;
}
void clearQueuevector(Queuevector * queue){
	for(int i=queue->queueCount;i>0;i--){
		queue->data->remove(queue->data,queue->queueCount-1);
		queue->queueCount-=1;
	}
}
void deleteQueuevector(Queuevector * queue){
	/*free(queue->data);
	queue->data=NULL;*/
	queue->data->delete(queue->data);
	free(queue);
	queue=NULL;
}
