#include<stdio.h>
void main(){
    int n,m,p,i;
    scanf("%d",&n);
    while (n!=0){
        m=n%10;
        n=n/10;
        printf("%d",m);
        i++;
    } 
}