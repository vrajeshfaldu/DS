#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    int p;
    struct node * link;
};

struct node * createNewNode(int p){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Underflow !!\n");
        return NULL;
    }
    else{
        newNode->p = p;
        return newNode;
    }
}

void displayQueue(struct node * head){
    
    if(head == NULL){
        printf("Queue is Empty !!\n");
        return;
    }
    
    struct node * save = head;

    while(save != NULL){
        printf("%d(%d) -> ",save->info,save->p);
        save = save->link;
    }
    printf("NULL\n");
    return;
}

void freeQueue(struct node **head){
    struct node * temp;
    while(*head != NULL){
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}


// Enqueue :
struct node * insertQueue(struct node * first,int x){
    
    int p = 0;
    printf("Enter Priority : ");
    scanf("%d",&p);

    struct node * newNode = createNewNode(p);
    if (newNode == NULL) {
        return first;
    }
    newNode->info = x;
    newNode->link = NULL;

    if(first == NULL){
        return newNode;
    }

    struct node * save = first;
    // int position = 0;
    struct node * pred = save;
    while(save -> link != NULL){

        if(save->p>p){
            pred = pred->link;
            // position++;
        }
        save = save->link;
    }
    newNode->link = pred->link;
    pred->link = newNode;

    return first;
}


//Dequeue :
struct node * deleteQueue(struct node * first){

    if(first == NULL){
        printf("Queue is Empty\n");
        return NULL;
    }
    struct node * save = first;
    first = save->link;
    free(save);

    return first;
}

void main(){

    struct node * first = NULL;
    int x = 0;
    int option = 0;
    while(1){
        printf("\nEnter :\n 1 to Enqueue\n 2 to Dequeue\n 3 to Display Queue\n-1 to Exit\n :");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("\nEnter value to Enqueue : ");
                scanf("%d",&x);
                first=insertQueue(first,x);
                break;
            case 2:
                first = deleteQueue(first);
                break;
            case 3:
                displayQueue(first);
                break;
            case -1:
                freeQueue(&first);
                printf("Exit");
                return;
            default:
                printf("Invalid option Try again.\n");
                break;
 }
    }
}
