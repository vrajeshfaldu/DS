#include<stdio.h>
int power(int m,int count){
    int sum=1;
    for(int i=1;i<=count;i++){
        
        sum=sum*m;
    }
    return sum;
}

void main(){
    int n;
    printf("enter number:");
    scanf("%d",&n);
    int p=n;
    int a=n;
    int m=1,count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    int ans=0;
    while(p!=0){
        m=p%10;
        ans=ans+power(m,count);
        p=p/10;
    }
    printf("%d is ",ans);
    if(ans==a){
        printf("armstrong");
    }
    else{
        printf("not armstrong");
    }    
}