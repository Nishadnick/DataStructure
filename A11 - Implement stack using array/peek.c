#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{
	/* Checking the Stack is empty or not */
	if (s->top == -1)
	{
		//printf("INFO : Stack is empty\n");
		return FAILURE;
	}
    else
    {
	    /* Declaring the temp for store the top value to print the values in the Stack*/
	   return s->stack[s->top];
    }
}