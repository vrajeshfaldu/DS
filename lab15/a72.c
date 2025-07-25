#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *rptr;
    struct Node *lptr;
};

struct Node *l = NULL;
struct Node *r = NULL;

void insertAtFirst(){

    int n;
    printf("enter info of node:");
    scanf("%d", &n);
    // struct Node *
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = n;
    if (l == NULL){
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        l = r = newnode;
    }
    else{
        newnode->rptr = l;
        newnode->lptr = NULL;
        l = newnode;
    }
}
void insertAtLast()
{
    int n;
    printf("enter info of node:");
    scanf("%d", &n);
    // struct Node *
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = n;
    newnode->rptr = NULL;
    if (r == NULL){
        newnode->lptr = NULL;       
        l = r = newnode;
    }
    else{
        newnode->lptr = r;
        r->rptr = newnode;
        r = newnode;
    }
}
void deleteSpecified(){
    struct Node *save = l;

    int position;
    printf("enter position which you want to delete:");
    scanf("%d", &position);

    if (save == NULL){
        printf("position out of bound");
    }
    int count = 1;
    
    while (save != NULL && count < position){
        
        save = save->rptr;
        count++;
    }
    save->lptr->rptr = save->rptr;
    save->rptr->lptr = save->lptr;
    free(save);
}
void display(){
    struct Node *save = l;
    while (save != NULL){
        printf("%d->", save->info);
        save = save->rptr;
    }
}
void freememory()
{
    struct Node *save = l;
    while (save != NULL)
    {
        free(save);
        save = save->rptr;
    }
}

void main(){
    int choice, position;
    struct Node *first = NULL;

    printf("\nMenu:\n");
    printf("1. Insert at front\n");
    printf("2. Display all nodes\n");
    printf("3. Insert at end\n");
    printf("4. Delete node at specified position\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            insertAtFirst();
            break;

        case 2:
            display();
            printf("\n");
            break;

        case 3:
            insertAtLast();
            break;

        case 4:
            deleteSpecified();
            break;

        case 5:
            return;
            break;
        }
    }
    freememory();
    
}
