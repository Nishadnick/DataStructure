#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
	/* If list is empty */
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}

	/* else */
	/* temp points to first node */
	Slist *temp = NULL;
	Slist *temp2 = *head;
	
	/* traverse to next node check next node is present or not */
	while (temp2->link!= NULL)
	{
		temp2=temp2->link;
		if(temp2->data==data)
		{
			temp = temp2;
		}	
	}
	if(temp!=NULL)
	{
		temp2->link=temp;
		return SUCCESS;
	}
	else
	{
		return DATA_NOT_FOUND;
	}
}