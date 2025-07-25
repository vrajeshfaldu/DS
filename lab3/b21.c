#include<stdio.h>

void main(){
    int n;
    printf("enter size: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b,c,p;
    printf("enter number:");
    scanf("%d",&b);
    printf("enter number which you want to change:");
    scanf("%d",&c);
    for(int i=0;i<n;i++){
        if(a[i]==b){
            a[i]=c;
            p=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d index:%d",a[i],i);
    }
}