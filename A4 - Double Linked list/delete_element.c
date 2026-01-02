#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
	if (*head==NULL || *tail==NULL)
	{		
		return LIST_EMPTY;
	}
	Dlist *temp=*head;
/*	if(temp->next==NULL)
	{
		if(temp->data==data)
		{
			*head=NULL;
			*tail=NULL;
			free(temp);
			return SUCCESS;
		}
	}
	else
	{*/
		while(temp!=NULL)
		{
			if(temp->data==data && temp->next==NULL)
			{
				temp->prev->next=NULL;
				free(temp);
				return SUCCESS;
			}
			else if(temp->data==data && temp->prev==NULL)
			{
				temp->next->prev=NULL;
				*head=temp->next;
				free(temp);
				return SUCCESS;
			}
			else if(temp->data==data)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
				return SUCCESS;
			}
		temp=temp->next;
		}
		
	//}
}