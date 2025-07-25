#include<stdio.h>
void main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int sum=0;
    for(int i=m;i<=n;i++){
        sum=sum+i;
    }
    printf("sum=%d",sum);
}