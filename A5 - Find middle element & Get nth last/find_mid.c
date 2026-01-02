#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{
	
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
	while (temp!= NULL)
	{
		count++;
		if(count%2==0)
		{
			temp2=temp2->link;
		}
		temp = temp->link;
	}
	*mid=temp2->data;
	return SUCCESS;
}