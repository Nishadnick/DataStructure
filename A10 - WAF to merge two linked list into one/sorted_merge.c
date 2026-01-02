#include "sll.h"
int sort(Slist **head);

int sorted_merge( Slist **head1, Slist **head2)
{
	//printf("MERGE\n");
	if (*head1==NULL && *head2==NULL)
	{
		return LIST_EMPTY;
	}
	else if (*head1!=NULL && *head2==NULL)
	{
	//	printf("*head1!=NULL\n");
		*head2=*head1;		
	}
	else if (*head1==NULL && *head2!=NULL)
	{
	//	printf("*head2!=NULL\n");
		*head1=*head2;		
	}
	else if (*head1!=NULL && *head2!=NULL)
	{		
		Slist *temp=*head1;
		
  		while(temp->link!=NULL)
		{
			temp=temp->link;		
		} 
		temp->link=*head2;
	}
	//printf("START SORT");
	sort(&(*head1));
	
	return SUCCESS;
}