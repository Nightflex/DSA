#include<stdio.h>
void main()
{
    int i,j,n,min,temp;
    int arr[10];
    printf("\n Enter the no of elements \n");
    scanf("%d",&n);
    printf("\n Enter the elements \n");
    for(i=0;i<n;i++)
    {                                       
     scanf("%d",&arr[i]);
    }
    printf("\n The elements of array initially are \n");
    for(i=0;i<n;i++)
    {
     printf("%d \t",arr[i]);
    }
    for(i=0;i<n;i++)
    {
      min=i;
      for(j=i+1;j<n;j++)
      {
        if(arr[j]<arr[min])
        {
           min=j;
        }
        if(min!=i)
        {
           temp=arr[i];
           arr[i]=arr[min];
           arr[min]=temp;
        }
      }
    }
    printf("\n Elements after selection sort \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}