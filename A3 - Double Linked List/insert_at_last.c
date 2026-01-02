#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
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
	Dlist *temp=*head;	
	if(temp!=NULL)
	{
		temp=temp->next;
	}	
	new->next=NULL;				//last node has next as NULL
	new->prev=*tail;		
	(*tail)->next=new;			//node pointed by tail has new as last now
	*tail=new;
	return SUCCESS;
}