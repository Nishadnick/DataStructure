#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
	int index=data%size;
	
	
	if( arr[index].link==NULL)	
	{
		if(arr[index].value==data)
		{
			arr[index].value=-1;
			return SUCCESS;
		}
		else
		{
			return  DATA_NOT_FOUND;
		}
	}
		hash_t *temp=arr[index].link;	
		hash_t *temp2=temp->link;	
	if(arr[index].value==data)							//Arr is still passed as an array pointer and not double pointer
	{
							//temp would be  POINTER SO -> IS USED	
		//printf("1st value\n");
		//arr[index].value=-1;
		arr[index].value=arr[index].link->value;
		arr[index].link=arr[index].link->link;
		return SUCCESS;
		
	}

	else if(temp->link==NULL && temp->value!=data)			//when only 1 node is presentand data not found
	{
		//printf("else if(temp==NULL && arr[index].value!=data)\n");
		return DATA_NOT_FOUND;
	}
	else if(temp->link==NULL && temp->value==data)			//when only 1 node is present and data found
	{
		//printf("else if(temp->link==NULL && temp->value==data)\n");
		arr[index].link=temp->link;
		free(temp);
		return SUCCESS;
	}
	else if(temp->link!=NULL && temp->value==data)			//when multiple node present and value is found in 1st node
	{
		//printf("else if(temp->link!=NULL && temp->value==data)\n");
		arr[index].link=temp->link;
		free(temp);
		return SUCCESS;
	}
	else if(arr[index].value!=data)					//when data not found in array continue	
	{
		while(temp!=NULL)							//temp1 check if data found in 1st node
		{
			if(temp2->value==data)					//when data found after the 1st node
			{	
				
				temp->link=temp2->link;
				free(temp2);
				//temp->value==-1;
				return SUCCESS;
			}
			temp=temp2;
			temp2=temp2->link;
		}
		//return DATA_NOT_FOUND;
	}
		return DATA_NOT_FOUND;
	
}