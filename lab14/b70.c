#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *link;
};

    struct Node* first=NULL;
    struct Node* secondHalf=NULL;

    void insertAtLast(){
    int n;
    printf("enter value of node:");
    scanf("%d", &n);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = n;
    if(first == NULL){
        first = newnode;
        newnode->link=first; 

    }
    else{
        struct Node *save=first;
        while(save->link!=first){
            save=save->link;
        }
        save->link=newnode;
        newnode->link=first;
        
    }
}

void *split(){
    struct Node *save=first;
    struct Node *save2=first;

    while(save->link!=first && save->link->link!=first){

        save2 = save2->link;
        save = save->link->link;

    }
    secondHalf = save2->link;
    save2->link = first;

    struct Node* curr = secondHalf;
    while (curr->link != first) {
        curr = curr->link;

    }
    curr->link = secondHalf; 
}

void display1(struct Node* root){

    struct Node *save = root;
    if (root == NULL){
        printf("List is empty.\n");
        return;
    }
    do{
        printf("%d->", save->info);
        save = save->link;
        
    } while (save != root);
    printf("%d->", save->info);  
}

void main(){
   
    int x;
    printf("enter size of list:");
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        insertAtLast();
    }
    split();
    display1(first);
    printf("\n");
    display1(secondHalf);
    // split(first,second);
}

// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int info;
//     struct node *link;
// };

// struct node *first = NULL;
// struct node *last = NULL;

// void insertAtLast()
// {
//     int x;
//     printf("Enter the value : ");
//     scanf("%d", &x);
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->info = x;
//     if (first == NULL)
//     {
//         newnode->link = newnode;
//         first = last = newnode;
//     }
//     else
//     {
//         newnode->link = first;
//         last->link = newnode;
//         last = newnode;
//     }
// }

// void displayAll(struct node *start)
// {
//     if (last == NULL)
//     {
//         return;
//     }
//     printf("Linked list is : \n");
//     struct node *save = start;
//     do
//     {
//         printf("%d -> ", save->info);
//         save = save->link;
//     } while (save != start);
//     printf("\n");
// }

// void split(){
//     if(first==NULL || first->link==first){
//         printf("list is empty.");
//     }

//     struct node *slow=first;
//     struct node *fast=first;

//     while(fast->link != first && fast->link->link != first){
//         slow=slow->link;
//         fast=fast->link->link;
//     }

//     if( fast->link->link==first){
//         fast=fast->link;
//     }

//     struct node *first1=first;
//     struct node *second1=slow->link;

//     slow->link=first1;
//     fast->link=second1;

//     printf("First half : \n");
//     displayAll(first1);

//     printf("Second half : \n");
//     displayAll(second1);
// }

// void main()
// {
//     int n, i;
//     printf("Enter numbers of nodes for linkedlist : \n");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         insertAtLast();
//     }

//     printf("Linked list before split list : \n");
//     displayAll(first);

//     printf("Linked list after split list : \n");
//     split();
// }


