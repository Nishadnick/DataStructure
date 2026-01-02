#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
	Queue_t *new=malloc(sizeof(Queue_t));		//a new wild node is prepared and its memory allocated 
	if(new==NULL)
	{
//		printf("Failed to Allocate memory\n");
		return FAILURE;
	}
	new->data=data;
	if(*front==NULL)					//front is for DqUEUE
	{								//used only ONCE
		*front=new;
		*rear=new;
		new->link=*front;
		
		//printf("enque\n");
		return SUCCESS;
	}
	
	(*rear)->link=new;					//rear ptr is attached with new data
	*rear=new;						//new becomes the new rear
	new->link=*front;				//and it attaches back to front to complete cycle
	return SUCCESS;
}