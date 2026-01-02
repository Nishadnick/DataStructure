#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
	Slist *new = malloc(sizeof(Slist));
	if (!new)
	{
		return FAILURE;
	}

	/* if new node created, update data + link */
	//new->data = data;
	//new->link = NULL;
	/* If list is empty */
	if (head == NULL)
	{
		return LIST_EMPTY;
	}

	/* else */
	/* temp points to first node */
	Slist *temp = head;
	Slist *temp2 = head;
	int count=0;
	/* traverse to next node check next node is present or not */
	while (temp2!= NULL)
	{
		count++;
		temp2=temp2->link;
		{
			if(count%2==0)
			{
				temp = temp->link;
			}
			if(temp==temp2 && temp2!=NULL)
			{
				return SUCCESS;
			}
		}
	}
	return LOOP_NOT_FOUND;
}