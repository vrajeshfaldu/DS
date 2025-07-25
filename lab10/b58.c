// 58. WAP to check whether 2 singly linked lists are same or not.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node * link;
};

struct node *  insertAtLast(struct node * first){
    int x;
    printf("Enter value : ");
    scanf("%d", &x);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(!newNode){
        printf("malloc failed");
    }
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        return newNode;
    }else{
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
        return first;
    }    
}

void displayNode(struct node * first){
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d", save->info);
        save = save->link;
    }
}

void compare(struct node * first, struct node * second){
    int comparetor = 1; // true
    if(first == NULL && second == NULL){
        printf("Both lists are empty, hence same");
        return;
    }
    else{
        while(first->link != NULL && second->link != NULL){
            if(first->info != second->info){
                comparetor = 0;
                break;
            }
            first = first->link;
            second = second->link;
        }
        if(comparetor == 1){
            printf("Both the Link List are Same");
        }else{
            printf("Not Same");
        }
    }
}

    
void main(){
    int length_first=0;
    int length_second=0;

    struct node * first = NULL;

    printf("Enter Number of Node in first list : ");
    scanf("%d",&length_first);

    for(int i=0; i<length_first; i++){
        first = insertAtLast(first);
    }

    struct node * second = NULL;

    printf("Enter Number of Node in second list : ");
    scanf("%d",&length_second);

    for(int i=0; i<length_second; i++){
        second = insertAtLast(second);
    }

    if(length_first == length_second){
        compare(first,second);
    }
    else{
        printf("Not same");
    }

    printf("\nFirst Node : ");
    displayNode(first);
    printf("\nSecond Node : ");
    displayNode(second);

    free(first);
    free(second);
    return;
}
