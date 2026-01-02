#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t data)
{

	Slist *new=malloc(sizeof(Slist));
	new->data=data;
	new->link=NULL;
	if(new==NULL)							//chk if new memory allocation is success
	{
		//printf("memory allocation failure");
		return FAILURE;
	}
	
	
	if (*head == NULL)						//chk if list empty
	{
		/*If list is empty then create the first node */
	//	*head = new;
		printf("INFO : List is empty\n");
		return SUCCESS;
	}
	
	Slist *curr=*head;
	//Slist *prev=*head;

	if(curr->link==NULL)					//chk if there's only one node in list		
	{
		if(curr->data==g_data)				//chk if the only node available is searched
		{
			
			curr->link=new;					//put address of new node to link part of curr node
			return SUCCESS;
		}
		//printf("Element is not in list\n");
		return FAILURE;
	}
	else									//we have while inside else cz there could be repeated elements present
	{
		while(curr!=NULL)				
		{
			
			if(curr->data==g_data)			//when data is found at current node
			{
				new->link=curr->link;		//new node link will get the link of current node link
				curr->link=new;				//then current node link will get address of new node
				return SUCCESS;				//this is the proper way
			}
			curr=curr->link;
		}
		printf("INFO : %d is not found at the list\n",g_data);
		return FAILURE;
	}
}