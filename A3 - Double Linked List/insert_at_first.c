#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{

	Dlist *new=malloc(sizeof(Dlist));
	
	if(new==NULL)
	{
		
		return FAILURE;
	}
	new->data=data;
	
	if(*head==NULL)
	{
		*head=new;
		*tail=new;
		return SUCCESS;
	}
	
	new->prev=NULL;				//ist node as prev as NULL
	new->next=*head;		
	(*head)->prev=new;			//node pointed by head shold have prev as 1st element
	*head=new;
	return SUCCESS;
	
}