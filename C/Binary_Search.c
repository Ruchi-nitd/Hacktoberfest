//Program to perform binary search on an array
#include <stdio.h>
#include <stdlib.h>

// A comparator function used by qsort 
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 
  
int main() {
   int n,s,i,low,high,mid,A[1000];
   printf("Enter the number of elements");
   scanf("%d",&n);
   
   printf("Enter the elements of array");
   for(i=0;i<n;i++)
   {
       scanf("%d",&A[i]);
   }
   
   printf("Enter the element to be searched");
   scanf("%d",&s);
   
   qsort(A, n, sizeof(int), compare);   //Binary search is applicable only on           sorted array
   low=0;
   high=n-1;                           //Initially our search space is the whole        array
   while(low<=high)
   {
       mid=low+((high-low)/2);
       if(A[mid]==s)
            break;
        else if(A[mid]>s)           // The element we are searching lies on the left side of middle element
            high=mid-1;
        else
            low=mid+1;             // The element we are searching lies on the right side of middle element
   }
   
    if(low<=high)
        printf("Element is present at index %d",mid);
    else
        printf("Element not present in the array");
    
   return 0;
}
