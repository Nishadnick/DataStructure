#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{

	if(q->count==q->capacity)
	{
		return QUEUE_FULL;
	}
	if(q->front==-1)					//front is for DqUEUE
	{
		q->front=0;
	}
	q->rear=(q->rear+1)%(q->capacity);
	q->Que[q->rear]=data;		//put data in que array
	q->count=q->count+1;					//no of elememts in queue
	return SUCCESS;
}