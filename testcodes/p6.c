#include<stdio.h>
void main(){
    int m,n;
    scanf("%d %d",&n,&m);
    int a[n],b[m],f[n+m];
    for(int i=0;i<n;i++){
        printf("enter element of 1st array:");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        printf("enter element of 2nd array:");
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        f[i]=a[i];   
    }
    
    for(int i=0;i<m;i++){
        f[n+i]=b[i];
    }
    for(int i=0;i<m+n;i++){
        printf("%d,",f[i]);
    }
    printf("\n");
    int temp;
    for(int i=0;i<m+n;i++){
        for(int j=0;j<m+n;j++){
            if(f[i]<f[j]){
                temp=f[i];
                f[i]=f[j];
                f[j]=temp;
            }
        }
    }
    for(int i=0;i<m+n;i++){
        printf("%d,",f[i]);
    }
}