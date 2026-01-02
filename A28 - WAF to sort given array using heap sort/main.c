#include "main.h"

/* Main Function */
int main()
{
	int i, limit;
	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);
	/* Declaring the array with size */
	int heap[limit];		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &heap[i]);
	}		
    max_heap(heap, limit,0);    
	/* Calling the function to bubble sort */
	heap_sort(heap, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", heap[i]);
	}		
	printf("\n");
	return 0;
}
