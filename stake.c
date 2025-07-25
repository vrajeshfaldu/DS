#include <stdio.h>

int size=100;
char stack[100];
int top = -1;

void push(char s[],char ch){
    if (top>= size-1){
        printf("Stack is overflow\n");
        return;
    }
    s[++top] =ch;
}

int pop(char s[]){
    if (top <= -1){
        printf("Stack is underflow\n");
        return 0;
    }
    return s[top--];
}

int recognize(char str[]){
    int i=0;
    char next,x;

    top=0;
    stack[top]='c';
    next=str[i];

    while(next != 'c'){
        if(next == 'c'){
            printf("Invalid string");
            return 0;
        }
        else{
        push(stack,stack[i]);
        i++;
        // next=str[i];
        }
    }
    while(stack[top]!='c'){
        x=pop(stack);
        if(next!='x'){
            printf("Invalid string");
            return 0;
        }
        i++;
        next=str[i];
    }
    if(str[i]==' '){
        printf("Valid String");
        return 1;
    }

    else{
        printf("Invalid String");
        return 0;
    }
}

void main(){
   char input[100];
   
   printf("Enter string to recognize :\n");
   scanf("%s",input);
   recognize(input);
}