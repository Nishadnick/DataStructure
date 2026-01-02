#include "main.h"

int expressionEvaluation(int valueA, int valueB, char sym );
int isOperator(char sym);

int Prefix_Eval(char *Prefix_exp, Stack_t *stk);
int my_itoa(int n, char *s)
{
    int count = 0, temp, i;
    
    /* Check for buf size */
    if(s == NULL)
    {
        return 0;
    }
    
    /* if number is 0 then just give zero */
    if(n == 0)
    {
        *s = '0';
        return 1;
    }
    
    /* if num is negative int */
    if(n < 0)
    {
        n *= (-1); /* make the num positive for next evaluation */
        *s++ = '-'; /* store the '-' in s[0] and */
        count++; /* increment count for string length */
    }
    
    /* to acess s buf from s[n-1] where n is the number of digits and also to add null at nth place */
    for(temp = n; temp > 0; temp /= 10, s++);
    *s = '\0';
    
    /* fill the ASCII value of each digit by getting from lsb into s[n-1] --> s[0] place */
    for(temp = n; temp > 0; temp /= 10)
    {
        
        *--s = temp % 10 + '0';
        count++; /* increment the str len */
    }
    
    
    /* returns the string len */
    rewind(stdin);
    return count;
    
}

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
	
	int length, i, j = 0;
	char data, char_result[SIZE_STACK];

	int int_valueA, int_valueB, int_result;
	//reverse the prefix exp
	strrev(Prefix_exp);
	
	//get the length of the postfixexp
	length = strlen(Prefix_exp);
	
	//push the values into stack and pop to get values from postfix exp while traversing to evaluate appropriately
	for(i = 0; i < length; i++)
	{
		//if it is not any operator, push postfixexp into stk	
		if(! isOperator(Prefix_exp[i]))
		{	
			push(stk, Prefix_exp[i]);
		}
		//else, if it is an operator
		else 
		{
			//printf("peek value A: %d\n", peek(stk));
			int_valueA = peek(stk);
			// Pop the stack and call the value A
			pop(stk, &data);
			
			//printf("peek value B: %d\n", peek(stk));
			int_valueB = peek(stk);
			// Pop the stack and call the value B
			pop(stk, &data);

			//Evaluate B op A using the operator just found.
			int_result = expressionEvaluation(int_valueA, int_valueB, Prefix_exp[i]);
			my_itoa (int_result, char_result);
			
			//printf("%d %c %d: %s = %d\n", int_valueA,  Prefix_exp[i], int_valueB, char_result, atoi(char_result) );	
			
			//Push the resulting value onto the stack
			push(stk, int_result);
			//printf("peek value res: %d\n", peek(stk));
			
		}
		
	}	

	//Pop the stack (this is the final value)
	pop(stk, &data);
	
	if( ( data >= '0' && data <= '9' ))
   	{
        	return ((data - '0') );
    	}
	else
	{
		return (data);
	}
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