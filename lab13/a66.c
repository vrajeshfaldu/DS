
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};
 struct Node * first=NULL;
struct Node *insertAtLast(struct  Node *first){
    printf("enter value of info:");
        int x;
        scanf("%d",&x);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info=x;
    newnode->link= NULL;
    if(first==NULL){
        first=newnode;
        return first;
    }
    else{
        struct Node *save=first;
        while(save->link!=NULL){
            save=save->link;
        }
        save->link=newnode;
        return first;
    }
}
   struct Node *sort(struct Node *first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *i, *j;
    int temp;

    for (i = first; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                // Swap data
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    return first;
}

        
    
    void display(struct Node *save) {
        while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
    free(save);
    }
    void main(){
        printf("enter size of linked list:");
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
           first= insertAtLast(first);
        }
        display(first);
        sort(first);
        display(first);
    }



