#include "main.h"
#include <string.h>

int isOperator(char sym);

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
	int length=strlen(Infix_exp);
	char data;
	int i=0,j=0;
		//push the values into stack and pop to get postfix exp while traversing
	for(i = 0; i < length; i++)
	{
		//if the operator is '(' then push this onto stack
		if(Infix_exp[i] == '(')
		{
			push(stk, Infix_exp[i]);
		}
		else if(! isOperator(Infix_exp[i]))
		{	
			Postfix_exp[j] = Infix_exp[i];				//pushed the numbers in Postfix
			//printf("Infix_exp[i] %d\n",Infix_exp[i]);
			j++;
		}
		//if the operator is ')' 
		else if (Infix_exp[i] == ')')
		{
			//if there are no other inner brackets
			while (peek(stk) != '(')
			{
				//get the operator from the top and save it onto postfix and increment the index
				pop(stk,&data);
				Postfix_exp[j] = data;
					
				j++;
			}
			//pop that operator out of the stack, as it is copied
			pop(stk,&data);				
		}
		//for any other operators 
		else
		{
			//pop out the operators and save in prefixexp till it becomes less than
			while ( priority(peek(stk)) >= priority(Infix_exp[i]) )
			{
				pop(stk,&data);
				Postfix_exp[j] = data;
				j++;
			}
			//once the stack is cleared of that , push the new operator
			push(stk, Infix_exp[i]);
		//	printf("Infix_exp[i] %c\n",Infix_exp[i]);
		}		
	}	
	//after the operator check, till stack becomes empty, pop the values and save in prefixexp and increment the index	
	while (stk->top != -1)
	{
		pop(stk,&data);
	//j++;													//pre incrementing
		Postfix_exp[j] = data;
		j++;
		
	}
	//make prefixexp string
	Postfix_exp[j] = '\0';
}

int isOperator(char sym)
{
	switch(sym)
	{
		case '*':
		case '+':
		case '-':
		case '{':
		case '}':
		case '(':
		case ')':
		case '/':
		case '%':
			return 1;
			 break;
		default:
			return 0;
		
	}
}

