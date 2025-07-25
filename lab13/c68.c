

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *insertAtLast(struct node *first)
{
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;

    if (first == NULL)
    {
        first = newnode;
        return first;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
    return first;
}

void display(struct node *first)
{
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("\n");
}

struct node *swapNode(struct node *first){
    struct node *firstone, *second, *third, *prev;
    prev = NULL;
    firstone = first;
    second = first->link;

    while (firstone != NULL && second != NULL)
    {
        third = second->link;
        second->link = firstone;
        firstone->link = third;
        if (prev == NULL)
        {
            first = second;
        }
        else
        {
            prev->link = second;
        }
        prev = firstone;
        firstone = third;
        if (third == NULL){
            second = NULL;
        }
        else{
            second = third->link;
        }
    }
    return first;
}

void main(){
    struct node *first = NULL;
    int n, i;
    printf("Enter numbers of nodes for linkedlist : \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        first = insertAtLast(first);
    }

    printf("Linked list before swap two nodes consecutive : \n");
    display(first);

    first = swapNode(first);
    printf("Linked list after swap two nodes consecutive : \n");
    display(first);
}
