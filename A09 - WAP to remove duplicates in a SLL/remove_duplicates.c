#include "sll.h"


int remove_duplicates( Slist **head )
{
	if (*head == NULL)
	{
	return FAILURE;			//list empty
	}
	Slist *prev = *head;
	Slist *ptr1 = *head;
	Slist *ptr2 = NULL;

	while (ptr1 != NULL && ptr1->link != NULL) 
	{
        prev = ptr1;										//new assignment of prev
        /* Compare the picked element with rest
           of the elements */
        while (prev->link != NULL) 
		{   												// If duplicate then delete
            if (ptr1->data == prev->link->data) 			//not using ptr2 becaus eit was causing problems
			{
                ptr2 = prev->link;							//only useing it for freeing ptr
                prev->link = prev->link->link;				//the mid node is skipped
                free(ptr2);
            }
            else
			{
				prev = prev->link;							//moving prev to chk next number
			}
        }
        ptr1 = ptr1->link;									//iteration over goto next
    }
	return SUCCESS;
}