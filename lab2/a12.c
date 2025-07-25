#include<stdio.h>
void main(){
    int n,m,count=0,i;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }

    }
    if(count<=2){
        printf("prime");
    }
    else{
        printf("not prime");
    }
}
