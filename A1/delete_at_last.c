#include "sll.h"

int sl_delete_last(Slist **head)
{

	if(*head==NULL)
	{
//		printf("LIst is empty\n");
		return FAILURE;
	}
	
	Slist *temp=*head;
	
	if(temp->link==NULL)				//temp=*head and when head-link==NULL then temp
	{
//		printf("1st node is null\n");
		*head=NULL;
		free(temp);
		return SUCCESS;
	}
	
	while(temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	Slist *temp2=temp->link;		//here temp is 2nd last and temp->link is pointing to last so temp2 is the last node
	free(temp2);					//free the memory address and content of last node
	temp->link=NULL;				//now temp is actaully the 2nd last node remains here, we updated its link part
	
	return SUCCESS;
	
	
}