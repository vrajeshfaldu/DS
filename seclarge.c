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



// 3 largest number 
// #include <stdio.h>

// int main() {
//     int n;
//     printf("enter size of an array: ");
//     scanf("%d", &n);

//     int a[n], max = 0, max2 = 0, max3 = 0;

//     for (int i = 0; i < n; i++) {
//         printf("enter element: ");
//         scanf("%d", &a[i]);
//     }

//     max = a[0];
//     max2 = a[0];
//     max3 = a[0];

//     for (int i = 0; i < n; i++) {
//         if (a[i] > max) { // New largest
//             max3 = max2;
//             max2 = max;
//             max = a[i];
//         } 
//         else if (a[i] < max && a[i] > max2) { // Between max and max2
//             max3 = max2;
//             max2 = a[i];
//         }
//         else if (a[i] < max2 && a[i] > max3) { // Between max2 and max3
//             max3 = a[i];
//         }
//     }

//     printf("Max1: %d\n", max);
//     printf("Max2: %d\n", max2);
//     printf("Max3: %d\n", max3);

//     return 0;
// }
