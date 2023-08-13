#include <stdio.h>    
     
int main()    
{    
     
    int arr[3];
    printf("Enter the 3 elements of the array");
    for(int i=0;i<3;i++)
    {
     
    scanf("%d",&arr[i]);
    }
    //Calculate length of array arr    
    int length = sizeof(arr)/sizeof(arr[0]);    
        
    printf("Duplicate elements in given array: \n");    
    //Searches for duplicate element    
    for(int i = 0; i < length; i++) {    
        for(int j = i + 1; j < length; j++) {    
            if(arr[i] == arr[j])    
                printf("%d\n", arr[j]);    
        }    
    }    
    return 0;    
}