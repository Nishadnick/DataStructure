#include "sll.h"

int insert_at_first(Slist **head, int data)
{
	Slist *new=malloc(sizeof(Slist));		//a new wild node is prepared and its memory allocated 
	if(new==NULL)
	{
//		printf("Failed to Allocate memory\n");
		return FAILURE;
	}

	new->link=*head;						//the new linkk  will get the address that was in head
	new->data=data;							//data that is passed will become data of new link
	*head=new;								//the new address will become head
	return SUCCESS;
}