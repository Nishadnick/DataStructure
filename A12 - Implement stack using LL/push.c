#include "stack.h"

int Push(Stack_t **top, data_t data)
{

	Stack_t *new=malloc(sizeof(Stack_t));		//a new wild node is prepared and its memory allocated 
	if(new==NULL)
	{
//		printf("Failed to Allocate memory\n");
		return FAILURE;
	}

	
	new->link=*top;						//the new linkk  will get the address that was in head
	new->data=data;							//data that is passed will become data of new link
	*top=new;								//the new address will become head
	return SUCCESS;
}