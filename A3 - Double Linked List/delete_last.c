#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
	if(*head==NULL)
	{		
		return FAILURE;
	}
	Dlist *temp=*tail;
	if(temp->prev==NULL)
	{
		*head=NULL;
		*tail=NULL;
		free(temp);	
		return SUCCESS;
	}
	//if(temp->next!=NULL)
//	{
	//	temp=temp->next;
	//}	
	*tail=temp->prev;			//skipping last
	(*tail)->next=NULL;			//last node has next as NULL
	free(temp);
	return SUCCESS;

}