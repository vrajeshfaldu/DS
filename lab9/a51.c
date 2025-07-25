#include <stdio.h>
#include<stdlib.h>

void main() {
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *ptr=(int *)malloc(sizeof(int )*n); 
    int sum=0;
     
     for(i = 0; i < n; i++) {
        scanf("%d",(ptr+ i*sizeof(int)));  
        sum+=*(ptr+ i*sizeof(int));
    }
    printf("%d",sum);
    free(ptr);
}