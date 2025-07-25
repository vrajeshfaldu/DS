// . WAP to find the largest element in the array using Pointer.
#include <stdio.h>

#include<stdlib.h>
void main() {
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *iptr=(int *)malloc(sizeof(int )*n); 
    int arr[n];  
    int *ptr = arr;  
    printf("enter elements of array:\n", n);
    if(ptr){
    for(i = 0; i < n; i++) {
        scanf("%d",(ptr+( i*sizeof(int))));  
    }
    int max=*ptr;
    for(i=0;i<n;i++){
        if(max<*(ptr+( i*sizeof(int)))){
            max=*(ptr+ (i*sizeof(int)));
        }
    }
    printf("largest = %d",max);
    }
    else{
        printf("not allocate");
    }
    

}