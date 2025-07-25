#include<stdio.h>
#include<string.h>

void main(){

    char str[10];
    printf("Enter String : ");
    scanf("%[^\n]",str);

    for(int i=0 ; i<strlen(str) ; i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
    printf("%s",str);
}       