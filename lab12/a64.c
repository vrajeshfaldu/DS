#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *first = NULL;


void insertAtLast() {
    int n;
        printf("enter value of node:");
        scanf("%d",&n);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = n;
    newnode->link = NULL;

    if (first == NULL) {
        first = newnode;
    } 
    else {
        struct Node *temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}


void reverseList() { 
    struct Node *prev = NULL, *current = first, *next = NULL;

    while (current != NULL) {
        next = current->link;   
        current->link = prev;   
        prev = current;         
        current = next;      
    }

    first = prev; 
}


void display() {
      
    struct Node *head=first;
    
    while (head != NULL) {
        printf("%d -> ", head->info);
        head = head->link;
    }
    printf("NULL\n");
    free(head);
}

void  main() {
  int n;
  printf("Enter the size of linked list:");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    insertAtLast();
  }
  display();
  reverseList();
  display();

   
}
