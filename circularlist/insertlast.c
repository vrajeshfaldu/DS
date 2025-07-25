#include<stdio.h>
#include<stdlib.h>
 struct Node{
        int info;
        struct Node *link;
};
struct Node *first=NULL;
struct Node *last=NULL;
void insertAtLast(){
     int n;
        printf("enter value of node:");
        scanf("%d",&n);
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->info=n;
        if(first==NULL){
            newnode->link=newnode;
            first=last=newnode;
        }
        else{
            newnode->link=first;
            last->link=newnode;
            last=newnode;
        }

}
void display(){
    struct Node *save = first;
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("%d ", save->info);
        save = save->link;
    } while(save != first);
    free(save);
}

    void main(){
        int x;
        printf("enter how long linked list you need:");
        scanf("%d",&x);
        int count=0;
        for(int i=1;i<=x;i++){
        insertAtLast();
        }
        display();
           
           
    }
