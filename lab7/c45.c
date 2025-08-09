// 5. You have an array A of integers of size N, an array B (initially empty) and a stack 
// S (initially empty). You are allowed to do the following operations:
// • Take the first element of array A and push it into S and remove it from A.
// • Take the top element from stack S, append it to the end of array B and 
// remove it from S.
// You have to tell if it possible to move all the elements of array A to array B using 
// the above operations such that finally the array B is sorted in ascending order.
// Input Format :
// • First line will contain T, number of testcases. Then the testcases follow.
// • First line of each testcase contains a single integer N.
// • Second line of each testcase contains N distinct integers : A1,A2...AN.
// Output Format :
// For each testcase, if it possible to move all the elements of array A to array B 
// using the above operations such that finally, the array B is sorted in ascending 
// order, print "YES" (without quotes), else print "NO" (without quotes).
#include <stdio.h>

int size = 100;
int stack[100];
int top = -1;
void  push(int ch){

    if (top >= size - 1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
        
}
int  pop(){
    if (top < 0){
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}
void display(){
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i<=top; i++){
        printf("%c", stack[i]);
    }
}

int sorted(int arr2[],int n){
      int temp;
    for (int i = 0; i < n-1; i++) {
        if(arr2[i]>arr2[i+1]){
            return 0;
        }
    }
    return 1;

}
void rev(int arr[],int arr2[],int n,int *ans){
    
    int temp,j=0;
    for(int i=0;i<n;i++){
        
        push(arr[i]);
        if(i==(n-1)){
            break;
        }
        if(stack[top]<arr[i+1]){
            arr2[j++]=pop();
        }
    }
    while(top!=-1){
        arr2[j++]=pop();
    }
    *ans=sorted(arr2,n);
    
}
void main(){
    int n;
    printf("Enter size of an araay");
    scanf("%d",&n);
    int arr[n];

   for(int i=0;i<n;i++){
    printf("Enter element:");
    scanf("%d",&arr[i]);
   }
   int arr2[n],ans;
    rev(arr,arr2,n,&ans);
    if(ans==1){
        printf("YES");
    }
    else{
        printf("NO");
    }
}
