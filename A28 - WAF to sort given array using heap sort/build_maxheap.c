#include "main.h"

void build_maxheap(int *heap, int size)
{
	int i;
    size=heap[0]; //no. of elements
    for(i=size/2;i>=1;i--)
        max_heap(heap,i,size);
}