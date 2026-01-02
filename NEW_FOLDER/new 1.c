#include "sll.h"

int print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is Empty\n");
		return FAILURE;
	}

	Slist *temp=head;
	while (temp!=NULL)		
	{
		printf("%d -> ", temp->data);			//this will print the data 
		temp = temp->link;
	}

	printf("NULL\n");
	return SUCCESS;
}