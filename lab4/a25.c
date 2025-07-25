#include<stdio.h>

void main(){
    int n;
    printf("enter size: ");
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int num,p;
    printf("enter position:");
    scanf("%d",&p);
    printf("enter number:");
    scanf("%d",&num);
    
    int temp;
    for(int i=p-1;i<n;i++){
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;

    }
    for(int i=0;i<n-1;i++){
        printf("%d",a[i]);
    }  
}