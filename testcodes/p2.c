#include<stdio.h>
void main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=12;i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }
}