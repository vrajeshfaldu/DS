// 34. Write a menu driven program to implement following operations on the Stack 
// using an Array
// • PUSH, POP, DISPLAY
// • PEEP, CHANGE
#include<stdio.h>
int size=100;
char stack[100];
int top = -1;


void push(char ch){
    if (top>= size-1){
        printf("Stack is overflow\n");
        return;
    }   
    top=top+1;
    stack[top]=ch;
}

void display(){
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--){
        printf("%c\n", stack[i]);
    }
}
void pop(){
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element is: %c\n", stack[top]);
    top = top - 1;
}


void peep(){
    int i;
    printf("Enter the index of element which you want to display from the top :\n");
    scanf("%d", &i);
    if (i > top + 1 || i <= 0){
        printf("Stack is underflow\n");
        return ;
    }
    printf("Element at position %d from top is: %c\n",i, stack[top-i+1]);
}
void change(){
    int i;
    printf("enter the position which value you want to change:");
    scanf("%d",&i);
    if(top-i+1<=0){
        printf("stack underflow");
    }
    printf("Enter the value for changing:");
    char ch;
    scanf("%c",ch);
    stack[top-i+1]=ch;
}

void main (){
    int choice;
    char ch;

    while(1){
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n 5.PEEP\n6.CHANGE\n Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter character to PUSH: ");
                scanf(" %c",&ch);  
                push(ch);
                break;
            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return;

            case 5:
                peep();
                break;
            case 6:
                change();
                break;    

            default:
                printf("Invalid choice!\n");
        }
    }
}
