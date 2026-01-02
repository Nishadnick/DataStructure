#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
	
	Dlist *new = malloc(sizeof (Dlist));
	if(new==NULL)
	{
		return FAILURE;
	}
	new -> data = ndata;
	new -> prev = NULL;
	new -> next = NULL;
	
	if(*head==NULL || *tail==NULL)
	{
		return LIST_EMPTY;
	}
	
	Dlist *temp=*tail;
	if(temp==*tail && temp->prev==NULL)
	{
		if(temp->data==gdata)
		{
			
			new->prev=NULL;
			
			new->next=temp;
			temp->prev=new;
				*head=new;
			return SUCCESS;
		}
		return DATA_NOT_FOUND;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==gdata && temp->prev==NULL)
			{
				new->prev=NULL;
				new->next=temp;
				temp->prev=new;
				*head=new;
				return SUCCESS;
			}
			else if(temp->data==gdata)
			{
				new->prev=temp->prev;
				new->next=temp;
				temp->prev->next=new;
				temp->prev=new;
				return SUCCESS;

			}
			temp=temp->prev;
		}
		return DATA_NOT_FOUND;
	}
	
}