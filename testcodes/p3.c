#include<stdio.h>
void main(){
    int n;
    printf("enter how many elements you want");
    scanf("%d",&n);
    int a=0,b=1,sum=0;
    for(int i=0;i<n;i++){
        sum=a+b;
        printf("%d ",a);
        a=b;
        b=sum;
    }

}