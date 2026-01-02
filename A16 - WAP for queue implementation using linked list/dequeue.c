#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
	if(*front==NULL)
	{
//		printf("LIst is empty\n");
		return FAILURE;
	}
	Queue_t *temp=*front;
	
	//if(temp->link==NULL)				//temp=*head and when head-link==NULL then temp
	
	if(*front==*rear)						//only 1 node so rear=front
	{
//		printf("1st node is null\n");
		free(*front);					//free node
		*front=NULL;
		*rear=NULL;
		
		return SUCCESS;
	}
	
	temp=*front;						//as data is removed from front
	*front=(*front)->link;
	free(temp);
	(*rear)->link=*front;					//the link of rear becomes the ptr to front and cycle comlpetes
	return SUCCESS;
}