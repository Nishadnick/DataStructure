#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
	Dlist *new = malloc(sizeof (Dlist));

	// If the node is not created the returning failure
	if (!new)
	{
		return FAILURE;
	}
	new -> data = ndata;
	new -> prev = NULL;
	new -> next = NULL;

	// If the list is empty then inserting the node as first node
	if (*head==NULL || *tail==NULL)
	{		
		return LIST_EMPTY;
	}
	Dlist *temp=*head;
	if(temp->next==NULL && temp==*head)
	{
		if(temp->data==gdata)
		{
			new->next=NULL;
			new->prev=temp;	
			temp->next=new;
				//*tail=new;
			return SUCCESS;
		}
		return DATA_NOT_FOUND;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==gdata && temp->next==NULL)
			{
				new->next=NULL;
				new->prev=temp;
				temp->next=new;
				*tail=new;
				return SUCCESS;
			}
			else if(temp->data==gdata)
			{
				new->prev=temp;
				new->next=temp->next;
				temp->next->prev=new;
				temp->next=new;
				return SUCCESS;
			}	
		temp=temp->next;
		}
		return DATA_NOT_FOUND;
	}
}