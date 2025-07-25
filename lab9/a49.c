#include<stdio.h>
#include<stdlib.h>
void main(){
    int *iptr=(int *)malloc(sizeof(int)); // 1000, 1004 : iptr, (iptr+ i* sizzeof(int))
    char *cptr=(char *)malloc(sizeof(char));
    float *fptr=(float *)malloc(sizeof(float));
    if(*iptr && *cptr && *fptr){
        *iptr=9;
        *cptr='v';
        *fptr=4.5;
    }
    else{
        printf("invalid memory allocation");
    }
    printf("%d\n",*iptr);
    printf("%c\n",*cptr);
    printf("%.2f",*fptr);
    free(iptr);
    free(cptr);
    free (fptr);
}