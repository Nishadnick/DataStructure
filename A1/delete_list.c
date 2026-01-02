#include "sll.h"

int sl_delete_list(Slist **head)
{
	if(*head==NULL)
	{
//		printf("LIst is emplty\n");
		return FAILURE;
	}
		
	
	Slist *temp=*head;
	while(temp!=NULL)
	{
		temp=temp->link;			//going to the next node
		free(*head);					//while the previous node (head) is free
		*head=temp;					//now there is a new head
	}
	
	return SUCCESS;	
}