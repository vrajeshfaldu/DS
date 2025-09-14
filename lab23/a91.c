// Write a program to implement Insertion Sort using Array.

#include <stdio.h>
#include <stdbool.h>

void insertionSort(int arr[], int size){

    for(int i=1 ; i<size ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){

    int arr[100], size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: ");
    for(int i=0 ; i<size ; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, size);

    printf("Sorted array: ");
    for(int i=0 ; i<size ; i++){
        printf("%d ", arr[i]);
    }
}
