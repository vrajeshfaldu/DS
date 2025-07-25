#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *add(struct Node *head){
    while (1)
    {
        printf("enter data or -1 for exit list: ");
        int n = 0;
        scanf("%d", &n);
        if (n == -1)
            break;
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info = n;
        newnode->link = head;
        head = newnode;
    }
    return head;
}
void print(struct Node *head){

    struct Node *save = head;
    while (save != NULL){

        printf("%d-> ", save->info);
        save = save->link;

    }
}
void merge(struct Node *arr[], int x)
{
    struct Node *save = NULL;

    for (int i = 0; i < x - 1; i++){

        save = arr[i];
        if (save == NULL)continue;
        
        while (save->link != NULL){
            save = save->link;
        }
        save->link = arr[i + 1];
    }
}
void sort(struct Node * save){
    struct Node * temp = save;
    int temper=0;
    while(save != NULL){
        temp = save->link;
        while(temp != NULL){
            if(temp->info < save->info){
                temper = save->info;
                save->info = temp->info;
                temp->info = temper;
            }
            temp = temp->link;
        }
        save = save->link;
    }
}
void main(){

    struct Node *head = NULL;
    int x;
    scanf("%d", &x);
    struct Node *arr[x];
    for (int i = 0; i < x; i++){
        arr[i] = NULL;
        arr[i] = add(arr[i]);
        print(arr[i]);
        printf("\n");
    }
    merge(arr, x);
    sort(arr[0]);
    print(arr[0]);
}




// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int info;
//     struct node *link;
// };

// struct node *insertAtLast(struct node *first)
// {
//     int x;
//     printf("Enter the value : ");
//     scanf("%d", &x);
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->info = x;
//     newnode->link = NULL;

//     if (first == NULL)
//     {
//         first = newnode;
//         return first;
//     }
//     else
//     {
//         struct node *save = first;
//         while (save->link != NULL)
//         {
//             save = save->link;
//         }
//         save->link = newnode;
//     }
//     return first;
// }

// void display(struct node *first)
// {
//     struct node *save = first;
//     while (save != NULL)
//     {
//         printf("%d -> ", save->info);
//         save = save->link;
//     }
//     printf("\n");
// }

// struct node *sortList(struct node *first)
// {
//     struct node *i, *j;
//     int temp;
//     for (i = first; i->link != NULL; i = i->link)
//     {
//         for (j = i->link; j != NULL; j = j->link)
//         {
//             if (i->info > j->info)
//             {
//                 temp = i->info;
//                 i->info = j->info;
//                 j->info = temp;
//             }
//         }
//     }
//     return first;
// }

// void main()
// {
//     struct node *first = NULL;
//     int n, i;
//     printf("Enter numbers of nodes for linkedlist : \n");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         first = insertAtLast(first);
//     }
//     printf("Linked list before sorting : \n");
//     display(first);

//     first = sortList(first);
//     printf("Linked list after sorting : \n");
//     display(first);
// }