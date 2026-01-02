#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
	if(*head==NULL)
	{	
		return FAILURE;
	}
	Dlist *temp=*head;
	if(temp->next==NULL)
	{
		*head=NULL;
		*tail=NULL;
		free(temp);
		return SUCCESS;
	}
	
	*head=temp->next;				//skipping temp
	temp->prev=NULL;				//1st node has prev as NULL
	free(temp);
	return SUCCESS;
	
	
}