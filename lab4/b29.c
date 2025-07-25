#include<stdio.h>
int main(){
    
    int n;
    printf("enter size:");
    scanf("%d",&n);
    int m;
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter number for 1st array:");
        scanf("%d",&a[i]); 
    }
    printf("enter size for 2nd array:");
    scanf("%d",&m);
    int b[m];
     for(int i=0;i<m;i++){
        printf("enter number for 2st arry:");
        scanf("%d",&b[i]); 
     }
     int c[m+n];
     for(int i=0;i<n;i++){
        c[i]=a[i];
        
     }
     for(int i=0;i<m;i++){
      c[n+i]=b[i];
     }

     for(int i=0;i<n+m;i++){
        printf("%d",c[i]);
     }
   return 0;

}