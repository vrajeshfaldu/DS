// #include <stdio.h>
// #include<string.h>
// #define SIZE 100
// int Top = -1;
// char s[SIZE];
// int i;
// char next;
// void push(char x);
// int pop();
// void push(char x){
//     if (Top >= SIZE-1){
//         printf("Overflow");
//         return;
//     }
//     s[++Top] = x;
// }
// int pop(){
//     if (Top == -1){
//         printf("Stack UnderFlow");
//     }
//     Top = Top - 1;
//     return s[Top+1];
// }

// void main(){
//     int i=0;
//     char x ;
//     char str[SIZE];
//     printf("Enter a string:");
//     scanf("%s", str);
//     // push('c');
//     char next = str[i];
//     while (next != 'c'){
//         if(next == '\0'){
//             printf("Invalid string");
//             return;
//         }
//         else{
//             push(next);
//             i++;
//             next = str[i];
//         }
//     }    
    
//     i++;
//     next = str[i];
//     while(str[i] != '\0'){
//         x = pop();
//         if(next != x){
//             printf("Invalid string");
//             return;
//         }
//         i++;
//         next = str[i];
//     }
//     char last=pop();
//     if (next == '\0'){
//         printf("Valid string");
//     }
//     else{
//         printf("Invalid string");
//     }
// }


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

char pop(){
    if (top < 0){
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}

int recognize(char str[]){
    int i = 0;
    char next, x;

    top = 0;
    stack[top] = 'c';

    next = str[i];
    while (next != 'c'){
        if (next == '\0')
        {
            printf("Invalid String\n");
            return 0;
        }
        else{
            push(next);
            i++;
            next = str[i];
        }
    }

    i++;
    next = str[i];

    while (stack[top]!='c'){
        x = pop();
        if (next != x)
        {
            printf("Invalid String\n");
            return 0;
        }
        i++;
        next = str[i];
    }

    if (str[i] == '\0'){
        printf("Valid String\n");
        return 1;
    }
    else{
        printf("Invalid String\n");
        return 0;
    }
}

void main(){
    char input[100];
    printf("Enter string to recognize:\n");
    scanf("%s", input);
    recognize(input); 
}



