#include <stdio.h>
#include<stdlib.h>
void main(){
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
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(*(ptr+( i*sizeof(int)))>*(ptr+( j*sizeof(int)))){
                int temp=*(ptr+( i*sizeof(int)));
                *(ptr+( i*sizeof(int)))=*(ptr+( j*sizeof(int)));
                *(ptr+( j*sizeof(int)))=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",*(ptr+( i*sizeof(int)))); 
    }
}
}