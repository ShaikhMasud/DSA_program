/*Selection Sort*/

/*
Name = Shaikh Masud
Roll No = 55
pid = 21
SE-IT
2023-24
*/
#include <stdio.h>
#include <stdlib.h>

void selectionsort(int *a,int n)
{
 int i,j,k,temp;
 for(i=0;i<n;i++)
	  {
	  for(j=i+1;j<n;j++)
	    {
	     if(a[i]>a[j])
	       {
		   temp=a[i];
		   a[i]=a[j];
		   a[j]=temp;
	       }
	     }
	     
  }
}


int main()
{
     int n,i,j,temp,a[20];

 // clrscr();
  printf("Enter total elements: ");
  scanf("%d",&n);

  printf("Enter %d elements: ",n);
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);

  selectionsort(a,n);

  printf("\nAfter sorting is: ");
  for(i=0;i<n;i++)
      printf(" %d",a[i]);

//  getch();
    return 0;
}