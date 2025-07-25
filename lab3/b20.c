#include<stdio.h>
void main(){
    int n;
    printf("enter size:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter number");
        scanf("%d",&a[i]);

    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]){
                count++; 
            }  
        }
    }
    if(count>=1){
        printf("duplicate");
    }
    else{
        printf("not duplicate");
    }
}