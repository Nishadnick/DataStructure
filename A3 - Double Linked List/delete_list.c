#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
	if(*head==NULL)
	{		
		return FAILURE;
	}
	Dlist *temp=*tail;
	/*if(temp->prev==NULL)
	{
		*head=NULL;
		*tail=NULL;
		free(temp);	
		return SUCCESS;
	}*/
	while(temp!=NULL)
	{
		
		temp=temp->prev;
		free(*tail);			//make tail as temp
		*tail=temp;
	}
	*head=NULL;						//this is necessary to remove the junk
	return SUCCESS;
}