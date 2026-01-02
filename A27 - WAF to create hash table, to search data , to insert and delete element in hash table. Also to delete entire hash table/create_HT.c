#include "hash.h"

void create_HT(hash_t *HT, int size)
{
	//hash_t=malloc(sizeof(hash_t)*size);
	//hash_t arr=malloc(sizeof(int)*size);			//no need to allocate memory for array 
													//
	int i=0;
	for(i=0;i<size;i++)
	{
		HT[i].index=i;
		HT[i].value=-1;
		HT[i].link=NULL;
		//return SUCCESS;
	}
   //return FAILURE;
}