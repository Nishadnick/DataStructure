#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{
	
	/* If list is empty */
	if (head == NULL)
	{
		return LIST_EMPTY;
	}

	/* else */
	/* temp points to first node */
	Slist *first = head;
	Slist *last = head;
	//int count=0;
	/* traverse to next node check next node is present or not */
	while (first!= NULL)
	{
		first=first->link;
		if(pos!=0)				//1st ptr will only confirm if the forward position exixts
		{
			pos--;				//2nd ptr creates a distance of 'pos' between the 1st pts
		}
		else if(pos==0)			//so that when 1st ptr reaches end, 
		{
			last=last->link;	//then the difference would be equal to the pos value from the end
		}
		
	}
	if(pos==0)
	{
		*data=last->data;
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
	
	return SUCCESS;
}