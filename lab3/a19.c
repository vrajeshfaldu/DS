#include<stdio.h>
void main(){
    int max,min,n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int max2=0,min2=0;
    max=a[0];
    min=a[0];
    for(int i=0;i<=n;i++){
        if(max<a[i]){
            max=a[i];
            max2=i;
        }
        if(min>a[i]){
            min=a[i];
            min2=i;
        }
    }
    printf("number:%d = index:%d \n",max,max2);
    printf("number:%d = index:%d \n",min,min2);
    
}