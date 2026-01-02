#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
	
	int index=element%size;
	if(arr[index].value==-1)			//this means there's no element
	{
		arr[index].value=element;
		arr[index].link=NULL;
		return SUCCESS;
	}
	
	hash_t *new=malloc(sizeof(hash_t));		//new node in case element is present
	if(new==NULL)
	{
		return FAILURE;
	}
	new->index=index;						//
	new->value=element;
	new->link=NULL;
	if(arr[index].link==NULL)				//1st linked node
	{
		arr[index].link=new;
	}
	else
	{
		hash_t *temp=arr[index].link;		//further nodes added
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=new;
		return SUCCESS;
	}
}