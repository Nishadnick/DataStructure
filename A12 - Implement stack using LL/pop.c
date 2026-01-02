#include "stack.h"

int Pop(Stack_t **top)
{
	if(*top==NULL)
	{
//		printf("LIst is emplty\n");
		return FAILURE;
	}
		
	Stack_t *temp=*top;
	*top=temp->link;		//jumping from 1 node's link and making it head
	free(temp);
	return SUCCESS;		
}