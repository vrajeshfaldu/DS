// 87. Write a program to implement a Linear Search using Array
#include <stdio.h>
#define MAX 100
int arr[MAX];
int n;
void main(){
    int i, val, flag=0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter value to search: ");
    scanf("%d", &val);
    for(i=0; i<n; i++){
        if(arr[i] == val){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("Element %d found at index %d\n", val, i);
    } else {
        printf("Element %d not found in the array\n", val);
    }
}
