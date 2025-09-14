// 90. Write a program to implement Selection Sort using Array.
#include <stdio.h>
void main(){
    int n;
    int i, j, minIndex, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(i=0; i<n-1; i++){
        minIndex = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    
    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}