#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    float avg;
    float sum=0;
    for(int i=0;i<=n;i++){
        sum=sum+i;
    }
    avg=sum/n;
    printf("%f",avg);
    return 0;
}