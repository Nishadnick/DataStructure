#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t data)
{

	Slist *new=malloc(sizeof(Slist));
	new->data=data;
	new->link=NULL;
	if(new==NULL)							//chk if new memory allocation is success
	{
		//printf("memory allocation failure");
		printf("INFO : List is empty\n");
		return FAILURE;
	}
	
	
	if (*head == NULL)						//chk if list empty
	{
		/*If list is empty then create the first node */
		//*head = new;
		return LIST_EMPTY;
	}
	
	Slist *curr=*head;
	Slist *prev=*head;

	if(curr->link==NULL)					//chk if there's only one node in list		
	{
		if(curr->data==g_data)				//chk if the only node available is searched
		{
			//new->link=curr;					//put adress of current node in link of new node
			new->link=*head;
			*head=new;						//make head point to new node
			return SUCCESS;
		}
		//printf("Element is not in list\n");
		return DATA_NOT_FOUND;
	}
	else									//we have while inside else cz there could be repeated elements present
	{
		while(curr!=NULL)				
		{	
			if(curr->data==g_data && curr==*head)			//1st instance is for head
			{
				//new->link=curr;
				//curr=new;
				new->link=*head;
				*head=new;
				return SUCCESS;
			}
			else if(curr->data==g_data && curr!=*head)			//when data is found at current node
			{
				new->link=prev->link;				//new node link will get address of current node
				prev->link=new;				//and the previous node link will get address of new node
				return SUCCESS;				//this is the proper way
			}
			prev=curr;
			curr=curr->link;
		}
		//printf("INFO : %d is not found at the list\n",g_data);
		return DATA_NOT_FOUND;
	}
}