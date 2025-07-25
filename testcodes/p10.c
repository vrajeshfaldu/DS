// input:2a3bc4d
// output:aabbbcdddd
#include<stdio.h>
void main(){
     char str[100];
    printf("Enter String : ");
    scanf("%[^\n]",str);
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>'0' &&  str[i]<='9' && (( str[i+1]>='A' && str[i+1]<='Z') || str[i+1]>='a' && str[i+1]<='z')){
            int a = str[i] - '0';
        //    int  b=i+1;
            for(int j=0;j<a;j++){
                printf("%c",str[i+1]);
            }
            i=i+2;
        }
        else{
        printf("%c",str[i]);
        i++;
        }
        

    }
}