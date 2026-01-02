#include "sll.h"

int sl_delete_first(Slist **head)
{

	if(*head==NULL)
	{
//		printf("LIst is emplty\n");
		return FAILURE;
	}
		
	Slist *temp=*head;
	*head=temp->link;		//jumping from 1 node's link and making it head
	free(temp);
	return SUCCESS;		
}