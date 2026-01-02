#include "sll.h"

int reverse_recursion(Slist ** head,Slist **prev,Slist **curr,Slist **next)
{
	if (*head == NULL)
	{
		return LIST_EMPTY;
	}
	if(*next!= NULL)
	{
		//next = curr->link;
		*next=(*next)->link;						//this is just the link from head
		(*curr)->link=*prev;						//at this pt, back node is connected to curr
		*prev=*curr;								//move ptr ahead
		*curr=*next;								//next will become curr
		reverse_recursion(head,prev,curr,next);
	}
	else
	{	
		*head=*prev;								//curr->link will get the prev address and
		return SUCCESS;
	}
}