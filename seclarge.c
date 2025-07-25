#include<stdio.h>
void main(){
    int n;
    printf("enter size of an array:");
    scanf("%d",&n);
    int a[n],max=0,max2=0;
    for(int i=0;i<n;i++){
        printf("enter element:");
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(int i=0;i<n;i++){

        if(max<a[i]){   
            max2=max; 
            max=a[i];    
        }
        else if(a[i]<max && a[i]>max2){
        max2=a[i];
        }
    }
    printf("%d \n",max);
    printf("%d \n",max2);
}