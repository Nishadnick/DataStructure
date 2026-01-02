#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
	if(s->top==(s->capacity-1))
	{
		return FAILURE;
	}
	//s.top=-1;
	
	(s->top)++;
//	printf("incremnt %d\n",s->top);
	//printf("capa %d\n",s->capacity);
	s->stack[s->top]=element;
	//printf("pushed\n");
	return SUCCESS;

}