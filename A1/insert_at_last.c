#include "sll.h"

int insert_at_last(Slist **head, int data)
{
	Slist *new=malloc(sizeof(Slist));
	new->data=data;
	if(new==NULL)
	{
//		printf("\n no mem allocation\n");
		return FAILURE;		
	}
	if(*head==NULL)
	{
//		printf("\n list emplty \n");
		*head=new;
		return SUCCESS;
		
	}
	Slist *temp=*head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=new;		//replace NULL with the address of new node
	new->link=NULL;		//new node's link is now NULL
	return SUCCESS;
	
}