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
int getGCD(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
  return a;
}
struct Node * gcd(struct Node *first){
    if(first==NULL){
        return first;
    }
    struct Node *save=first;
   
    
  while (save != NULL && save->link != NULL){
        struct Node *nextNode = save->link;
        
        int gcdVal = getGCD(save->info, nextNode->info);

        struct Node *gcdNode = (struct Node *)malloc(sizeof(struct Node));
        gcdNode->info = gcdVal;
        gcdNode->link = nextNode;

        save->link = gcdNode;

        save = nextNode; // Move to the original next node
    }
   return first;
}
   void deleteAtLast(struct Node *first ){
        struct Node *save=first;
        if (first == NULL){
        printf("List Is Empty");
       return;
   }
        while(save->link->link!=NULL){
            free(save);

            save=save->link;    
        }
        save->link=NULL;   
    }

int main(){
    struct Node *first = NULL;
    
    for (int i = 0; i < 5; i++){
       first= insertAtLast(first);
    }
    first=gcd(first);
    display(first);
    deleteAtLast(first);
    display(first);
        
}
