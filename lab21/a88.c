#include<stdio.h>
int binary(int a[],int n){
    int key;
    scanf("%d",&key);
    int mid;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            printf("your element is= %d ",a[mid]);
            return 1;
        }
        if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid+1;
        }
    }
    return 0;
}
int binary2(int a[],int low,int high,int key){
    
    if(low>high)return 0;
    int mid=(low+high)/2;
    if(a[mid]==key)return 1;
    if(a[mid]<key){
        low=mid+1;
        
        return binary2(a,low,high,key);
    }
    else{
        high=mid-1;
        return binary2(a,low,high,key);

    }
    return 0;
}
void main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

   int key;
    scanf("%d",&key);
int result2=binary2(a,0,n-1,key);

if(result2==0){
    printf("element not found");
   }
   else{
    printf("element is found");
   }

}
