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
    printf("Enter value : ");
    scanf("%d", &x);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("malloc failed");
    }
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        return newNode;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
        return first;
    }
}

void displayNode(struct node *first)
{
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d", save->info);
        save = save->link;
    }
}

struct node *mergTwoLL(struct node *first1, struct node *first2)
{
    if (first1 == NULL) return first2;
    if (first2 == NULL) return first1;

    struct node *first = NULL, *save = NULL;

    while (first1 != NULL && first2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->link = NULL;

        if (first1->info < first2->info)
        {
            newNode->info = first1->info;
            first1 = first1->link;
        }
        else
        {
            newNode->info = first2->info;
            first2 = first2->link;
        }

        if (first == NULL){
            first = newNode;
            save = newNode;
        }
        else
        {
            save->link = newNode;
            save = newNode;
        }
    }
    while (first1 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = first1->info;
        newNode->link = NULL;
        save->link = newNode;
        save = newNode;
        first1 = first1->link;
    }

    while (first2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = first2->info;
        newNode->link = NULL;
        save->link = newNode;
        save = newNode;
        first2 = first2->link;
    }
    return first;
}

void freeList(struct node * head) {
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->link;
        free(temp);
    }
    head = NULL;
}

void main()
{
    int length1 = 0;
    int length2 = 0;

    struct node *first1 = NULL;

    printf("Enter Number of Node in first list : ");
    scanf("%d", &length1);

    for (int i = 0; i < length1; i++)
    {
        first1 = insertAtLast(first1);
    }

    struct node *first2 = NULL;

    printf("Enter Number of Node in second list : ");
    scanf("%d", &length2);

    for (int i = 0; i < length2; i++)
    {
        first2 = insertAtLast(first2);
    }

    struct node* first3 = mergTwoLL(first1,first2);
    displayNode(first3);
    freeList(first1);
    freeList(first2);
    freeList(first3);
}
