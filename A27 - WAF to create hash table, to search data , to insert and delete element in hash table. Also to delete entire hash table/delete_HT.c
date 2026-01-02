#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
	int index=0;
	//hash_t *temp=arr[index]->link;
	hash_t *temp=arr[index].link;
	hash_t *temp2=temp;
	for(index=0;index<size;index++)
	{
		temp=arr[index].link;
		if(arr[index].value!=-1)
		{
			arr[index].value=-1;
			arr[index].link=NULL;
		}
		while(temp!=NULL)
		{	
			//temp=temp->link;
			temp=temp->link;
			
			free(temp2);
			temp2=temp;
			
		}
	}
		return SUCCESS;
}