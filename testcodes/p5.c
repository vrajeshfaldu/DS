// #include<stdio.h>
// void main(){
//     int x,y,sum=1;
//     scanf("%d %d",&x,&y);
//     for(int i=1;i<=y;i++){
//         sum=sum*x;
//     }
//     printf("ans=%d",sum);
//
//  }
#include<stdio.h>
void main(){
    int x,y;
    int ans=1;
    scanf("%d %d",&x,&y);
    int sum=0;

    for(int i=0;i<y;i++){
        int sum=0;
        for(int j=0;j<x;j++){
            sum+=ans;
        }
        ans=sum;   
    }
    printf("ans=%d",ans);

}