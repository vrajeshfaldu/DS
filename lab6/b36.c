#include <stdio.h>

int size = 100;
char stack[100];
int top = -1;
int size2=100;
char stack2[100];

int top2 = -1;


void push(char ch){

    if (top >= size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    
    stack[top] = ch;    
}
void push2(char ch){

    if (top2 >= size2 - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top2++;
    
    stack2[top2] = ch;    
}
void sep(char str[]){
   int  i=0;
   if(str[0]=='\0'){
    printf("stack overflow");
    return;
   }
   while(str[i]!='\0'){
    if(str[i]=='a'){
        push(str[i]);

    }
    else{
        push2(str[i]);
    }
    i++;
   }
    }
void display(){
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("A- Stack elements are:\n");
    for (int i = top; i >= 0; i--){
        printf("%c", stack[i]);
    }
}
void display2(){
    if (top2 == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("\n");
    printf("B- Stack elements are:\n");
    for (int i = top2; i >= 0; i--){
        printf("%c", stack2[i]);
    }
}
void main(){
    char str[100];
    printf("Enter string:\n");
    scanf("%s", str);
    sep(str);
    display();
    display2();
    if(top==top2){
        printf("\nsame number of a and b character in string");
    }
    else{
        printf("\nnot same");
    }
}

