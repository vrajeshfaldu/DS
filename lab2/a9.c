#include<stdio.h>
void main(){   
    int n,ans=0,p,sum=1;
    scanf("%d",&n);
    scanf("%d",&p);
    for(int i=1;i<=p;i++){
        sum=sum*n;
    }
    printf("power=%d",sum);
}
