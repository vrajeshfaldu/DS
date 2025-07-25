#include<stdio.h>
void main(){
    int a,b,max,min,count=0;
    printf("enter first number:");
    scanf("%d",&a);
    printf("enter second number:");
    scanf("%d",&b);
    if(a>b){
        max=a;
        min=b;
    }
    else{
        max=b;
        min=a;
    }
    for(int i=min;i<=max;i++){
        count=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                count++;
            }

        }
        if(count<=2){
            printf("%d ,",i);
        }
    }
}