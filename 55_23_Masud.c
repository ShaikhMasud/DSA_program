/* Merge Sort */

/*
Name = Shaikh Masud
Roll No = 55
pid = 23
SE-IT
2023-24
*/
#include<stdio.h>
# include <stdlib.h>

void partition(int *,int,int);

void main(){

  int n,temp,i,j,a[20];
  
  printf("Enter total numbers of elements: ");
  scanf("%d",&n);

  printf("Enter %d elements: ",n);
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);

  partition(a,0,n-1);

  printf("\n After sorting: ");
  for(i=0;i<n;i++)
      printf(" %d",a[i]);


}

void partition(int *a,int low,int high)
{
    int mid=0;

    if(low<high)   // divide the array into half till it has single element
    {
      mid=(low+high)/2;
      partition(a,low,mid);
      partition(a,mid+1,high);
      mergesort(a,low,mid,high);
    }
}

 mergesort(int *a,int low,int mid,int high)
{
 int i,m,k,l,temp[20];
 l=low;
 i=low;            //iterator for merged array
 m=mid+1;

 while(l<=mid && m<=high)                  // this will iterate till all the element from
   {                                       //left & right subarray are compared.
    if(a[l]<=a[m])                         // a[l] points to first element of left sub-array
	  {                                // a[m] points to first element of right sub-array
	      temp[i]=a[l];                // temp is merged array
		  l++;i++;
     }
    else
     {
		temp[i]=a[m];
		m++;i++;
     }
  } // end of while


 if(l>mid)                 // this is true when all left sub-arr element are compared
   {
     for(k=m;k<=high;k++)  //d remaning element of right arr r stored in merged array
       {
	 temp[i]=a[k];
	 i++;
       }
   }
 else
   {
    for(k=l;k<=mid;k++)
     {
      temp[i]=a[k];
      i++;
     }
   }


   for(k=low;k<=high;k++)
  {
    a[k]=temp[k];
  }
 }