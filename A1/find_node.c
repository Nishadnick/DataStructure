#include "sll.h"

int find_node(Slist *head, int key)
{
	if(head==NULL)
	{
//		printf("LIst is emplty\n");
		return FAILURE;
	}
	int count=0;
	Slist *temp=head;					//as temp = head so we are checking from the beginning 
//	if(temp->data==key)
//		{
//			printf("Element found\n");
//		}
	while(temp!=NULL)
	{
		count++;
		if(temp->data==key)			//chking data at a node 
		{
			printf("Element found\n");
			return count;
			
		}
		
		temp=temp->link;
	}
	return FAILURE;
}