#include<stdio.h>
void main(){
    int n;
    printf("enter rows:");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        
        for(int j=1;j<=(2*i)-1;j++){
            if(j==1||j==(2*i)-1){
                printf("1");
            }
            else if(j==(2*i)/2){
                printf("%d",i);
            }
            else{
                printf("*");
            }
        }    
        printf("\n");
    }
}