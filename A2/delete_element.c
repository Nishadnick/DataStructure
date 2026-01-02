#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
	
	if (*head == NULL)
	{
		//printf("List Empty\n");
		return FAILURE;
	}
	Slist *curr=*head;
	Slist *prev=NULL;
	
	while(curr!=NULL)
	{
	//	if((*head)->data==data)
		if(curr==*head && curr->data==data)				//this will be head content
		{
			*head=curr->link;
			free(curr);
			return SUCCESS;
		}
		else if(curr!=*head && curr->data==data)		//chk and make it different then head content
		{
			prev->link=curr->link;			//connecting the link of required node to back node 
			
			free(curr);						//clear memory of the requied node
			return SUCCESS;
		}
		prev=curr;							//making a copy of addrss of a node
		curr=curr->link;					//also having the address of next node
	}
	return DATA_NOT_FOUND;
}