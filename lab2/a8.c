#include<stdio.h>
void main(){
    int n,fac=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        fac=fac*i;

    }
    printf("factorial=%d",fac);
}