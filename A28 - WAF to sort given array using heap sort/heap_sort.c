#include "main.h"

/* Function to sort the array using heap sort */
int heap_sort(int *heap, int size )
{
	int last=0,temp=0;
	 while(heap[0] > 1)
    {
        //swap heap[1] and heap[last]
        last=heap[0];
        temp=heap[1];
        heap[1]=heap[last];
        heap[last]=temp;
        heap[0]--;
       max_heap(heap,1,size);
    }
	printf("\n");
}       
