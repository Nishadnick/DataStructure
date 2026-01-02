#include "sll.h"

void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is Empty\n");
	}
	Slist *temp=head;
	while (temp)		
	{
		printf("%d -> ", temp -> data);
		temp = temp -> link;
	}
	
	if (head != NULL)
	{
		printf("NULL\n");
	}
}