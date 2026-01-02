#include "main.h"

/* Function to check the number is minimum or maximum to decide the position */
void max_heap(int *heap, int i, int size)
{
	  int j,temp,n,flag=1;
    size=heap[0];

    while(2*i<=size && flag==1)
    {
        j=2*i;    //j points to left child
        if(j+1<=size && heap[j+1] > heap[j])
            j=j+1;
        if(heap[i] > heap[j])
            flag=0;
        else
        {
            temp=heap[i];
            heap[i]=heap[j];
            heap[j]=temp;
            i=j;
        }
    }
}
