
#include "main.h"
#include <string.h>

int isOperator(char sym);

int expressionEvaluation(int valueA, int valueB, char sym );

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
	int length=strlen(Postfix_exp);
	char data;
	int i=0,j=0;
	char int_valueA, int_valueB, int_result;
	
	//push the values into stack and pop to get values from postfix exp while traversing to evaluate appropriately
	for(i = 0; i < length; i++)
	{
		//if it is not any operator, push Postfix_exp into stk	
		if(! isOperator(Postfix_exp[i]))
		{	
			push(stk, Postfix_exp[i]);
		}
		//else, if it is an operator
		 
		if(isOperator(Postfix_exp[i]))
		{
			// Pop the stack and call the value B
			pop(stk,&data);
			int_valueB = data;
			
			// Pop the stack and call the value A
			pop(stk,&data);
			int_valueA = data;	

			//Evaluate B op A using the operator just found.
			int_result = expressionEvaluation(int_valueA, int_valueB, Postfix_exp[i]);
			
			//change this int to ascii equivalent
			int_result += '0';				
			//printf("%d and %d: %d\n", int_valueA, int_valueB, int_result);	
			
			//Push the resulting value onto the stack
			push(stk, int_result);
			//printf("peek value: %d\n", peek(stk));				
		}		
	}	
	//Pop the stack (this is the final value)
	pop(stk,&data);
	printf("posteval %d\n",data);
	return (data - '0');
}

int expressionEvaluation(int valueA, int valueB, char sym )
{
	int a, b;
	if(  valueA >= '0' && valueA <= '9' )
	{
		a = (valueA - '0');
	}
	else
	{
		a = valueA;
	}	
	
	if( valueB >= '0' && valueB <= '9' )
	{
		b = (valueB - '0');
	}
	else
	{
		b = valueB;
	}

	switch(sym)
	{
		case '+':
			return (a + b);
			break;
		case '-':
			return (a - b);
			break;
		case '*':
			return (a * b);
			break;
		case '/':
			return (a / b);
			break;
		case '%':
			return (a % b);
			
			break;
		default:
			break;
	}	
}		