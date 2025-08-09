#include <stdio.h>
int top = -1;
int size = 100;
void push(char stack[], char ch){
    if (top >= size - 1){
        printf("Stack is overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = ch;
}

void display(char stack[]){
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--){
        printf("%c\n", stack[i]);
    }
}
char pop(char stack[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}


void validateString(char stack[]) {
    int i = 0;
    char next;

    // Step 1: Initialize stack with 'c'
    push(stack,'c');

    // Step 2: Get and PUSH symbols until 'c' or blank is encountered
    next = stack[i++];
    while (next != 'c') {
        if (next == '\0' || next == ' ') {
            printf("Invalid String\n");
            return;
        }
        push(stack,next);
        next = stack[i++];
    }

    // Step 3: Scan characters following 'c' and compare with stack
    while (stack[top] != 'c') {
        next = stack[i++];
        char x = pop(stack);
        if (next != x) {
            printf("Invalid String\n");
            return;
        }
    }

    // Step 4: Next symbol must be blank (end of string or space)
    next = stack[i];
    if (next == '\0' || next == ' ') {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }
}

void main(){

    char stack[100];
    char ch;

    while (1){
        printf("\n1.PUSH\n 2.display\n3.validate\n Enter choice:");
        int choice;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter character to PUSH:");
            scanf(" %c", &ch);
            push(stack, ch);
            break;

        case 2:
            display(stack);
            break;
            
            case 3:
            validateString(stack);
            break;
        }
    }
}