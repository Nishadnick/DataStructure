#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
	if(q->count==0)
	{
		return QUEUE_EMPTY;
	}
	//*element=q->Que[q->front];				//note data on top 
	q->front=(q->front+1)%q->capacity;
	q->count=q->count-1;								//no. of elements in que array
	return SUCCESS;
}