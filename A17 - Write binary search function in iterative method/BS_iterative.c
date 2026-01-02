#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    int mid,upper=size,lower=0;

     mid=(lower+upper)/2;        //middle point
    while(upper>=lower)
    {
        if(key < *(arr+mid))
        {
          upper=mid-1;
          mid=(lower+upper)/2;
        }

        if(key > *(arr+mid))
        {
            lower=mid+1;
            mid=(lower+upper)/2;
        }
        if(key == *(arr+mid))
        {
			//printf("mid %d and %d ",mid,*(arr+mid));
			return mid;
            //break;
        }

    }
	return DATA_NOT_FOUND;
    //    printf("Your item is Avail on [%d]\n",mid);
}

int find_min(int arr[],int n, int k)
{
    int MIN,LOC,j;
    LOC=k;
    MIN=arr[k];
    for(j=k+1;j<n;j++)
    {
        if(MIN>arr[j])
         {
            MIN=arr[j];
            LOC=j;
         }
    }
    return(LOC);
}
/*
int selection(int *arr, int n)
{
    int k,LOC,temp;
    for(k=0;k<n-1;k++)
        {
            LOC=find_min(arr,n,k);
            temp=arr[k];
            arr[k]=arr[LOC];
            arr[LOC]=temp;
        }
}
/*void print_array(int *arr,int n)
{
    int i;
     printf(" Array :");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");

}*/
