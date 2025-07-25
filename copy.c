#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *link;
};
struct Node * insertAtLast(struct Node *first){
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node ));
    newnode->info = x;
    newnode->link = NULL;

    if (first == NULL){
        first=newnode;
        return first;
    }
    else{
        struct Node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
        return first;
    }
    
}
void display(struct Node *first)
{
    if (first == NULL)
    {
        return ;
    }
    struct Node *save = first;
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("\n");
}

struct Node * copyList(struct Node *first,struct Node *sec)
{
    if (first == NULL){

        printf("Linked List is empty.");
        return NULL;
    }
    else{
        struct Node *save = first;
        struct Node *save2 = sec ;
        while (save != NULL){
            // struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
            save2->info = save->info;

            if(save->link == NULL){
             save2->link=NULL;
             break;
            }
            else{
                save2->link=(struct Node *)malloc(sizeof(struct Node));
            }
            save2 = save2->link;
            save = save -> link;

           
        }
        // save2->link = NULL;
        // newnode->link=NULL;
    }
    return sec;
}

int main()
{
    struct Node *first = NULL;
    struct Node *sec=(struct Node *)malloc(sizeof(struct Node));;
    for (int i = 0; i < 5; i++){
       first= insertAtLast(first); 
    }
    printf("Linked List is : \n");
    display(first);

    printf("Copy Linked List is : \n");
    sec=copyList(first,sec);
    display(sec);
}





