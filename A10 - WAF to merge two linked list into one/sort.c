#include "sll.h"

int sort(Slist **head)
{
	if (*head==NULL)
	{
		return LIST_EMPTY;
	}
	
	Slist *ptr1=*head;
	Slist *ptr2=ptr1->link;
	Slist *swap=*head;

    int i, j, flag=0, len=0;
  	while(swap!=NULL)
	{
		swap=swap->link;
		len++;
	} 
	//printf("len %d\n",len);
    for (i=0;i<=len;i++)
    {
		//printf("Loop1\n");
       
        flag = 0;
        for (j=0;j<len-1-i;j++) 
        {
			//printf("Loop2\n");
            if(ptr1->data>ptr2->data && ptr1==*head)			//this is for when head start
            { 
            	//printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);
			//	printf("IF\n");
				swap=ptr2->link;				
				ptr2->link=ptr1;
				ptr1->link=swap;	
			//	printf("SWAP\n");	
				flag=1;
				*head=ptr2;
				swap=ptr2;										//swap is first used to gather the ptr before ptr2
				ptr2=ptr1->link;
			//	printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);  
			}  
			else if(ptr1->data > ptr2->data && ptr1!=*head)		//this ia almost for remaining
			{
			//	printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);
			//	printf("ELSE IF\n");
				swap->link=ptr2;				
				ptr1->link=ptr2->link;;
				ptr2->link=ptr1;	
			//	printf("SWAP\n");	
				flag=1;
				swap=ptr2;										//swap used here too for gathering the ptr before ptr2
				ptr2=ptr1->link;
			//	printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);
			}
			else if(ptr1->data < ptr2->data) 					//
			{
			//	printf("ELSE IF2\n");
			//	printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);			
				swap=ptr1;										//swap is just shifted
				ptr1=ptr2;
				ptr2=ptr2->link;
			//	printf("NO SWP\n");
				flag=1;
				if(ptr1->link==NULL)
					break;
			//	printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);
			}	
			if(ptr1->data > ptr2->data && ptr2->link==NULL)			//here ptr1->link will become NULL
			{
			//	printf("EEND\n");
			//	printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);
				swap->link=ptr2;				
				ptr1->link=NULL;	//
				ptr2->link=ptr1;	
				flag=1;
				//printf("swap=%d,ptr1=%d,ptr2=%d\n",swap->data,ptr1->data,ptr2->data);
				//printf("BREAK 1st\n");
				break;
				
			}						
			 //swap = (swap)->link;
			//printf("inner loop End\n");
        }
		if(flag==0)												//this is also a break condition where, if an iteration comes 
		{break;}												// which has already fulfilled all conditions and now 
		ptr1=*head;												//doesn't have anything left so it'll be 0
		ptr2=ptr1->link; 										//these are for the next interation
    }
    return SUCCESS;
}
