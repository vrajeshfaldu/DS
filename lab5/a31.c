#include<stdio.h>
void main(){
    int a[2][2],b[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("enter 1st matrix elements:");
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("enter 2nd matrix elements:");
            scanf("%d",&b[i][j]);
        }
    }
    int c[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
        
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d  ",c[i][j]);
        }
        printf("\n");
        
    }
    

}