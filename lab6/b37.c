#include <stdio.h>

int size = 100;
char stack[100];
int top = -1;

void push(char ch){

    if (top >= size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
        
}
void display(){
    if (top == -1){
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i<=top; i++){
        printf("%c", stack[i]);
    }
}
char pop(){
    if (top < 0){
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}
void validpar(char str[]){
    if(str[0]==' '){
        printf("balanced parenthesis");
        return;
    }
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        push(str[i]);
        else if(str[i]==')'||str[i]=='}'||str[i]==']'){
              if (top == -1) {
                printf("Unbalanced Parenthesis\n");
                return;
            }
            pop();
        }
        i++;
    }
    if(top==-1){
        printf("balanced parenthesis");
        return;
    }
    else{
        printf("unbalanced parenthesis");
    }
}



void main(){
    char str[100];
    printf("Enter string:\n");
    scanf("%[^\n]s", str);
    validpar(str); 
    display();
}