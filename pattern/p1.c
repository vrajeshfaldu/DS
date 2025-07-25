#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *rptr;
    struct node *lptr;
};

struct node *l = NULL;
struct node *r = NULL;

void insertAtFirst()
{
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if (l == NULL)
    {
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        l = r = newnode;
    }
    else
    {
        newnode->rptr = l;
        newnode->lptr = NULL;
        l = newnode;
    }
}
void insertAtLast()
{
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->rptr = NULL;
    if (r == NULL)
    {
        newnode->lptr = NULL;
        l = r = newnode;
    }
    else
    {
        newnode->lptr = r;
        r->rptr = newnode;
        r = newnode;
    }
}

void deleteSpecified()
{
    struct node *save = l;

    int pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d", &pos);

    if (save == NULL)
    {
        printf("List is already empty.\n");
    }
    int count = 1;
    while (save != NULL && count < pos)
    {
        save = save->rptr;
        count++;
    }
    save->lptr->rptr = save->rptr;
    save->rptr->lptr = save->lptr;
    free(save);
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
    
    while (save != NULL && count < position)
    {

        save = save->rptr;
        count++;
    }
    save->lptr->rptr = save->rptr;
    save->rptr->lptr = save->lptr;
    free(save);
}

void displayAll()
{
    struct node *save = l;
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->rptr;
    }
    printf("\n");
}

void displayCount()
{
    int count = 0;
    struct node *save = l;
    while (save != NULL)
    {
        save = save->rptr;
        count++;
    }
    printf("Number of node is : %d\n", count);
}

void main()
{
    int n;
    while (1)
    {
        printf("Enter 1 for insert node at first\n");
        printf("Enter 2 for insert node at last \n");
        printf("Enter 3 for insert node at ordered list\n");
        printf("Enter 4 for delete first node\n");
        printf("Enter 5 for delete last node\n");
        printf("Enter 6 for delete node from specified position\n");
        printf("Enter 7 for display all nodes\n");
        printf("Enter 8 for display number of nodes \n");
        printf("Enter the number  : \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insertAtFirst();
            break;

        case 2:
            insertAtLast();
            break;

        // case 3:
        //     insertAtOrdered();
        //     break;

        // case 4:
        //     deleteFirst();
        //     break;

        // case 5:
        //     deleteLast();
        //     break;

        case 6:
            deleteSpecified();
            break;

        case 7:
            displayAll();
            break;

        case 8:
            displayCount();
            break;
 }
}
}
