// 89. Write a program to implement Bubble using Array.
#include <stdio.h>

void main(){
    
     
       int n;
    int i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}