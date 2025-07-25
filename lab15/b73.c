#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *rptr;
    struct Node *lptr;
};

struct Node *l = NULL;
struct Node *r = NULL;
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
void deletealternate(){
     struct Node *save=l;

    struct Node *temp;
     while(save!=NULL &&save->rptr!=NULL){
        temp=save->rptr;
         save->rptr=temp->rptr;
         
         if(temp->rptr!=NULL){
         temp->rptr->lptr=save;
        }
            free(temp);
            save= save->rptr;     
    }

}
void display()
{
    struct Node *save = l;
    while (save != NULL){
        printf("%d->", save->info);
        save = save->rptr;
    }
    printf("NULL");
}

void freememory()
{
    struct Node *save = l;
    while (save != NULL){
        free(save);
        save = save->rptr;
    }
}

void main(){
    int n;
    
    printf("enter the size of arry: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insertAtLast();
    }
    printf("Before delete alternate:");
    display();
    printf("\n");

    deletealternate();
    printf("After delete alternate:");
    display();
    freememory();
}