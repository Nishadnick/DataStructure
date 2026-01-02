#include "stack.h"

int Peek(Stack_t **top)
{
	if (*top == NULL)
	{
		//printf("INFO : List is Empty\n");
		return FAILURE;
	}

	Stack_t *temp=*top;
	
	//while (temp!=NULL)		
	//{
	//	printf("%d -> ", temp->data);			//this will print the data 
	//	temp = temp->link;
	//}
	
	//printf("NULL\n");
	return temp->data;
}