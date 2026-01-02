#include "main.h"


void strrev(char *string)
{
    /* TODO: Write logic for string reverse */
		int length, c;
   	char *begin, *end, temp;
 
	//get teh length of the string to be reversed
   	length = strlen(string);

	//pointer to beginning
   	begin  = string;

	//pointer to end of string
   	end    = string;
    	for (c = 0; c < length - 1; c++)
   		end++;
 	
	//change the pointer values to reverse
   	for (c = 0; c < length/2; c++)
   	{        
      		temp   = *end;
      		*end   = *begin;
      		*begin = temp;
 
      		begin++;
      		end--;
   	}
}



int main()
{
	char Infix_exp[50], Prefix_exp[50], ch;
	int choice, result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	strrev(Infix_exp);
	Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);
	//strrev(Prefix_exp);
	printf("PreFix expression : %s\n", Prefix_exp);

	stk.top = -1;

	strrev(Prefix_exp);
	result = Prefix_Eval(Prefix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}
