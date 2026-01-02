#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{
	int index=data%size;
	hash_t *temp=arr[index].link;
	if(arr[index].value==data)
	{
		//return DATA_FOUND;
		return 1;
	}
	else if(arr[index].value!=data )
	{
		if(temp!=NULL)
		{
			if(temp->value==data)
			{	
				//temp->data==-1;
				//return DATA_FOUND;
				return 1;
			}
			temp=temp->link;
		}
		return DATA_NOT_FOUND;
	}
	
}