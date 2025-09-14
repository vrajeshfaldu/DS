// #include <stdio.h>

// int size=100;
// char stack[100];
// int top = -1;

// void push(char s[],char ch){
//     if (top>= size-1){
//         printf("Stack is overflow\n");
//         return;
//     }
//     s[++top] =ch;
// }

// int pop(char s[]){
//     if (top <= -1){
//         printf("Stack is underflow\n");
//         return 0;
//     }
//     return s[top--];
// }

// int recognize(char str[]){
//     int i=0;
//     char next,x;

//     top=0;
//     stack[top]='c';
//     next=str[i];

//     while(next != 'c'){
//         if(next == 'c'){
//             printf("Invalid string");
//             return 0;
//         }
//         else{
//         push(stack,stack[i]);
//         i++;
//         // next=str[i];
//         }
//     }
//     while(stack[top]!='c'){
//         x=pop(stack);
//         if(next!='x'){
//             printf("Invalid string");
//             return 0;
//         }
//         i++;
//         next=str[i];
//     }
//     if(str[i]==' '){
//         printf("Valid String");
//         return 1;
// }

//else{
//         printf("Invalid String");
//         return 0;
// }
// }

// void main(){
//    char input[100];
   
//    printf("Enter string to recognize :\n");
//    scanf("%s",input);
//    recognize(input);
// }
#include <stdio.h>
#include <string.h>

void reverse(char result[], int start, int end){
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}

int isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void vowelAnxiety(char str[]) {
    char result[200];
    int resIndex = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isVowel(str[i])){
            // Reverse the entire result built so far
            reverse(result, 0, resIndex - 1);
            // Append the vowel itself
            result[resIndex++] = str[i];
        } else {
            // Add consonant to result
            result[resIndex++] = str[i];
        }
    }

    result[resIndex] = '\0';
    printf("%s\n", result);
}

int main() {
    int n;
    char input[105];

    printf("How many strings you want to enter:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter string:\n");
        scanf("%s", input);
        vowelAnxiety(input);
    }

    return 0;
}
