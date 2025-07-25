#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

// adding element in first
struct Node *insertAtFirst(struct Node *first)
{
    int n;
    printf("enter info of node:");
    scanf("%d", &n);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = n;
    if (first == NULL){
        first = newnode;
        newnode->link=first; 
        return first;
    }
    else
    {
        struct Node *save=first;
        while(save->link!=first){
        save=save->link;
    }
    newnode->link=first;
    save->link=newnode;
    first =newnode;
        return first;
    }
}

// display of linked list
void display(struct Node *first)
{
    struct Node *save = first;
    if (first == NULL){
        printf("List is empty.\n");
        return;
    }
    do{
        printf("%d->", save->info);
        printf("%d",save->link->info);
        save = save->link;
        
    } while (save != first);
  
}

// adding element in last
    struct Node* insertAtLast(struct Node *first){
    int n;
    printf("enter value of node:");
    scanf("%d", &n);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = n;
    if (first == NULL)
    {
        first = newnode;
        newnode->link=first; 
        return first;
    }
    else{
        struct Node *save=first;
        while(save->link!=first){
            save=save->link;
        }
        save->link=newnode;
        newnode->link=first;
        return first;
    }
}


struct Node * deleteNodeFromPosition(int position,struct Node *first){
    struct Node* save = first;
   
    if(save->link == first){
        
        free(save);
        return first;
    }
    int I=1;
    struct Node* temp;  // curr->next ne free karva mate apde temp variable lidhel che 
    while(save->link!=first){
        if(I==(position-1)){
            break;
        }
        save = save->link;
        I++;
    }
    temp = save->link;   
    save->link= save->link->link;
    free(temp);
    return first;
}

//}

void main()
{
    int choice, position;
    struct Node *first = NULL;
    
    printf("\nMenu:\n");
    printf("1. Insert at front\n");
    printf("2. Display all nodes\n");
    printf("3. Delete first node\n");
    printf("4. Insert at end\n");
    // printf("5. Delete last node\n");
     printf("6. Delete node at specified position\n");
    // printf("7. Count nodes\n");
    printf("8. Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:

            first= insertAtFirst(first);
            break;

        case 2:
            display(first);
            break;

        // case 3:
        //     deleteAtStart();
        //     break;

        case 4:
           
           first= insertAtLast(first);
            break;

        // case 5:
        //     deleteAtEnd();
        //     break;

        case 6:
            printf("Enter position to delete node: ");
            int position;
            scanf("%d", &position);
            first=deleteNodeFromPosition(position,first);
            break;
        // case 7:
        //     return;
        }
    }
}
