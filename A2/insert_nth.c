#include "sll.h"

int sl_insert_nth(Slist **head, data_t pos, data_t data)
{
	Slist *new=malloc(sizeof(Slist));
	new->data=data;
	new->link=NULL;
	if(new==NULL)							//chk if new memory allocation is success
	{
		//printf("memory allocation failure");
		return FAILURE;
	}
	if (*head == NULL)
	{
		//printf("List Empty\n");
		if(pos==1)
		{
		 	*head=new;
			return SUCCESS;	
		}
		return LIST_EMPTY;
	}
	int count=0;
	Slist *curr=*head;
	Slist *prev=*head;
	
	while(curr->link!=NULL)
	{
		count++;					//we'r assigning index to nodes just before using them
		if(pos==count)				//if the position maches the count of node
		{
			//printf("LOOP 1\n");
			if(pos==1)
			{
				new->link=curr;
		 		*head=new;
				return SUCCESS;	
			}
			new->link=curr;					//tempp link gets address of new node
			prev->link=new;		//connect the address of current node to the new node
		
			return SUCCESS;
		}
		prev=curr;
		curr=curr->link;
		//printf("count %d\n",count);
	}
	count++;					//increase it just once more cz it came out of while 
	if(pos==count+1)
	{
		//printf("count %d\n",count);
		curr->link=new;		//replace NULL with the address of new node
		new->link=NULL;		//new node's link is now NULL
		
		return SUCCESS;
	}
	else if(pos>count+1)
	{
		//printf("count is more %d\n",count);
		return POSITION_NOT_FOUND;
	}
}