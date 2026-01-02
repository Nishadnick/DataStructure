#include "main.h"

void strrev(char *string); 
int priority(char sym);

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
	int length, i, j = 0;
	char data;
	//reverse the infix
	strrev(Infix_exp);
		
	//get the legth of the Infix_exp
	length = strlen(Infix_exp);
	//printf("length: %d\n", length );
	
	//push the values into stack and pop to get prefix exp while traversing from back
	for(i = 0; i < length; i++)
	{
		//if it is not any operator, copy to Prefix_exp and increment the index			
		if(! isOperator(Infix_exp[i]))
		{	
			Prefix_exp[j] = Infix_exp[i];
			j++;
		}
		//else, if it is an operator
		else 
		{
			//if the operator is ')' then push this onto stack
			if(Infix_exp[i] == ')')
			{
				push(stk, Infix_exp[i]);
			}
			//if the operator is '(' 
			else if (Infix_exp[i] == '(')
			{
				
				//if there are no other inner brackets
				while (peek(stk) != ')')
				{
					//get the operator from the top and save it onto prefix and increment the index
					pop(stk, &data);
					Prefix_exp[j] = data;
					j++;
				}
				//pop that operator out of the stack, as it is copied
				pop(stk, &data);				
			}
			//for any other operators 
			else
			{
				//check for precedency rule, if the top of the stack operator is less then push then push new operator
				if ( priority(peek(stk)) <= priority(Infix_exp[i]) )
				{
					push(stk, Infix_exp[i]);
				}
				//else, 
				else
				{
					//pop out the operators and save in Prefix_exp till it becomes less than
					while ( priority(peek(stk)) >= priority(Infix_exp[i]) )
					{
						pop(stk, &data);
						Prefix_exp[j] = data;
						j++;
					}
					//once the stack is cleared of that , push the new operator
					push(stk, Infix_exp[i]);
				}
			}	
		}
	}	

	//after the operator check, till stack becomes empty, pop the values and save in Prefix_exp and increment the index	
	while (stk->top != -1)
	{
		pop(stk, &data);
		Prefix_exp[j] = data;
		j++;
	}

	//make Prefix_exp string
	Prefix_exp[j] = '\0';

	//reverse the Prefix_exp to get the actual exp
	strrev(Prefix_exp);	
	
}
	
