#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
	/* If list is empty */
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	/* else */									//3 pointers
	Slist *curr = *head;						//curr is the base ptr
	Slist *prev = NULL;							//prev is the ptr that will move ahead as curr->link and then become curr
	//Slist *next = curr->link;					//next will be the ptr holding the future addresses
	Slist *next = *head;	
	/* traverse to next node check next node is present or not */
	while (next!= NULL)
	{
		//next = curr->link;
		next=next->link;						//this is just the link from head
		curr->link=prev;						//at this pt, back node is connected to curr
		prev=curr;								//move ptr ahead
		curr=next;								//next will become curr
								//next will move ahead
	}
		*head=prev;								//curr->link will get the prev address and
	return SUCCESS;
} 