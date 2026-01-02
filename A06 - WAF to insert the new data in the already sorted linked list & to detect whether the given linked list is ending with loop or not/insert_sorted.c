#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
	Slist *new = malloc(sizeof(Slist));
	if (!new)
	{
		return FAILURE;
	}

	/* if new node created, update data + link */
	new->data = data;
	new->link = NULL;
	
	/* temp points to first node */
	Slist *temp = *head;
	Slist *temp2 = *head;
	/* If list is empty */
	if(*head == NULL)						//this is when list is empty
	{
		new->link=*head;
		*head=new;
		return SUCCESS;
	}
	/* else */
	if(temp->link==NULL)					//if only single node then
	{
		if(temp->data > data)				//less than
		{
	//		printf("temp->data > data \n");
			new->link=*head;
			*head=new;
			return SUCCESS;
		}
		else								//greater than
		{
	//		printf("temp->data < data \n");
			new->link=temp->link;
			temp->link=new;
			return SUCCESS;
		}	
	}
	else if(temp->link!=NULL)		//Multiple NOdes
	{
		Slist *temp = *head;
		Slist *temp2 = *head;
		while (temp2!= NULL)
		{
			if(data < temp2->data && temp2==*head)			//1st instance is for head
			{
		//		printf("IF \n");
				new->link=*head;
				*head=new;
				return SUCCESS;
			}
			else if(data < temp2->data)						//the general sorting	
			{
		//		printf("ELSE IF 1\n");
				new->link=temp->link;
				temp->link=new;
				return SUCCESS;
			}
			else if(temp2->data < data && temp2->link== NULL)		//when it reaches the End
			{
		//		printf("ELSE IF 2 \n");
				temp2->link=new;
				return SUCCESS;
			}
		temp = temp2;												//this is very important 
		temp2=temp2->link;											//as messing this step will make the sorting 
																	//in parts
		}
	return FAILURE;
	}
} 